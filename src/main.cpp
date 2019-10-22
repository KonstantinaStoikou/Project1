#include "../include/defines.h"
#include "../include/hashtable.h"
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
    print_arguments(infile, qfile, outfile, k, L);
    ask_file(infile, "input");

    // read file with input points and return them in a vector
    std::vector<Point> in_points;
    if (read_vectors_file("../sample datasets/vectors/siftsmall/test",
                          in_points) < 0) {
        std::cout << RED << "Error while reading input file." << RESET
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    int dims = in_points.at(0).get_vector().size();
    // print_points(in_points);
    // const int w = find_avg_nn_dist(points) * 10;
    const int w = 1464 * 4;
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
        exit(EXIT_FAILURE);
    }
    // std::cout << "Query Points are: " << std::endl;
    // print_points(q_points);
    // std::vector<std::tuple<int, int, float>> real_nn;
    // exhaustive_nn(in_points, q_points, real_nn);
    // std::cout << "Real Nearest Neighbors: " << std::endl;
    // print_nn(real_nn);

    // search limit to iterate through "search_lim" points in bucket
    std::vector<std::tuple<int, int, float>> approx_nn;
    int search_lim = 3 * L;
    for (auto q : q_points) {
        int nn_dist = std::numeric_limits<int>::max();
        int nn_id;
        for (auto ht : ht_vec) {
            int index = ht->get_hash(q) / ht->get_size();
            std::list<Point *> bucket = ht->get_indexed_bucket(index);
            for (std::list<Point *>::const_iterator it = bucket.begin();
                 it != bucket.end() && search_lim > 0; ++it, --search_lim) {
                int dist = 0;
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
        approx_nn.push_back({q.get_id(), nn_id, nn_dist});
    }
    print_nn(approx_nn);
    // ask_file(outfile, "output");
    // print_arguments(infile, qfile, outfile, k, L);

    return 0;
}
