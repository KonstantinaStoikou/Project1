#ifndef HASH
#define HASH

#include <cstdint>
#include <vector>

class Hash {
  private:
    uint32_t g;

  public:
    Hash();
    ~Hash();
    uint32_t concat_hash_values(std::vector<int> h_vec);
};

#endif