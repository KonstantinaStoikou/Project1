#ifndef HASHTABLE_CUBE
#define HASHTABLE_CUBE

#include <list>
#include "hash.h"
#include "point.h"
#include "../include/structures.h"


class HashtableC {
   private:
    int size;
    Hash g;                     // class with hash function
    struct_hashtable * table = new struct_hashtable;  // array of buckets

   public:
    HashtableC(int size, int k, int dims, int w);
    ~HashtableC();
    void insert_item(Point *p);
    uint32_t get_hash(Point p) ;
    int get_size(void);
    int get_map(int index);
    void display_hashtable();
};

#endif