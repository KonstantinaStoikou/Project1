#include "../include/h.h"
#include <iostream>
#include <math.h> /* pow */
#include <random>

H::H(int k, int dimension, int w) {
    M = pow(2, 32 / k);
    m = pow(2, 32 - 5);
    dim = dimension;
    w = w;
    std::vector<int>::iterator it;
    // rd will be used to obtain a seed for the random number engine
    std::random_device rd;
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, w);
    for (int n = 0; n < dim; ++n) {
        it = s.begin();
        it = s.insert(it, dis(gen));
    }
}

H::~H(){};

int H::a(int x, int s, int w) { return (x - s) / w; }

int H::h_func(Point x) {
    int h;
    for (unsigned i = 0; i < dim; i++) {
        // h = a(x.get_vector().at(i), s.at(i), w) * pow(m, dim - 1 - i) % M;
    }
    return h;
}
