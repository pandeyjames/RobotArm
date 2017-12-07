#ifndef ROBOTARM_H
#define ROBOTARM_H

#include<gmParametricsModule>
#include<memory>

#include "arm.h"
#include "griper.h"
#include "pen.h"

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
    std::shared_ptr<GMlib::PPlane<float>> getBoard(){
        return board;
    }
    std::shared_ptr<GMlib::PSphere<float>> getSph(){
        return sph;
    }
    GMlib::APoint<float,4> get_base_pos(){ getBoardPosition(); return board_base_pos;}

protected:
    std::shared_ptr<GMlib::PCylinder<float>> body;
    std::vector<std::shared_ptr<Arm>> arm;
    std::vector<std::shared_ptr<Pen>> pen;
    std::shared_ptr<GMlib::PSphere<float>> sph;
    std::shared_ptr<GMlib::PPlane<float>> board;

private:
    void localSimulate (double dt) override;
    void makeBody(GMlib::Point<float, 3> pos);
    void makeSph(GMlib::Point<float, 3> pos);
    void makeArm(GMlib::Point<float, 3> pos);
    void makeBoard();
    void reArrange();
    void getBoardPosition();
    void armLinks();
    GMlib::APoint<float,4> board_base_pos;

};
#endif // ROBOTARM_H
