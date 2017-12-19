#ifndef SCENARIO_H
#define SCENARIO_H

class Simulator;
class Controller;
class RobotArm;

namespace GMlib {

template <typename T, int n>
class PCurve;
template <typename T, int n>
class PSurf;


}
#include "../application/gmlibwrapper.h"

// qt
#include <QObject>
#include<QImage>

class Scenario : public GMlibWrapper {
  Q_OBJECT
public:
  using GMlibWrapper::GMlibWrapper;

  void    setTexture(QImage img);
  void    initializeScenario() override;
  void    cleanupScenario() override;

  void    deleteRobotArm();
  void    Replot();


private:
  std::shared_ptr<Simulator> _simulator;
  QImage                     _img;
  std::shared_ptr<Controller> _controller;
  std::shared_ptr<RobotArm> _robotarm;


};

#endif // SCENARIO_H
