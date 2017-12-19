#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMainWindow>
#include <../../src/qextserialport.h>

namespace Ui {
class Connection;
}

class Connection : public QMainWindow
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = 0);
    ~Connection();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Connection *ui;
    QextSerialPort *port;
};

#endif // CONNECTION_H
