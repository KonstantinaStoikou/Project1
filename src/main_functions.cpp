#include "../include/main_functions.h"
#include "../include/metrics.h"
#include <limits>

double find_avg_nn_dist(std::vector<Point> points) {
    double dist_sum = 0;
    // iterate vector with points
    for (std::size_t i = 0; i < points.size() - 1; i++) {
        double nn_dist = std::numeric_limits<int>::max();
        // for each point calculate distance between all other points
        for (std::size_t j = i + 1; j < points.size(); j++) {
            std::vector<int> point1_vec = points.at(i).get_vector();
            std::vector<int> point2_vec = points.at(j).get_vector();
            // calculate manhattan distance for all vector values
            double dist = 0;
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
                   std::vector<std::tuple<int, int, double>> &nn) {

    for (std::size_t i = 0; i < q_points.size(); i++) {
        double nn_dist = std::numeric_limits<float>::max();
        int id;
        std::vector<int> q_point_vec = q_points.at(i).get_vector();
        for (std::size_t j = 0; j < in_points.size(); j++) {
            std::vector<int> in_point_vec = in_points.at(j).get_vector();
            // calculate manhattan distance for all vector values
            double dist = 0;
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
        Hashtable *ht = new Hashtable(table_size, k, dims, w);
        for (auto &x : in_points) {
            ht->insert_item(&x);
        }
        ht_vec.push_back(ht);
    }
}

void lsh_search(std::vector<Hashtable *> ht_vec, std::vector<Point> q_points,
                std::vector<std::tuple<int, int, double>> &nn,
                int search_limit) {
    for (auto q : q_points) {
        double nn_dist = std::numeric_limits<float>::max();
        int nn_id;
        for (auto ht : ht_vec) {
            int limit = search_limit;
            int index = ht->get_hash(q) % ht->get_size();
            std::list<Point *> bucket = ht->get_indexed_bucket(index);
            for (std::list<Point *>::const_iterator it = bucket.begin();
                 it != bucket.end() && limit > 0; ++it, --limit) {
                if (ht->get_hash(q) == ht->get_hash(**it)) {
                    double dist = 0;
                    for (std::size_t d = 0; d < q.get_vector().size(); d++) {
                        dist += manhattan_dist(q.get_vector().at(d),
                                               (*it)->get_vector().at(d));
                    }
                    // check if this point is nearest than the previous nearest
                    if (dist <= nn_dist) {
                        nn_dist = dist;
                        nn_id = (*it)->get_id();
                    }
                }
            }
        }
        if (nn_dist == std::numeric_limits<float>::max()) {
            nn.push_back({q.get_id(), -1, -1});
        } else {
            nn.push_back({q.get_id(), nn_id, nn_dist});
        }
    }
}

float find_accuracy(std::vector<std::tuple<int, int, double>> real_nn,
                    std::vector<std::tuple<int, int, double>> approx_nn) {
    int correct_num = 0;
    for (unsigned int i = 0; i < real_nn.size(); i++) {
        if (std::get<2>(real_nn.at(i)) == std::get<2>(approx_nn.at(i))) {
            correct_num++;
        }
    }
    return (float)correct_num / real_nn.size();
}

double
find_mean_absolute_error(std::vector<std::tuple<int, int, double>> real_nn,
                         std::vector<std::tuple<int, int, double>> approx_nn) {
    double err_sum = 0;
    for (unsigned int i = 0; i < real_nn.size(); i++) {
        err_sum +=
            std::abs(std::get<2>(real_nn.at(i)) - std::get<2>(approx_nn.at(i)));
    }

    return err_sum / real_nn.size();
}
