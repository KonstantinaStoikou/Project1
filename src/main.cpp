#include <iostream>
#include "../include/hash.h"
#include "../include/point.h"
#include "../include/read_functions.h"
#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */

void print_vectors(std::vector<Point> &points) {
    // print vector of vectors with points
    for (auto i : points) {
        std::cout << "New Point: ";
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

int main(int argc, char const *argv[]) {
    std::string infile, query_file, outfile;
    int k = 4, L = 5;  // initialize k, L with default values
    std::vector<Point> points;
    read_lsh_arguments(argc, argv, infile, query_file, outfile, k, L);
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
    // print_vectors(points);
    return 0;
}
