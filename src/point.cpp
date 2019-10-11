#include "../include/point.h"

Point::Point(int id, std::vector<int> values) {
    id = id;
    vec = values;
}

Point::Point(std::vector<int> values) { vec = values; }

Point::~Point(void) {}

int Point::get_id(void) { return id; }

std::vector<int> Point::get_vector(void) { return vec; }
