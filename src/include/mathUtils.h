#pragma once

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

    vec3x1 operator+=(vec3x1 * vector){
        this->x += vector->x;
        this->y += vector->y;
        this->z += vector->z;
        return *this;
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