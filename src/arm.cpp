#include "../include/arm.h"

Arm::Arm(GMlib::Point<float, 3> pos, bool orientation){
    makeJoints();
    makeUpperArm();
    makeLowerArm();
    makeGriper();
    makePen(pos);

    arm_base= std::make_shared< GMlib::PSphere<float>>(0.2); //base frame (fixed orientation)
    tip= std::make_shared< GMlib::PSphere<float>>(0.2); //end effector
    right = orientation; //left or right arm
    reArrangePosition();
    link();
}

void Arm::setMaterial(const GMlib::Material &m1, const GMlib::Material &m2, const GMlib::Material &m3, const GMlib::Material &m4)
{
    //for(unsigned int i= 0;i<joints.size();i++){
    //   joints[i]->setMaterial(m4);
    //}
    upperarm->setMaterial(m1);
    lowerarm->setMaterial(m2);
    griper->setMaterial(m3);
    tip->setMaterial(GMlib::GMmaterial::sapphire());
    arm_base->setMaterial(GMlib::GMmaterial::blackRubber());

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

}

void Arm::toggleDefaultVisualizer()
{
    for(unsigned int i= 0; i < 3; i++) {
        joints[i]->toggleDefaultVisualizer();


    }
    upperarm->toggleDefaultVisualizer();
    lowerarm->toggleDefaultVisualizer();
    griper->toggleDefaultVisualizer();
    penbody->toggleDefaultVisualizer();
    pentip->toggleDefaultVisualizer();
    arm_base->toggleDefaultVisualizer();
    tip->toggleDefaultVisualizer();
}

void Arm::makeUpperArm()
{
    upperarm = std::make_shared<GMlib::PCylinder<float>>(0.8,0.8,18.0f);
}

void Arm::makeLowerArm()
{
    lowerarm = std::make_shared<GMlib::PCylinder<float>>(0.8f,0.8f,12.0f);

}

void Arm::makeGriper()
{
    griper = std::make_shared<Griper>(0.2f,4.5f);
}

void Arm::makeJoints()
{
    for(unsigned int i =0;i<3;i++){
        joints.push_back( std::make_shared<GMlib::PSphere<float>>(0.5));
    }
    for(unsigned int i =0;i<3;i++){
        auto x = new GMlib::PLine<float>(joints[i]->getPos(), joints[i]->getDir());
        auto y = new GMlib::PLine<float>(joints[i]->getPos(), joints[i]->getSide());
        auto z = new GMlib::PLine<float>(joints[i]->getPos(), joints[i]->getUp());
        x->setColor(GMlib::GMcolor::red());
        y->setColor(GMlib::GMcolor::green());
        z->setColor(GMlib::GMcolor::blue());
        x->toggleDefaultVisualizer();
        y->toggleDefaultVisualizer();
        z->toggleDefaultVisualizer();
        x->replot(100,1);
        y->replot(100,1);
        z->replot(100,1);
        joints[i]->insert(x);
        joints[i]->insert(y);
        joints[i]->insert(z);
        joints[0]->setMaterial(GMlib::GMmaterial::blackRubber());
        joints[1]->setMaterial(GMlib::GMmaterial::gold());
        joints[2]->setMaterial(GMlib::GMmaterial::jade());

    }

}

void Arm::makePen(GMlib::Point<float, 3> pos)
{
    penbody = std::make_shared<GMlib::PCylinder<float>>(0.2,0.2,4.5);
    pentip = std::make_shared<GMlib::PCone<float>>(0.1,0.5);

}

void Arm::checkPosition(GMlib::Point<float, 3> pos)
{
    float x=pos(0);
    float y=pos(1);
    float z=pos(2);
    auto uHeight = upperarm->getHeight();
    auto lHeight = lowerarm->getHeight();
    auto gHeight = griper->getHeight()*2;
    auto r=0.0f;
    if ((x<=3+uHeight+lHeight && x<=5)&& (z<=(3+uHeight+lHeight)&& z>=5)&&(y<=(3+uHeight+lHeight)&& y>=-(3+uHeight+lHeight))){

        if (r == sqrt(x*x+y*y+z*z))
        {
            std::cout<<"Inside Range"<<std::endl;
            range=true;
        }
    }
    else
        range=false;

}

void Arm::reArrangePosition(){

    // Arms and body joints
    //arm_base->translate(GMlib::Vector<float,3>(-5.0f,0.0f,-1.0f));
    //arm_base->rotate( GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) );
    joints[0]->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, 4.0f ) );
    joints[0]->rotate(GMlib::Angle(-30), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) ); //base joint exact rot v0=30

    joints[0]->rotate(GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) ); //v1
    joints[0]->rotate(GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f ) );
    joints[0]->rotate(GMlib::Angle(-90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) );

    //    joints[0]->rotate(GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ) );
    //    joints[0]->rotate(GMlib::Angle(90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) );


    upperarm->rotate(GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));
    upperarm->translate( GMlib::Vector<float,3>( 0.0f, 0.0f, -10.0f ) );


    // Joint between lowerarm and upperarm
    joints[1]->translate( GMlib::Vector<float,3>(0.0f, 0.0f, -10.0f ) );
    joints[1]->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f, 0.0f ) );
    joints[1]->rotate(GMlib::Angle(-90), GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f ) );
    joints[1]->rotate(GMlib::Angle(-90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ) );
    joints[1]->rotate(GMlib::Angle(-60), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f ) );//V2
    lowerarm->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f,0.0f ) );

    lowerarm->translate( GMlib::Vector<float,3>( 0.0f, 0.0f,6.0f ) );


    // Joint 2

    joints[2]->rotate( GMlib::Angle(-90), GMlib::Vector<float,3>( 0.0f, 1.0f, 0.0f ) );
    //joints[2]->rotate( GMlib::Angle(60), GMlib::Vector<float,3>( 0.0f, 0.0f, 0.0f ) );//v3
    joints[2]->translate( GMlib::Vector<float,3>(6.0f, 0.0f, 0.0f ) );
    //griper->translate( GMlib::Vector<float,3>( -2.0f, 0.0f, 0.0f ));
    griper->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 1.0f, 0.0f,0.0f ) );
    //griper->rotate( GMlib::Angle(180), GMlib::Vector<float,3>( 0.0f, 1.0f,0.0f ) );
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

std::vector<GMlib::Angle> Arm::inverseKinematics(GMlib::Point<float, 3> targetPosition){

    //    auto uHeight = upperarm->getHeight();
    //    auto lHeight = lowerarm->getHeight();
    //    auto gHeight = penbody->getHeight()/2+0.5;//*2;
    //    //std::cout<<"uHeight = "<<uHeight<<" lHeight"<<lHeight<<" gHeight="<<gHeight<<std::endl;
    //    //auto ph = penbody->getHeight();
    //    auto z0 =  targetPosition(2) ;
    //    auto l1= std::sqrt((targetPosition(0)) * (targetPosition(0)) + (targetPosition(1)) * (targetPosition(1)) );
    //    auto l2= (targetPosition(0)) * (targetPosition(0)) + (targetPosition(1)) * (targetPosition(1));
    //    auto r= l1-uHeight;
    //    auto l = z0 *z0  +  r*r;


    //    auto A0 = std::atan2(targetPosition(1),targetPosition(0));

    //    auto A2 =  6.28319 - std::acos((l-lHeight*lHeight-gHeight*gHeight)/(2*lHeight*gHeight));

    //    //auto A2 = 3.1415-(std::acos(l2-uHeight*uHeight-lHeight*lHeight)/2*uHeight*lHeight);
    //    auto A1 =  std::atan2(r,z0)-std::atan2(lHeight+gHeight*std::cos(A2), gHeight* std::sin(A2) );

    //    auto A3 = (std::acos(uHeight*uHeight+l2-lHeight*lHeight)/2*uHeight*l1)+(std::acos(targetPosition(1))/l1);
    checkPosition(targetPosition);

    //Help from Ghada
    if(!range){
    auto uHeight = upperarm->getHeight();
    auto lHeight = lowerarm->getHeight();
    auto gHeight = griper->getHeight()*2;
    auto z0 =  targetPosition(2) ;
    auto l1= std::sqrt((targetPosition(0)) * (targetPosition(0)) + (targetPosition(1)) * (targetPosition(1)) );
    auto r= l1-uHeight;
    auto l = z0 *z0  +  r*r;
    auto bAngle =std::atan2(targetPosition(1),targetPosition(0));
    auto uAngle1 = std::atan2(targetPosition(2),targetPosition(0));
    auto gAngle =  6.28319 - std::acos((l-lHeight*lHeight-gHeight*gHeight)/(2*lHeight*gHeight));
    auto lAngle =  std::atan2(r,z0)-std::atan2(lHeight+gHeight*std::cos(gAngle), gHeight* std::sin(gAngle) );
    auto k1 = uHeight+lHeight*cos(lAngle);
    auto k2 = lHeight*sin(lAngle);
    auto uAngle = uAngle1-std::atan2(k2,k1);
    std::cout<<"uHeight = "<<uHeight<<" lHeight"<<lHeight<<" gHeight="<<gHeight<<std::endl;
    Angle.clear();
    Angle.push_back(uAngle);
    Angle.push_back(lAngle);
    Angle.push_back(lAngle);
    Angle.push_back(bAngle);
    return Angle;
}

//    auto l1 = upperarm->getHeight();
//    auto l2 = lowerarm->getHeight();
//    auto l3 = griper->getHeight()*2;
//    auto z =  targetPosition(2) ;
//    auto x = targetPosition(0);
//    auto y = targetPosition(1);
//    auto v0=std::atan2(y,x);
//    auto h=sqrt(x*x+z*z);
//    auto v11=std::atan2(z,x);
//    auto v2=acos((-(h*h)+(l2+l3)*(l2+l3)+l1*l1)/2*l1*(l2+l3));
//    auto v12=v11+std::acos((h*h)-(l2+l3)*(l2+l3)+(l1*l1)/2*l1*h);
//    auto v1=v11+v12;
//    auto v3=std::atan2()
//    auto l1= std::sqrt((targetPosition(0)) * (targetPosition(0)) + (targetPosition(1)) * (targetPosition(1)) );
//    auto r= l1-uHeight;
//    auto l = z0 *z0  +  r*r;
//    auto u0 =std::atan2(targetPosition(2),targetPosition(0));
//    auto uAngle = std::atan2(targetPosition(1),targetPosition(0));
//    auto gAngle =  6.28319 - std::acos((l-lHeight*lHeight-gHeight*gHeight)/(2*lHeight*gHeight));
//    auto lAngle =  std::atan2(r,z0)-std::atan2(lHeight+gHeight*std::cos(gAngle), gHeight* std::sin(gAngle) );
    //Angle.push_back(A3);
    //std::cout<<"Angle= "<<Angle[0]<<"    "<<Angle[1]<<"    "<<Angle[2]<<std::endl;

    // }
//        else {
//            Angle[0]=GMlib::Angle(0);
//            Angle[1]=GMlib::Angle(0);
//            Angle[2]=GMlib::Angle(0);
//            Angle[3]=GMlib::Angle(0);
//            return Angle;
//    }
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
