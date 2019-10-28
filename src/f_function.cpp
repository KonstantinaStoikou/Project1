#include "../include/f_function.h"
#include "../include/hash.h"
#include <iostream>
#include <vector>
#include <random>



int f_func(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);
    return dis(gen);
}