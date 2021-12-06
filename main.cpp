#include <iostream>
#include "camera.cpp"
#include "primitives.cpp"

int main() 
{
    Camera camera;

    for (size_t i = 0; i < 10000; i++)
        camera.draw(i);

    getchar();
}