#include "pen.h"
#include <gmParametricsModule>

//Pen::Pen(GMlib::Vector<float,3> pos){
//    // Start values
//    _rx = 0.2f;
//    _ry = 0.2f;   s
//    _h = 1.5f;
//    translateGlobal(pos);
//}


//Pen::Pen(float r, float h1, float h2){
//_r1=r;
//_h1=h1;
//_h2=h2;
//}

Pen::Pen(GMlib::Point<float, 3> pos)
{
    body = std::make_shared<GMlib::PCylinder<float>>(1,2.5,1.5);
    head = std::make_shared<GMlib::PCone<float>>(1,1.5);
    body->rotate( GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ) );
    body->rotateGlobal( GMlib::Angle(90), GMlib::Vector<float,3>(1.0f, 0.0f, 0.0f ));

}

void Pen::replot(int m1, int m2, int d1, int d2){

    // Replot for body...
    body->replot(m1,m2,d1,d2);
    head->replot(m1,m2,d1,d2);

}

void Pen::toggleDefaultVisualizer(){

    // Toggle default visualizer for body...
    body->toggleDefaultVisualizer();
    head->toggleDefaultVisualizer();

}

void Pen::insert(GMlib::Scene &scene){

    scene.insert(body.get());
    scene.insert(head.get());
}

