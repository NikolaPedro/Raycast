#include <iostream>
#include "transform.h"
#include "color.h"
#include "world.cpp"

class Camera : Transform {
private:
    const char * GRADIENT = " .:r1Z4H9W8S@";
    int height = 30;
    int width = 120;
    float aspect = (float)width / height * 11.0 / 24.0;

    char get_pixel(int x, int y) {
        double _x = (double)x / width * 2 - 1;
        double _y = (double)y / height * 2 - 1;
        _x *= aspect;
        double distance = Vector3(0.5, 0.5).distance_to(Vector3(_x, _y));
        return distance < 0.31 ? '@' : ' ';
    }

public:
    void draw() {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                std::cout << get_pixel(x, y);
            }
        }
    }
};