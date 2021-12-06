#include "transform.h"

class Plane : public Transform 
{
public:
    double x;
    double y;
    double z;
    double w;

    double intersect() 
    {

    }
};

class Cube : public Transform 
{
public:
    double size;

    Cube(double size, Vector3 position) : Transform(position)
    {
        this->size;
    }

    double intersect() 
    {

    }
};

class Sphere : public Transform 
{
public:
    double radius;

    Sphere(double radius, Vector3 position) : Transform(position)
    {
        this->radius = radius;
    }

    double intersect() 
    {

    }
};