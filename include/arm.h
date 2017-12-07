#ifndef ARM_H
#define ARM_H

#include<gmParametricsModule>
#include<memory>
#include "griper.h"

struct IKAngles {

    GMlib::Angle uAngle;
    GMlib::Angle lAngle;
    GMlib::Angle gAngle;
    IKAngles(GMlib::Angle upperarm, GMlib::Angle lowerarm, GMlib::Angle griper) {uAngle = upperarm; lAngle = lowerarm; gAngle = griper; }
    void operator=(IKAngles angles){uAngle = angles.uAngle; lAngle = angles.lAngle; gAngle = angles.gAngle;}
};


class Arm: public  GMlib::SceneObject {
    GM_SCENEOBJECT(Arm)

    public:

        Arm(GMlib::Point<float,3> pos= {0.0f,0.0f,0.0f} , bool orientation = true);
        Arm(const Arm &copy){}
        virtual ~Arm() {}
        void replot(int m1=20, int m2=20, int d1=1, int d2=1);
        void toggleDefaultVisualizer();
        void insert(GMlib::Scene& scene){ scene.insert(this);}
        void setMaterial(const GMlib::Material &m1, const GMlib::Material &m2, const GMlib::Material &m3, const GMlib::Material &m4);

        IKAngles inverseKinematics(GMlib::Point<float,3> targetPosition);
        void update_tip_position();
        void makePen(GMlib::Point<float, 3> pos);
        GMlib::APoint<float,4> get_tip_pos(){ update_tip_position(); return tip_base_pos;}

        std::shared_ptr<GMlib::PCylinder<float>> getPenBody(){
            return penbody;
        }
        std::shared_ptr<GMlib::PCone<float>> getPenTip(){
            return pentip;
        }
        std::shared_ptr<GMlib::PSphere<float>> arm_base;
        std::shared_ptr<GMlib::PSphere<float>> tip;
        bool isRight(){return right;}


        std::vector<std::shared_ptr<GMlib::PSphere<float>>> getJoints();
        std::shared_ptr<GMlib::PCylinder<float>> getLowerArm();
        std::shared_ptr<GMlib::PCylinder<float>> getUpperArm();
        std::shared_ptr<Griper> getGriper();
        std::shared_ptr<GMlib::PSphere<float>> getArmBase();


    protected:
        std::shared_ptr< GMlib::PCylinder<float>> upperarm;
        std::shared_ptr<GMlib::PCylinder<float>> lowerarm;
        std::shared_ptr<GMlib::PCircle<float>> circle;
        std::shared_ptr<Griper> griper;
        std::vector<std::shared_ptr< GMlib::PSphere<float>>> joints;    // 3
        std::shared_ptr<GMlib::PCylinder<float>> body;
        std::shared_ptr<GMlib::PCylinder<float>> penbody;
        std::shared_ptr<GMlib::PCone<float>> pentip;

    private:
        void makeLowerArm();
        void makeUpperArm();
        void makeGriper();
        void makeJoints();
        void reArrangePosition();
        void link();

        bool right;
        GMlib::APoint<float,4> tip_base_pos;

};


#endif // ARM_H
