#include "../include/hash.h"

Hash::Hash(void) {}

Hash::~Hash(void) {}

uint32_t concat_hash_values(std::vector<int> h_vec) {
    uint32_t g = 0;
    int k = h_vec.size();
    std::vector<int>::iterator it;
    for (auto i : h_vec) {
        g = (g << (32 / k)) + i;
    }
    return g;
}
