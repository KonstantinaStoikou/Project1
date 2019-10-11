#include <iostream>
#include "../include/hash_functions.h"
#include "../include/point.h"
#include "../include/read_functions.h"

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

int main(int argc, char const *argv[]) {
    std::vector<Point> points;
    if (read_vectors_file("../sample datasets/vectors/siftsmall/query_small_id",
                          points) < 0) {
        std::cout << "error";
    }
    // print_vectors(points);
    return 0;
}
