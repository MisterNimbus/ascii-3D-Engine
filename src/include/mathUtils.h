#pragma once

#include <cmath>

float const PI = 3.141519265359;

struct mat4x4
{
    float m[4][4];
};

struct mat3x3
{
    float m[3][3];
};

struct vec3x1{
    float x,y,z;

public:

    vec3x1 operator*=(float scalar){
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    vec3x1 operator/=(float scalar){
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        return *this;
    }

    vec3x1 operator+=(vec3x1 * vector){
        this->x += vector->x;
        this->y += vector->y;
        this->z += vector->z;
        return *this;
    }

    vec3x1 operator-(vec3x1 vector){
        vec3x1 result;
        result.x = this->x - vector.x;
        result.y = this->y - vector.y;
        result.z = this->z - vector.z;
        return result;
    }

    vec3x1 crossProduct(vec3x1 vector2){
        vec3x1 result;
        result.x = this->y * vector2.z - this->z * vector2.y;
        result.y = this->z * vector2.x - this->x * vector2.z;
        result.z = this->x * vector2.y - this->y * vector2.x;
        return result;
    }

    float length(){
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }
};

// I used the aviation terms for rotation axis:
// "roll"  is for rotation around X axis.
// "yaw"   is for rotation around Y axis.
// "pitch" is for rotation around Z axis.
struct rotationVector
{
    float roll, yaw, pitch;

    rotationVector operator+=(rotationVector vector){
        this->roll += vector.roll;
        this->yaw += vector.yaw;
        this->pitch += vector.pitch;
        return *this;
    }
};

struct movementVector
{
    float x, y, z;
};