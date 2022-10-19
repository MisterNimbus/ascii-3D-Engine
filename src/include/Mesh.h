#include "./mathUtils.h"
#include "./Triangle.h"
#include "Point.h"

#include <vector>

class Engine;

class Mesh{
private:
    // Coordinates of the points forming the Triangles are relative to this anchor point.
    Point * anchor = new Point(0,0,0);

    // Triangles forming the mesh are stored here.
    std::vector<Triangle*> triangles;

public:
    // Moves the anchor point according to the movementVector of the Object and updates all triangles inside the triangles vector.
    void update(Engine * engine, float tick, movementVector velocity, rotationVector rotation);

    // Moves the anchor of the mesh (Moving the anchor, rather than moving each point on the mesh one by one, makes it easier to rotate the object later on.)
    void moveAnchor(movementVector velocity, float tick);
    
    // Sets the anchor position
    void setAnchor(float x, float y, float z);
    void setAnchor(vec3x1 position);
    void setAnchor(Point point);

    // Adds a new triangle to the triangles vector by copying it from a pointer. 
    void addTriangle(Triangle * triangle);

    // Adds a new triangle to the triangles vector by copying it from a pointer. Override the surfaceChar stored inside the Triangle.
    void addTriangle(Triangle * triangle, char surfaceChar);

    // Creates a triangle using the function parameters and adds it to the triangles vector.
    void addTriangle(float p1x, float p1y, float p1z, float p2x, float p2y, float p2z, float p3x, float p3y, float p3z, char surfaceChar);

    // Returns a pointer to the vector that stores the pointers of the triangles forming the mesh.
    std::vector<Triangle*> * getTriangleVector();

    // Returns a pointer to the triangle that is stored in the triangles vector with the respective index.
    Triangle * getTriangle(int index);

    // Draws the mesh on the screen.
    void draw(Engine * engine);
};