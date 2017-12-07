#include "controller.h"

Controller::Controller(){
    //create square


}

void Controller::motionrotate()
{


}

void Controller::addRobotArm(std::shared_ptr<RobotArm> robotarm){
    this->robotarm = robotarm;
    body =robotarm->getBody();
    arm = robotarm->getArm();
    sph = robotarm->getSph();
    createSquare(5.0f);
}

void Controller::move_from_A_to_B(GMlib::APoint<float, 3> A,GMlib::APoint<float, 3> B)
{

}

void Controller::createSquare(float len)
{
    for( unsigned int i =0;i<arm.size();i++){
    auto A=arm[i]->get_tip_pos();
    //std::cout<<"Tip Pos "<<A<<std::endl;

    //auto c = robotarm->getBoard()->getCenterPos();
    auto c = robotarm->get_base_pos();
    std::cout<<"Board Pos "<<c(0)<<","<<c(1)<<","<<c(2)<<std::endl;
    for (int k=0;k<4;k++){
    for(int j=0; j<=(int)len; j++){
        //float x=0,y=0,z=0;
        if (k==0)
        move_target_positions.push_back(GMlib::Vector<float,3>((float)(-len/2-c(0)+j),len/2-c(1),c(2)));
        if (k==1)
        move_target_positions.push_back(GMlib::Vector<float,3>((float)((len/2)-c(0)),len/2-c(1)-j,c(2)));
        if (k==2)
        move_target_positions.push_back(GMlib::Vector<float,3>((float)((len/2)-c(0))-j,-len/2-c(1),c(2)));
        if (k==3)
        move_target_positions.push_back(GMlib::Vector<float,3>((float)((-len/2)-c(0)),-len/2-c(1)+j,c(2)));

    }

    }

}
    for (int g=0;g<move_target_positions.size();g++)
          std::cout<<g<<". "<<move_target_positions[g]<<std::endl;
}
void Controller::createCircle(float r){
//    auto A = arm[0]->get_tip_pos();
//    auto c = robotarm->getBoard()->getCenterPos();
//    for(int i=0; i<r; i++){
//        //auto l2= (targetPosition(0)) * (targetPosition(0)) + (targetPosition(1)) * (targetPosition(1));
//        //move_target_positions[i](0)=c+r/2;

//        move_target_positions[i]=(c+r/2,c-r/2,0);
//        std::cout<<move_target_positions[i]<<std::endl;
//    }


}


void Controller::update_target_positions(GMlib::APoint<float,3> &tip_position, std::vector<GMlib::Point<float,3>> &target_positions,int i, int j){

    std::cout<<"Tip pos 1 ="<<tip_position<<std::endl;
    float y =0.0f ;
            y = tip_position[1];
            auto l = std::sqrt(tip_position[0]*tip_position[0]+tip_position[1]*tip_position[1]);
            auto x = l * std::sin(std::acos(y/l));
            for(int i=0;i<target_positions.size();i++){
                std::cout<<"Target Pos "<<target_positions[i]<<std::endl;
            target_positions[i]  = GMlib::Point<float,3>(x , y ,tip_position[2]);
            tip_position= target_positions[i];
            std::cout<<"Tip pos 2 ="<<tip_position<<std::endl;
            }
}
void Controller::update_angles(std::vector<std::vector<IKAngles>> &angles,std::vector<GMlib::Point<float,3>> &target_positions, int i,int j){
    for(int i=0;i<target_positions.size();i++){
    auto angle = arm[0]->inverseKinematics(target_positions[i]);
    angles[i][j]= angle ;
    }
}



void Controller::localSimulate(double dt) {

//    if(!IK){
//        run_inverse_kinematicts();
//        std::cout<<""<<std::endl;
//        IK = true;
//    }
    //arm[0]->getJoints()[0]->rotateGlobal(dt,(GMlib::Vector<float, 3>(0,1,0)));
    //arm[0]->getJoints()[1]->rotateGlobal(-10,(GMlib::Vector<float, 3>(0,1,0)));
    //if(moving) move(dt);

    //if(turning_left) turn_left(dt);
    //if(turning_right) turn_right(dt);
    //std::cout<<dt;
    //robotarm->movePreDef(dt);


}

void Controller::run_inverse_kinematicts(){
//    arm[0]->getJoints()[0]->rotateGlobal(90,(GMlib::Vector<float, 3>(0,1,0)));
//    arm[0]->getJoints()[1]->rotateGlobal(-10,(GMlib::Vector<float, 3>(0,1,0)));

        for(unsigned int i =0;i<arm.size();i++){
            //move_tip_position =   arm[i]->get_tip_pos();
            tip_position=   arm[i]->get_tip_pos();
            std::cout<<"tip pos " <<tip_position<<std::endl;


            {//move
                auto count = 0;
                auto index =0;
                while(count <4){
                    update_target_positions(tip_position,move_target_positions,i, index);
                    update_angles(move_angles,move_target_positions,i, index-1);
                    count++;
                    if(index<4)
                        index++;
                    else
                        index =1;
                }
            }


//            {//left turn
//                auto count = 0;
//                auto index =1;
//                while(count <4){
//                    update_target_positions(tip_position,turn_left_target_positions, i,index);
//                    update_angles(turn_left_angles,turn_left_target_positions,i,index-1);
//                    count++;
//                    if(index<4)
//                        index++;
//                    else
//                        index =1;
//                }

//            }
//            {//right turn
//                auto count = 0;
//                 auto index =0;
//                 while(count <4){
//                     update_target_positions(tip_position,turn_right_target_positions, i,index);
//                     update_angles(turn_right_angles,turn_right_target_positions,i,index-1);
//                     count++;
//                     if(index<4)
//                         index++;
//                     else
//                         index =1;
//                 }
//            }
            }

}

void Controller::return_to_start() {

        if(!reset) {
//            std::cout<<"Restart !"<<std::endl;
//            moving = false;

//            // Reset position
//            auto pos = GMlib::Point<float,3>(0.0f, 0.0f, 0.0f);
//            auto dir = GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f);
//            auto up = GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f);

//            body->set(pos, dir, up);

            // arm
            for( unsigned int i = 0; i < arm.size(); i++) {


                GMlib::Angle angle1= (arm[i]->getJoints()[0]->getGlobalDir())
                        .getAngle(arm[i]->arm_base->getGlobalDir());
                GMlib::Angle angle2= (arm[i]->getJoints()[1]->getGlobalDir())
                        .getAngle(arm[i]->getJoints()[0]->getGlobalDir());
                GMlib::Angle angle3=  (arm[i]->getJoints()[2]->getGlobalDir())
                        .getAngle(arm[i]->getJoints()[1]->getGlobalDir());
                std::cout<<angle1<<angle2<<angle3;

                GMlib::Angle sAngle = 45;
                GMlib::Angle sAngle_r = sAngle.getRad();
                if( i == 1 || i == 4) sAngle_r =  0.0;

                GMlib::Angle uAngle = 0.0;

                GMlib::Angle lAngle_degrees = -90;
                GMlib::Angle lAngle_radians = lAngle_degrees.getRad();

//                if( (i !=0  && i !=2 && arm[i]->isRight()) || (i !=3  && i !=5 && !arm[i]->isRight()) ) {
//                    arm[i]->getJoints()[0]->rotate((sAngle_r +angle1),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//                    arm[i]->getJoints()[1]->rotate((-uAngle-angle2 ), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//                    arm[i]->getJoints()[2]->rotate((lAngle_radians+angle3),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//                }
//                else{
                    arm[i]->getJoints()[0]->rotateGlobal((sAngle_r -angle1),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
                    arm[i]->getJoints()[1]->rotateGlobal((-uAngle-angle2 ), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
                    arm[i]->getJoints()[2]->rotateGlobal(((lAngle_radians+angle3)),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//                }

                reset = true;
            }
        }
}

void Controller::turn_left(double dt){

    reset = false;

    auto var = tick/timespan;

    if(rotate_body_left){
        body->rotateGlobal(0.261799*var/50,GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));   // 0.261799 radians = 15 degrees

    }


}

void Controller::turn_down(double dt)
{

}

void Controller::turn_right(double dt){

    }
