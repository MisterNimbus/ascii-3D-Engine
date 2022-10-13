#include <iostream>
#include <math.h>
#include <unistd.h>
#include <vector>

#include "./include/Engine.h"
#include "include/Object.h"
#include "include/Point.h"
#include "include/mathUtils.h"

void pointRotationTest(){
    Point point(1.0f,2.0f,3.0f);
    point.log();
    rotationVector rotationStep = {90.0f,90.0f,90.0f};
    rotationVector rotation = {0.0f,0.0f,0.0f};
    while(true){
        std::cout << "\n\n======== ROLL ========";
        point.rotateRoll(rotationStep.roll);
        rotation.roll += rotationStep.roll;
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        point.log();
        usleep(5000000);
        std::cout << "\n\n======== YAW =========";
        point.rotateYaw(rotationStep.yaw);
        rotation.yaw += rotationStep.yaw;
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        point.log();
        usleep(5000000);
        std::cout << "\n\n======== PITCH =======";
        point.rotatePitch(rotationStep.pitch);
        rotation.pitch += rotationStep.pitch;
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        point.log();
        usleep(5000000);
    }
}


void pointRotationTest2(){
    Point point(1.0f,2.0f,3.0f);
    point.log();
    rotationVector rotationStep = {90.0f,45.0f,90.0f};
    rotationVector rotation = {0.0f,0.0f,0.0f};
    Point pointBuffer = point;

    while(true){
        
        /*std::cout << "\n\n======== ROLL ========";
        rotation.roll += rotationStep.roll;
        pointBuffer.rotateRoll(rotation.roll);
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        pointBuffer.log();
        */
        //pointBuffer = point;
        //std::cout << "before<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
        //pointBuffer.log();
        usleep(500000);
        
        std::cout << "\n\n======== YAW =========";
        rotation.yaw += rotationStep.yaw;
        pointBuffer.rotateYaw(rotationStep.yaw);
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        pointBuffer.log();
        /*
        pointBuffer = point;
        usleep(5000000);

        std::cout << "\n\n======== PITCH =======";
        rotation.pitch += rotationStep.pitch;
        pointBuffer.rotatePitch(rotation.pitch);
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        pointBuffer.log();
        
        pointBuffer = point;
        usleep(5000000);
        */
    }
}

Object * createCubeManually(){
    Object * cube = new Object();
        
        // This can also be done by writing one surface by hand and rotating it with triangle.rotate() for each other surface.
        float cubeWidth = 20;
        //Front
        /*
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2,   cubeWidth/2,cubeWidth/2,-cubeWidth/2);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        
        //Right
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2,   cubeWidth/2,cubeWidth/2,cubeWidth/2);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2,   cubeWidth/2,-cubeWidth/2,cubeWidth/2);
        
        //Left
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2,   -cubeWidth/2,cubeWidth/2,-cubeWidth/2);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        
        //Back
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2,   -cubeWidth/2,cubeWidth/2,cubeWidth/2);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2,   -cubeWidth/2,-cubeWidth/2,cubeWidth/2);

        //Top
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2,   cubeWidth/2,cubeWidth/2,cubeWidth/2);
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2,   cubeWidth/2,cubeWidth/2,-cubeWidth/2);

        //Bottom
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,cubeWidth/2,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,-cubeWidth/2,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        */

        //Front
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        
        //Right
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET);
        
        //Left
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        
        //Back
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET);

        //Top
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET);

        //Bottom
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        




        
        cube->rotation = {0.00,0.005,0.00};
        cube->velocity = {0.0,0,-0.001};
        cube->mesh.anchor->position.x = 0.0f;
        cube->mesh.anchor->position.y = 0.0f;
        cube->mesh.anchor->position.z = 100.0f;

        return cube;
}

Object * createCubeByRotating(){
    Object * cube = new Object();
        
        // This can also be done by writing one surface by hand and rotating it with triangle.rotate() for each other surface.
        float cubeWidth = 20;
        //Front
        /*
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2,   cubeWidth/2,cubeWidth/2,-cubeWidth/2);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        
        //Right
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2,   cubeWidth/2,cubeWidth/2,cubeWidth/2);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2,   cubeWidth/2,-cubeWidth/2,cubeWidth/2);
        
        //Left
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2,   -cubeWidth/2,cubeWidth/2,-cubeWidth/2);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        
        //Back
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2,   -cubeWidth/2,cubeWidth/2,cubeWidth/2);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2,   -cubeWidth/2,-cubeWidth/2,cubeWidth/2);

        //Top
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2,   cubeWidth/2,cubeWidth/2,cubeWidth/2);
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2,   cubeWidth/2,cubeWidth/2,-cubeWidth/2);

        //Bottom
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,cubeWidth/2,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,-cubeWidth/2,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        */

        //Front
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        
        //Right
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET);
        
        //Left
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        
        //Back
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET);

        //Top
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET,    cubeWidth/2,cubeWidth/2,cubeWidth/2 + Z_OFFSET,   cubeWidth/2,cubeWidth/2,-cubeWidth/2 + Z_OFFSET);

        //Bottom
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2 + Z_OFFSET,    -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2 + Z_OFFSET);
        




        
        cube->rotation = {0.00,0.005,0.00};
        cube->velocity = {0.0,0,-0.001};
        cube->mesh.anchor->position.x = 0.0f;
        cube->mesh.anchor->position.y = 0.0f;
        cube->mesh.anchor->position.z = 100.0f;

        return cube;
}

int main(){
    std::cout << "\x1b[2J"; // ANSI clearScreen
    Engine * demo = new Engine();
    demo->initialize(1.0f, 1000.0f, 5.0f);
    
    pointRotationTest();

    return 0;
}