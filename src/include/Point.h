#pragma once

#include "./mathUtils.h"

class Point{
protected:
    static int nextId;
public:
    int id;
    Point(float x,float y,float z);
    ~Point();
    vec3x1 position;
    void rotatePoint(float roll_step, float yaw_step, float pitch_step);
    void rotate(rotationVector rotation);
    void rotateRoll(float rollDegree);
    void rotateYaw(float yawDegree);
    void rotatePitch(float pitchDegree);
    void move(movementVector velocity);
    float distanceToAnchor();
    Point * applyAnchorOffset(Point anchor);
    void turnProjectionIntoScreenIndex();
    void log();
};