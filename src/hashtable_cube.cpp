#include "../include/hashtable_cube.h"
#include "../include/f_function.h"
#include "../include/structures.h"

#include <iostream>

HashtableC::HashtableC(int size, int k, int dims, int w) : g(k, dims, w) {
    this->size = size;
    struct_hashtable *table = new struct_hashtable;
}

HashtableC::~HashtableC() {
    g.~Hash();
    delete table;
}

void HashtableC::insert_item(Point *p) {
    int index = g.concat_hash_values(*p) % size;
    if (table[index].cell.empty()) {
        table[index].bin = f_func(g);
    }

    table[index].cell.push_back(p);
}
uint32_t HashtableC::get_hash(Point p) { return g.concat_hash_values(p); }

int HashtableC::get_size(void) { return size; }

int HashtableC::get_map(int index) { return table[index].bin; }

// function to display hash table
void HashtableC::display_hashtable() {
    for (int i = 0; i < size; i++) {
        std::cout << i << table[i].bin; // arithmos keliou
        for (auto x : table[i].cell) {
            std::cout << " --> " << x->get_id();
        }
        std::cout << std::endl;
    }
}