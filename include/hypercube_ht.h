#ifndef HYPERCUBE_HT
#define HYPERCUBE_HT

#include "point.h"
#include <list>
#include <tuple>
#include <vector>

class Hypercube_Ht {
  private:
    int size;
    std::list<std::tuple<std::vector<int>, Point *>> *table; // array of buckets

  public:
    Hypercube_Ht(int size);
    ~Hypercube_Ht();
    void insert_item(std::tuple<std::vector<int>, Point *> tup);
    std::size_t hash_function(std::tuple<std::vector<int>, Point *> tup);
    // return size of the hashtable
    int get_size(void);
    // return list with items in the bucket with given index
    std::list<Point *> get_indexed_bucket(int index);
    void delete_item(Point *p);
    // hash function to map values to key
    void display_hashtable();
};

#endif