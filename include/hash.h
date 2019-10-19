#ifndef HASH
#define HASH

#include <cstdint>
#include <vector>

// isos na einai mia klasi pou periexei ena vector me antikeimena h kai ston
// constructor kalei ton diko tous constructor kai ta arxikopoiei

class Hash {
  private:
    uint32_t g;

  public:
    Hash();
    ~Hash();
    uint32_t concat_hash_values(std::vector<int> h_vec);
};

#endif