#include "griper.h"

Griper::Griper(GMlib::Vector<float,3> pos){
    // Start values
    _rx = 0.2f;
    _ry = 0.2f;
    _h = 4.5f;
    translateGlobal(pos);
}


Griper::Griper(float r, float h){

    _rx = r;
    _ry = r;
    _h = h;
}

void Griper::setRadius(float r)
{
    _rx = r;
    _ry = r;

}

void Griper::setHeight(float h){

    _h = h;
}

float Griper::getHeight() {

    return _h;
}
