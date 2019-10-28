#include "../include/hypercube_ht.h"
#include <iostream>

Hypercube_Ht::Hypercube_Ht(int size) {
    this->size = size;
    table = new std::list<std::tuple<std::vector<int>, Point *>>[size];
}

Hypercube_Ht::~Hypercube_Ht() {}

std::size_t
Hypercube_Ht::hash_function(std::tuple<std::vector<int>, Point *> tup) {
    std::size_t seed = std::get<0>(tup).size();
    for (auto &i : std::get<0>(tup)) {
        seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
}

void Hypercube_Ht::insert_item(std::tuple<std::vector<int>, Point *> tup) {
    int index = hash_function(tup) % size;
    table[index].push_back(tup);
}

int Hypercube_Ht::get_size(void) { return size; }

// function to display hash table
void Hypercube_Ht::display_hashtable() {
    for (int i = 0; i < size; i++) {
        for (auto x : table[i]) {
            std::cout << std::get<1>(x)->get_id() << " ";
            // print vector
            for (auto v : std::get<0>(x)) {
                std::cout << v;
            }
        }
        std::cout << std::endl;
    }
}