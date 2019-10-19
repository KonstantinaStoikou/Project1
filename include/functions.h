#ifndef FUNCTIONS
#define FUNCTIONS

#include "point.h"
#include <string>
#include <tuple>
#include <vector>

// Print all points (id and vector) in the given vector
void print_points(std::vector<Point> points);
// Print the command line arguments
void print_arguments(std::string infile, std::string query_file,
                     std::string outfile, int k, int L);
// Find the average nearest neighbor distance of the given points
int find_avg_nn_dist(std::vector<Point> points);
// Exhaustive solution to find nearest neighbors and their distances and return
// them in a vector of tuples
void exhaustive_nn(std::vector<Point> in_points, std::vector<Point> q_points,
                   std::vector<std::tuple<int, int, float>> &nn);
// Print the tuples (id, distance) of the nearest neighbors
void print_nn(std::vector<std::tuple<int, int, float>> nn);

#endif