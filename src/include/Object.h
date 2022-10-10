#pragma once

#include "./Mesh.h"

class Engine;

class Object{
public:
    Object();
    ~Object();
    Mesh mesh;
    movementVector velocity = {0,0,0};
    rotationVector rotation = {0,0,0};
    void update(Engine* engine, float tick, char surfaceChar);
};