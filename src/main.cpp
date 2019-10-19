#include "../include/defines.h"
#include "../include/functions.h"
#include "../include/h.h"
#include "../include/hash.h"
#include "../include/point.h"
#include "../include/read_functions.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    std::string infile, query_file, outfile;
    int k = 4, L = 5; // initialize k, L with default values

    read_lsh_vector_args(argc, argv, infile, query_file, outfile, k, L);
    print_arguments(infile, query_file, outfile, k, L);

    // if files not given ask for user input
    if (infile.empty()) {
        std::cout << GREEN << "Please give input file:\n" << RESET;
        std::cin >> infile;
    }

    // here we create search structure (lsh etc.)
    // read file with input points and return them in a vector
    std::vector<Point> in_points;
    if (read_vectors_file("../sample datasets/vectors/siftsmall/input_small_id",
                          in_points) < 0) {
        std::cout << RED << "Error while reading input file." << RESET
                  << std::endl;
    }
    print_points(in_points);
    // const int w = find_avg_nn_dist(points) * 10;
    const int w = 1464 * 10;
    std::cout << "Average nn distance: " << w / 10 << std::endl;

    if (query_file.empty()) {
        std::cout << GREEN << "Please give query file:\n" << RESET;
        std::cin >> query_file;
    }

    // read file with query points and return them in a vector
    std::vector<Point> q_points;
    if (read_vectors_file("../sample datasets/vectors/siftsmall/query_small_id",
                          q_points) < 0) {
        std::cout << RED << "Error while reading query file." << RESET
                  << std::endl;
    }
    std::cout << "Query Points are: " << std::endl;
    print_points(q_points);
    std::vector<std::tuple<int, int, float>> real_nn;
    exhaustive_nn(in_points, q_points, real_nn);
    std::cout << "Real Nearest Neighbors: " << std::endl;
    print_nn(real_nn);

    if (outfile.empty()) {
        std::cout << GREEN << "Please give output file:\n" << RESET;
        std::cin >> outfile;
    }
    print_arguments(infile, query_file, outfile, k, L);

    return 0;
}
