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
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,-cubeWidth/2 );
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2 );
        
        //Right
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,cubeWidth/2  );
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,cubeWidth/2  );
        
        //Left
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,-cubeWidth/2);
        cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        
        //Back
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,cubeWidth/2);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,cubeWidth/2);

        //Top
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,cubeWidth/2);
        cube->mesh.addTriangle(-cubeWidth/2,cubeWidth/2,-cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,-cubeWidth/2);

        //Bottom
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,-cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,-cubeWidth/2,-cubeWidth/2);
        




        
        cube->rotation = {0.00,0.000,0.00};
        cube->velocity = {0.0,0,-0.000};
        cube->mesh.anchor->position.x = 0.0f;
        cube->mesh.anchor->position.y = 0.0f;
        cube->mesh.anchor->position.z = -3.0f;

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
    demo->initialize(1.0f, 1000.0f, 3.0f);
    
    Object * cube = createCubeManually();
    demo->addObject(cube);

    movementVector velocity = {0,0,0};
    rotationVector rotation = {0.01,1,.5};

    while(1){
        cube->mesh.update(demo, 5000, velocity, rotation, '#');
        demo->loop(5000);
    }

    return 0;
}