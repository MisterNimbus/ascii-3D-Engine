#include "./include/Point.h"
#include "include/mathUtils.h"
#include <cmath>
#include <math.h>
#include <iostream>

// Matrix * Vector
vec3x1 matrixMultiplication(mat3x3 * matrix, vec3x1 * vector){
    vec3x1 result;
    result.x = vector->x * matrix->m[0][0] + vector->y * matrix->m[0][1] + vector->z * matrix->m[0][2];
    result.y = vector->x * matrix->m[1][0] + vector->y * matrix->m[1][1] + vector->z * matrix->m[1][2];
    result.z = vector->x * matrix->m[2][0] + vector->y * matrix->m[2][1] + vector->z * matrix->m[2][2];
    return result;
}

    int Point::nextId=0;
    const float SMALLEST_FLOAT = 0.000001;

    Point::Point(float x,float y,float z):position({x,y,z}){
        id = nextId;
        nextId++;
    };

    Point::~Point(){};
    
    void Point::rotate(rotationVector rotation){
        this->rotateRoll(rotation.roll);
        this->rotatePitch(rotation.pitch);
        this->rotateYaw(rotation.yaw);
    };
    

    void Point::rotateYaw(float yawDegree){
        float initialDistance = this->distanceToAnchor();
        float yawInRadians = yawDegree * 3.14159265359f /180.0f;
        
        // Snap value to 0
        float cosfValue = cosf(yawInRadians);
        if (fabs(cosfValue) < SMALLEST_FLOAT) {
            cosfValue = 0;
        }
        
        // Snap value to 0
        float sinfValue = sinf(yawInRadians);
        if (fabs(sinfValue) < SMALLEST_FLOAT) {
            sinfValue = 0;
        }
        
        mat3x3 rotationMatrixYaw ={cosfValue, -sinfValue, 0.0f,
                                    sinfValue, cosfValue,0.0f,
                                    0.0f, 0.0f,1.0f};
        
        //calculating new position
        this->position = matrixMultiplication(&rotationMatrixYaw,&this->position);
        
        
        float distortedDistance = this->distanceToAnchor();

        // Avoiding division by 0
        if(distortedDistance!=0){
            // Normalizing to the original length
            this->position *= initialDistance/distortedDistance;
        }

        // Snap value to 0
        if (fabs(this->position.x) < SMALLEST_FLOAT) {
            this->position.x = 0;
        }
        // Snap value to 0
        if (fabs(this->position.y) < SMALLEST_FLOAT) {
            this->position.y = 0;
        }
        // Snap value to 0
        if (fabs(this->position.z) < SMALLEST_FLOAT) {
            this->position.z = 0;
        }
    }

    void Point::rotateRoll(float rollDegree){
        float initialDistance = this->distanceToAnchor();
        float rollInRadians = rollDegree * 3.14159265359f /180.0f;
        
        // Snap value to 0
        float cosfValue = cosf(rollInRadians);
        if (fabs(cosfValue) < SMALLEST_FLOAT) {
            cosfValue = 0;
        }
        
        // Snap value to 0
        float sinfValue = sinf(rollInRadians);
        if (fabs(sinfValue) < SMALLEST_FLOAT) {
            sinfValue = 0;
        }
        
        mat3x3 rotationMatrixRoll ={1.0f, 0.0f, 0.0f,
                                    0.0f, cosfValue,-sinfValue,
                                    0.0f, sinfValue,cosfValue};
        

        //calculating new position
        this->position = matrixMultiplication(&rotationMatrixRoll,&this->position);
        
        
        float distortedDistance = this->distanceToAnchor();

        // Avoiding division by 0
        if(distortedDistance!=0){
            // Normalizing to the original length
            this->position *= initialDistance/distortedDistance;
        }

        // Snap value to 0
        if (fabs(this->position.x) < SMALLEST_FLOAT) {
            this->position.x = 0;
        }
        // Snap value to 0
        if (fabs(this->position.y) < SMALLEST_FLOAT) {
            this->position.y = 0;
        }
        // Snap value to 0
        if (fabs(this->position.z) < SMALLEST_FLOAT) {
            this->position.z = 0;
        }
    }

    void Point::rotatePitch(float pitchDegree){
        float initialDistance = this->distanceToAnchor();
        float pitchInRadians = pitchDegree * 3.14159265359f /180.0f;
        
        // Snap value to 0
        float cosfValue = cosf(pitchInRadians);
        if (fabs(cosfValue) < SMALLEST_FLOAT) {
            cosfValue = 0;
        }
        
        // Snap value to 0
        float sinfValue = sinf(pitchInRadians);
        if (fabs(sinfValue) < SMALLEST_FLOAT) {
            sinfValue = 0;
        }
        
        mat3x3 rotationMatrixPitch ={cosfValue, 0.0f, sinfValue,
                                    0.0f, 1.0f,0.0f,
                                    -sinfValue, 0.0f,cosfValue};
        
        //calculating new position
        this->position = matrixMultiplication(&rotationMatrixPitch,&this->position);
        
        
        float distortedDistance = this->distanceToAnchor();

        // Avoiding division by 0
        if(distortedDistance!=0){
            // Normalizing to the original length
            this->position *= initialDistance/distortedDistance;
        }

        // Snap value to 0
        if (fabs(this->position.x) < SMALLEST_FLOAT) {
            this->position.x = 0;
        }
        // Snap value to 0
        if (fabs(this->position.y) < SMALLEST_FLOAT) {
            this->position.y = 0;
        }
        // Snap value to 0
        if (fabs(this->position.z) < SMALLEST_FLOAT) {
            this->position.z = 0;
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
        std::cout << "             Distance to anchor: " << this->distanceToAnchor() << "\n";
    }

    Point Point::operator+(Point point){
        Point result= {0,0,0};
        result.position.x = this->position.x + point.position.x; 
        result.position.y = this->position.y + point.position.y; 
        result.position.z = this->position.z + point.position.z;
        return result;
    }
    Point Point::operator-(Point point){
        Point result= {0,0,0};
        result.position.x = this->position.x - point.position.x; 
        result.position.y = this->position.y - point.position.y; 
        result.position.z = this->position.z - point.position.z;
        return result;

    }
    Point Point::operator/(int divisor){
        Point result= {0,0,0};
        result.position.x = this->position.x / divisor; 
        result.position.y = this->position.y / divisor; 
        result.position.z = this->position.z / divisor; 
        return result;
    }

    Point Point::operator*(int divisor){
        Point result= {0,0,0};
        result.position.x = this->position.x * divisor; 
        result.position.y = this->position.y * divisor; 
        result.position.z = this->position.z * divisor; 
        return result;
    }