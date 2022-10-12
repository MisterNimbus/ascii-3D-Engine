#include "./include/Engine.h"
#include "include/Object.h"
#include "include/Point.h"
#include "include/Triangle.h"
#include <cstdio>
#include <iostream>
#include <math.h>
#include <cstring>
#include <unistd.h>

    Engine::Engine(){};

    void Engine::addObject(Object* object){
        this->objects.push_back(object);
    }
    void Engine::multiplyProjectionMatrix(Point &input, Point &output, mat4x4 &projectionMatrix){
        output.x = input.x * projectionMatrix.m[0][0] + input.y * projectionMatrix.m[1][0] + input.z * projectionMatrix.m[2][0]+ projectionMatrix.m[3][0];
        output.y = input.x * projectionMatrix.m[0][1] + input.y * projectionMatrix.m[1][1] + input.z * projectionMatrix.m[2][1]+ projectionMatrix.m[3][1];
        output.z = input.x * projectionMatrix.m[0][2] + input.y * projectionMatrix.m[1][2] + input.z * projectionMatrix.m[2][2]+ projectionMatrix.m[3][2];
        float w  = input.x * projectionMatrix.m[0][3] + input.y * projectionMatrix.m[1][3] + input.z * projectionMatrix.m[2][3]+ projectionMatrix.m[3][3];
        if(w != 0.0f)
        {
            output.x /= w;
            output.y /= w;
            output.z /= w;
        }
    }


    mat4x4 * Engine::getProjectionMatrix(){
        return &projectionMatrix;
    };

    void Engine::initialize(){

        // Projection Matrix
        float zOffsetNear = 20.1f;  // closest distance to be rendered from the camere (screen)
        float zFurthest = 300.0f; // furthest distance to be rendered from the camera
        float fieldOfView = 15.0f; // in degrees
        float fieldOfViewRad = 1.0f / tanf(fieldOfView / 180.0f * 3.14159f);
        float aspectRatio = (float) SCREEN_HEIGHT / (float) SCREEN_WIDTH;

        projectionMatrix.m[0][0] = aspectRatio + fieldOfViewRad;
        projectionMatrix.m[1][1] = fieldOfViewRad;
        projectionMatrix.m[2][2] = zFurthest / (zFurthest - zOffsetNear);
        projectionMatrix.m[3][2] = (-zFurthest * zOffsetNear) / (zFurthest - zOffsetNear);
        projectionMatrix.m[2][3] = 1.0f;
        projectionMatrix.m[3][3] = 0.0f;


        Object * cube = new Object();
        /*
        //Front
        cube->mesh.addTriangle(0.0f,0.0f,0.0f,    0.0f,1.0f,0.0f,   1.0f,1.0f,0.0f);
        cube->mesh.addTriangle(0.0f,0.0f,0.0f,    1.0f,1.0f,0.0f,   1.0f,0.0f,0.0f);
        
        //Right
        cube->mesh.addTriangle(1.0f,0.0f,0.0f,    1.0f,1.0f,0.0f,   1.0f,1.0f,1.0f);
        cube->mesh.addTriangle(1.0f,0.0f,0.0f,    1.0f,1.0f,1.0f,   1.0f,0.0f,1.0f);
        
        //Left
        cube->mesh.addTriangle(0.0f,0.0f,1.0f,    0.0f,1.0f,1.0f,   0.0f,1.0f,0.0f);
        cube->mesh.addTriangle(0.0f,0.0f,1.0f,    0.0f,1.0f,0.0f,   0.0f,0.0f,0.0f);
        
        //Back
        cube->mesh.addTriangle(1.0f,0.0f,1.0f,    1.0f,1.0f,1.0f,   0.0f,1.0f,1.0f);
        cube->mesh.addTriangle(1.0f,0.0f,1.0f,    0.0f,1.0f,1.0f,   0.0f,0.0f,1.0f);

        //Top
        cube->mesh.addTriangle(0.0f,1.0f,0.0f,    0.0f,1.0f,1.0f,   1.0f,1.0f,1.0f);
        cube->mesh.addTriangle(0.0f,1.0f,0.0f,    1.0f,1.0f,1.0f,   1.0f,1.0f,0.0f);

        //Bottom
        cube->mesh.addTriangle(1.0f,0.0f,1.0f,    0.0f,0.0f,1.0f,   0.0f,0.0f,0.0f);
        cube->mesh.addTriangle(1.0f,0.0f,1.0f,    0.0f,0.0f,0.0f,   1.0f,0.0f,0.0f);
        */
        
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
        cube->mesh.anchor->x = 0.0f;
        cube->mesh.anchor->y = 0.0f;
        cube->mesh.anchor->z = 100.0f;

        this->addObject(cube);
        /*for(auto triangle : cube->mesh.triangles){
            triangle->log();
        }*/

        std::cout << "Initialization complete !\n";
    }
    void Engine::loop(float tick){
        std::memset(screenBuffer, ' ', SCREEN_WIDTH*SCREEN_HEIGHT*4);
        std::memset(zBuffer,0,SCREEN_HEIGHT*SCREEN_WIDTH*4);
        /*for(auto object : objects){
            object->update(this, tick,'#');
        }*/
        objects[0]->mesh.triangles[0]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'A');
        objects[0]->mesh.triangles[1]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'B');
        /*objects[0]->mesh.triangles[2]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'C');
        objects[0]->mesh.triangles[3]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'D');
        objects[0]->mesh.triangles[4]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'E');
        objects[0]->mesh.triangles[5]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'F');
        objects[0]->mesh.triangles[6]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'G');
        objects[0]->mesh.triangles[7]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'H');
        objects[0]->mesh.triangles[8]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'I');
        objects[0]->mesh.triangles[9]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'J');
        objects[0]->mesh.triangles[10]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'K');
        objects[0]->mesh.triangles[11]->update(this, tick, objects[0]->mesh.anchor, objects[0]->rotation, 'L');
        */
        
        
        std::cout << "\x1b[H";
            for(char output : screenBuffer){
                putchar(output);
            }
        usleep(tick);
    }