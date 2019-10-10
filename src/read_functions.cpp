#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int read_vectors_file(const char *filename,
                      std::vector<std::vector<int>> &points) {
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
        points.push_back(dims);
    }
    infile.close();
    return 0;
}