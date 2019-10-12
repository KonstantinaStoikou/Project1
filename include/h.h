#ifndef POINT
#define POINT
#include "../include/metrics.h"
#include "../include/point.h"
#include <vector>

class h{
private:
	int m, M,int dim, int w;
    std::vector<int> s;

public:
	h::h(int k,int dimension,int w);
	h::~h();
	int h:: h_func(Point X);
	int h::a(int x, int s, int w);
}

#endif