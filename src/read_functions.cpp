#include "../include/read_functions.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

int read_vectors_file(const std::string filename, std::vector<Point> &points) {
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
        points.push_back(*ptr);
    }
    infile.close();
    return 0;
}

void read_lsh_arguments(int argc, char const *argv[], std::string &infile,
                        std::string &query_file, std::string &outfile, int &k,
                        int &L) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            infile = argv[i + 1];
        } else if (strcmp(argv[i], "-q") == 0) {
            query_file = argv[i + 1];
        } else if (strcmp(argv[i], "-k") == 0) {
            k = atoi(argv[i + 1]);
        } else if (strcmp(argv[i], "-L") == 0) {
            L = atoi(argv[i + 1]);
        } else if (strcmp(argv[i], "-o") == 0) {
            outfile = argv[i + 1];
        }
    }
}