#pragma once

#include <vector>
#include <iostream>

#include "./mathUtils.h"
#include "./Object.h"
#include "Point.h"


const int SCREEN_WIDTH = 190;
const int SCREEN_HEIGHT = 35;

const int X_OFFSET = 85;
const int Y_OFFSET = 20;
const int Z_OFFSET = 3;

class Engine {
private:
    float zFurthest = 100.0f;
    float zOffsetNear = 1.0f;
    float fieldOfView = 5.0f;
    std::vector<Object*> objects;
    mat4x4 projectionMatrix = {0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f};
public:
    //Constructor
    Engine();

    //Destructor
    ~Engine();

    //Buffers
    char screenBuffer[SCREEN_HEIGHT*SCREEN_WIDTH];  // What will be displayed on the screen.
    float zBuffer[SCREEN_HEIGHT*SCREEN_WIDTH];      // Used to decide which surface is closer to the camera, blocking others behind it. Stores Z value of the last drawn object on the index.
    
    //Manipulation
    void addObject(Object* object);
    void initialize(float zOffsetNear, float zFurthest, float fieldOfView);
    void loop(float tick, bool update = true, bool draw =true);

    //Utilities
    void multiplyProjectionMatrix(Point &input, Point &output, mat4x4 &projectionMatrix);
    mat4x4 * getProjectionMatrix();
};