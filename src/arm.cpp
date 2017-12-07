#include "../include/arm.h"

Arm::Arm(GMlib::Point<float, 3> pos, bool orientation){
    makeJoints();
    makeUpperArm();
    makeLowerArm();
    makeGriper();
    makePen(pos);

    arm_base= std::make_shared< GMlib::PSphere<float>>(0.2); //base frame (fixed orientation)
    circle = std::make_shared<GMlib::PCircle<float>>(10.0f);
    tip= std::make_shared< GMlib::PSphere<float>>(0.1); //end effector
    right = orientation; //left or right arm
    reArrangePosition();
    link();
}

void Arm::setMaterial(const GMlib::Material &m1, const GMlib::Material &m2, const GMlib::Material &m3, const GMlib::Material &m4)
{
    for(unsigned int i= 0;i<joints.size();i++){
        joints[i]->setMaterial(m4);
    }
    upperarm->setMaterial(m1);
    lowerarm->setMaterial(m2);
    griper->setMaterial(m3);
    tip->setMaterial(GMlib::GMmaterial::sapphire());
    arm_base->setMaterial(GMlib::GMmaterial::blackRubber());
    circle->setMaterial(GMlib::GMmaterial::blackPlastic());

}

void Arm::replot(int m1, int m2, int d1, int d2)
{
    for(unsigned int i= 0; i < joints.size(); i++){
        joints[i]->replot(m1,m2,d1,d2);
    }
    upperarm->replot(m1,m2,d1,d2);
    lowerarm->replot(m1,m2,d1,d2);
    griper->replot(20,100,1,1);
    arm_base->replot(10,10,1,1);
    penbody->replot(m1,m2,d1,d2);
    pentip->replot(m1,m2,d1,d2);
    tip->replot(10,10,1,1);

    circle->replot(100,1);

}

void Arm::toggleDefaultVisualizer()
{
    for(unsigned int i= 0; i < joints.size(); i++) {
        joints[i]->toggleDefaultVisualizer();

    }
    upperarm->toggleDefaultVisualizer();
    lowerarm->toggleDefaultVisualizer();
    griper->toggleDefaultVisualizer();
    penbody->toggleDefaultVisualizer();
    pentip->toggleDefaultVisualizer();
    arm_base->toggleDefaultVisualizer();
    tip->toggleDefaultVisualizer();
    circle->toggleDefaultVisualizer();
}

void Arm::makeUpperArm()
{
    upperarm = std::make_shared<GMlib::PCylinder<float>>(0.4,0.4,5.0f);
}

void Arm::makeLowerArm()
{
    lowerarm = std::make_shared<GMlib::PCylinder<float>>(0.4f,0.4f,6.0f);

}

void Arm::makeGriper()
{
    griper = std::make_shared<Griper>(0.2f,0.2f);
}

void Arm::makeJoints()
{
    for(unsigned int i =0;i<3;i++){
        joints.push_back( std::make_shared<GMlib::PSphere<float>>(0.5));
    }
}

void Arm::makePen(GMlib::Point<float, 3> pos)
{
    penbody = std::make_shared<GMlib::PCylinder<float>>(0.2,0.2,4.5);
    pentip = std::make_shared<GMlib::PCone<float>>(0.1,0.5);

}

void Arm::reArrangePosition(){

    // Arms and body joints
    //arm_base->translate(GMlib::Vector<float,3>(-5.0f,0.0f,-1.0f));
    joints[0]->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, -3.0f ) );
    //tip->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ) );
    joints[0]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) );
    //arm_base->rotate( GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) );
    joints[0]->translate( GMlib::Vector<float,3>( -1.8f, 0.0f, 0.0f ) );


    // Joint between shoulder and upperarm
    joints[1]->translate( GMlib::Vector<float,3>(-0.4f, 0.0f, 2.5f ) );
    joints[1]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f,0.0f ) );
    upperarm->rotate(GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ));
    lowerarm->translate( GMlib::Vector<float,3>( 2.0f, 0.0f,0.0f ) );

    joints[1]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 1.0f, 0.0f,0.0f ) );
    joints[1]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 0.0f,1.0f ) );
    upperarm->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, 2.5f ) );

    // Joint 1
    joints[1]->translate( GMlib::Vector<float,3>(0.5f, 0.0f, 0.0f ) );
    lowerarm->rotate( GMlib::Angle(-90), GMlib::Vector<float,3>( 0.0f, 1.0f,0.0f ) );
    lowerarm->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, -0.8f ));

    // Joint 2
    joints[2]->translate( GMlib::Vector<float,3>(0.0f, 0.0f, -3.0f ) );
    //joints[2]->rotate( GMlib::Angle(-90), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f ) );
    joints[2]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f,0.0f ) );
    griper->translate( GMlib::Vector<float,3>( 0.6f, 0.0f, 0.0f ));
    griper->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 1.0f, 0.0f,0.0f ) );

    //penbody->translateGlobal(GMlib::Vector<float,3>(0.0f, 0.0f, 0.0f ));
    penbody->rotateGlobal( GMlib::Angle(180), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
    pentip->rotate(GMlib::Angle(180), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
    pentip->translate(GMlib::Vector<float,3>(0.0f, 0.0f, 2.7f ));
    tip->translate(GMlib::Vector<float, 3>(0.0f, 0.0f, 0.4f ));
}

void Arm::link()
{

    for( unsigned int j = 0; j <= 2; j++) {

        if( j % 3 == 2) {
            lowerarm->insert( joints[j].get() );
            joints[j]->insert( griper.get() );
        }
        else if( j % 3 == 1) {
            upperarm->insert( joints[j].get() );
            joints[j]->insert( lowerarm.get() );

        }
        else joints[j]->insert( upperarm.get() );
    }
    griper->insert(penbody.get());
    pentip->insert(tip.get());
    penbody->insert(pentip.get());
}

IKAngles Arm::inverseKinematics(GMlib::Point<float, 3> targetPosition){

    auto uHeight = upperarm->getHeight();
    auto lHeight = lowerarm->getHeight();
    auto gHeight = griper->getHeight()*2;
    //auto ph = penbody->getHeight();
    auto z0 =  targetPosition(2) ;
    auto l1= std::sqrt((targetPosition(0)) * (targetPosition(0)) + (targetPosition(1)) * (targetPosition(1)) );
    auto l2= (targetPosition(0)) * (targetPosition(0)) + (targetPosition(1)) * (targetPosition(1));
    auto r= l1-uHeight;
    auto l = z0 *z0  +  r*r;
    auto uAngle = (std::acos(uHeight*uHeight+l2-lHeight*lHeight)/2*uHeight*l1)+(std::acos(targetPosition(1))/l1);
    auto lAngle = 180-acos(uHeight*uHeight+lHeight*lHeight -l2)/2*uHeight*lHeight;
    auto gAngle = std::atan2(targetPosition(1),targetPosition(0));
    auto angles = IKAngles(uAngle, lAngle, gAngle);
    std::cout<<uAngle<<lAngle<<gAngle;
    return angles;
}

std::vector<std::shared_ptr<GMlib::PSphere<float> > > Arm::getJoints()
{
    return joints;
}


std::shared_ptr<GMlib::PCylinder<float> > Arm::getLowerArm()
{
    return lowerarm;
}


std::shared_ptr<GMlib::PCylinder<float>>Arm::getUpperArm()
{
    return upperarm;
}


std::shared_ptr<Griper> Arm::getGriper()
{
    return griper;
}

std::shared_ptr<GMlib::PSphere<float> > Arm::getArmBase(){
    return arm_base;
}

void Arm::update_tip_position(){


    auto present = arm_base->getMatrixGlobal();
    auto tip_global_pos = tip->getGlobalPos();

    auto present_inverted = present;
    present_inverted.invertOrthoNormal(); //scene to base

    tip_base_pos = present_inverted * (tip_global_pos);
}
