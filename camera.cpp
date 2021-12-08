#include <iostream>
#include "primitives.cpp"
#include "color.h"

class Camera : public Transform 
{
private:
    int height;
    int width;

    float aspect;
    char * screen;

    char get_pixel(int x, int y) 
    {
        static double time = 0;
        time += 0.00001;

        Vector3 ray = Vector3((double)x / width, (double)y / height, 1);
        ray = ray * 2 - Vector3(1, 1);
        ray.x *= aspect;
        ray = ray.normalize();

        position.x = cos(time);
        position.y = sin(time);

        Sphere sphere(1, Vector3(0, 0, 5 + time * 0.1));
        // Plane plane(0, 1, 1, 5 * time * 0.1);
        Vector3 intersect = sphere.intersect(position, ray);

        if (intersect == Vector3(-1))
            return Color(0).to_char();
        
        double distance = position.distance_to(intersect);
        distance = (20.0 - distance) / 20.0;
        return Color(distance).to_char();
    }

    char get_sphere(int x, int y) 
    {
        static double time = 0;
        time += 0.0001;
        double _x = (double)x / width * 2 - 1;
        double _y = (double)y / height * 2 - 1;
        _x *= aspect;
        _x += cos(time * 0.0003);
        _y += sin(time * 0.0001) * 0.7;

        double distance = position.distance_to(Vector3(_x, _y));
        double radius = 0.3;
        return Color((radius - distance) / radius).to_char();
    }

public:
    Camera() 
    {
        height = 30;
        width = 120;
        screen = new char[height * width + 1];

        aspect = (float)width / height;
        aspect *= 11.0 / 24.0;
    }

    void draw()
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++) 
            {  
                screen[y * width + x] = get_pixel(x, y);  
            } 
        }
        screen[width * height] = '\0';
        printf(screen);
    }
};