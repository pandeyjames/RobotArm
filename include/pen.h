#ifndef PEN_H
#define PEN_H
#include<gmParametricsModule>
#include<memory>
class Pen:public GMlib::SceneObject {
    GM_SCENEOBJECT(Pen)
public:
    //Pen(float r, float h1,float h2);
    Pen(GMlib::Point<float, 3> pos);
    Pen(const Pen &copy){}
    virtual ~Pen() {}
    void setParameters();
    void replot(int m1=20, int m2=20, int d1=1, int d2=1);
    void toggleDefaultVisualizer();
    void insert(GMlib::Scene &scene);
    void makePen(GMlib::Point<float, 3> pos);

protected:
    std::shared_ptr<GMlib::PCylinder<float>> body;
    std::shared_ptr<GMlib::PCone<float>> head;
    float _r1, _h1, _h2;
};




#endif // PEN_H
