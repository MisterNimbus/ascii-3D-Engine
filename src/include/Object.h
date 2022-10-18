#pragma once

#include "./Mesh.h"

class Engine;

class Object{
public:
    //Constructor
    Object();

    //Destructor
    ~Object();

    //Variables
    Mesh mesh;
    movementVector velocity = {0,0,0};
    rotationVector rotationSpeed = {0,0,0};

    //Manipulation
    void update(Engine* engine, float tick);
    void draw(Engine * engine);
};