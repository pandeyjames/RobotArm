#include "../include/robotarm.h"
#include <cmath>

RobotArm::RobotArm(GMlib::Point<float, 3> pos){
    makeBody(pos);
    makeArm(pos);
    //makePen(GMlib::Vector<float, 3>(10.2,10.2,21.5));
}

void RobotArm::makeBody(GMlib::Point<float, 3> pos){

    body = std::make_shared<GMlib::PCylinder<float>>(1,2.5,1.5);
}

void RobotArm::makeArm(GMlib::Point<float, 3> pos) {
    for(unsigned int i = 0; i < 1; i++)  arm.push_back(std::make_shared<Arm> (pos, false));
}

//void RobotArm::makePen(GMlib::Point<float, 3> pos)
//{
//    penbody = std::make_shared<GMlib::PCylinder<float>>(0.2,0.2,4.5);
//    pentip = std::make_shared<GMlib::PCone<float>>(0.1,0.5);

//}

void RobotArm::setMaterial(const GMlib::Material &m1,const GMlib::Material &m2){
    body->setMaterial(m1);
    for(unsigned int i = 0; i < arm.size(); i++) {
        arm[i]->setMaterial(m1, m1, m1, m2);
    }
}

void RobotArm::replot(int m1, int m2, int d1, int d2){
    body->replot(m1,m2,d1,d2);
//    penbody->replot(m1,m2,d1,d2);
    for(unsigned int i = 0; i < arm.size(); i++) {
        arm[i]->replot(m1,m2,d1,d2);
    }
//    pentip->replot(m1,m2,d1,d2);
}

void RobotArm::toggleDefaultVisualizer(){
    body->toggleDefaultVisualizer();
    for(unsigned int i = 0; i < arm.size(); i++) {
        arm[i]->toggleDefaultVisualizer();
    }
//    penbody->toggleDefaultVisualizer();
//    pentip->toggleDefaultVisualizer();
}

void RobotArm::insert(GMlib::Scene &scene){

    reArrange();
    armLinks();
    scene.insert(body.get());
    //scene.insert(penbody.get());
}

void RobotArm::reArrange(){
    body->rotate( GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ) );
    body->rotateGlobal( GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
//    penbody->translateGlobal(GMlib::Vector<float,3>(-6.4f, 0.0f, -5.0f ));
//    penbody->rotateGlobal( GMlib::Angle(180), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
//    pentip->rotate(GMlib::Angle(180), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
//    pentip->translate(GMlib::Vector<float,3>(0.0f, 0.0f, 2.7f ));
}

void RobotArm::armLinks(){
    for(unsigned int i = 0; i <arm.size(); i++) {
        body->insert(arm[i]->getJoints()[0].get());
        body->insert((arm[i]->arm_base).get());
//        arm[i]->arm_base->insert(penbody.get());
    }
    //std::cout<<"size= "<<arm.size();
    //body->insert(penbody.get());
//    penbody->insert(pentip.get());
}


void RobotArm::localSimulate(double dt){
    std::cout<<"localsimulate from robotarm";

}

void RobotArm::movePreDef(double dt)
{
//arm[0]->getJoints()[0].get()->rotateGlobal(GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
//arm[0]->replot(100,100,1,1);
}
