#pragma once

#include "./mathUtils.h"

class Point{
protected:
    static int nextId;
    int id;
    vec3x1 position;
public:
    //Constuctors
    Point(Point * point);
    Point(vec3x1 position);
    Point(float x,float y,float z);

    //Destructor
    ~Point();

    //Manipulation
    void rotate(rotationVector rotation);
    void rotateRoll(float rollDegree);
    void rotateYaw(float yawDegree);
    void rotatePitch(float pitchDegree);
    void move(movementVector velocity);

    //Utilities
    float distanceToAnchor();
    Point * applyAnchorOffset(Point anchor);
    void turnProjectionIntoScreenIndex();

    //Getters
    vec3x1 getPosition();
    float getPositionX();
    float getPositionY();
    float getPositionZ();
    int getId();

    //Setters
    void setPosition(vec3x1 position);
    void setPositionX(float x);
    void setPositionY(float y);
    void setPositionZ(float z);


    //Output
    void log();

    //Operation Overloads
    Point operator+(Point point);
    Point operator-(Point point);
    Point operator/(int divisor);
    Point operator*(int factor);
};