#include "../include/point.h"

Point::Point(int id, std::vector<int> values) {
    this->id = id;
    vec = values;
}

Point::~Point() { vec.clear(); }

int Point::get_id(void) { return id; }

std::vector<int> Point::get_vector(void) { return vec; }
