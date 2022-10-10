#include "./include/Point.h"
#include <math.h>


    Point::Point(float x,float y,float z):x(x),y(y),z(z){};

    Point::~Point(){};

    void Point::rotatePoint(float roll_step, float yaw_step, float pitch_step){
        x = y*sin(roll_step)*sin(yaw_step)*cos(pitch_step) - z*cos(roll_step)*sin(yaw_step)*cos(pitch_step) + y*cos(roll_step)*sin(pitch_step) + z*sin(roll_step)*sin(pitch_step) + x*cos(yaw_step)*cos(pitch_step);
        y = y*cos(roll_step)*cos(pitch_step) + z*sin(roll_step)*cos(pitch_step) - y*sin(roll_step)*sin(yaw_step)*sin(pitch_step) + z*cos(roll_step)*sin(yaw_step)*sin(pitch_step) - x*cos(yaw_step)*sin(pitch_step); 
        z = z*cos(roll_step)*cos(yaw_step)-y*sin(roll_step)*cos(yaw_step) + x*sin(yaw_step);
    };
    
    void Point::rotate(rotationVector rotation){
        x = y*sin(rotation.roll)*sin(rotation.yaw)*cos(rotation.pitch) - z*cos(rotation.roll)*sin(rotation.yaw)*cos(rotation.pitch) + y*cos(rotation.roll)*sin(rotation.pitch) + z*sin(rotation.roll)*sin(rotation.pitch) + x*cos(rotation.yaw)*cos(rotation.pitch);
        y = y*cos(rotation.roll)*cos(rotation.pitch) + z*sin(rotation.roll)*cos(rotation.pitch) - y*sin(rotation.roll)*sin(rotation.yaw)*sin(rotation.pitch) + z*cos(rotation.roll)*sin(rotation.yaw)*sin(rotation.pitch) - x*cos(rotation.yaw)*sin(rotation.pitch); 
        z = z*cos(rotation.roll)*cos(rotation.yaw)-y*sin(rotation.roll)*cos(rotation.yaw) + x*sin(rotation.yaw);
    };
    
    void Point::move(movementVector velocity){
        x += velocity.x;
        y += velocity.y;
        z += velocity.z; 
    };

    Point * Point::applyAnchorOffset(Point anchor){
        Point * result = new Point (0,0,0);
        result->x = this->x + anchor.x;
        result->y = this->y + anchor.y;
        result->z = this->z + anchor.z;
        return result;
    };