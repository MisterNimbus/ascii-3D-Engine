#include "./include/Object.h"

    Object::Object(){};

    void Object::update(Engine * engine, float tick){
        this->mesh.update(engine, tick, velocity, rotationSpeed);
    }

    void Object::draw(Engine * engine){
        this->mesh.draw(engine);
    }