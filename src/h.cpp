#include "../include/h.h"
#include <iostream>
#include <math.h> /* pow */
#include <random>

H::H(int k, int dimension, int w) {
    M = pow(2, 32 / k);
    m = pow(2, 32);
    m -= 5;
    dim = dimension;
    this->w = w;
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

int H::a(int x, int s, int w) { return floor((double)(x - s) / w); }

int H::h_func(Point x) {
    // calculate h using modulo properties:
    // 1. (a+b) mod c = ((a mod c) + (b mod c)) mod c
    // 2. (a*b) mod c = ((a mod c) * (b mod c)) mod c
    // 3. a^b mod c = ( (a mod c)^b ) mod c
    // 4. (a mod c) mod c = a mod c
    // h(x) = (a^(d−1) + m*a^(d−2) + ... + m^(d−1)*a^0) mod M
    int h;
    int m_mod_M = m % M;
    for (int i = 0; i < dim; i++) {
        unsigned long int a_res = a(x.get_vector().at(i), s.at(i), w) % M;
        unsigned long m_res = 1;
        int end = i > dim - 1 - i ? i : dim - 1 - i;
        for (int j = 0; j < end; j++) {
            if (j < i) {
                a_res *= a_res % M;
            }
            if (j < dim - i - 1) {
                m_res *= m_mod_M % M;
            }
        }
        a_res %= M;
        m_res %= M;
        h += (a_res * m_res) % M;
    }
    return h % M;
}
