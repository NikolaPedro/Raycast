#include "transform.h"

class Plane : Transform {
public:
    double x;
    double y;
    double z;
    double w;
};

class Cube : Transform {
public:
    double size;
};

class Sphere : Transform {
public:
    double radius;
};