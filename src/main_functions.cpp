#include "../include/main_functions.h"
#include "../include/metrics.h"
#include <iostream>
#include <limits>

int find_avg_nn_dist(std::vector<Point> points) {
    int dist_sum = 0;
    // iterate vector with points
    for (std::size_t i = 0; i < points.size() - 1; i++) {
        int nn_dist = std::numeric_limits<int>::max();
        // for each point calculate distance between all other points
        for (std::size_t j = i + 1; j < points.size(); j++) {
            std::vector<int> point1_vec = points.at(i).get_vector();
            std::vector<int> point2_vec = points.at(j).get_vector();
            // calculate manhattan distance for all vector values
            int dist = 0;
            for (std::size_t d = 0; d < point1_vec.size(); d++) {
                dist += manhattan_dist(point1_vec.at(d), point2_vec.at(d));
            }
            // check if this point is nearest than the previous nearest
            if (dist <= nn_dist) {
                nn_dist = dist;
            }
        }
        dist_sum += nn_dist;
    }
    return dist_sum / points.size();
}

void exhaustive_nn(std::vector<Point> in_points, std::vector<Point> q_points,
                   std::vector<std::tuple<int, int, float>> &nn) {

    for (std::size_t i = 0; i < q_points.size(); i++) {
        float nn_dist = std::numeric_limits<float>::max();
        int id;
        std::vector<int> q_point_vec = q_points.at(i).get_vector();
        for (std::size_t j = 0; j < in_points.size(); j++) {
            std::vector<int> in_point_vec = in_points.at(j).get_vector();
            // calculate manhattan distance for all vector values
            float dist = 0.0;
            for (std::size_t d = 0; d < q_point_vec.size(); d++) {
                dist += (float)manhattan_dist(q_point_vec.at(d),
                                              in_point_vec.at(d));
            }
            // check if this input point is nearest than the previous nearest
            if (dist <= nn_dist) {
                nn_dist = dist;
                id = in_points.at(j).get_id();
            }
        }
        nn.push_back({q_points.at(i).get_id(), id, nn_dist});
    }
}

void create_hashtables(std::vector<Hashtable *> &ht_vec, int L, int dims, int w,
                       int k, std::vector<Point> &in_points, int table_size) {
    for (int i = 0; i < L; i++) {
        std::cout << "HT #" << i << std::endl;
        Hashtable *ht = new Hashtable(table_size, k, dims, w);
        for (auto x : in_points) {
            ht->insert_item(&x);
        }
        ht_vec.push_back(ht);
    }

    ht_vec.at(0)->display_hashtable();
}

// vgazo iostream!