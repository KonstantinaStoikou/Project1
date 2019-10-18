#include "../include/defines.h"
#include "../include/functions.h"
#include "../include/hash.h"
#include "../include/point.h"
#include "../include/read_functions.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    std::string infile, query_file, outfile;
    int k = 4, L = 5; // initialize k, L with default values
    std::vector<Point> points;
    read_lsh_vector_args(argc, argv, infile, query_file, outfile, k, L);
    print_arguments(infile, query_file, outfile, k, L);
    // if files not given ask for user input
    if (infile.empty()) {
        std::cout << GREEN << "Please give input file:\n" << RESET;
        std::cin >> infile;
    }

    // here we create search structure (lsh etc.)

    if (query_file.empty()) {
        std::cout << GREEN << "Please give query file:\n" << RESET;
        std::cin >> query_file;
    }
    if (outfile.empty()) {
        std::cout << GREEN << "Please give output file:\n" << RESET;
        std::cin >> outfile;
    }
    print_arguments(infile, query_file, outfile, k, L);

    if (read_vectors_file("../sample datasets/vectors/siftsmall/query_small_id",
                          points) < 0) {
        std::cout << "error";
    }
    print_vectors(points);
    int avg_nn_dist = find_avg_nn_dist(points);
    const int w = 0;
    std::cout << "Average nn distance: " << avg_nn_dist << "\n";
    return 0;
}
