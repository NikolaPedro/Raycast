#pragma once
#include "vector3.h"

class Transform 
{
public:
    Vector3 position;
    Vector3 rotation;

    Transform(Vector3 pos = Vector3(), Vector3 rot = Vector3()) 
    {
        position = pos;
        rotation = rot;
    }

    void look_at(Vector3 point) 
    {

    }
};