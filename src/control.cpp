//#include "../include/control.h"
//#include <QDebug>
//#include <QtSerialPort/QSerialPort>
////#include <QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
//Control::Control()
//{
////    init_port(); //initiation of the port


//    qDebug() << "Number of serial ports:" << QSerialPortInfo::availablePorts().count();

//        foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {

//            qDebug() << "\nPort:" << serialPortInfo.portName();
//            qDebug() << "Location:" << serialPortInfo.systemLocation();
//            qDebug() << "Description:" << serialPortInfo.description();
//            qDebug() << "Manufacturer:" << serialPortInfo.manufacturer();
//            qDebug() << "Vendor Identifier:" << (serialPortInfo.hasVendorIdentifier() ? QByteArray::number(serialPortInfo.vendorIdentifier(), 16) : QByteArray());
//            qDebug() << "Product Identifier:" << (serialPortInfo.hasProductIdentifier() ? QByteArray::number(serialPortInfo.productIdentifier(), 16) : QByteArray());
//            qDebug() << "Busy:" << (serialPortInfo.isBusy() ? QObject::tr("Yes") : QObject::tr("No"));

//            QSerialPort *port = new QSerialPort(serialPortInfo);
//            if (port->open(QIODevice::ReadWrite)) {
//                qDebug() << "Baud rate:" << port->baudRate();
//                qDebug() << "Data bits:" << port->dataBits();
//                qDebug() << "Stop bits:" << port->stopBits();
//                qDebug() << "Parity:" << port->parity();
//                qDebug() << "Flow control:" << port->flowControl();
//                qDebug() << "Read buffer size:" << port->readBufferSize();
//                port->close();
//            } else {
//                qDebug() << "Unable to open port, error code" << port->error();
//            }
//            delete port;
//        }

//}

//Control::~Control()
//{
////    port->close(); //we close the port at the end of the program
//}

//void Control::init_port()
//{
////    port = new QextSerialPort("COM3"); //we create the port

////    port->open(QIODevice::ReadWrite | QIODevice::Unbuffered); //we open the port
////    if(!port->isOpen())
////    {
////        //QMessageBox::warning(this, "port error", "Impossible to open the port!");
////        qDebug()<<"Warning";
////    }

////    //we set the port properties
////    port->setBaudRate(BAUD115200);//modify the port settings on your own
////    port->setFlowControl(FLOW_OFF);
////    port->setParity(PAR_NONE);
////    port->setDataBits(DATA_8);
////    port->setStopBits(STOP_1);

//}

//void Control::transmitCmd(int value)
//{
////  if(value < 0 || value >255)return; //if the value is not between 0 and 255
////                                     //no transmission

////  char *buf; //creation of a buffer
////  *buf = value;

////  //for messages longer than 1 character :
////  /*
////  char *buf[255]; //buffer size = 255char;
////  sprintf(buf,"%c",value);
////  */

////  port->write(buf); //send the buffer






//}
