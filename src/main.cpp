#include <iostream>
#include <math.h>
#include <vector>

#include "./include/Engine.h"

int main(){
    std::cout << "\x1b[2J"; // ANSI clearScreen
    Engine * demo = new Engine();
    demo->initialize();
    while(true){
        demo->loop(50000);
    }

    return 0;
}