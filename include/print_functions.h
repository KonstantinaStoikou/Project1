#ifndef PRINT_FUNCTIONS
#define PRINT_FUNCTIONS

#include "point.h"
#include <string>
#include <tuple>
#include <vector>

// Print all points (id and vector) in the given vector
void print_points(std::vector<Point> points);
// Print the command line arguments
void print_arguments(std::string infile, std::string query_file,
                     std::string outfile, int k, int L);
// Print the tuples (id, distance) of the nearest neighbors
void print_nn(std::vector<std::tuple<int, int, float>> nn);
// Write results to output file
void write_outfile(std::string filename,
                   std::vector<std::tuple<int, int, float>> real_nn,
                   std::vector<std::tuple<int, int, float>> approx_nn,
                   int time1, int time2);

#endif