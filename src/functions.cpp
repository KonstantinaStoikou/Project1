#include "../include/functions.h"
#include "../include/defines.h"
#include "../include/metrics.h"
#include <iostream>
#include <limits>

void print_vectors(std::vector<Point> &points) {
    // print vector of vectors with points
    for (auto i : points) {
        std::cout << GREEN << "Point #" << i.get_id() << ": " << RESET;
        for (auto j : i.get_vector()) {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
}

void print_arguments(std::string infile, std::string query_file,
                     std::string outfile, int k, int L) {
    std::cout << BLUE << "Input file: " << infile << "\n";
    std::cout << "Query file: " << query_file << "\n";
    std::cout << "Output file: " << outfile << "\n";
    std::cout << "k: " << k << "\n";
    std::cout << "L: " << L << "\n" << RESET;
}

int find_avg_nn_dist(std::vector<Point> &points) {
    int dist_sum = 0;
    // iterate vector with points
    for (std::size_t i = 0; i < points.size() - 1; i++) {
        int nn_dist = std::numeric_limits<int>::max();
        // for each point calculate distance between all other points
        for (std::size_t j = i + 1; j < points.size(); j++) {
            std::vector<int> point1_vec = points.at(i).get_vector();
            std::vector<int> point2_vec = points.at(j).get_vector();
            int dist = 0;
            // calculate manhattan distance for all vector values
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