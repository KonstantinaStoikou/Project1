#include <iostream>
#include "../include/hash_functions.h"
#include "../include/read_functions.h"

int main(int argc, char const *argv[]) {
    std::vector<std::vector<int>> points;
    if (read_vectors_file("../sample datasets/vectors/siftsmall/query_small_id",
                          points) < 0) {
        std::cout << "error";
    }
    std::vector<std::vector<int>>::iterator pnt;
    std::vector<int>::iterator dim;
    for (pnt = points.begin(); pnt != points.end(); pnt++) {
        std::cout << "New Point: ";
        for (dim = pnt->begin(); dim != pnt->end(); dim++) {
            std::cout << *dim << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
