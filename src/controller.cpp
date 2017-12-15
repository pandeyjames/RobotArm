#include "controller.h"
#include "math.h"

Controller::Controller(){

}

void Controller::motionrotate()
{


}

void Controller::addRobotArm(std::shared_ptr<RobotArm> robotarm){
    this->robotarm = robotarm;
    body =robotarm->getBody();
    arm = robotarm->getArm();
    sph = robotarm->getSph();
    circle = robotarm->getCircle();


    move_target_positions.push_back(GMlib::Point<float,3>(35,0,0));
    move_target_positions.push_back(GMlib::Point<float,3>(20,-5,1));
    //move_target_positions.push_back(GMlib::Point<float,3>(20,5,10));
    //move_target_positions.push_back(GMlib::Point<float,3>(15,15,10));
    //createSquare(GMlib::Point<float>(10,10,-5),10.0f);
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
        }

    }
    sq_created = true;
}
void Controller::createCircle(GMlib::Point<float, 3> c,float r){
    auto A = arm[0]->get_tip_pos();
    //auto c = robotarm->getSph()->getPos();
    auto x=0.0f, y=0.0f, z=c(2);
    for(int i=0; i<M_2PI; i++){
        x = r*cos(i);
        y = r*sin(i);
        move_target_positions.push_back(GMlib::Vector<float,3>(x,y,z));
        std::cout<<move_target_positions[i]<<std::endl;
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
    target_pos=arm[0]->getRange(tip_position);
}
void Controller::updateAngles(std::vector<GMlib::Angle> &angles,GMlib::Point<float,3> &target_position){
    //for(int i=0;i<target_positions.size();i++){
    angles = arm[0]->inverseKinematics(target_position);
    Angle.push_back(angles[0]);
    Angle.push_back(angles[1]);
    Angle.push_back(angles[2]);
    Angle.push_back(angles[3]);
    //std::cout<<"Angles "<<angle;
    //}
}


void Controller::localSimulate(double dt) {

    //restart();
    //createSquare(GMlib::Point<float, 3>(10,1,5), 5);
    move_from_A_to_B(previous_tip_position,tip_position);
    if(IK){
        std::cout<<"Run Inverse Kinematics"<<std::endl;
        //createSquare(5);
        run_inverse_kinematicts(dt);
        //IK = true;
        move(dt);

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
    //robotarm->movePreDef(dt);


}

void Controller::run_inverse_kinematicts(double dt){
    tip_position=   arm[0]->get_tip_pos();
    //std::cout<<"tip pos " <<tip_position<<std::endl;
    //if(!move_target_positions.empty()){
    for (int j=0;j<move_target_positions.size();j++){
        update_target_positions(tip_position,move_target_positions[j]);
        updateAngles(Angle,move_target_positions[j]);

        //std::cout<<"Angle = "<<Angle[k]<<std::endl;
    }
    //}
    //else update_target_positions(tip_position,target_position);
}

void Controller::restart() {

    if(!reset) {
        std::cout<<"Restart !"<<std::endl;
        moving = false;

        // Reset position
        auto pos = GMlib::Point<float,3>(0.0f, 0.0f, 0.0f);
        auto dir = GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f);
        auto up = GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f);

        body->set(pos, dir, up);

        // arm
        arm[0]->getJoints()[0]->rotateGlobal((10),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        arm[0]->getJoints()[1]->rotateGlobal((30), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        arm[0]->getJoints()[2]->rotateGlobal((60),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
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

        //            reset = true;
        //        }
        reset=true;
    }
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
    switch(op){
    case 1:
        turn_left(0.016);
        break;
    case  2:
        turn_right(0.016);
        break;
    case 3:

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

        GMlib::Angle angle1= ((arm[0]->getJoints()[0]->getGlobalDir())
                .getAngle(arm[0]->arm_base->getGlobalDir()));
        GMlib::Angle angle2= ((arm[0]->getJoints()[1]->getGlobalDir())
                .getAngle(arm[0]->getJoints()[0]->getGlobalDir()));
        GMlib::Angle angle3=  ((arm[0]->getJoints()[2]->getGlobalDir())
                .getAngle(arm[0]->getJoints()[1]->getGlobalDir()));
        GMlib::Angle A0= std::atan2(previous_tip_position(1),previous_tip_position(0));
        auto a0 =  Angle[0];
        auto a1 =  Angle[1];
        auto a2 =  Angle[2];
        auto a3 =  Angle[3];
        std::cout<<"angle1="<<angle1<<" angle2="<<angle2<<" angle3="<<angle3<<" angle0="<<A0<<std::endl;
        std::cout<<"a0="<<a0<<" a1 "<<a1<<" a2 "<<a2<<" a3 "<<a3<<std::endl;
        ///arm[0]->getJoints()[0]->rotate((a0-A0.getRad()),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        //if(a0>A0){
        //            if (tip_position(1)>0){
        //                if(a0.getRad()>0 and A0.getRad()<=max_angle.getRad()){
        //                    arm[0]->getJoints()[0]->rotate((a0+A0.getRad()),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        //                }
        //                else if (a0.getRad()<0 and a0.getRad()>=min_angle.getRad()){
        //                    arm[0]->getJoints()[0]->rotate((a0-A0.getRad()),GMlib::Vector<float,3>(0.0f, 0.0f, -1.0f));
        //                }
        //            }//

        //            //else if(a0<A0){
        //            if(tip_position(1)<0){
        //                if(a0.getRad()>0 and a0.getRad()<max_angle.getRad()){
        //                    arm[0]->getJoints()[0]->rotate((A0.getRad()-a0.getRad()),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        //                }
        //                else if (a0.getRad()<0 and a0.getRad()>min_angle.getRad()){
        //                    arm[0]->getJoints()[0]->rotate((a0-A0.getRad()),GMlib::Vector<float,3>(0.0f, 0.0f, -1.0f));
        //                }
        //            }

        //            //            legs[i]->getJoints()[0]->rotate((coxaAngle -angle1)*var,GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        //            //            legs[i]->getJoints()[1]->rotate((-femurAngle-angle2 )*var, GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        //            //            legs[i]->getJoints()[2]->rotate(((tibiaAngle+angle3))*var,GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
        //if(target_pos){


        bool elbowup,elbowright;
        std::cout<<"Current = "<<tip_position<<std::endl;
        std::cout<<"Previous = "<<previous_tip_position<<std::endl;
        //sph->editPos(tip_position);
        if((previous_tip_position(0)-tip_position(0)>0)||(previous_tip_position(2)-tip_position(2)>0))
            elbowup=true;
        else
            elbowup=false;

        if((previous_tip_position(1)-tip_position(1)>0)||(previous_tip_position(2)-tip_position(2)>0))
            elbowup=true;
        else
            elbowup=false;


        if(elbowup){
            std::cout<<"elbowup= ";
            //arm[0]->getJoints()[0]->rotate((a3.getRad()+A0.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[0]->rotateGlobal((angle1.getRad()-a0.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[1]->rotateGlobal(-(a1.getRad()-angle2.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[2]->rotateGlobal((a2.getRad()+angle3.getRad())*var,GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            //body->rotate((a3.getRad()+A0.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
        }
        else{
            std::cout<<"elbowdown= ";
            //arm[0]->getJoints()[0]->rotate((a3.getRad()-A0.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[0]->rotateGlobal((a0.getRad()+angle1.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[1]->rotateGlobal(-(a1.getRad()-angle2.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
            arm[0]->getJoints()[2]->rotateGlobal((a2.getRad()+angle3.getRad()),GMlib::Vector<float,3>(0.0f,  0.0f, 1.0f));
        }
        //}
        //}
        tick=0.0f;
    }
}

void Controller::turn_right(double dt){
    //timespan = 0.16;
    //auto var = tick/timespan;
    //GMlib::Angle angle1= (arm[0]->getJoints()[0]->getGlobalDir())
    // .getAngle(arm[0]->arm_base->getGlobalDir());
    //if(previous_tip_position(1)-tip_position(1)>0)
    robotarm->getArm()[0]->getJoints()[0]->rotate((5+1),GMlib::Vector<float,3>(0.0f, 1.0f, 0.0f));
}
