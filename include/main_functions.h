#ifndef MAIN_FUNCTIONS
#define MAIN_FUNCTIONS

#include "../include/hashtable.h"
#include "point.h"
#include <string>
#include <tuple>
#include <vector>

// Find the average nearest neighbor distance of the given points
int find_avg_nn_dist(std::vector<Point> points);
// Exhaustive solution to find nearest neighbors and their distances and return
// them in a vector of tuples
void exhaustive_nn(std::vector<Point> in_points, std::vector<Point> q_points,
                   std::vector<std::tuple<int, int, float>> &nn);
// create a vector with L hashtables and pass it to ht_vec
void create_hashtables(std::vector<Hashtable *> &ht_vec, int L, int dims, int w,
                       int k, std::vector<Point> &in_points, int table_size);

#endif