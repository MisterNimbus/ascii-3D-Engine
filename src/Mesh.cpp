#include "./include/Mesh.h"
#include "include/Point.h"

void Mesh::update(Engine * engine, float tick, movementVector velocity, rotationVector rotation){
    this->moveAnchor(velocity,tick);
    for(auto triangle : this->triangles){
        triangle->update(engine, tick, this->anchor, rotation);
    }    
}

void Mesh::addTriangle(Triangle * triangle){
    this->triangles.push_back(triangle);
}

void Mesh::addTriangle(Triangle * triangle, char surfaceChar){
    triangle->setSurfaceChar(surfaceChar);
    this->triangles.push_back(triangle);
}

void Mesh::addTriangle(float p1x, float p1y, float p1z, float p2x, float p2y, float p2z, float p3x, float p3y, float p3z, char surfaceChar){
    this->triangles.push_back(new Triangle(p1x, p1y, p1z, p2x, p2y, p2z, p3x, p3y, p3z, surfaceChar));
}

void Mesh::moveAnchor(movementVector velocity, float tick){
    this->anchor->setPosition({
    this->anchor->getPositionX() + velocity.x * tick,
    this->anchor->getPositionY() + velocity.y * tick,
    this->anchor->getPositionZ() + velocity.z * tick});
};

void Mesh::setAnchor(float x, float y, float z){
    this->anchor->setPosition({x,y,z});
}

void Mesh::setAnchor(vec3x1 position){
    this->anchor->setPosition(position);
}

void Mesh::setAnchor(Point point){
    this->setAnchor(point.getPosition());
}

std::vector<Triangle*> * Mesh::getTriangleVector(){
    return &this->triangles;
}

Triangle * Mesh::getTriangle(int index){
    return this->triangles[index];
}

void Mesh::draw(Engine * engine){
    for(auto triangle : this->triangles){
        triangle->draw(engine, this->anchor);
    }    
}