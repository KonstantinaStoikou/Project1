#include "../include/hashtable_cube.h"
#include "../include/defines.h"
#include "../include/main_functions.h"
#include "../include/metrics.h"
#include "../include/point.h"
#include "../include/print_functions.h"
#include "../include/read_functions.h"
#include <ctime>
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
    // for small dataset: avr_nn_dist = 14641.3
    // for big dataset avr_nn_dist =
    // const double w = find_avg_nn_dist(in_points) * 10;
    const double w = 14641.3 * 4;
    int table_size = in_points.size() / 16;
    // create vector with L hashtables
    std::vector<HashtableC *> ht_vec;
     for (int i = 0; i < L; i++) {
        HashtableC *ht = new HashtableC(table_size, k, dims, w);
        for (auto &x : in_points) {
            ht->insert_item(&x);
        }
        ht_vec.push_back(ht);
    }
    ask_file(qfile, "query");
    // read file with query points and return them in a vector
    std::vector<Point> q_points;
    if (read_vectors_file(qfile, q_points) < 0) {
        std::cout << RED << "Error while reading query file." << RESET
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    std::vector<std::tuple<int, int, double>> real_nn;
    clock_t begin = clock();
    exhaustive_nn(in_points, q_points, real_nn);
    clock_t end = clock();
    double tTrue = double(end - begin) / CLOCKS_PER_SEC;

    // search limit to iterate through "search_lim" points in bucket
    const int search_lim = 4 * L;
    std::vector<std::tuple<int, int, double>> approx_nn;
    begin = clock();



    for (auto q : q_points) {
            double nn_dist = std::numeric_limits<float>::max();
            int nn_id;
            for (auto ht : ht_vec) {
                int limit = search_lim;
                int index = ht->get_hash(q) % ht->get_size();
                int bucket = ht->get_map(index);
                /* for (std::list<Point *>::const_iterator it = bucket.begin();
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
                } */
            }
            if (nn_dist == std::numeric_limits<float>::max()) {
                nn.push_back({q.get_id(), -1, -1});
            } else {
                nn.push_back({q.get_id(), nn_id, nn_dist});
            }
       
    }  
    //display_hashtable();

    end = clock();
    double tLSH = double(end - begin) / CLOCKS_PER_SEC;

    ask_file(outfile, "output");
    write_outfile(outfile, real_nn, approx_nn, tTrue, tLSH);

    std::cout << YELLOW << "Accuracy: " << find_accuracy(real_nn, approx_nn)
              << YELLOW << std::endl;
    std::cout << YELLOW << "Mean Absolute Error: "
              << find_mean_absolute_error(real_nn, approx_nn) << YELLOW
              << std::endl;
    in_points.clear();
    q_points.clear();
    for (auto ht : ht_vec) {
        delete ht;
    }
    ht_vec.clear();

    return 0;
}
