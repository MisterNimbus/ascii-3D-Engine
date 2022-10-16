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
    float cubeWidth = 10;
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
    cube->rotation = {1.0f,0.5f,0.5f};
    cube->velocity = {0.0f,0.0f,-0.00000f};
    cube->mesh.anchor->position = {0,0,-15.};

    return cube;
}

Object * createCubeByRotating(){
    Object * cube = new Object();
    float cubeWidth = 10;

    //Front
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,cubeWidth/2, '+');
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    -cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,-cubeWidth/2,cubeWidth/2, '+');

    cube->mesh.addTriangle(cube->mesh.triangles[0]->getRotatedTriangle({0,45,0}), '#');
    cube->mesh.addTriangle(cube->mesh.triangles[1]->getRotatedTriangle({0,45,0}), '#');

    /*cube->mesh.addTriangle(cube->mesh.triangles[0]->getRotatedTriangle({0,0,180}));
    cube->mesh.addTriangle(cube->mesh.triangles[1]->getRotatedTriangle({0,0,180}));

    cube->mesh.addTriangle(cube->mesh.triangles[0]->getRotatedTriangle({0,0,270}));
    cube->mesh.addTriangle(cube->mesh.triangles[1]->getRotatedTriangle({0,0,270}));

    cube->mesh.addTriangle(cube->mesh.triangles[0]->getRotatedTriangle({0,90,0}));
    cube->mesh.addTriangle(cube->mesh.triangles[1]->getRotatedTriangle({0,90,0}));

    cube->mesh.addTriangle(cube->mesh.triangles[0]->getRotatedTriangle({0,270,0}));
    cube->mesh.addTriangle(cube->mesh.triangles[1]->getRotatedTriangle({0,270,0}));*/

    cube->rotation = {1.0f,0.5f,0.5f};
    cube->velocity = {0.0f,0.0f,-0.00000f};
    cube->mesh.anchor->position = {0,0,-15.};

        return cube;
}

Object * createOverlappingObject(){
    Object * cube = new Object();

    float cubeWidth = 10;
    /**/
    //Front
    cube->mesh.addTriangle(cubeWidth/2,-cubeWidth/2,cubeWidth/2,    cubeWidth/2,cubeWidth/2,cubeWidth/2 ,   -cubeWidth/2,cubeWidth/2,cubeWidth/2, '@');

    //Back
    cube->mesh.addTriangle(-cubeWidth/2,-cubeWidth/2,-cubeWidth/2,    -cubeWidth/2,cubeWidth/2,-cubeWidth/2 ,   cubeWidth/2,cubeWidth/2,-cubeWidth/2 , '.');
    
    //cube->rotation = {0.01f,1.0f,0.5f};
    cube->rotation = {0.5f,0.0f,0.0f};
    cube->velocity = {0.0f,0.0f,-0.0f};
    cube->mesh.anchor->position = {0,0,-15.};

    return cube;
}

int main(){
    std::cout << "\x1b[2J"; // ANSI clearScreen
    Engine * demo = new Engine();
    demo->initialize(0.1f, 100.0f, 3.0f);
    
    Object * cube = createCubeByRotating();
    //Object * cube = createCubeManually();
    demo->addObject(cube);

    while(1){
        demo->loop(5000);
    }

    return 0;
}