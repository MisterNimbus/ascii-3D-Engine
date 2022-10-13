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
        output.position.x = input.position.x * projectionMatrix.m[0][0] + input.position.y * projectionMatrix.m[1][0] + input.position.z * projectionMatrix.m[2][0]+ projectionMatrix.m[3][0];
        output.position.y = input.position.x * projectionMatrix.m[0][1] + input.position.y * projectionMatrix.m[1][1] + input.position.z * projectionMatrix.m[2][1]+ projectionMatrix.m[3][1];
        output.position.z = input.position.x * projectionMatrix.m[0][2] + input.position.y * projectionMatrix.m[1][2] + input.position.z * projectionMatrix.m[2][2]+ projectionMatrix.m[3][2];
        float w  = input.position.x * projectionMatrix.m[0][3] + input.position.y * projectionMatrix.m[1][3] + input.position.z * projectionMatrix.m[2][3]+ projectionMatrix.m[3][3];
        if(w != 0.0f)
        {
            output.position.x /= w;
            output.position.y /= w;
            output.position.z /= w;
        }
    }


    mat4x4 * Engine::getProjectionMatrix(){
        return &projectionMatrix;
    };

    // zOffsetNear closest distance to be rendered from the camere (screen)
    // zFurthest furthest distance to be rendered from the camera
    // fieldOfView in degrees
    void Engine::initialize(float zOffsetNear, float zFurthest, float fieldOfView){

        // Setting up Projection Matrix
        float fieldOfViewRad = 1.0f / tanf(fieldOfView / 180.0f * 3.14159f);
        float aspectRatio = (float) SCREEN_HEIGHT / (float) SCREEN_WIDTH;

        projectionMatrix.m[0][0] = aspectRatio + fieldOfViewRad;
        projectionMatrix.m[1][1] = fieldOfViewRad;
        projectionMatrix.m[2][2] = zFurthest / (zFurthest - zOffsetNear);
        projectionMatrix.m[3][2] = (-zFurthest * zOffsetNear) / (zFurthest - zOffsetNear);
        projectionMatrix.m[2][3] = 1.0f;
        projectionMatrix.m[3][3] = 0.0f;

        std::cout << "Initialization complete !\n";
    }
    void Engine::loop(float tick){
        
        // Buffer that will be shown on the console (initialized with ' ', so empty at first.)
        std::memset(screenBuffer, ' ', SCREEN_WIDTH*SCREEN_HEIGHT*4);

        // Buffer to save the z value of the last object that rewritten the screenBuffer (used to decide if the new object is in front of the last not getting blocked)
        std::memset(zBuffer,0,SCREEN_HEIGHT*SCREEN_WIDTH*4);
        
        //Drawing all objects
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