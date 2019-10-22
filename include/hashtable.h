#ifndef HASHTABLE
#define HASHTABLE

#include <list>
#include "hash.h"
#include "point.h"

class Hashtable {
   private:
    int size;
    Hash g;                     // class with hash function
    std::list<Point *> *table;  // array of buckets

   public:
    Hashtable(int size, int k, int dims, int w);
    ~Hashtable();
    void insert_item(Point *p);
    // return the hash (key) of the point
    uint32_t get_hash(Point p);
    // return size of the hashtable
    int get_size(void);
    // return list with items in the bucket with given index
    std::list<Point *> get_indexed_bucket(int index);
    void delete_item(Point *p);
    // hash function to map values to key
    void display_hashtable();
};

#endif