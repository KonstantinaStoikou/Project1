#ifndef HASH
#define HASH

#include <cstdint>
#include <vector>
#include "h.h"
#include "point.h"

class Hash {
   private:
    uint32_t g;
    std::vector<H> h_vec;

   public:
    Hash(int k, int dims, int w);
    ~Hash();
    uint32_t concat_hash_values(Point p);
};

#endif