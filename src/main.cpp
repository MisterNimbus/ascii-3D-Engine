#include <iostream>
#include <math.h>
#include <unistd.h>
#include <vector>

#include "include/Engine.h"
#include "include/Object.h"
#include "include/Point.h"
#include "include/mathUtils.h"
#include "include/Tests.h"

Object * createCubeManually(){
    Object * cube = new Object();
        
    // This can also be done by writing one surface by hand and rotating it with triangle.rotate() for each other surface.
    float cubeWidth = 2;
    /**/
    //Front
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,cubeWidth/2, '+');
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,cubeWidth/2, '+');

    //Back
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,-cubeWidth/2 , '.');
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2 , '.');
    
    //Right
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,cubeWidth/2 ,':' );
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,cubeWidth/2  ,':');
    
    //Left
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,-cubeWidth/2, '=');
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2, '=');
    
    //Top
    cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,cubeWidth/2, '#');
    cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,-cubeWidth/2, '#');

    //Bottom
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2, '@');
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2, '@');
    
    //cube->rotation = {0.01f,1.0f,0.5f};
    cube->rotation = {1.0f,0.0f,0.0f};
    cube->velocity = {0.0f,0.0f,-0.0f};
    cube->mesh.anchor->position = {0,0,-3};

    return cube;
}

Object * createCubeByRotating(){
    Object * cube = new Object();
        
        // This can also be done by writing one surface by hand and rotating it with triangle.rotate() for each other surface.
        float cubeWidth = 20;
        /*
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
        */
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
    demo->initialize(1.0f, 1000.0f, 3.0f);
    
    Object * cube = createCubeManually();
    demo->addObject(cube);

    while(1){
        demo->loop(10000);
    }

    return 0;
}