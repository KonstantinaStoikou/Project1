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
    for (std::vector<Point>::iterator iti = points.begin(); iti != points.end();
         ++iti) {
        std::cout << "New Point: ";
        for (std::vector<int>::iterator itj = iti->get_vector().begin();
             itj != iti->get_vector().end(); ++itj) {
            std::cout << *itj << " ";
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
    int k, L;
    std::vector<Point> points;
    read_lsh_arguments(argc, argv, infile, query_file, outfile, k, L);
    print_arguments(infile, query_file, outfile, k, L);
    if (read_vectors_file("../sample datasets/vectors/siftsmall/query_small_id",
                          points) < 0) {
        std::cout << "error";
    }
    // print_vectors(points);
    return 0;
}
