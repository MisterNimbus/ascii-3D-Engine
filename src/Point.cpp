#include "./include/Point.h"
#include "include/mathUtils.h"
#include <cmath>
#include <math.h>
#include <iostream>

    int Point::nextId=0;

    Point::Point(float x,float y,float z):position({x,y,z}){
        id = nextId;
        nextId++;
    };

    Point::~Point(){};
    
    void Point::rotatePoint(float roll_step, float yaw_step, float pitch_step){
        //x = y*sin(roll_step)*sin(yaw_step)*cos(pitch_step) - z*cos(roll_step)*sin(yaw_step)*cos(pitch_step) + y*cos(roll_step)*sin(pitch_step) + z*sin(roll_step)*sin(pitch_step) + x*cos(yaw_step)*cos(pitch_step);
        //y = y*cos(roll_step)*cos(pitch_step) + z*sin(roll_step)*cos(pitch_step) - y*sin(roll_step)*sin(yaw_step)*sin(pitch_step) + z*cos(roll_step)*sin(yaw_step)*sin(pitch_step) - x*cos(yaw_step)*sin(pitch_step); 
        //z = z*cos(roll_step)*cos(yaw_step)-y*sin(roll_step)*cos(yaw_step) + x*sin(yaw_step);
    };
    
    
    void Point::rotate(rotationVector rotation){
        //x = y*sin(rotation.roll)*sin(rotation.yaw)*cos(rotation.pitch) - z*cos(rotation.roll)*sin(rotation.yaw)*cos(rotation.pitch) + y*cos(rotation.roll)*sin(rotation.pitch) + z*sin(rotation.roll)*sin(rotation.pitch) + x*cos(rotation.yaw)*cos(rotation.pitch);
        //y = y*cos(rotation.roll)*cos(rotation.pitch) + z*sin(rotation.roll)*cos(rotation.pitch) - y*sin(rotation.roll)*sin(rotation.yaw)*sin(rotation.pitch) + z*cos(rotation.roll)*sin(rotation.yaw)*sin(rotation.pitch) - x*cos(rotation.yaw)*sin(rotation.pitch); 
        //z = z*cos(rotation.roll)*cos(rotation.yaw)-y*sin(rotation.roll)*cos(rotation.yaw) + x*sin(rotation.yaw);
    };
    

    void Point::rotateRoll(float rollDegree){
        float initialDistance = this->distanceToAnchor();
        float rollInRadians = rollDegree *3.14159265359f /180.f;
        mat3x3 rotationMatrixRoll ={1.0f, 0.0f, 0.0f,
                                    0.0f, cosf(rollInRadians),-sinf(rollInRadians),
                                    0.0f, sinf(rollInRadians),cosf(rollInRadians)};
        this->position *= &rotationMatrixRoll;
        float distortedDistance = this->distanceToAnchor();
        if(distortedDistance!=0){
        this->position *= initialDistance/distortedDistance;
        }
    }

    void Point::rotateYaw(float yawDegree){
        float initialDistance = this->distanceToAnchor();
        float yawInRadians = yawDegree *3.14159265359f /180.f;
        mat3x3 rotationMatrixYaw ={cosf(yawInRadians), -sinf(yawInRadians), 0.0f,
                                    sinf(yawInRadians), cosf(yawInRadians),0.0f,
                                    0.0f, 0.0f,1.0f};
        this->position *= &rotationMatrixYaw;
        float distortedDistance = this->distanceToAnchor();
        if(distortedDistance!=0){
        this->position *= initialDistance/distortedDistance;
        }
    }

    void Point::rotatePitch(float pitchDegree){
        float initialDistance = this->distanceToAnchor();
        float pitchInRadians = pitchDegree *3.14159265359f /180.f;
        mat3x3 rotationMatrixPitch ={cosf(pitchInRadians), 0.0f, sinf(pitchInRadians),
                                    0.0f, 1.0f,0.0f,
                                    -sin(pitchInRadians), 0.0f,cosf(pitchInRadians)};
        this->position *= &rotationMatrixPitch;
        float distortedDistance = this->distanceToAnchor();
        if(distortedDistance!=0){
        this->position *= initialDistance/distortedDistance;
        }
    }
    
    void Point::move(movementVector velocity){
        position.x += velocity.x;
        position.y += velocity.y;
        position.z += velocity.z; 
    };

    Point * Point::applyAnchorOffset(Point anchor){
        Point * result = new Point (0,0,0);
        result->position.x = this->position.x + anchor.position.x;
        result->position.y = this->position.y + anchor.position.y;
        result->position.z = this->position.z + anchor.position.z;
        return result;
    };

    float Point::distanceToAnchor(){
        return std::sqrt(this->position.x*this->position.x + this->position.y * this->position.y + this->position.z*this->position.z);
    }

    void Point::log(){
        std::cout << "\nPoint ID: " << this->id << "\n";
        std::cout << "    Relative Position to anchor: ( " << this->position.x << ", " << this->position.y << ", " << this->position.z << " ) \n" ;
        std::cout << "             Distance to anchor: " << this->distanceToAnchor();
    }