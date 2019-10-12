#include "metrics.h"

int manhattan_dist(int x, int y) { 
	int sub;
	sub=x-y;
	if(sub<0;){
		sub=y-x;
	}
	return sub;
}
