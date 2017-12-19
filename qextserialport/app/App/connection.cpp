#include "connection.h"
#include "ui_connection.h"

#include <qDebug>

Connection::Connection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Connection)
{
    ui->setupUi(this);
}

Connection::~Connection()
{
    delete ui;
}

void Connection::on_pushButton_clicked()
{
    if(port == 0 || (port != 0 && port->isOpen()))
        {
            port = new QextSerialPort("COM3", QextSerialPort::EventDriven);
            port->setBaudRate(BAUD115200);
            // check the baud rate on your Arduino since it has to be the same
            // as set with Serial.begin(...)
            port->setFlowControl(FLOW_OFF);
            port->setParity(PAR_NONE);
            port->setDataBits(DATA_8);
            port->setStopBits(STOP_1);

            if(port->open(QIODevice::ReadWrite) == true)
            {
                connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
                qDebug() << "listening for data on" <<port->portName();
            }
            else
            {
                qDebug() << "device failed to open:" <<port->errorString();
            }
        }
        else
        {
            port->close();
        }
}

void Connection::on_pushButton_2_clicked()
{

}
