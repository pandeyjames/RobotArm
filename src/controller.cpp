#include "controller.h"

Controller::Controller(){
//    left_turn = std::make_shared<Gait>(gait_type::LeftTurn);
//    right_turn = std::make_shared<Gait>(gait_type::RightTurn);
    for(unsigned int i= 0; i<6;i++){
        turn_left_target_positions.push_back(GMlib::Vector<float,3>(10.0f,-3.0f,-10.0f));
        turn_right_target_positions.push_back(GMlib::Vector<float,3>(0.0f,0.0f,0.0f));
        std::vector<IKAngles> temp_angles;
        for(unsigned int j =0; j<4;j++){
            auto angle = IKAngles(0.0f,0.0f,0.0f);
            temp_angles.push_back(angle);
        }
        turn_left_angles.push_back(temp_angles);
        turn_right_angles.push_back(temp_angles);
    }

}

void Controller::motionrotate()
{


}

void Controller::addRobotArm(std::shared_ptr<RobotArm> robotarm){
    this->robotarm = robotarm;
    body =robotarm->getBody();
    arm = robotarm->getArm();
}

void Controller::update_target_positions(GMlib::APoint<float,3> &tip_position, std::vector<GMlib::Point<float,3>> &target_positions,int i, int j){

            float y =0.0f ;

            y = tip_position[1];
            auto l = std::sqrt(tip_position[0]*tip_position[0]+tip_position[1]*tip_position[1]);
            auto x = l * std::sin(std::acos(y/l));
            target_positions[i]  = GMlib::Point<float,3>(x , y ,tip_position[2]);
            tip_position= target_positions[i];
}
void Controller::update_angles(std::vector<std::vector<IKAngles>> &angles,std::vector<GMlib::Point<float,3>> &target_positions,int i, int j){

    auto angle = arm[i]->inverseKinematics(target_positions[i]);
    angles[i][j]= angle ;
}



void Controller::localSimulate(double dt) {

    if(!IK){
        run_inverse_kinematicts();
        std::cout<<""<<std::endl;
        IK = true;
    }

    //if(moving) move(dt);

    if(turning_left) turn_left(dt);
    if(turning_right) turn_right(dt);
    //std::cout<<dt;
    //robotarm->movePreDef(dt);


}

void Controller::run_inverse_kinematicts(){

        for(unsigned int i =0;i<arm.size();i++){
            //move_tip_position =   arm[i]->get_tip_pos();
            tip_position=   arm[i]->get_tip_pos();
            std::cout<<"tip pos " <<tip_position<<std::endl;

            {//left turn
                auto count = 0;
                auto index =1;
                while(count <4){
                    update_target_positions(tip_position,turn_left_target_positions, i,index);
                    update_angles(turn_left_angles,turn_left_target_positions,i,index-1);
                    count++;
                    if(index<4)
                        index++;
                    else
                        index =1;
                }

            }
            {//right turn
                auto count = 0;
                 auto index =0;
                 while(count <4){
                     update_target_positions(tip_position,turn_right_target_positions, i,index);
                     update_angles(turn_right_angles,turn_right_target_positions,i,index-1);
                     count++;
                     if(index<4)
                         index++;
                     else
                         index =1;
                 }
            }
            {//move
                auto count = 0;
                auto index =0;
                while(count <4){
                    update_target_positions(tip_position,move_target_positions,i,index);
                    update_angles(move_angles,move_target_positions,i,index-1);
                    count++;
                    if(index<4)
                        index++;
                    else
                        index =1;
                }
            }
        }
}

void Controller::return_to_start() {

//    if(!reset) {

//        std::cout<<"Restart !"<<std::endl;
//        moving = false;

//        // Reset position
//        auto pos = GMlib::Point<float,3>(0.0f, 0.0f, 0.0f);
//        auto dir = GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f);
//        auto up = GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f);

//        body->set(pos, dir, up);

//        // arm
//        for( unsigned int i = 0; i < arm.size(); i++) {


//            GMlib::Angle angle1= (arm[i]->getJoints()[0]->getGlobalDir())
//                    .getAngle(arm[i]->arm_base->getGlobalDir());
//            GMlib::Angle angle2= (arm[i]->getJoints()[1]->getGlobalDir())
//                    .getAngle(arm[i]->getJoints()[0]->getGlobalDir());
//            GMlib::Angle angle3=  (arm[i]->getJoints()[2]->getGlobalDir())
//                    .getAngle(arm[i]->getJoints()[1]->getGlobalDir());

//            GMlib::Angle sAngle = 45;
//            GMlib::Angle sAngle_r = sAngle.getRad();
//            if( i == 1 || i == 4) sAngle_r =  0.0;

//            GMlib::Angle femurAngle = 0.0;

//            GMlib::Angle lAngle_degrees = -90;
//            GMlib::Angle Langle_radians = lAngle_degrees.getRad();

//            if( (i !=0  && i !=2 && arm[i]->isRight()) || (i !=3  && i !=5 && !arm[i]->isRight()) ) {
//                arm[i]->getJoints()[0]->rotate((sAngle_r +angle1),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//                arm[i]->getJoints()[1]->rotate((-uAngle-angle2 ), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//                arm[i]->getJoints()[2]->rotate((lAngle_radians+angle3),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//            }
//            else{
//                arm[i]->getJoints()[0]->rotate((sAngle_r -angle1),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//                arm[i]->getJoints()[1]->rotate((-uAngle-angle2 ), GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//                arm[i]->getJoints()[2]->rotate(((lAngle_radians+angle3)),GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));
//            }

//            reset = true;
//        }
//    }
}

void Controller::turn_left(double dt){

    reset = false;

    auto var = tick/timespan;

    if(rotate_body_left){
        body->rotateGlobal(0.261799*var/50,GMlib::Vector<float,3>(0.0f, 0.0f, 1.0f));   // 0.261799 radians = 15 degrees

    }


}

void Controller::turn_right(double dt){

    }
