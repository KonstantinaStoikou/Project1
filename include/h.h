#ifndef H_FUNC
#define H_FUNC

#include "../include/point.h"
#include <vector>

class H {
  private:
    unsigned long m, M;
    int dim;
    double w;
    // a vector with numbers from uniform distribution (0,w)
    std::vector<float> s;
    int a(int x, float s);

  public:
    H(int k, int dimension, double w);
    ~H();
    int h_func(Point X);
};

#endif