#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "controller.h"
#include<gmParametricsModule>
#include "QtGui/QImage"
#include<vector>
#include<memory>

class Simulator{
public:
    explicit Simulator ( GMlib::Scene& scene);

    void set_texture(QImage img);
    void setupSimulator();
    void insert_to_scene(std::shared_ptr<RobotArm> robotarm);

    void deleteRobotArm();

private:
    GMlib::Scene&                                       _scene;
    Controller                                          _controller;
    std::shared_ptr<RobotArm>                           _robotarm;
    std::shared_ptr<GMlib::PPlane<float>>               _ground;
    GMlib::GL::Texture                                  _texture;
    GMlib::Material                                     _material;
    GMlib::PSurfTexVisualizer<float,3>*                 _surface_visualizer ;



};

#endif // SIMULATOR_H
