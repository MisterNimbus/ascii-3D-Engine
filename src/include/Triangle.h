#pragma once

#include "./mathUtils.h"
#include "./Point.h"

class Engine;

class Triangle{
protected:
    static int nextId;
private:
    int id;
public:
    Triangle();
    Triangle(Point * p1, Point * p2, Point * p3);
    Triangle(float p1x, float p1y, float p1z, float p2x, float p2y, float p2z, float p3x, float p3y, float p3z);
    void Draw(Engine * engine, Point * meshAnchor, char surfaceChar);
    void DrawLine(Engine * engine, char lineChar, Point & p1, Point & p2, int resolution);
    ~Triangle();
    Point* points[3];
    void update(Engine * engine, float tick, Point * meshAnchor, rotationVector rotation, char surfaceChar);
    void log();
};
