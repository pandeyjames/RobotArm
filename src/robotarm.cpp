#include "../include/robotarm.h"
#include <cmath>

RobotArm::RobotArm(GMlib::Point<float, 3> pos){
    makeBody(pos);
    makeArm(pos);
    makeBoard();
    makeSph(pos);

}

void RobotArm::makeBody(GMlib::Point<float, 3> pos){

    body = std::make_shared<GMlib::PCylinder<float>>(1,2.5,1.5);
}

void RobotArm::makeSph(GMlib::Point<float, 3> pos){
    sph = std::make_shared<GMlib::PSphere<float>>(0.5f);
}

void RobotArm::makeArm(GMlib::Point<float, 3> pos) {
    for(unsigned int i = 0; i < 1; i++)  arm.push_back(std::make_shared<Arm> (pos, false));
}


void RobotArm::setMaterial(const GMlib::Material &m1,const GMlib::Material &m2){
    body->setMaterial(m1);
    for(unsigned int i = 0; i < arm.size(); i++) {
        arm[i]->setMaterial(m1, m1, m1, m2);
    }
}

void RobotArm::replot(int m1, int m2, int d1, int d2){
    body->replot(m1,m2,d1,d2);
    for(unsigned int i = 0; i < arm.size(); i++) {
        arm[i]->replot(m1,m2,d1,d2);
    }
    board->replot(m1,m2,d1,d2);
    sph->replot(10,10,1,1);;
}

void RobotArm::toggleDefaultVisualizer(){
    body->toggleDefaultVisualizer();
    for(unsigned int i = 0; i < arm.size(); i++) {
        arm[i]->toggleDefaultVisualizer();
    }
    sph->toggleDefaultVisualizer();
    board->toggleDefaultVisualizer();
}

void RobotArm::insert(GMlib::Scene &scene){

    reArrange();
    armLinks();
    scene.insert(body.get());
    scene.insert(board.get());
    scene.insert(sph.get());
}

void RobotArm::reArrange(){
    body->rotate( GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ) );
    body->rotateGlobal( GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
    //body->translate(GMlib::Vector<float,3>(-1.0f, 0.0f, 0.0f ));
    sph->translate(GMlib::Vector<float,3>(-7,0,1));
}

void RobotArm::getBoardPosition()
{
    auto present = sph->getMatrixGlobal();
    auto sph_global = sph->getGlobalPos();

    auto present_inverted = present;
    present_inverted.invertOrthoNormal(); //scene to base

    board_base_pos = present_inverted*sph_global;
}

void RobotArm::armLinks(){
    for(unsigned int i = 0; i <arm.size(); i++) {
        body->insert(arm[i]->getJoints()[0].get());
        body->insert((arm[i]->arm_base).get());
    }
    //body->insert(sph.get());
}

void RobotArm::makeBoard()
{
    board = std::make_shared<GMlib::PPlane<float>> (
                      GMlib::Point<float, 3> (-16.0f,-5.0f,1.0f),
                      GMlib::Vector<float, 3>(14.0f,0.0f,0.0f),
                      GMlib::Vector<float, 3>(0.0f,10.0f,0.0f));
    board->setMaterial(GMlib::Material(1,0,0));
}

void RobotArm::localSimulate(double dt){
    std::cout<<"localsimulate from robotarm";

}

void RobotArm::movePreDef(double dt)
{
//arm[0]->getJoints()[0].get()->rotateGlobal(GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
//arm[0]->replot(100,100,1,1);
}
