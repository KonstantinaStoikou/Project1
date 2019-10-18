#ifndef POINT
#define POINT

#include <vector>

class Point {
  private:
    int id;
    std::vector<int> vec;

  public:
    Point(int id, std::vector<int> values);
    ~Point();
    int get_id(void);
    std::vector<int> get_vector(void);
};

#endif
