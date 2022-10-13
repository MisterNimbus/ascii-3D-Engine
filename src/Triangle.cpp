#include "./include/Triangle.h"
#include "./include/Engine.h"
#include "include/Point.h"
#include <iostream>
#include <ostream>
#include <vector>

    //Unique triangle
    int Triangle::nextId=0;
    
    Triangle absolutePosition(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
    Triangle projectionBuffer(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
    Triangle projectionBufferScreenIndex(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
    Point * anchorProjection= new Point(0.0f,0.0f,0.0f);

    Triangle::Triangle(){
        this->id = nextId;
        Triangle::nextId++;
    };
    
    Triangle::Triangle(Point * p1, Point * p2, Point * p3){
        this->id = nextId;
        Triangle::nextId++;
        this->points[0] = p1;
        this->points[1] = p2;
        this->points[2] = p3;
    };

    Triangle::~Triangle(){
        
    };

    Triangle::Triangle(float p1x, float p1y, float p1z, float p2x, float p2y, float p2z, float p3x, float p3y, float p3z){
        this->id = nextId;
        Triangle::nextId++;
        this->points[0] = new Point(p1x,p1y, p1z);
        this->points[1] = new Point(p2x,p2y, p2z);
        this->points[2] = new Point(p3x,p3y, p3z);
    };

    void Triangle::update(Engine * engine, float tick, Point * meshAnchor, rotationVector rotation,char surfaceChar){
        for(auto point : points){
            point->rotate(rotation);
        }
        //this->log();
        this->Draw(engine, meshAnchor, surfaceChar);
    };



    void Triangle::DrawLine(Engine * engine, char lineChar, Point & p1, Point & p2, int resolution){
        std::vector<Point*> linePoints;
        float difX = p2.position.x - p1.position.x;
        float difY = p2.position.y - p1.position.y;
        float difZ = p2.position.z - p1.position.z;
        for(int i = 0; i <= resolution; i++){
            linePoints.push_back(new Point(p1.position.x + i* difX/resolution,p1.position.y + i*difY/resolution,p1.position.z + i*difZ/resolution));
        }
        for(auto point : linePoints){
            if(point->position.x + point->position.y*SCREEN_WIDTH >=0 && point->position.x + point->position.y*SCREEN_WIDTH < SCREEN_WIDTH*SCREEN_HEIGHT){
                if(point->position.z > engine->zBuffer[(int)point->position.x + (int) point->position.y*SCREEN_WIDTH]){
                    engine->zBuffer[(int)point->position.x + (int) point->position.y*SCREEN_WIDTH] = (int) point->position.z;
                    engine->screenBuffer[(int)point->position.x + (int) point->position.y*SCREEN_WIDTH] = lineChar;
                }
            }
        }
    };

    void Triangle::Draw(Engine * engine, Point *meshAnchor, char surfaceChar){

        // Applies the Anchor Offset to the points.
        absolutePosition.points[0] = this->points[0]->applyAnchorOffset(*meshAnchor);
        absolutePosition.points[1] = this->points[1]->applyAnchorOffset(*meshAnchor);
        absolutePosition.points[2] = this->points[2]->applyAnchorOffset(*meshAnchor);

        absolutePosition.log();

        // Applies Projection Matrix and stores resulting triangle in projectionBuffer
        engine->multiplyProjectionMatrix(*this->points[0], *projectionBuffer.points[0], *engine->getProjectionMatrix());
        engine->multiplyProjectionMatrix(*this->points[1], *projectionBuffer.points[1], *engine->getProjectionMatrix());
        engine->multiplyProjectionMatrix(*this->points[2], *projectionBuffer.points[2], *engine->getProjectionMatrix());

        // Calculating Screen Buffer Index
        projectionBufferScreenIndex.points[0]->position.x = (int) projectionBuffer.points[0]->position.x*2 + X_OFFSET;
        projectionBufferScreenIndex.points[0]->position.y = (int) projectionBuffer.points[0]->position.y   + Y_OFFSET;
        projectionBufferScreenIndex.points[0]->position.z = (int) projectionBuffer.points[0]->position.z   + Z_OFFSET;

        projectionBufferScreenIndex.points[1]->position.x = (int) projectionBuffer.points[1]->position.x*2 + X_OFFSET;
        projectionBufferScreenIndex.points[1]->position.y = (int) projectionBuffer.points[1]->position.y   + Y_OFFSET;
        projectionBufferScreenIndex.points[1]->position.z = (int) projectionBuffer.points[1]->position.z   + Z_OFFSET;

        projectionBufferScreenIndex.points[2]->position.x = (int) projectionBuffer.points[2]->position.x*2 + X_OFFSET;
        projectionBufferScreenIndex.points[2]->position.y = (int) projectionBuffer.points[2]->position.y   + Y_OFFSET;
        projectionBufferScreenIndex.points[2]->position.z = (int) projectionBuffer.points[2]->position.z   + Z_OFFSET;

        projectionBufferScreenIndex.log();

        for(auto point : projectionBufferScreenIndex.points){
            if(point->position.x + point->position.y*SCREEN_WIDTH >=0 && point->position.x + point->position.y*SCREEN_WIDTH < SCREEN_WIDTH*SCREEN_HEIGHT){
                if(point->position.z > engine->zBuffer[(int)point->position.x + (int) point->position.y*SCREEN_WIDTH]){
                    engine->zBuffer[(int)point->position.x + (int) point->position.y*SCREEN_WIDTH] = (int) point->position.z;
                    engine->screenBuffer[(int)point->position.x + (int) point->position.y*SCREEN_WIDTH] = surfaceChar;
                }
            }
        }
        DrawLine(engine,'1',*projectionBufferScreenIndex.points[0], *projectionBufferScreenIndex.points[1], 10);
        DrawLine(engine,'2',*projectionBufferScreenIndex.points[1], *projectionBufferScreenIndex.points[2], 10);
        DrawLine(engine,'0',*projectionBufferScreenIndex.points[2], *projectionBufferScreenIndex.points[0], 10);
    }  

    void Triangle::log(){
        std::cout << "\nTriangle ID: " << this->id << "\n";
        std::cout << "          Point1 : (" << this->points[0]->position.x << ", " << this->points[0]->position.y << ", " << this->points[0]->position.z << ") \n" ;
        std::cout << "          Point2 : (" << this->points[1]->position.x << ", " << this->points[1]->position.y << ", " << this->points[1]->position.z << ") \n" ;
        std::cout << "          Point3 : (" << this->points[2]->position.x << ", " << this->points[2]->position.y << ", " << this->points[2]->position.z << ") \n" ;
    }