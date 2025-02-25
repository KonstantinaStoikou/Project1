#ifndef MAIN_FUNCTIONS
#define MAIN_FUNCTIONS

#include "../include/hashtable_lsh.h"
#include "point.h"
#include <string>
#include <tuple>
#include <vector>

// Find the average nearest neighbor distance of the given points
double find_avg_nn_dist(std::vector<Point> points);
// Exhaustive solution to find nearest neighbors and their distances and return
// them in a vector of tuples
void exhaustive_nn(std::vector<Point> in_points, std::vector<Point> q_points,
                   std::vector<std::tuple<int, int, double, double>> &nn);
// create a vector with L hashtables and pass it to ht_vec
void create_hashtables(std::vector<Hashtable_LSH *> &ht_vec, int L, int dims,
                       int w, int k, std::vector<Point> &in_points,
                       int table_size);
// Search in buckets with same hash as query points to find approximate nearest
// neighbor
void lsh_search(std::vector<Hashtable_LSH *> ht_vec,
                std::vector<Point> q_points,
                std::vector<std::tuple<int, int, double, double>> &nn,
                int search_limit);
// Find accuracy of approximate nearest neighbors
float find_accuracy(
    std::vector<std::tuple<int, int, double, double>> real_nn,
    std::vector<std::tuple<int, int, double, double>> approx_nn);
// Find the mean absolute error of approximate nearest neighbors
double find_mean_absolute_error(
    std::vector<std::tuple<int, int, double, double>> real_nn,
    std::vector<std::tuple<int, int, double, double>> approx_nn);
// Find average approximation fraction
double
find_avg_fraction(std::vector<std::tuple<int, int, double, double>> real_nn,
                  std::vector<std::tuple<int, int, double, double>> approx_nn);
// Find max approximation fraction
double
find_max_fraction(std::vector<std::tuple<int, int, double, double>> real_nn,
                  std::vector<std::tuple<int, int, double, double>> approx_nn);
// Find average search time
double find_avg_time(std::vector<std::tuple<int, int, double, double>> nn);

#endif