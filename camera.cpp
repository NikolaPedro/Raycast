#include <iostream>
#include "transform.h"
#include "color.h"
#include "world.cpp"

class Camera : Transform 
{
private:
    const char * gradient = " .:r1Z4H9W8S@";
    int height;
    int width;

    float aspect;
    char * screen;

    char get_pixel(int x, int y, int i) 
    {
        double _x = (double)x / width * 2 - 1;
        double _y = (double)y / height * 2 - 1;
        _x *= aspect;
        // _x += sin(i * 0.001);
        double distance = Vector3(0, 0).distance_to(Vector3(_x, _y));
        return distance < 0.5 ? '@' : ' ';
    }

public:
    Camera() {
        height = 30;
        width = 120;
        aspect = (float)width / height;
        aspect *= 11.0 / 24.0;
        screen = new char[height * width];
    }

    void draw(int i)
    {
        for (int y = 0; y < height; y++) 
        {
            for (int x = 0; x < width; x++) 
            {
                screen[y * width + x] = get_pixel(x, y, i);
            }
        }
        std::cout << screen;
    }
};