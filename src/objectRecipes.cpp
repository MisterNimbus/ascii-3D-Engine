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

Object * createTriangleBasedPyramid(float triangleCornerDistance, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars){
    Object * pyramid = new Object;

    Point * corner1 = new Point(0,triangleCornerDistance,0);
    corner1->rotate({0,0,0});
    Point * corner2 = new Point(corner1);
    corner2->rotate({30,-120,0});
    Point * corner3 = new Point(corner1);
    corner3->rotate({30,120,0});

    Triangle* triangle = new Triangle(corner1,corner2, corner3);
    
    pyramid->mesh.addTriangle(triangle,surfaceChars[0]);
    pyramid->mesh.addTriangle(0,0,0,0,0,0,0,0,0,'*'); //Anchor Point

    pyramid->mesh.addTriangle(pyramid->mesh.getTriangle(0)->getRotatedTriangle({0,0,120}), surfaceChars[1]);
    pyramid->mesh.addTriangle(pyramid->mesh.getTriangle(0)->getRotatedTriangle({0,0,240}), surfaceChars[2]);
    pyramid->mesh.addTriangle(new Triangle(new Point(pyramid->mesh.getTriangle(0)->getPoint(2)->getPosition()),new Point(pyramid->mesh.getTriangle(2)->getPoint(1)->getPosition()),new Point(pyramid->mesh.getTriangle(2)->getPoint(2)->getPosition())),surfaceChars[3]);

    pyramid->rotationSpeed = rotationSpeed;
    pyramid->velocity = velocity;
    pyramid->mesh.setAnchor(anchorPosition);
    return pyramid;
}