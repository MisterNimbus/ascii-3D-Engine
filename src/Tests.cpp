#include "./include/Tests.h"
#include <unistd.h>


// For inspecting the point rotations seperately
void pointRotationDemo1(){
    Point point(1.0f,2.0f,3.0f);
    point.log();
    rotationVector rotationStep = {90.0f,90.0f,90.0f};
    rotationVector rotation = {0.0f,0.0f,0.0f};
    while(true){
        std::cout << "\n\n======== ROLL ========";
        point.rotateRoll(rotationStep.roll);
        rotation.roll += rotationStep.roll;
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        point.log();
        usleep(5000000);
        std::cout << "\n\n======== YAW =========";
        point.rotateYaw(rotationStep.yaw);
        rotation.yaw += rotationStep.yaw;
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        point.log();
        usleep(5000000);
        std::cout << "\n\n======== PITCH =======";
        point.rotatePitch(rotationStep.pitch);
        rotation.pitch += rotationStep.pitch;
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        point.log();
        usleep(5000000);
    }
}

// For inspecting the point rotation
void pointRotationDemo2(){
    Point point(1.0f,2.0f,3.0f);
    point.log();
    rotationVector rotationStep = {90.0f,90.0f,90.0f};
    rotationVector rotation = {0.0f,0.0f,0.0f};
    while(true){
        point.rotate(rotationStep);
        rotation += rotationStep;
        std::cout   << "\nRotation:"
                    << "\n     Pitch: " << rotation.pitch 
                    << "\n      Roll: " << rotation.roll 
                    << "\n       Yaw: " << rotation.yaw;
        
        point.log();
    }
}