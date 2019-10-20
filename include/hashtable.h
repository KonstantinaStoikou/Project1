#ifndef HASHTABLE
#define HASHTABLE

#include <list>
#include "hash.h"
#include "point.h"

class Hashtable {
   private:
    int size;
    Hash g;
    // Pointer to an array containing buckets
    std::list<Point *> *table;

   public:
    Hashtable(int size, int k, int dims, int w);
    ~Hashtable();
    // inserts a key into hash table
    void insert_item(Point *p);
    // deletes a key from hash table
    void delete_item(Point *p);
    // hash function to map values to key
    void display_hashtable();
};

#endif