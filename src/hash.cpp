#include "../include/hash.h"
#include <iostream>
#include <iterator>

Hash::Hash(void) {}

Hash::~Hash(void) {}

uint32_t concat_hash_values(std::vector<int> h_vec) {
    uint32_t g = 0;
    int k = h_vec.size();
    std::cout << k;
    std::vector<int>::iterator it;
    for (it = h_vec.begin(); it < h_vec.end(); it++) {
        g = (g << (32 / k)) + *it;
    }
    std::cout << g;
    return g;
}
