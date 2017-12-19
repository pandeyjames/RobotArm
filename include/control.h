#ifndef CONTROL_H
#define CONTROL_H

#include "../qextserialport/src/qextserialport.h"

class Control
{

public:
    Control(); //the creator
    ~Control();  //destructor

    void init_port(); // port initialisation function

//public slots:
    void transmitCmd(int value); // sending function

private :

    QextSerialPort *port;
};

#endif // CONTROL_H
