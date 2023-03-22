#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QLineEdit>
#include "alarminformationwidget.h"
#include "loginwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LoginWidget *login_widget;
    QTimer *timer;
    QPainter *painter;
    int alarmColor = 0;
    QString alarmTitle1;
    QString alarmTitleTime1;
    QString alarmTitle2;
    QString alarmTitleTime2;
    int sqlPassword = 123456;

    double lat = 60.5;
    double lon = -120.5;
    double speed = 60;
    double sx = 120;//艏向

    void initWindow();
    void connectFunctions();
    void mapInit();
public slots:
    void updateTimeLabel();
    void changeLight(int index);
    void updateAlarmInformation(QStringList information);
    void updateAlarmInformation2();
    void updateData();
protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void changeLightSignal(int index);
};
#endif // MAINWINDOW_H
