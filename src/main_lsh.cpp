#include "../include/defines.h"
#include "../include/hashtable_lsh.h"
#include "../include/main_functions.h"
#include "../include/metrics.h"
#include "../include/point.h"
#include "../include/print_functions.h"
#include "../include/read_functions.h"
#include <iostream>
#include <limits>

int main(int argc, char const *argv[]) {
    std::string infile, qfile, outfile;
    int k = 4, L = 5; // initialize k, L with default values
    read_lsh_vector_args(argc, argv, infile, qfile, outfile, k, L);

    ask_file(infile, "input");
    // read file with input points and return them in a vector
    std::vector<Point> in_points;
    if (read_vectors_file(infile, in_points) < 0) {
        std::cout << RED << "Error while reading input file." << RESET
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    int dims = in_points.at(0).get_vector().size();
    const double w = find_avg_nn_dist(in_points) * 4;
    int table_size = in_points.size() / 8;
    // create vector with L hashtables
    std::vector<Hashtable_LSH *> ht_vec;
    create_hashtables(ht_vec, L, dims, w, k, in_points, table_size);
    ask_file(qfile, "query");
    // read file with query points and return them in a vector
    std::vector<Point> q_points;
    if (read_vectors_file(qfile, q_points) < 0) {
        std::cout << RED << "Error while reading query file." << RESET
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    // Vector: id query, id neighbor, distance, search time
    std::vector<std::tuple<int, int, double, double>> real_nn;

    exhaustive_nn(in_points, q_points, real_nn);

    // search limit to iterate through "search_lim" points in bucket
    const int search_lim = 4 * L;
    // Vector: id query, id neighbor, distance, search time
    std::vector<std::tuple<int, int, double, double>> approx_nn;
    lsh_search(ht_vec, q_points, approx_nn, search_lim);

    ask_file(outfile, "output");
    write_outfile(outfile, real_nn, approx_nn);

    std::cout << YELLOW << "Accuracy: " << find_accuracy(real_nn, approx_nn)
              << YELLOW << std::endl;
    std::cout << YELLOW << "Mean Absolute Error: "
              << find_mean_absolute_error(real_nn, approx_nn) << YELLOW
              << std::endl;
    std::cout << YELLOW << "Average approximation fraction: "
              << find_avg_fraction(real_nn, approx_nn) << YELLOW << std::endl;
    std::cout << YELLOW << "Maximum approximation fraction: "
              << find_max_fraction(real_nn, approx_nn) << YELLOW << std::endl;
    std::cout << YELLOW << "Average search time for approximate neighbors: "
              << find_avg_time(approx_nn) << RESET << std::endl;

    for (int i = 0; i < L; i++) {
        delete ht_vec[i];
    }
    in_points.clear();
    q_points.clear();

    return 0;
}
