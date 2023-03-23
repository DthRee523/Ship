#ifndef HXFZWIDGET_H
#define HXFZWIDGET_H

#include <QWidget>
#include "led.h"

namespace Ui {
class HxfzWidget;
}

class HxfzWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HxfzWidget(QWidget *parent = nullptr);
    ~HxfzWidget();
    void getlight(int index);
    void connectFunc();
    void dataToNetData1();//从具体数据转化为网络报文
    void dataToNetData2();//从具体数据转化为网络报文
    void dataToNetData3();//从具体数据转化为网络报文
    void dataToNetData4();//从具体数据转化为网络报文
    void dataToNetData5();//从具体数据转化为网络报文

private:
    Ui::HxfzWidget *ui;
    LED l_led;
    LED lf_led;
    LED rf_led;
    LED r_led;
    LED power_led;
    LED fast_led;
    LED slow_led;
    LED tb_led;
    LED water_led;
    //雨刮器数据区
    int l_state = 0;//状态反馈
    int l_ctrl = 0;//控制指令
    int lf_state = 0;
    int lf_ctrl = 0;
    int rf_state = 0;
    int rf_ctrl = 0;
    int r_state = 0;
    int r_ctrl = 0;
    int fast_ctrl = 0;//控制指令
    int slow_ctrl = 0;
    int tb_ctrl = 0;
    int water_ctrl = 0;
    int power = 0;

    QString textQss1 = "color: rgb(0, 150, 255);";
    QString textQss2 = "color: rgb(121, 121, 126);";
    QString textQss3 = "color: rgb(80, 80, 80);";
    QString valueQss1 = "color: rgb(0, 255, 255);";
    QString valueQss2 = "color: rgb(121, 121, 126);";
    QString valueQss3 = "color: rgb(80, 80, 80);";
    QString buttonQss1 = "background-color:rgb(0, 255, 255);";
    QString buttonQss2 = "background-color: rgb(121, 121, 126);";
    QString buttonQss3 = "background-color: rgb(80, 80, 80);";

signals:
    void sendData1(QByteArray data);
    void sendData2(QByteArray data);
    void sendData3(QByteArray data);
    void sendData4(QByteArray data);
    void sendData5(QByteArray data);
public slots:
    void getData1(QByteArray data);
    void getData2(QByteArray data);
    void getData3(QByteArray data);
    void getData4(QByteArray data);
    void getData5(QByteArray data);
};

#endif // HXFZWIDGET_H
