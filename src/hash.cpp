#include "../include/hash.h"
#include <iostream>

Hash::Hash(int k, int dims, int w) {
    for (int i = 0; i < k; i++) {
        H *h = new H(k, dims, w);
        h_vec.push_back(*h);
    }
}

Hash::~Hash(void) {}

uint32_t Hash::concat_hash_values(Point p) {
    uint32_t g = 0;
    int k = h_vec.size();

    for (auto i : h_vec) {
        int f = i.h_func(p);
        g = (g << (32 / k)) + f;
    }
    return g;
}
