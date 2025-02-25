#include "../include/hashtable_lsh.h"
#include <iostream>

Hashtable_LSH::Hashtable_LSH(int size, int k, int dims, int w) : g(k, dims, w) {
    this->size = size;
    table = new std::list<Point *>[size];
}

Hashtable_LSH::~Hashtable_LSH() { delete[] table; }

void Hashtable_LSH::insert_item(Point *p) {
    int index = g.concat_hash_values(*p) % size;
    table[index].push_back(p);
}

uint32_t Hashtable_LSH::get_hash(Point p) { return g.concat_hash_values(p); }

int Hashtable_LSH::get_size(void) { return size; }

std::list<Point *> Hashtable_LSH::get_indexed_bucket(int index) {
    return table[index];
}

void Hashtable_LSH::delete_item(Point *p) {
    // get the hash index of key
    int index = g.concat_hash_values(*p) % size;

    // find the key in (inex)th list
    std::list<Point *>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == p)
            break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

// function to display hash table
void Hashtable_LSH::display_hashtable() {
    for (int i = 0; i < size; i++) {
        std::cout << i;
        for (auto x : table[i]) {
            std::cout << " --> " << x->get_id();
        }
        std::cout << std::endl;
    }
}