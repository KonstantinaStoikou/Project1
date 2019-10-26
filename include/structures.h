#ifndef STRUCTURES
#define STRUCTURES
#include "hash.h"
#include "point.h"
#include <list>

struct struct_hashtable {
    std::list<Point *> cell;
    int bin;
};

#endif