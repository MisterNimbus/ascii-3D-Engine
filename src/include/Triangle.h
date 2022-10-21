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
    Point* points[3];
public:

    // Constructs a Triangle with '#' as surfaceChar and uninitialised points.
    Triangle();

    // Constructs a Triangle by copying the points from the triangle pointer and setting the surfaceChar from parameter.
    Triangle(Triangle * triangle, char surfaceChar='#');
    
    // Constructs a Triangle with the points given as parameter and setting the surfaceChar from parameter.
    Triangle(Point * p1, Point * p2, Point * p3, char surfaceChar='#');

    // Constructs a Triangle by constructing each point from given parameters and constructing the triangle using them. surfaceChar is set from parameter.
    Triangle(float p1x, float p1y, float p1z, float p2x, float p2y, float p2z, float p3x, float p3y, float p3z, char surfaceChar = '#');
    
    // Destructor
    ~Triangle();

    // Returns array of point pointers forming the triangle (Array Length: 3)
    Point* getPoints();

    // Returns point pointer of one of the points forming the triangle (Index can take the value of 0, 1 or 2)
    Point* getPoint(int index);

    // Returns the unique Id of the triangle
    int getId();

    // Returns the surfaceChar of the triangle
    char getSurfaceChar();

    // Returns the normal of the Triangle
    vec3x1 getNormal();

    rotationVector getRotationOfNormal();
    
    // Rotates all three points forming the triangle around the anchor point ((0,0,0) relative to the triangle points)
    void rotate(rotationVector rotation);

    // Returns a triangle pointer to the rotated instance of this triangle.
    Triangle * getRotatedTriangle(rotationVector rotation);

    // Sets surfaceChar
    void setSurfaceChar(char surfaceChar);

    // 
    void update(Engine * engine, float tick, Point * meshAnchor, rotationVector rotation);
    
    //Output
    void draw(Engine * engine, Point * meshAnchor);
    void drawLine(Engine * engine, char lineChar, Point & p1, Point & p2, int resolution);
    void fillSurface(Engine * engine, Triangle projectionBufferScreenIndex, char surfaceChar, int resolution01, int resolution12, int resolution20);
    void log();
};
