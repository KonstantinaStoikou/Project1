#include "../include/print_functions.h"
#include "../include/defines.h"
#include <fstream>
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

void print_nn(std::vector<std::tuple<int, int, double>> nn) {
    for (auto &tuple : nn) {
        std::cout << "Point #" << std::get<0>(tuple)
                  << ": NN: " << std::get<1>(tuple)
                  << " Dist: " << std::get<2>(tuple) << std::endl;
    }
}

void write_outfile(
    std::string filename,
    std::vector<std::tuple<int, int, double, double>> real_nn,
    std::vector<std::tuple<int, int, double, double>> approx_nn) {
    std::ofstream file;
    // open file and overwrite it if it exists, or create it if it doesn't exist
    file.open(filename, std::ios::out);
    for (unsigned int i = 0; i < real_nn.size(); i++) {
        file << "Query: " << std::get<0>(real_nn.at(i)) << std::endl;
        if (std::get<1>(approx_nn.at(i)) == -1) {
            file << "Nearest Neighbor: Fail" << std::endl;
            file << "DistanceLSH: Fail " << std::endl;
        } else {
            file << "Nearest Neighbor: " << std::get<1>(approx_nn.at(i))
                 << std::endl;
            file << "DistanceLSH: " << std::get<2>(approx_nn.at(i))
                 << std::endl;
        }
        file << "DistanceTrue: " << std::get<2>(real_nn.at(i)) << std::endl;
        file << "tLSH: " << std::get<3>(approx_nn.at(i)) << std::endl;
        file << "tTrue: " << std::get<3>(real_nn.at(i)) << std::endl;
        file << std::endl;
    }
}