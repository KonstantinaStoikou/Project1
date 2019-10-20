#include "../include/hashtable.h"
#include <iostream>

Hashtable::Hashtable(int size, int k, int dims, int w) : g(k, dims, w) {
    this->size = size;
    table = new std::list<Point *>[size];
}

Hashtable::~Hashtable() {}

void Hashtable::insert_item(Point *p) {
    int index = g.concat_hash_values(*p) % size;
    table[index].push_back(p);
    std::cout << "Index: " << index << std::endl;
    for (auto x : table[index]) {
        std::cout << " --> " << x->get_id();
    }
    std::cout << std::endl;
}

void Hashtable::delete_item(Point *p) {
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
void Hashtable::display_hashtable() {
    for (int i = 0; i < size; i++) {
        std::cout << i;
        for (auto x : table[i]) {
            std::cout << " --> " << x->get_id();
        }
        std::cout << std::endl;
    }
}