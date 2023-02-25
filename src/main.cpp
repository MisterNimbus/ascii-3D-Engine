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
#include "include/dialog.h"

int main(){

    //Object * tetrahedron = createTetrahedron(5,{0,0,-15},{0,0,1},{0,0,0}, "$#_/");
    //Object * cube = createCubeByRotating(5,{0,0,-15},{0,0,1},{0,0,0}, "$#_/.+P");
    //rotatingObjectDemo(cube);
    //normalVecTest();
    Object * tetrahedron = createTetrahedron(5,{0,1.5,-13},{.2,.5,1.5},{0,0,0}, "$_/.");
    Object * cube = createCubeByRotating(5,{0,0.5,-6.25},{0.2,0.5,1.5},{0,0,0}, "$#_/.+P");
    int choice = OpeningDialog();
    std::cout << "\x1b[2J"; // ANSI clearScreen
    switch (choice)
    {
    case 1:
        rotatingObjectDemo(cube);
        rotatingCubeDemo();
        break;
    case 2:
        rotatingObjectDemo(tetrahedron);
        break;
    case 3:
        normalVecTest();
    default:
        break;
    }
    return 0;
}