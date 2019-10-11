#include "../include/read_functions.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int read_vectors_file(const char *filename, std::vector<Point> &points) {
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    if (!infile.is_open()) {
        return -1;
    }
    std::string line;
    while (std::getline(infile, line)) {
        int num;
        std::vector<int> dims;
        std::stringstream ss(line);
        while (ss >> num) {
            dims.push_back(num);
        }
        Point *ptr = new Point(dims);
        std::cout << "NEW: ";
        for (std::vector<int>::const_iterator i = ptr->get_vector().begin();
             i != ptr->get_vector().end(); ++i)

            std::cout << *i << " ";
        points.push_back(*ptr);
        std::cout << "\n";
    }
    infile.close();
    return 0;
}