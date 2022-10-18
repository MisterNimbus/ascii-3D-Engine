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
        output.setPositionX(input.getPositionX() * projectionMatrix.m[0][0] + input.getPositionY() * projectionMatrix.m[1][0] + input.getPositionZ() * projectionMatrix.m[2][0]+ projectionMatrix.m[3][0]);
        output.setPositionY(input.getPositionX() * projectionMatrix.m[0][1] + input.getPositionY() * projectionMatrix.m[1][1] + input.getPositionZ() * projectionMatrix.m[2][1]+ projectionMatrix.m[3][1]);
        output.setPositionZ(input.getPositionX() * projectionMatrix.m[0][2] + input.getPositionY() * projectionMatrix.m[1][2] + input.getPositionZ() * projectionMatrix.m[2][2]+ projectionMatrix.m[3][2]);
        float w  = input.getPositionX() * projectionMatrix.m[0][3] + input.getPositionY() * projectionMatrix.m[1][3] + input.getPositionZ() * projectionMatrix.m[2][3]+ projectionMatrix.m[3][3];
        if(w != 0.0f)
        {
            output.setPosition({
                output.getPositionX()/w,
                output.getPositionY()/w,
                output.getPositionZ()/w});
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
        this->zFurthest = zFurthest;
        this->zOffsetNear = zOffsetNear;
        this->fieldOfView = fieldOfView;
        float fieldOfViewRad = 1.0f / tanf(fieldOfView * 3.14159f / 180.0f);
        //float aspectRatio = (float) SCREEN_HEIGHT / (float) SCREEN_WIDTH;

        //projectionMatrix.m[0][0] = aspectRatio * fieldOfViewRad;
        projectionMatrix.m[0][0] = fieldOfViewRad;
        projectionMatrix.m[0][1] = 0;
        projectionMatrix.m[0][2] = 0;
        projectionMatrix.m[0][3] = 0;

        projectionMatrix.m[1][0] = 0;
        projectionMatrix.m[1][1] = fieldOfViewRad;
        projectionMatrix.m[1][2] = 0;
        projectionMatrix.m[1][3] = 0;

        projectionMatrix.m[2][0] = 0;
        projectionMatrix.m[2][1] = 0;
        projectionMatrix.m[2][2] = zFurthest / (zFurthest - zOffsetNear);
        projectionMatrix.m[2][3] = 1.0f;

        projectionMatrix.m[3][0] = 0;
        projectionMatrix.m[3][1] = 0;
        projectionMatrix.m[3][2] = (-zFurthest * zOffsetNear) / (zFurthest - zOffsetNear);
        projectionMatrix.m[3][3] = 0;

        std::cout << "Initialization complete !\n";
    }
    void Engine::loop(float tick, bool update, bool draw){
        
        // Buffer that will be shown on the console (initialized with ' ', so empty at first.)
        std::memset(screenBuffer, ' ', SCREEN_WIDTH*SCREEN_HEIGHT*4);

        // Buffer to save the z value of the last object that rewritten the screenBuffer (used to decide if the new object is in front of the last not getting blocked)
        std::memset(zBuffer,0,SCREEN_HEIGHT*SCREEN_WIDTH*4);
        
        //Drawing all objects
        for(auto object : objects){
            if(update){object->update(this, tick);}
            if(draw){object->draw(this);}
        }
        if(draw){
        std::cout << "\x1b[H";
        for(float output : screenBuffer){
            putchar(output);
        }}
        usleep(tick);
    }