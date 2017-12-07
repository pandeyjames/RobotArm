#ifndef GRIPER_H
#define GRIPER_H

#include<gmParametricsModule>
#include<memory>


class Griper: public GMlib::PCylinder<float>{

public:
    Griper(GMlib::Vector<float,3> pos = GMlib::Point<float,3>(0.0f,0.0f,0.0f));
    Griper(float r, float h);
    void setRadius(float);
    void setHeight(float);
    float getHeight();

};


#endif // GRIPER_H
