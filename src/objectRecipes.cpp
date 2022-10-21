#pragma once

#include "include/Engine.h"
#include "include/Object.h"
#include "include/Point.h"
#include "include/Triangle.h"
#include "include/mathUtils.h"
#include <cmath>
#include <string>

Object * createCubeByRotating(float cubeWidth, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars = "+&.:_="){
    Object * cube = new Object();

    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,cubeWidth/2, surfaceChars[0]);
    cube->mesh.addTriangle(cube->mesh.getTriangle(0)->getRotatedTriangle({0,180,0}), surfaceChars[0]);

    cube->mesh.addTriangle(cube->mesh.getTriangle(0)->getRotatedTriangle({90,0,0}), surfaceChars[1]);
    cube->mesh.addTriangle(cube->mesh.getTriangle(1)->getRotatedTriangle({90,0,0}), surfaceChars[1]);

    cube->mesh.addTriangle(cube->mesh.getTriangle(0)->getRotatedTriangle({180,0,0}), surfaceChars[2]);
    cube->mesh.addTriangle(cube->mesh.getTriangle(1)->getRotatedTriangle({180,0,0}), surfaceChars[2]);

    cube->mesh.addTriangle(cube->mesh.getTriangle(0)->getRotatedTriangle({270,0,0}), surfaceChars[3]);
    cube->mesh.addTriangle(cube->mesh.getTriangle(1)->getRotatedTriangle({270,0,0}), surfaceChars[3]);

    cube->mesh.addTriangle(cube->mesh.getTriangle(0)->getRotatedTriangle({0,0,90}), surfaceChars[4]);
    cube->mesh.addTriangle(cube->mesh.getTriangle(1)->getRotatedTriangle({0,0,90}), surfaceChars[4]);

    cube->mesh.addTriangle(cube->mesh.getTriangle(0)->getRotatedTriangle({0,0,270}), surfaceChars[5]);
    cube->mesh.addTriangle(cube->mesh.getTriangle(1)->getRotatedTriangle({0,0,270}), surfaceChars[5]);

    cube->rotationSpeed = rotationSpeed;
    cube->velocity = velocity;
    cube->mesh.setAnchor(anchorPosition);

    return cube;
}

Object * createCubeManually(float cubeWidth, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars = "+&.:_="){
    Object * cube = new Object();

    //Front
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,cubeWidth/2, surfaceChars[0]);
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,cubeWidth/2, surfaceChars[0]);

    //Back
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,-cubeWidth/2 , surfaceChars[1] );
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2 , surfaceChars[1]);
    
    //Right
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,cubeWidth/2 ,surfaceChars[2] );
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,cubeWidth/2  ,surfaceChars[2]);
    
    //Left
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,-cubeWidth/2, surfaceChars[3]);
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2, surfaceChars[3]);
    
    //Top
    cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,cubeWidth/2, surfaceChars[4]);
    cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,-cubeWidth/2, surfaceChars[4]);

    //Bottom
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2, surfaceChars[5]);
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2, surfaceChars[5]);

    cube->rotationSpeed = rotationSpeed;
    cube->velocity = velocity;
    cube->mesh.setAnchor(anchorPosition);

    return cube;
}

Object * createTetrahedron(float baseDistance, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars){
    Object * tetrahedron = new Object;

    Point * corner1 = new Point(-baseDistance,-baseDistance,-baseDistance);
    Point * corner2 = new Point(baseDistance,-baseDistance,baseDistance);
    Point * corner3 = new Point(baseDistance,baseDistance,-baseDistance);
    Triangle* triangle = new Triangle(corner1,corner2, corner3);
    tetrahedron->mesh.addTriangle(triangle,surfaceChars[0]);

    tetrahedron->mesh.addTriangle(tetrahedron->mesh.getTriangle(0)->getRotatedTriangle({180,0,0}), surfaceChars[1]);

    corner1 = new Point(-baseDistance,-baseDistance,-baseDistance);
    corner2 = new Point(-baseDistance,baseDistance,baseDistance);
    corner3 = new Point(baseDistance,baseDistance,-baseDistance);
    triangle = new Triangle(corner1,corner2, corner3);
    tetrahedron->mesh.addTriangle(triangle,surfaceChars[2]);

    tetrahedron->mesh.addTriangle(tetrahedron->mesh.getTriangle(2)->getRotatedTriangle({180,0,0}), surfaceChars[3]);

    tetrahedron->rotationSpeed = rotationSpeed;
    tetrahedron->velocity = velocity;
    tetrahedron->mesh.setAnchor(anchorPosition);
    return tetrahedron;
}

Object * createDodecahedron(float triangleCornerDistance, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars){
    Object * dodecahedron = new Object;

    return dodecahedron;
}

Object * createIcosahedron(float triangleCornerDistance, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars){
    Object * icosahedron = new Object;
    
    return icosahedron;
}