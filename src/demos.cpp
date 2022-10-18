#include "include/Engine.h"
#include "include/Object.h"
#include "include/objectRecipes.h"

void rotatingCubeDemo(){
    std::cout << "\x1b[2J"; // ANSI clearScreen

    Engine * demo = new Engine();

    demo->initialize(0.1f, 100.0f, 3.0f);
    
    Object * cube = createCubeByRotating(10,{0,0,-15},{0,0.5,1},{0,0,0});
    demo->addObject(cube);

    
    while(1){
        demo->loop(5000, true, true);
    }
}

void rotatingObjectDemo(Object * object){
    std::cout << "\x1b[2J"; // ANSI clearScreen

    Engine * demo = new Engine();

    demo->initialize(0.1f, 100.0f, 3.0f);
    
    demo->addObject(object);
    
    while(1){
        demo->loop(5000, true, true);
    }
    
}