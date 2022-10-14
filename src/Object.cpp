#include "./include/Object.h"

    Object::Object(){};

    void Object::update(Engine * engine, float tick){
        mesh.update(engine, tick, velocity, rotation);
    }