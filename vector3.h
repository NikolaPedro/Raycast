#pragma once
#include <cmath>

class Vector3 
{
public:
    double x;
    double y;
    double z;

    Vector3(double x = 0, double y = 0, double z = 0) 
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3 operator+(Vector3 other) 
    {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }

    Vector3 operator-(Vector3 other) 
    {
        return Vector3(x - other.x, y - other.y, z - other.z);
    }

    Vector3 operator*(double value) 
    {
        return Vector3(x * value, y * value, z * value);
    }

    Vector3 operator/(double value) 
    {
        return Vector3(x / value, y / value, z / value);
    }

    Vector3 operator*(Vector3 other) 
    {
        return Vector3
        (
            y * other.z - z * other.y, 
            x * other.z - z * other.x, 
            x * other.y - y * other.x
        );
    }

    double get_scalar(Vector3 other) 
    {
        return x * other.x + y * other.y + z * other.z; 
    }

    double length() 
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vector3 normalize() 
    {
        return Vector3(x, y, z) / length();
    }

    double distance_to(Vector3 other) 
    {
        return (*this - other).length();
    }
};