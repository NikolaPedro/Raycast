#include <iostream>
#include "transform.h"
#include "color.h"

class Camera : public Transform 
{
private:
    const char * gradient = " .:r1Z4H9W8S@";
    int height;
    int width;

    float aspect;
    char * screen;

    char get_pixel(int x, int y) {

    }

    char get_sphere(int x, int y) 
    {
        static double time = 0;
        time += 0.002;
        double _x = (double)x / width * 2 - 1;
        double _y = (double)y / height * 2 - 1;
        _x *= aspect;
        _x += sin(time * 0.0003);
        _y += cos(time * 0.0003);
        double distance = Vector3(0, 0).distance_to(Vector3(_x, _y));
        return distance < 0.5 ? '@' : ' ';
    }

public:
    Camera() {
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
                screen[y * width + x] = get_sphere(x, y);  
            } 
        }
        screen[width * height] = '\0';
        printf(screen);
    }
};