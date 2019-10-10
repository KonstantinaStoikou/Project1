#include <math.h>       /* pow */
#include "functions.h"
//να βαζουμε τις συντεταγμένες σε πίνακα
int h_func(int X[], int S[], int dimension, int m, int M) { //X:array of x coordinates, S:array of s coordinates
	 int i,h;
	 for(i=0; i<=dimension-1; i++){
	 	if(i!=dimension-1){
	 		h=manhattan_dist(X[i],S[i], w)*pow(m,dimension-1-i)%M;
	 	}
	 	else {
	 		h=manhattan_dist(X[i],S[i], w)%M;
	 	}
	 }
	 return h;
}