#pragma once
#include "vector3.h"

class Transform {
public:
    Vector3 position;
    Vector3 rotation;

    Transform() {
        position = Vector3();
        rotation = Vector3();
    }

    void look_at(Vector3 point) {

    }
};