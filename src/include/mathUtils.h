#pragma once
struct mat4x4
{
    float m[4][4];
};

struct mat3x3
{
    float m[3][3];
    
};

struct vec1x3{
    float x,y,z;

public:
    vec1x3 operator*=(mat3x3 * matrix){
        vec1x3 result;
        this->x = this->x * matrix->m[0][0] + this->y * matrix->m[1][0] + this->z * matrix->m[2][0];
        this->y = this->x * matrix->m[0][1] + this->y * matrix->m[1][1] + this->z * matrix->m[2][1];
        this->z = this->x * matrix->m[0][2] + this->y * matrix->m[1][2] + this->z * matrix->m[2][2];
        return *this;
    };

    vec1x3 operator*=(float scalar){
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    vec1x3 operator+=(vec1x3 * vector){
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
};

struct movementVector
{
    float x, y, z;
};