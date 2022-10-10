#pragma once

struct vec1x3{
    float x,y,z;
};

struct mat4x4
{
    float m[4][4];
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