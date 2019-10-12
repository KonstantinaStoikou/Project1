#include <random>
#include <iostream>
#include "../include/h.h"
#include <math.h> /* pow */

h::h(int k, int dimension, int w) {
    M = pow(2, 32 / k);  
    m = pow(2, 32 - 5);
    dim = dimension;
    w=w;
	std::vector<int> S;
    std::vector<int>::iterator it;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, w);
    for (int n = 0; n < dim; ++n) { 
 		it = S.begin();
  		it = S.insert ( it , dis(gen) );    
    }

}

h::~h(){};
int h::h_func(Point X) {
    int h;
    int dim = X.get_vector().size();
    for (unsigned i = 0; i < dim; i++) {
        h = a(X.at(i), S.at(i), w) * pow(m, dim - 1 - i) % M;
        i++;
    }
    return h;
}
int h::a(int x, int s, int w) { return (x - s) / w; }
