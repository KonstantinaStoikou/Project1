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
    int h;
    int m_mod_M = m % M;
    for (int i = 0; i < dim; i++) {
        int a_res = a(x.get_vector().at(i), s.at(i), w) % M;
        // std::cout << "m: " << m << std::endl;
        // std::cout << "M: " << M << std::endl;
        // std::cout << "(m mod M)^(Dim-1-i): " << m_mod_M << " " << dim - 1 - i
        //           << std::endl;
        // calaculate pow %M using modular exponentiation property:
        // (a^b) mod c = (a mod c)^b mod c
        unsigned long p = pow(m_mod_M, dim - 1 - i);
        // std::cout << "P before: " << p << std::endl;
        p = p % M;
        h += (a_res * p) % M;

        // std::cout << "X: " << x.get_vector().at(i) << " S: " << s.at(i)
        //           << std::endl;
        // std::cout << "A: " << a_res << std::endl;
        // std::cout << "Pow: " << p << std::endl;
        // std::cout << std::endl;
    }
    std::cout << "h: " << h << std::endl;
    return h;
}
