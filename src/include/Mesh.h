#include "./mathUtils.h"
#include "./Triangle.h"
#include "Point.h"

#include <vector>

class Engine;

class Mesh{
public:
    // Coordinates of the Points on the Triangles are relative to this anchor point.
    Point * anchor = new Point(0,0,0);
    
    // Triangles forming the mesh are stored here
    std::vector<Triangle*> triangles;

    //moves the anchor point depending on the movementVector of the Object and time elapsed (tick), updates all triangles forming the mesh.
    void update(Engine * engine, float tick, movementVector velocity, rotationVector rotation);

    // To move a mesh move the anchor rather than moving each point on the mesh one by one.
    void moveAnchor(movementVector velocity, float tick);
    
    // For creating meshes by writing one triangle by hand and then rotating it to form the others.
    void addTriangle(Triangle * triangle);

    //manually creating points of the triangle
    void addTriangle(float p1x, float p1y, float p1z, float p2x, float p2y, float p2z, float p3x, float p3y, float p3z, char surfaceChar);
};