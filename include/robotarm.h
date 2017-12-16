#ifndef ROBOTARM_H
#define ROBOTARM_H

#include<gmParametricsModule>
#include<memory>

#include "arm.h"
#include "griper.h"

class RobotArm: public GMlib::SceneObject {
    GM_SCENEOBJECT(RobotArm)

public:
    RobotArm(GMlib::Point<float,3> pos= {20.0f,0.0f,0.0f} );
    RobotArm(const RobotArm &copy){}
    virtual ~RobotArm() {}
    //inside functions to plot and set property
    void replot(int m1=20, int m2=20, int d1=1, int d2=1);
    void toggleDefaultVisualizer();
    void insert(GMlib::Scene &scene);
    void setMaterial(const GMlib::Material &m1, const GMlib::Material &m2);
    void getSphPosition();
    std::shared_ptr<GMlib::Visualizer> vis;
    std::shared_ptr<GMlib::PCylinder<float>> getBody(){
        return body;
    }
    std::vector<std::shared_ptr<Arm>> getArm(){
        return arm;
    }
    std::shared_ptr<GMlib::PPlane<float>> getBoard(){
        return board;
    }
    std::shared_ptr<GMlib::PSphere<float>> getSph(){
        return sph;
    }
    std::shared_ptr<GMlib::PCircle<float>> getPlate(){
        return plate;
    }
    std::shared_ptr<GMlib::PLine<float>> getLine(){
        return _ln;
    }

    GMlib::APoint<float,4> get_sph_pos(){ getSphPosition(); return sph_pos;}
    void makeLine(GMlib::Point<float,3> A,GMlib::Point<float,3>B);


protected:
    std::shared_ptr<GMlib::PCylinder<float>> body;
    std::vector<std::shared_ptr<Arm>> arm;
    std::shared_ptr<GMlib::PSphere<float>> sph;
    std::shared_ptr<GMlib::PPlane<float>> board;
    std::shared_ptr<GMlib::PCircle<float>> plate;
    std::shared_ptr<GMlib::PLine<float>> _ln;

private:
    void makeBody(GMlib::Point<float, 3> pos);
    void makeSph(GMlib::Point<float, 3> pos);
    void makeArm(GMlib::Point<float, 3> pos);
    void makeBoard();
    void reArrange();
    void armLinks();
    GMlib::APoint<float,4> sph_pos;

};
#endif // ROBOTARM_H
