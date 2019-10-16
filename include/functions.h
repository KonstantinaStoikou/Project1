#ifndef FUNCTIONS
#define FUNCTIONS

#include "point.h"
#include <string>

void print_vectors(std::vector<Point> &points);
void print_arguments(std::string infile, std::string query_file,
                     std::string outfile, int k, int L);
// find the average nearest neighbor distance of the given points
int find_avg_nn_dist(std::vector<Point> &points);

#endif