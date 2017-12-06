#ifndef ROBOTARM_H
#define ROBOTARM_H

#include<gmParametricsModule>
#include<memory>

#include "arm.h"
#include "lowerarm.h"
#include "pen.h"

class RobotArm: public GMlib::SceneObject {
    GM_SCENEOBJECT(RobotArm)

public:
    RobotArm(GMlib::Point<float,3> pos= {0.0f,0.0f,0.0f} );
    RobotArm(const RobotArm &copy){}
    virtual ~RobotArm() {}
    //inside functions to plot and set property
    void replot(int m1=20, int m2=20, int d1=1, int d2=1);
    void toggleDefaultVisualizer();
    void insert(GMlib::Scene &scene);
    void setMaterial(const GMlib::Material &m1, const GMlib::Material &m2);
    //predef
    void movePreDef(double dt);
    std::shared_ptr<GMlib::PCylinder<float>> getBody(){
        return body;
    }
    std::vector<std::shared_ptr<Arm>> getArm(){
        return arm;
    }
    std::vector<std::shared_ptr<Pen>> getPen(){
        return pen;
    }
//    std::shared_ptr<GMlib::PCylinder<float>> getPenBody(){
//        return penbody;
//    }
//    std::shared_ptr<GMlib::PCone<float>> getPenTip(){
//        return pentip;
//    }

protected:
    std::shared_ptr<GMlib::PCylinder<float>> body;
//    std::shared_ptr<GMlib::PCylinder<float>> penbody;
//    std::shared_ptr<GMlib::PCone<float>> pentip;
    std::vector<std::shared_ptr<Arm>> arm;
    std::vector<std::shared_ptr<Pen>> pen;

private:
    void localSimulate (double dt) override;
    void makeBody(GMlib::Point<float, 3> pos);
    void makeArm(GMlib::Point<float, 3> pos);
//    void makePen(GMlib::Point<float, 3> pos);
    void reArrange();
    void armLinks();

};


#endif // ROBOTARM_H
