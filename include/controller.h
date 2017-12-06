#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<gmParametricsModule>
#include "robotarm.h"
#include <vector>
#include<memory>


class Controller: public GMlib::SceneObject {
    GM_SCENEOBJECT (Controller)

public:
    Controller();
    void motionrotate();
    void turn_right();
    void turn_left();
    void addRobotArm(std::shared_ptr<RobotArm> robotarm);
    void move_from_A_to_B();
    void change_simulation(int i);

    void return_to_start();

    bool turning_left = false;
    bool turning_right = false;
    bool turning_down = false;
    bool turning_up = false;




protected:
    void turn_right(double dt);
    void turn_left(double dt);
    void turn_up(double dt);
    void turn_down(double dt);

private:

    void localSimulate(double dt) override;
    void run_inverse_kinematicts();
    void update_target_positions(GMlib::APoint<float,3> &tip_position, std::vector<GMlib::Point<float,3>> &target_positions, int i, int j);
    void update_angles(std::vector<std::vector<IKAngles>> &angles,std::vector<GMlib::Point<float,3>> &target_positions,int i, int j);
    std::shared_ptr<RobotArm> robotarm;
    std::shared_ptr<GMlib::PCylinder<float>> body;
    std::vector<std::shared_ptr<Arm>> arm;
    std::vector<std::shared_ptr<Pen>> pen;
    std::shared_ptr<GMlib::PCylinder<float>> penbody;
    std::shared_ptr<GMlib::PCone<float>> pentip;
    std::vector<GMlib::Point<float,3>> turn_left_target_positions;
    std::vector<GMlib::Point<float,3>> move_target_positions;
    GMlib::Point<float,3> move_tip_position;
    GMlib::APoint<float,3> tip_position; // IK variable
    std::vector<std::vector<IKAngles>> turn_left_angles;  //arm/step (3 angles)
    std::vector<GMlib::Point<float,3>> turn_right_target_positions;
    std::vector<std::vector<IKAngles>> turn_right_angles;  //arm/step (3 angles)
    std::vector<std::vector<IKAngles>> move_angles;

    int active_arm = 0;
    bool rotate_body = false;
    bool body_rotated = false;
    bool rotate_body_left = false;
    bool body_rotated_left = false;
    bool IK = false;

    double timespan = 0.16; //dt*10
    double tick =0.0;
    double rotation_speed= 2.0;
    double translation_speed=1.0;
    bool moving = false;

    bool reset = false;

};

#endif //CONTROLLER_H
