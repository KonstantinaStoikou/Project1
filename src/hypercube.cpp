#include "../include/hypercube.h"
#include <iostream>
#include <vector>

//h g exei buckets to kathena tha exei 0 h 1
//tha prepei na apothikefsome ti exei to kathena

std::vector<int> f_func(Hash g,std::list<Point *> *table){
    std::vector<int> bool_buckets (table.size());
    for(int i=0; i<bool_buckets.size(); i++){
        bool_buckets.at(i) = rand() % 2 ;
    }
    return bool_buckets;
}