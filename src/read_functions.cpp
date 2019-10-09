#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int read_vectors_file(const char *filename) {
    std::ifstream infile;
    infile.open(filename, std::ios::in);
    if (!infile.is_open()) {
        return -1;
    }
    std::string line;
    while (std::getline(infile, line)) {
        std::stringstream ss(line);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);
        std::copy(vstrings.begin(), vstrings.end(),
                  std::ostream_iterator<std::string>(std::cout, "\n"));
    }
    infile.close();
    return 0;
}