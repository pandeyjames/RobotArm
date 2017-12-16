#include "../include/simulator.h"
#include "../include/robotarm.h"
#include "QDir"
#include <QQmlContext>
#include <QGuiApplication>

Simulator::Simulator(GMlib::Scene& scene) : _scene{scene}{
    _robotarm = std::make_shared< RobotArm>();
    _robotarm->setMaterial(GMlib::GMmaterial::blackRubber(),GMlib::GMmaterial::silver());

    _ground = std::make_shared<GMlib::PPlane<float>>(
                                                     GMlib::Vector<float,3>(0.0f, 500.0f, -2.2f),
                                                     GMlib::Vector<float,3>(0.0f, -500, 0.0f),
                                                     GMlib::Vector<float,3>(-500.0, 0.0f, 0.0f));
    _ground->translate(GMlib::Point<float,3>(250.0f,-100.0f,0.0f));

    _surface_visualizer = new GMlib::PSurfTexVisualizer<float,3>;
    _material = GMlib::GMmaterial::emerald();

}

void Simulator::setupSimulator(){


    _robotarm->toggleDefaultVisualizer();
    _robotarm->replot();
    _controller = Controller();
    double dt = 0.016;
    _scene.enabledFixedDt();
    _scene.setFixedDt(dt);
    insert_to_scene(_robotarm);
    _ground->insertVisualizer(_surface_visualizer);
    _ground->replot(10,10);
    _scene.insert(_ground.get());
    _controller.addRobotArm(_robotarm);
    _scene.insert(&_controller);


}

void Simulator::insert_to_scene(std::shared_ptr<RobotArm> robotarm){

    robotarm->insert(_scene);
}

void Simulator::set_texture(QImage img){

    img = img.convertToFormat(QImage::Format_RGB888);
    _ground->setMaterial( _material );

    _texture.create(GL_TEXTURE_2D);
    _texture.bind();
    _texture.texParameteri(GL_TEXTURE_WRAP_S, GL_REPEAT);
    _texture.texParameteri(GL_TEXTURE_WRAP_T, GL_REPEAT);
    _texture.texParameteri(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    _texture.texParameteri( GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    _texture.texImage2D(0, GL_RGB,  img.width(), img.height(), 0, GL_RGB, GL_UNSIGNED_BYTE, img.bits());
    _surface_visualizer->setTexture(_texture);
    _texture.unbind();

}

void Simulator::deleteRobotArm() {

    _controller.remove(_robotarm.get());
    _robotarm.reset();
}



