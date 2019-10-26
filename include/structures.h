#ifndef STRUCTURES
#define STRUCTURES
#include <list>
#include "hash.h"
#include "point.h"

struct struct_hashtable{
    std::list<Point *> *cell;
    int bin;
};

#endif