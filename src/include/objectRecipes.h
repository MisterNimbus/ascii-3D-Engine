#include "Engine.h"
#include "Object.h"
#include "Point.h"
#include "mathUtils.h"
#include <cmath>
#include <string>

Object * createCubeByRotating(float cubeWidth, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars = "+&.:_=");
Object * createCubeManually(float cubeWidth, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars = "+&.:_=");
Object * createTriangleBasedPyramid(float triangleCornerDistance, Point anchorPosition, rotationVector rotationSpeed, movementVector velocity, std::string surfaceChars = "1234");