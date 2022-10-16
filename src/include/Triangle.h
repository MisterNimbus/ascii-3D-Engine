#pragma once

#include "./mathUtils.h"
#include "./Point.h"

class Engine;

class Triangle{
protected:
    static int nextId;
private:
    int id;
    char surfaceChar;
public:
    Triangle();
    Triangle(Point * p1, Point * p2, Point * p3, char surfaceChar='#');
    Triangle(float p1x, float p1y, float p1z, float p2x, float p2y, float p2z, float p3x, float p3y, float p3z, char surfaceChar = '#');
    Triangle * getRotatedTriangle(rotationVector rotation);
    void draw(Engine * engine, Point * meshAnchor);
    void drawLine(Engine * engine, char lineChar, Point & p1, Point & p2, int resolution);
    void fillSurface(Engine * engine, Triangle projectionBufferScreenIndex, char surfaceChar, int resolution01, int resolution12, int resolution20);
    ~Triangle();
    Point* points[3];
    void update(Engine * engine, float tick, Point * meshAnchor, rotationVector rotation);
    void log();
    void setSurfaceChar(char surfaceChar);
    void rotate(rotationVector rotation);
};
