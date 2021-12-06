#include <iostream>
#include "camera.cpp"
#include "primitives.cpp"

int main() 
{
    Camera camera;

    Transform objects[] = { 
        Sphere(5, Vector3(10, 2, 0)), 
        Cube(5, Vector3(10, 2, 3))
    };

    while (true)
        camera.draw();

    getchar();
}