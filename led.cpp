#include "led.h"
#include "ui_led.h"

LED::LED(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LED)
{
    ui->setupUi(this);
    this->setMaximumSize(50, 50);
    this->setMinimumSize(50, 50);
    this->setWindowFlags(Qt::FramelessWindowHint);//无窗体
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    this->timer.start(100, this);
}

LED::~LED()
{
    delete ui;
}

void LED::setOn(int isOn)
{
    this->isOn = isOn;
}

void LED::changeLight(int index)
{
    this->light = index;
}

void LED::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor color;
    switch (this->light)
    {
        case 0:
            color = QColor(0, 255, 255);
            break;
        case 1:
            color = QColor(121, 121, 126);
            break;
        case 2:
            color = QColor(80, 80, 80);
            break;
    }
    painter.setPen(color);
    if (this->isOn)//打开时显示
    {
        painter.setBrush(color);
    }
    painter.drawEllipse(0, 00, 49, 49);
}

void LED::timerEvent(QTimerEvent *event)
{
    this->update();
}
