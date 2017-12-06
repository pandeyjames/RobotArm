#include "../include/arm.h"

Arm::Arm(GMlib::Point<float, 3> pos, bool orientation){
    makeJoints();
    makeShoulder();
    makeUpperArm();
    makeLowerArm();
    makePen(pos);

    arm_base= std::make_shared< GMlib::PSphere<float>>(0.5); //base frame (fixed orientation)
    circle = std::make_shared<GMlib::PCircle<float>>(10.0f);
    tip= std::make_shared< GMlib::PSphere<float>>(0.02); //end effector
    right = orientation; //left or right arm
    reArrangePosition();
    link();
}

void Arm::setMaterial(const GMlib::Material &m1, const GMlib::Material &m2, const GMlib::Material &m3, const GMlib::Material &m4)
{
    for(unsigned int i= 0;i<joints.size();i++){
        joints[i]->setMaterial(m4);
    }
    shoulder->setMaterial(m1);
    upperarm->setMaterial(m2);
    lowerarm->setMaterial(m3);
    tip->setMaterial(GMlib::GMmaterial::sapphire());
    arm_base->setMaterial(GMlib::GMmaterial::blackRubber());
    circle->setMaterial(GMlib::GMmaterial::blackPlastic());

}

void Arm::replot(int m1, int m2, int d1, int d2)
{

    //... joints...
    for(unsigned int i= 0; i < joints.size(); i++){
        joints[i]->replot(m1,m2,d1,d2);
    }

    //  ... and arms
    shoulder->replot(m1,m2,d1,d2);
    upperarm->replot(m1,m2,d1,d2);
    lowerarm->replot(20,100,1,1);
    arm_base->replot(10,10,1,1);
    penbody->replot(m1,m2,d1,d2);
    pentip->replot(m1,m2,d1,d2);
    tip->replot(10,10,1,1);
    circle->replot(100,1);

}

void Arm::toggleDefaultVisualizer()
{
    // ... joints...
    for(unsigned int i= 0; i < joints.size(); i++) {
        joints[i]->toggleDefaultVisualizer();

    }
    shoulder->toggleDefaultVisualizer();
    upperarm->toggleDefaultVisualizer();
    lowerarm->toggleDefaultVisualizer();
    penbody->toggleDefaultVisualizer();
    pentip->toggleDefaultVisualizer();
    arm_base->toggleDefaultVisualizer();
    tip->toggleDefaultVisualizer();
    circle->toggleDefaultVisualizer();


}

void Arm::makeShoulder()
{
    shoulder = std::make_shared<GMlib::PCylinder<float>>(0.4,0.4,5.0f);
}

void Arm::makeUpperArm()
{
    upperarm = std::make_shared<GMlib::PCylinder<float>>(0.4f,0.4f,6.0f);

}

void Arm::makeLowerArm()
{
    lowerarm = std::make_shared<LowerArm>(0.2f,0.2f);
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
    arm_base->translate(GMlib::Vector<float,3>(0.0f,0.0f,-1.0f));
    joints[0]->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, -3.0f ) );
    //tip->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ) );
    joints[0]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) );
    arm_base->rotate( GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) );
    joints[0]->translate( GMlib::Vector<float,3>( -1.8f, 0.0f, 0.0f ) );


    // Joint between shoulder and upperarm
    joints[1]->translate( GMlib::Vector<float,3>(-0.4f, 0.0f, 2.5f ) );
    joints[1]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f,0.0f ) );
    shoulder->rotate(GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ));
    upperarm->translate( GMlib::Vector<float,3>( 2.0f, 0.0f,0.0f ) );

    joints[1]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 1.0f, 0.0f,0.0f ) );
    joints[1]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 0.0f,1.0f ) );
    shoulder->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, 2.5f ) );

    // Joint 1
    joints[1]->translate( GMlib::Vector<float,3>(0.5f, 0.0f, 0.0f ) );
    upperarm->rotate( GMlib::Angle(-90), GMlib::Vector<float,3>( 0.0f, 1.0f,0.0f ) );
    upperarm->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, -0.8f ));

    // Joint 2
    joints[2]->translate( GMlib::Vector<float,3>(0.0f, 0.0f, -3.0f ) );
    //joints[2]->rotate( GMlib::Angle(-90), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f ) );
    joints[2]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f,0.0f ) );
    lowerarm->translate( GMlib::Vector<float,3>( 0.6f, 0.0f, 0.0f ));
    lowerarm->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 1.0f, 0.0f,0.0f ) );

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
            upperarm->insert( joints[j].get() );
            joints[j]->insert( lowerarm.get() );
        }
        else if( j % 3 == 1) {
            shoulder->insert( joints[j].get() );
            joints[j]->insert( upperarm.get() );

        }
        else joints[j]->insert( shoulder.get() );
    }
    lowerarm->insert(penbody.get());
    pentip->insert(tip.get());
    penbody->insert(pentip.get());
    //body->insert(circle.get());
}

IKAngles Arm::inverseKinematics(GMlib::Point<float, 3> targetPosition){

    auto sHeight = shoulder->getHeight();
    auto uHeight = upperarm->getHeight();
    auto lHeight = lowerarm->getHeight()*2;
    auto z0 =  targetPosition(2) ;
    auto l1= std::sqrt((targetPosition(0)) * (targetPosition(0)) + (targetPosition(1)) * (targetPosition(1)) );
    auto r= l1-sHeight;
    auto l = z0 *z0  +  r*r;

    auto sAngle = std::atan2(targetPosition(1),targetPosition(0));
    auto lAngle =  6.28319 - std::acos((l-uHeight*uHeight-lHeight*lHeight)/(2*uHeight*lHeight));
    auto uAngle =  std::atan2(r,z0)-std::atan2(uHeight+lHeight*std::cos(lAngle), lHeight* std::sin(lAngle) );

    auto angles = IKAngles(sAngle, uAngle, lAngle);
    return angles;
}

std::vector<std::shared_ptr<GMlib::PSphere<float> > > Arm::getJoints()
{
    return joints;
}


std::shared_ptr<GMlib::PCylinder<float> > Arm::getShoulder()
{
    return shoulder;
}


std::shared_ptr<GMlib::PCylinder<float>>Arm::getUpperArm()
{
    return upperarm;
}


std::shared_ptr<LowerArm> Arm::getLowerArm()
{
    return lowerarm;
}

void Arm::update_tip_position(){

    auto present = arm_base->getMatrixGlobal();
    auto tip_global_pos = tip->getGlobalPos();

    auto present_inverted = present;
    present_inverted.invertOrthoNormal(); //scene to base

    tip_base_pos = present_inverted * (tip_global_pos);
}
