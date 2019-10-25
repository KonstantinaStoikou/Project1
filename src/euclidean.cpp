#include "../include/euclidean.h"
#include <math.h> 
#include <iostream>
#include <cmath> 
#include <vector> 

double euclidean(std::vector<double> x, std::vector<double> y) { 
    int i,dim;
    double sum=0;
    dim= x.size();
    for(int i=0; i<dim; i++){
        sum+=pow(std::abs(x[i]-y[i]),dim);
    }
    return std::sqrt(sum); 
}
