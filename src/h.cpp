#include <math.h>       /* pow */
#include "../include/h.h"


	h::h(int k,int dimension,int w){
		M=pow(2,32/k);///
		m=pow(2,32-5);
		dim=dimension;
	    //for uniform s;

	}

	h::~h(){};
	int h:: h_func(Point X, std::vector<int> S, int m, int M) { 
	 int h;
	int dim = X.get_vector().size();
	for (unsigned i=0; i<dim; i++) {

	 	h=a(X.at(i),S.at(i), w)*pow(m,dim-1-i)%M;
		i++;
}
	 return h;
}
	int h::a(int x, int s, int w) { return (x - s) / w; }



