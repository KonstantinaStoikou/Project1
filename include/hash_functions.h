#ifndef HASH_FUNCTIONS
#define HASH_FUNCTIONS

#include <cstdint>
#include <vector>

// Concatenate all h function values to one 32 bit integer and return it
// Arguments: h_arr vector with integer hash values
uint32_t concat_hash_values(std::vector<int> h_vec);

#endif