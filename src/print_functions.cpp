#include "../include/print_functions.h"
#include "../include/defines.h"
#include <iostream>

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

void print_nn(std::vector<std::tuple<int, int, float>> nn) {
    for (auto &tuple : nn) {
        std::cout << "Point #" << std::get<0>(tuple)
                  << ": NN: " << std::get<1>(tuple)
                  << " Dist: " << std::get<2>(tuple) << std::endl;
    }
}