#include "./include/Object.h"

    Object::Object(){};

    void Object::update(Engine * engine, float tick, char surfaceChar){
        mesh.update(engine, tick, velocity, rotation, surfaceChar);
    }