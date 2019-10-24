#include "../include/hash.h"
#include <bitset>
#include <iostream>

Hash::Hash(int k, int dims, int w) {
    for (int i = 0; i < k; i++) {
        H *h = new H(k, dims, w);
        h_vec.push_back(*h);
    }
}

Hash::~Hash(void) {
    delete h;
}

uint32_t Hash::concat_hash_values(Point p) {
    uint32_t g = 0;
    int k = h_vec.size();
    for (auto h : h_vec) {
        g = (g << (32 / k)) + h.h_func(p);
    }
    return g;
}
