#ifndef H_FUNC
#define H_FUNC

#include "../include/point.h"
#include <vector>

class H {
  private:
    unsigned long m, M;
    int dim, w;
    std::vector<int> s; // a vector with numbers from uniform distribution (0,w)
    int a(int x, int s, int w);

  public:
    H(int k, int dimension, int w);
    ~H();
    int h_func(Point X);
};

#endif