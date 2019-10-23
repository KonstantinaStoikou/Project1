#include "../include/dtw.h"
#include <iostream>
#include <vector>

double** dtw_init (std::vector<double> x, std::vector<double> y){

    double** D;    
    D[0][0]=10000000;
    for(int j=0; j<x.size(); j++){
        for(int i=0; i<y.size(); i++){
            D[0][j] = x.at(j);
            D[i][0] = y.at(i);
            if(i!=0 && j!=0){
                D[i][j] = 0.0;
            }
        }
    }
}



std::vector<double> dtw_compute (std::vector<double> x, std::vector<double> y){
    double** D = dtw_init(x,y);
    int max_size = x.size();
    if(y.size() > x.size()){
        max_size = y.size();
    }
    std::vector<double> distance (max_size);
    for(int j=1; j<x.size(); j++){
        for(int i=1; i<y.size(); i++){
            D[i][j] = D[0][j] - D[i][0];  
        }
    }
    double min=D[1][1];
    distance.at(0) = min;
    
    if(){

    }
     for(int j=1; j<x.size(); j++){
        for(int i=1; i<y.size(); i++){
            if( D[i][j] < )  
        }
    }
    //min-max
}

