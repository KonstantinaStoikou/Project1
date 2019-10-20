#ifndef HASHTABLE
#define HASHTABLE

#include <list>
#include "hash.h"
#include "point.h"

class Hashtable {
   private:
    int size;
    Hash g;                     // class with hash function
    std::list<Point *> *table;  // array containing buckets

   public:
    Hashtable(int size, int k, int dims, int w);
    ~Hashtable();
    void insert_item(Point *p);
    void delete_item(Point *p);
    // hash function to map values to key
    void display_hashtable();
};

#endif