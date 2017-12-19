#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(port == 0 || (port != 0 && port->isOpen()))
        {
            port = new QextSerialPort("/dev/ttyUSB0", QextSerialPort::EventDriven);
            port->setBaudRate(BAUD9600);
            // check the baud rate on your Arduino since it has to be the same
            // as set with Serial.begin(...)
            port->setFlowControl(FLOW_OFF);
            port->setParity(PAR_NONE);
            port->setDataBits(DATA_8);
            port->setStopBits(STOP_2);

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
