#pragma once
#include "transform.h"

class Plane : public Transform 
{
public:
    double x;
    double y;
    double z;
    double w;

    Plane(double x, double y, double z, double w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    double intersect(Vector3 ray_pos, Vector3 ray_dir) 
    {
        return -(ray_pos.dot(Vector3(x, y, z)) + w) / ray_dir.dot(Vector3(x, y, z));
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
private:
    double radius;

public:
    Sphere(double radius, Vector3 position) : Transform(position)
    {
        this->radius = radius;
    }

    Vector3 intersect(Vector3 ray_pos, Vector3 ray_dir) 
    {
        Vector3 vector = ray_pos - position;

        // v = v_0 + t * v_e;
        // double value = v.dot(v);
        // (x - x_0)^2 + (y - y_0)^2 + (z - z_0)^2 = r^2;


        // double b = 2.0 * ray_dir.dot(vector);
        // double c = vector.dot(vector) - radius * radius;
        // double discriminant = b * b - 4.0 * c;
        // if (discriminant < 0)
        //     return Vector3(-1);
        

        double sqr = vector.dot(ray_dir);
        double c = vector.dot(vector) - radius * radius;
        double h = sqr * sqr - c;
        if (h < 0.0)
            return Vector3(-1);
        h = sqrt(h);
        return Vector3(); 

        // ( (3x)^2 - 2*3x + 1 ) - ( (4y)^2 -2*4y + 1) - 144 =0;
        // (3x-1)^2 - (4y-1)^2 = 144;
        // ((3x-1)^2)/144 - ((4y-1)^2)/144 = 1;
        // 1/9(x-1/3)^2/144 - 1/16(y-1/4)^2/144 = 1;
        // (x -1/3)^2/36^2 - (y - 1.4)^2 / 48^2 = 1;
    }
};