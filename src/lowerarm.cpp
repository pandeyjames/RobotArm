#include "lowerarm.h"

LowerArm::LowerArm(GMlib::Vector<float,3> pos){
    // Start values
    _rx = 0.2f;
    _ry = 0.2f;
    _h = 1.5f;
    translateGlobal(pos);
}


LowerArm::LowerArm(float r, float h){

    _rx = r;
    _ry = r;
    _h = h;
}

void LowerArm::setRadius(float r)
{
    _rx = r;
    _ry = r;

}

void LowerArm::setHeight(float h){

    _h = h;
}

float LowerArm::getHeight() {

    return _h;
}
