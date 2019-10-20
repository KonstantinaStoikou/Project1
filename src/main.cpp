#include "../include/defines.h"
#include "../include/hashtable.h"
#include "../include/main_functions.h"
#include "../include/point.h"
#include "../include/print_functions.h"
#include "../include/read_functions.h"
#include <iostream>

int main(int argc, char const *argv[]) {
    std::string infile, qfile, outfile;
    int k = 4, L = 5; // initialize k, L with default values
    read_lsh_vector_args(argc, argv, infile, qfile, outfile, k, L);
    print_arguments(infile, qfile, outfile, k, L);
    ask_file(infile, "input");

    // read file with input points and return them in a vector
    std::vector<Point> in_points;
    if (read_vectors_file("../sample datasets/vectors/siftsmall/test",
                          in_points) < 0) {
        std::cout << RED << "Error while reading input file." << RESET
                  << std::endl;
    }

    int dims = in_points.at(0).get_vector().size();
    // print_points(in_points);
    // const int w = find_avg_nn_dist(points) * 10;
    const int w = 1464 * 10;
    // std::cout << "Average nn distance: " << w / 10 << std::endl;
    int table_size = in_points.size() / 2;
    // create vector with L hashtables
    std::vector<Hashtable *> ht_vec;
    create_hashtables(ht_vec, L, dims, w, k, in_points, table_size);

    ask_file(qfile, "query");

    // read file with query points and return them in a vector
    std::vector<Point> q_points;
    if (read_vectors_file("../sample datasets/vectors/siftsmall/query_small_id",
                          q_points) < 0) {
        std::cout << RED << "Error while reading query file." << RESET
                  << std::endl;
    }
    // std::cout << "Query Points are: " << std::endl;
    // print_points(q_points);
    // std::vector<std::tuple<int, int, float>> real_nn;
    // exhaustive_nn(in_points, q_points, real_nn);
    // std::cout << "Real Nearest Neighbors: " << std::endl;
    // print_nn(real_nn);

    // ask_file(outfile, "output");
    // print_arguments(infile, qfile, outfile, k, L);

    return 0;
}
