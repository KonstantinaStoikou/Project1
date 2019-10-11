#ifndef READ_FUNCTIONS
#define READ_FUNCTIONS

#include "point.h"

// Read file with vectors and pass them to the points vector of vectors. Return
// -1 for error code, else 0
int read_vectors_file(const char *filename, std::vector<Point> &points);

#endif