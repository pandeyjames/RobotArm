#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <../../src/qextserialport.h>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QextSerialPort *port;
};

#endif // MAINWINDOW_H
