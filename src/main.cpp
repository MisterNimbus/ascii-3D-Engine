#include <iostream>
#include <math.h>
#include <unistd.h>
#include <vector>

#include "include/Engine.h"
#include "include/Object.h"
#include "include/Point.h"
#include "include/Triangle.h"
#include "include/mathUtils.h"
#include "include/Tests.h"
#include "include/objectRecipes.h"
#include "include/demos.h"

int main(){
    std::cout << "\x1b[2J"; // ANSI clearScreen
    Object * pyramid = createTriangleBasedPyramid(5,{0,0,-15},{0,0,1},{0,0,0}, "1#_/");
    rotatingObjectDemo(pyramid);
    return 0;
}