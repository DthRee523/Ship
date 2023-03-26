#ifndef HXINFORMAION_H
#define HXINFORMAION_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QString>

namespace Ui {
class HxInformaion;
}

class HxInformaion : public QWidget
{
    Q_OBJECT

public:
    explicit HxInformaion(QWidget *parent = nullptr);
    ~HxInformaion();
    QString updateDw(int index);
    QString updateEleState(int index);
    void updateEleAnState(int index);
    void updatePower1State(int index);
    void updatePower2State(int index);
    void updateEle1State(int index);
    void updateEle2State(int index);

public slots:
    void changeLight(int index);
    void updateData();
    void getData(int power_left_state, int power_left_dw, double power_left_gk,
                 int power_right_state, int power_right_dw, double power_right_gk,
                 int ele1_state_1, int ele1_state, double ele1_V, double ele1_A,
                 int ele2_state_2, int ele2_state, double ele2_V, double ele2_A,
                 int ele_an_state, double ele_an_V, double ele_an_A, int duo_value,
                 int duo_value_1, int ym_value, int ym_value_1, int ry_value);

private:
    Ui::HxInformaion *ui;
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
    int duo_value = 90;//主舵角指令
    int duo_value_1 = 90;//副舵角指令
    int power_left_state = 0;//主机报警状态
    int power_right_state = 0;
    int ele1_state_1 = 0;//报警状态
    int ele2_state_2 = 0;
    int light = 0;//当前光模式

    //QSS
    QString pBarQss1 = "QProgressBar {\
            border: 2px solid rgb(0, 255, 255); \
            border-radius: 5px;  \
            background-color: #06061d;\
            }\
            QProgressBar::chunk {  \
            background-color: rgb(0, 255, 255);\
            }";
    QString pBarQss2 = "QProgressBar {  \
            border: 2px solid rgb(121, 121, 126); \
            border-radius: 5px;  \
            background-color: #06061d;\
            }\
            QProgressBar::chunk {   \
            background-color: rgb(121, 121, 126);\
            }";
    QString pBarQss3 = "QProgressBar { \
            border: 2px solid rgb(80, 80, 80);\
            border-radius: 5px;   \
            background-color: #000000;\
            }\
            QProgressBar::chunk {   \
            background-color: rgb(80, 80, 80);\
            }";
    QString textQss1 = "color: rgb(0, 150, 255);";
    QString textQss2 = "color: rgb(121, 121, 126);";
    QString textQss3 = "color: rgb(80, 80, 80);";
    QString valueQss1 = "color: rgb(0, 255, 255);";
    QString valueQss2 = "color: rgb(121, 121, 126);";
    QString valueQss3 = "color: rgb(80, 80, 80);";
    QString titleQss1 = "background-color: rgb(0, 255, 255);";
    QString titleQss2 = "background-color: rgb(121, 121, 126);";
    QString titleQss3 = "background-color: rgb(80, 80, 80);";
};

#endif // HXINFORMAION_H
