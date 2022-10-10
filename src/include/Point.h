#pragma once

#include "./mathUtils.h"

class Point{
public:
    Point(float x,float y,float z);
    ~Point();
    float x,y,z;
    void rotatePoint(float roll_step, float yaw_step, float pitch_step);
    void rotate(rotationVector rotation);
    void move(movementVector velocity);
    Point * applyAnchorOffset(Point anchor);
    void turnProjectionIntoScreenIndex();
};