#ifndef READ_FUNCTIONS
#define READ_FUNCTIONS

#include <string>
#include "point.h"

// Read file with vectors and pass them to the points vector of vectors. Return
// -1 for error code, else 0
int read_vectors_file(const std::string filename, std::vector<Point> &points);
// Read command line arguments for lsh for vectors program
void read_lsh_vector_args(int argc, char const *argv[], std::string &infile,
                          std::string &query_file, std::string &outfile, int &k,
                          int &L);

#endif