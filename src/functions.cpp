#include "../include/functions.h"
#include "../include/defines.h"
#include "../include/metrics.h"
#include <iostream>
#include <limits>

void print_points(std::vector<Point> points) {
    // print vector of vectors with points
    for (auto i : points) {
        std::cout << GREEN << "Point #" << i.get_id() << ": " << RESET;
        for (auto j : i.get_vector()) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void print_arguments(std::string infile, std::string query_file,
                     std::string outfile, int k, int L) {
    std::cout << BLUE << "Input file: " << infile << std::endl;
    std::cout << "Query file: " << query_file << std::endl;
    std::cout << "Output file: " << outfile << std::endl;
    std::cout << "k: " << k << std::endl;
    std::cout << "L: " << L << std::endl << RESET;
}

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

void print_nn(std::vector<std::tuple<int, int, float>> nn) {
    for (auto &tuple : nn) {
        std::cout << "Point #" << std::get<0>(tuple)
                  << ": NN: " << std::get<1>(tuple)
                  << " Dist: " << std::get<2>(tuple) << std::endl;
    }
}