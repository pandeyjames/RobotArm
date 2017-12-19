#include "../include/controller.h"
#include "math.h"
#include "../include/scenario.h"
//class Control;
Controller::Controller(){
//auto c=new Control();
}

void Controller::motionrotate()
{


}

void Controller::addRobotArm(std::shared_ptr<RobotArm> robotarm){
    this->robotarm = robotarm;
    body =robotarm->getBody();
    arm = robotarm->getArm();
    sph = robotarm->getSph();
    plate = robotarm->getPlate();


    move_target_positions.push_back(GMlib::Point<float,3>(35,0,10));
    move_target_positions.push_back(GMlib::Point<float,3>(20,-5,6));
    //move_target_positions.push_back(GMlib::Point<float,3>(20,5,10));
    //move_target_positions.push_back(GMlib::Point<float,3>(15,15,10));
    //createSquare(GMlib::Point<float, 3>(10,10,-5),100.0f);
}

void Controller::move_from_A_to_B(GMlib::Point<float, 3> A,GMlib::Point<float, 3> B)
{
    auto c = sph->getPos();

    if(previous_tip_position!=c ){//||c!=GMlib::Point<float, 3>((0),(0),(0))){
        std::cout<<"Sphere Pos "<<c(0)<<","<<c(1)<<","<<c(2)<<std::endl;
        move_target_positions.push_back(GMlib::Vector<float,3>(c));
        previous_tip_position=c;
        IK=false;
    }
    //robotarm->makeLine(A, B);


}

void Controller::createSquare(GMlib::Point<float, 3> p, float len)
{
    if(!sq_created){
        auto A=arm[0]->get_tip_pos();
        float x = p(0);
        float y = p(1);
        float z = p(2);
        float x1 = 0;
        float y1 = 0;
        float z1 = 0;

        for(int i=0; i<len; i++){
            x1=x+i;
            y1=y;
            z1=z;
            move_target_positions.push_back(GMlib::Vector<float,3>(x1,y1,z1));

        }
        x=x1;
        y=y1;
        for(int j=0; j<len; j++){
            x1=x;
            y1=y+j;
            z1=z;
            move_target_positions.push_back(GMlib::Vector<float,3>(x1,y1,z1));

        }
        x=x1;
        y=y1;
        for(int k=0; k<len; k++){
            x1=x-k;
            y1=y1;
            z1=z;
            move_target_positions.push_back(GMlib::Vector<float,3>(x1,y1,z1));
        }
        x=x1;
        y=y1;
        for(int l=0; l<len; l++){
            x1=x;
            y1=y-l;
            z1=z;
            move_target_positions.push_back(GMlib::Vector<float,3>(x1,y1,z1));
        }
        //std::cout<<"Tip Pos "<<A<<std::endl;

        //auto c = robotarm->getBoard()->getCenterPos();
        //            auto c = robotarm->getSph()->getPos();
        //            std::cout<<"Sphere Pos "<<c(0)<<","<<c(1)<<","<<c(2)<<std::endl;
        //            for (int k=0;k<4;k++){
        //                for(int j=0; j<=(int)len; j++){
        //                    //float x=0,y=0,z=0;
        //                    if (k==0)
        //                        move_target_positions.push_back(GMlib::Vector<float,3>((float)(-len/2-c(0)+j),len/2-c(1),c(2)));
        //                    if (k==1)
        //                        move_target_positions.push_back(GMlib::Vector<float,3>((float)((len/2)-c(0)),len/2-c(1)-j,c(2)));
        //                    if (k==2)
        //                        move_target_positions.push_back(GMlib::Vector<float,3>((float)((len/2)-c(0))-j,-len/2-c(1),c(2)));
        //                    if (k==3)
        //                        move_target_positions.push_back(GMlib::Vector<float,3>((float)((-len/2)-c(0)),-len/2-c(1)+j,c(2)));
        //                    //                if (k==0)
        //                    //                    sq_points.push_back(GMlib::Vector<float,3>((float)(c(0)+j),c(1),c(2)));
        //                    //                if (k==1)
        //                    //                    sq_points.push_back(GMlib::Vector<float,3>((float)((c(0),c(1)-j,c(2)))));
        //                    //                if (k==2)
        //                    //                    sq_points.push_back(GMlib::Vector<float,3>((float)((c(0)-j,c(1),c(2)));
        //                    //                if (k==3)
        //                    //                    sq_points.push_back(GMlib::Vector<float,3>((float)((c(0),(c(1)+len/2-j),c(2)));

        //                }

        //            }

        //        }

        //move_target_positions.empty();
        for (int g=0;g<move_target_positions.size();g++){
            //move_target_positions.push_back(sq_points[g]);
            std::cout<<g<<". "<<move_target_positions[g]<<std::endl;
            //move_target_positions[g]=GMlib::Point<float, 3>(0,0,0);
        }

    }
    //sq_created = true;
}
void Controller::createCircle(GMlib::Point<float, 3> c,float r){
    //auto A = arm[0]->get_tip_pos();
    //auto c = robotarm->getSph()->getPos();
for (int i=0;i<360;i++){
    auto x=c(0), y=c(1), z=c(2);
    //auto x1=
    y=sqrt(r*r-x*x);
    move_target_positions[i]=GMlib::Point<float,3> (x,y,z);
}
for (int g=0;g<move_target_positions.size();g++){
    //move_target_positions.push_back(sq_points[g]);
    std::cout<<g<<". "<<move_target_positions[g]<<std::endl;
}
}


void Controller::update_target_positions(GMlib::APoint<float,3> &tip_position, GMlib::Point<float,3> &target_positions){

    //std::cout<<"Tip pos 1 ="<<tip_position<<std::endl;
    previous_tip_position=tip_position;
    float y =0.0f ;
    y = tip_position[1];
    auto l = std::sqrt(tip_position[0]*tip_position[0]+tip_position[1]*tip_position[1]);
    auto x = l * std::sin(std::acos(y/l));
    //for(int i=0;i<move_target_positions.size();i++){
    //std::cout<<"Target Pos "<<target_positions[i]<<std::endl;
    //target_positions  = move_target_positions[i];//robotarm->get_sph_pos();//GMlib::Point<float,3>(x , y ,tip_position[2]);
    tip_position= target_positions;
    arm[0]->tip->editPos(tip_position);
    //std::cout<<"Tip pos 2 ="<<tip_position<<std::endl;
    //}
}

void Controller::checkTargetPositionRange()
{
    //if(tip_position<GMlib::APoint())
    auto r = true;
    targetrange=arm[0]->getRange(tip_position);

}
void Controller::updateAngles(std::vector<GMlib::Angle> &angles,GMlib::Point<float,3> &target_position){

    Angle.clear();
    angles = arm[0]->inverseKinematics(target_position);
    Angle.push_back(angles[0]);
    Angle.push_back(angles[1]);
    Angle.push_back(angles[2]);
    Angle.push_back(angles[3]);
    for(int i=0;i<4;i++){
        std::cout<<"angles ="<<Angle[i]<<" "<<std::endl;
        //    Angle.push_back(angles[1]);
        //    Angle.push_back(angles[2]);
        //    Angle.push_back(angles[3]);
        //std::cout<<"Angles "<<angle;
    }
}


void Controller::localSimulate(double dt) {

    if(reset)
    restart();
    //createSquare(GMlib::Point<float, 3>(10,1,5), 5);
    move_from_A_to_B(previous_tip_position,tip_position);
    if(IK){
        std::cout<<"Run Inverse Kinematics"<<std::endl;
        //createSquare(5);
        //moving=false;
        run_inverse_kinematicts(dt);
        //IK = true;
        //move(dt);

    }



    //run_inverse_kinematicts();


    //    arm[0]->getJoints()[0]->rotateGlobal(Angle[0],(GMlib::Vector<float, 3>(1,0,0)));
    //    pause(4);
    //    arm[0]->getJoints()[1]->rotateGlobal(Angle[1],(GMlib::Vector<float, 3>(0,1,0)));
    //    pause(4);
    //    arm[0]->getJoints()[2]->rotateGlobal(Angle[2],(GMlib::Vector<float, 3>(0,1,0)));
    //    pause(4);
    //if(moving) move(dt);

    //if(turning_left) turn_left(dt);
    //if(turning_right) turn_right(dt);
    //std::cout<<dt;


}

void Controller::run_inverse_kinematicts(double dt){
    tip_position= arm[0]->get_tip_pos();
    //std::cout<<"tip pos " <<tip_position<<std::endl;


    for (int j=0;j<move_target_positions.size();j++){
        update_target_positions(tip_position,move_target_positions[j]);
        updateAngles(Angle,move_target_positions[j]);
        move(dt);

        //std::cout<<"Angle = "<<Angle[k]<<std::endl;
    }
    //moving=true;
    //move_target_positions.clear();
    //}
    //else update_target_positions(tip_position,target_position);
}

void Controller::restart() {
        std::cout<<"Restart !"<<std::endl;
        moving = false;
        IK=false;

        // Reset position
        move_target_positions.clear();
        Angle.clear();
        std::cout<<"Positions and Angles cleared"<<std::endl;
        //        auto pos = GMlib::Point<float,3>(0.0f, 0.0f, 0.0f);
        //        auto dir = GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f);
        //        auto up = GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f);

        //        body->set(pos, dir, up);

        // arm

        arm[0]->getJoints()[0]->rotate((30),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        arm[0]->getJoints()[1]->rotate((30), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        arm[0]->getJoints()[2]->rotate((60),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));

        //        for( unsigned int i = 0; i < arm.size(); i++) {


        //            GMlib::Angle angle1= (arm[i]->getJoints()[0]->getGlobalDir())
        //                    .getAngle(arm[i]->arm_base->getGlobalDir());
        //            GMlib::Angle angle2= (arm[i]->getJoints()[1]->getGlobalDir())
        //                    .getAngle(arm[i]->getJoints()[0]->getGlobalDir());
        //            GMlib::Angle angle3=  (arm[i]->getJoints()[2]->getGlobalDir())
        //                    .getAngle(arm[i]->getJoints()[1]->getGlobalDir());
        //            std::cout<<"Angles "<<angle1<<angle2<<angle3;

        //            GMlib::Angle uAngle = 90;
        //            GMlib::Angle uAngle_r = uAngle.getRad();
        //            GMlib::Angle lAngle = 90;

        //            GMlib::Angle gAngle_degrees = -90;
        //            GMlib::Angle gAngle_radians = gAngle_degrees.getRad();

        //            arm[i]->getJoints()[0]->rotateGlobal((uAngle_r +angle1),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        //            arm[i]->getJoints()[1]->rotateGlobal((-lAngle-angle2 ), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        //            arm[i]->getJoints()[2]->rotateGlobal(((gAngle_radians+angle3)),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));

                   reset = false;
        //        }
}

void Controller::turn_left(double dt){

    reset = false;


    auto var = tick/timespan;

    if(rotate_body_left){
        body->rotateGlobal(0.261799*var/50,GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));   // 0.261799 radians = 15 degrees

    }


}

void Controller::manual_control(int op)
{
    GMlib::Angle angle1= ((arm[0]->getJoints()[0]->getGlobalDir())
            .getAngle(arm[0]->arm_base->getGlobalDir()));
    GMlib::Angle angle2= ((arm[0]->getJoints()[1]->getGlobalDir())
            .getAngle(arm[0]->getJoints()[0]->getGlobalDir()));
    GMlib::Angle angle3=  ((arm[0]->getJoints()[2]->getGlobalDir())
            .getAngle(arm[0]->getJoints()[1]->getGlobalDir()))-6.28319;
    GMlib::Angle angle4 = (arm[0]->getGlobalDir().getAngle(arm[0]->arm_base->getGlobalDir()));
    std::cout<<"angle1="<<angle1<<" angle2="<<angle2<<" angle3="<<angle3<<" angle4="<<angle4<<std::endl;
    switch(op){
    case 1:
        //if((angle4.getRad()+0.0872665)<max_angle.getRad()&& (angle4.getRad()+0.0872665)>min_angle.getRad())
        plate->rotate((angle4.getRad()+0.0174533),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        break;
    case 2:
        //if((angle4.getRad()-0.0872665)<max_angle.getRad()&& (angle4.getRad()-0.0872665)>min_angle.getRad())
        plate->rotate((angle4.getRad()-0.0174533),GMlib::Vector<float,3>(0.0f, 0.0f, -1.0f));
        break;
    case 3:
        arm[0]->getJoints()[0]->rotate((angle1.getRad()+0.0174533),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        break;
    case 4:
        arm[0]->getJoints()[0]->rotate((angle1.getRad()-0.0174533),GMlib::Vector<float,3>(0.0f, 0.0f, -1.0f));
        break;
    case 5:
        arm[0]->getJoints()[1]->rotate((angle2.getRad()+0.0174533),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        break;
    case 6:
        arm[0]->getJoints()[1]->rotate((angle2.getRad()-0.0174533),GMlib::Vector<float,3>(0.0f, 0.0f, -1.0f));
        break;
    case 7:
        arm[0]->getJoints()[2]->rotate((angle3.getRad()+0.0174533),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        break;
    case 8:
        arm[0]->getJoints()[2]->rotate((angle3.getRad()-0.0174533),GMlib::Vector<float,3>(0.0f, 0.0f, -1.0f));
        break;
    default:
        std::cout<<"Can't be controlled manually, simulation is going on"<<std::endl;
    }

}

void Controller::move(double dt)
{
    if(!moving){
        timespan = 0.16;
        auto var = tick/timespan;
        tick+=dt;

        //        GMlib::Angle angle1= ((arm[0]->getJoints()[0]->getGlobalDir())
        //                .getAngle(plate->getGlobalDir()));
        //        GMlib::Angle angle2= ((arm[0]->getJoints()[1]->getGlobalDir())
        //                .getAngle(arm[0]->arm_base->getGlobalDir()));
        //        GMlib::Angle angle3=  ((arm[0]->getJoints()[2]->getGlobalDir())
        //                .getAngle(arm[0]->getJoints()[1]->getGlobalDir()))-6.28319;
        //        GMlib::Angle angle4 = (plate->getGlobalDir().getAngle(arm[0]->arm_base->getGlobalDir()));
        GMlib::Angle angle1= ((arm[0]->getJoints()[0]->getGlobalDir())
                .getAngle(arm[0]->arm_base->getGlobalDir()));
        GMlib::Angle angle2= ((arm[0]->getJoints()[1]->getGlobalDir())
                .getAngle(arm[0]->getJoints()[0]->getGlobalDir()));
        GMlib::Angle angle3=  ((arm[0]->getJoints()[2]->getGlobalDir())
                .getAngle(arm[0]->getJoints()[1]->getGlobalDir()))-6.28319;
        GMlib::Angle angle4 = (arm[0]->getGlobalDir().getAngle(arm[0]->arm_base->getGlobalDir()));
        auto a1 =  Angle[0];
        auto a2 =  Angle[1];
        auto a3 =  Angle[2];
        auto a4 =  Angle[3];
        std::cout<<"angle1="<<angle1<<" angle2="<<angle2<<" angle3="<<angle3<<" angle4="<<angle4<<std::endl;
        std::cout<<" a1 "<<a1<<" a2 "<<a2<<" a3 "<<a3<<" a4 "<<a4<<std::endl;
        bool elbowup;
        std::cout<<"Current = "<<tip_position<<std::endl;
        std::cout<<"Previous = "<<previous_tip_position<<std::endl;
        //sph->editPos(tip_position);
        if((tip_position(0)-previous_tip_position(0)>0)&&(tip_position(2)-previous_tip_position(2)>0))
            elbowup=false;
        else
            elbowup=true;

        if((tip_position(1)-previous_tip_position(1)>0)&&(tip_position(2)-previous_tip_position(2)>0))
            elbowup=true;
        else
            elbowup=false;


        if(elbowup){
            std::cout<<"elbowup= ";
            //arm[0]->getJoints()[0]->rotate((a3.getRad()+A0.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            if (tip_position(1)>0)
            plate->rotate((angle4.getRad()+a4.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[0]->rotate((angle1.getRad()-a1.getRad())*var,GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[1]->rotate(-(a2.getRad()-angle2.getRad())*var,GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
            arm[0]->getJoints()[2]->rotate((a3.getRad()+angle3.getRad())*var,GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
        }
        else{
            std::cout<<"elbowdown= ";
            plate->rotateGlobal((angle4.getRad()-a4.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[0]->rotate((a1.getRad()+angle1.getRad())*var,GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[1]->rotate(-(a2.getRad()-angle2.getRad()*var),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[2]->rotate((a3.getRad()+angle3.getRad())*var,GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
        }
        //turn(dt);
        //createLine(previous_tip_position,tip_position);

        //}
        //}
        tick=0.0f;
    }
}

void Controller::turn(double dt){

    bool elbowright;
    if((previous_tip_position(0)-tip_position(0)>0)||(previous_tip_position(1)-tip_position(1)>0))
        elbowright=true;
    else
        elbowright=false;

    if((previous_tip_position(1)-tip_position(1)>0)||(previous_tip_position(2)-tip_position(2)>0))
        elbowright=true;
    else
        elbowright=false;
    GMlib::Angle angle4 = (arm[0]->getGlobalDir().getAngle(arm[0]->arm_base->getGlobalDir()));
    auto a4= Angle[3];
    if (elbowright)
        plate->rotate((angle4.getRad()-a4.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
    else
        plate->rotateGlobal((angle4.getRad()-a4.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
}

void Controller::createLine(GMlib::Point<float, 3> A, GMlib::Point<float, 3> B)
{
    ln = std::make_shared<GMlib::PLine<float>>(A,B);
    ln->toggleDefaultVisualizer();
    ln->replot(10,1);

}
void Controller::insert(GMlib::Scene &scene){
 scene.insert(ln.get());
}

