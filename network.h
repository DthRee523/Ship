#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QDebug>
#include <QSettings>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = nullptr);

public slots:
    void getBaseData();
    void getHxData();
    void getNetData1();
    void sendNetData1(QByteArray data);
private:
    QUdpSocket *socket1;
    QUdpSocket *socket2;
    QUdpSocket *socket3;

    //数据区
    //基本数据
    double lat = 60.5;
    double lon = -120.5;
    int speed = 60;
    int sx = 120;//艏向
    //航行信息数据
    double power_left_gk = 0.0;
    double power_right_gk = 0.0;
    int ym_value = 0;//主油门指令
    int ym_value_1 = 0;//副油门指令
    int ry_value = 0;//剩余燃油
    int power_left_dw = 0;
    int power_right_dw = 0;
    double ele1_V = 0;//1号电机电压
    double ele2_V = 0;//2号电机电压
    double ele1_A = 0;//2号电机电流
    double ele2_A = 0;//2号电机电流
    int ele1_state = 0;//1#电机状态
    int ele2_state = 0;//2#电机状态
    int ele_an_state = 0;//岸电状态
    double ele_an_V = 0;//岸电电压
    double ele_an_A = 0;//岸电电流
    int duo_value = 0;//主舵角指令
    int duo_value_1 = 0;//副舵角指令
    int power_left_state = 0;//主机报警状态
    int power_right_state = 0;
    int ele1_state_1 = 0;//报警状态
    int ele2_state_2 = 0;

    //端口区
    int hxPort = 9001;//船舶信息端口
    int basePort = 9002;//基本信息端口
    int data1Port = 9003;//雨刮器信息端口
    //模拟仿真IP地址
    QHostAddress server;


signals:
    void sendHxData(int, int, int, int, int, int, int, int,
                    double, double, int, int, double, double, int, double, double,
                    int, int, int, int, int);

    void sendBaseData(double, double, int, int);
    void sendData1(QByteArray);
};

#endif // NETWORK_H
