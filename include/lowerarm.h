#ifndef LOWERARM_H
#define LOWERARM_H

#include<gmParametricsModule>
#include<memory>


class LowerArm: public GMlib::PCylinder<float>{

public:
    LowerArm(GMlib::Vector<float,3> pos = GMlib::Point<float,3>(0.0f,0.0f,0.0f));
    LowerArm(float r, float h);
    void setRadius(float);
    void setHeight(float);
    float getHeight();

};


#endif // LOWERARM_H
