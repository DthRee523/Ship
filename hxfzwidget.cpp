#include "hxfzwidget.h"
#include "ui_hxfzwidget.h"

HxfzWidget::HxfzWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HxfzWidget)
{
    ui->setupUi(this);
    ui->l_layout->addWidget(&l_led);
    ui->lf_layout->addWidget(&lf_led);
    ui->rf_layout->addWidget(&rf_led);
    ui->r_layout->addWidget(&r_led);
    ui->power_layout->addWidget(&power_led);
    ui->fast_layout->addWidget(&fast_led);
    ui->slow_layout->addWidget(&slow_led);
    ui->tb_layout->addWidget(&tb_led);
    ui->water_layout->addWidget(&water_led);
    this->connectFunc();
}

HxfzWidget::~HxfzWidget()
{
    delete ui;
}

void HxfzWidget::getlight(int index)
{
    QString qss;
    switch (index)
    {
    case 0:
        qss = "QTabBar::tab{\
                background-color:rgb(0, 255, 255);\
            }\
            #tab.QWidget{\
                background-color:rgb(6, 6, 29);\
            }\
            #tab_2.QWidget{\
                background-color:rgb(6, 6, 29);\
            }\
            #tab_3.QWidget{\
                background-color:rgb(6, 6, 29);\
            }\
            #tab.QWidget{\
                background-color:rgb(6, 6, 29);\
            }\
            #tab.QWidget{\
                background-color:rgb(6, 6, 29);\
            }\
            #tab_4.QWidget{\
                background-color:rgb(6, 6, 29);\
            }\
            #tab_5.QWidget{\
                background-color:rgb(6, 6, 29);\
            }\
            QTabWidget::pane {\
                border: 1px solid rgb(6, 6, 29);\
            }";
        ui->tabWidget->setStyleSheet(qss);
        ui->l_btn->setStyleSheet(buttonQss1);
        ui->lf_btn->setStyleSheet(buttonQss1);
        ui->rf_btn->setStyleSheet(buttonQss1);
        ui->r_btn->setStyleSheet(buttonQss1);
        ui->power_btn->setStyleSheet(buttonQss1);
        ui->fast_btn->setStyleSheet(buttonQss1);
        ui->slow_btn->setStyleSheet(buttonQss1);
        ui->tb_btn->setStyleSheet(buttonQss1);
        ui->slow_btn->setStyleSheet(buttonQss1);
        ui->water_btn->setStyleSheet(buttonQss1);
        break;
    case 1:
        qss = "QTabBar::tab{\
            background-color:rgb(121, 121, 126);\
        }\
        #tab.QWidget{\
            background-color:rgb(6, 6, 29);\
        }\
        #tab_2.QWidget{\
            background-color:rgb(6, 6, 29);\
        }\
        #tab_3.QWidget{\
            background-color:rgb(6, 6, 29);\
        }\
        #tab.QWidget{\
            background-color:rgb(6, 6, 29);\
        }\
        #tab.QWidget{\
            background-color:rgb(6, 6, 29);\
        }\
        #tab_4.QWidget{\
            background-color:rgb(6, 6, 29);\
        }\
        #tab_5.QWidget{\
            background-color:rgb(6, 6, 29);\
        }\
        QTabWidget::pane {\
            border: 1px solid rgb(6, 6, 29);\
        }";
        ui->tabWidget->setStyleSheet(qss);
        ui->l_btn->setStyleSheet(buttonQss2);
        ui->lf_btn->setStyleSheet(buttonQss2);
        ui->rf_btn->setStyleSheet(buttonQss2);
        ui->r_btn->setStyleSheet(buttonQss2);
        ui->power_btn->setStyleSheet(buttonQss2);
        ui->fast_btn->setStyleSheet(buttonQss2);
        ui->slow_btn->setStyleSheet(buttonQss2);
        ui->tb_btn->setStyleSheet(buttonQss2);
        ui->slow_btn->setStyleSheet(buttonQss2);
        ui->water_btn->setStyleSheet(buttonQss2);
        break;
    case 2:
        qss = "QTabBar::tab{\
            background-color: rgb(80, 80, 80);\
        }\
        #tab.QWidget{\
            background-color:rgb(0, 0, 0);\
        }\
        #tab_2.QWidget{\
            background-color:rgb(0, 0, 0);\
        }\
        #tab_3.QWidget{\
            background-color:rgb(0, 0, 0);\
        }\
        #tab.QWidget{\
            background-color:rgb(0, 0, 0);\
        }\
        #tab.QWidget{\
            background-color:rgb(0, 0, 0);\
        }\
        #tab_4.QWidget{\
            background-color:rgb(0, 0, 0);\
        }\
        #tab_5.QWidget{\
            background-color:rgb(0, 0, 0);\
        }\
        QTabWidget::pane {\
            background-color:rgb(0, 0, 0);\
        }";
        ui->tabWidget->setStyleSheet(qss);
        ui->l_btn->setStyleSheet(buttonQss3);
        ui->lf_btn->setStyleSheet(buttonQss3);
        ui->rf_btn->setStyleSheet(buttonQss3);
        ui->r_btn->setStyleSheet(buttonQss3);
        ui->power_btn->setStyleSheet(buttonQss3);
        ui->fast_btn->setStyleSheet(buttonQss3);
        ui->slow_btn->setStyleSheet(buttonQss3);
        ui->tb_btn->setStyleSheet(buttonQss3);
        ui->slow_btn->setStyleSheet(buttonQss3);
        ui->water_btn->setStyleSheet(buttonQss3);
        break;
    }

    this->l_led.changeLight(index);
    this->lf_led.changeLight(index);
    this->rf_led.changeLight(index);
    this->r_led.changeLight(index);
    this->power_led.changeLight(index);
    this->fast_led.changeLight(index);
    this->slow_led.changeLight(index);
    this->tb_led.changeLight(index);
    this->water_led.changeLight(index);
}

void HxfzWidget::connectFunc()
{
    /////////////////////雨刮器////////////////////////////////////////
    //电源按钮
    connect(ui->power_btn, &QPushButton::clicked, this, [=]()
    {
        this->power = !this->power;
        this->power_led.setOn(this->power);
        if (!this->power)
        {
            this->l_ctrl = this->power;
            this->lf_ctrl = this->power;
            this->rf_ctrl = this->power;
            this->r_ctrl = this->power;
            this->fast_ctrl = this->power;
            this->fast_led.setOn(this->power);
            this->slow_ctrl = this->power;
            this->slow_led.setOn(this->power);
            this->tb_ctrl = this->power;
            this->tb_led.setOn(this->power);
            this->water_ctrl = this->power;
            this->water_led.setOn(this->power);
            this->dataToNetData1();
        }
    });

    connect(ui->fast_btn, &QPushButton::clicked, this, [=]() {//快
        if (this->power)
        {
            if (this->slow_ctrl)
            {
                this->slow_led.setOn(this->slow_ctrl = !this->slow_ctrl);
            }
            this->fast_led.setOn(this->fast_ctrl = !this->fast_ctrl);
        }
    });

    connect(ui->slow_btn, &QPushButton::clicked, this, [=]() {//慢
        if (this->power)
        {
            if (this->fast_ctrl)
            {
                this->fast_led.setOn(this->fast_ctrl = !this->fast_ctrl);
            }
            this->slow_led.setOn(this->slow_ctrl = !this->slow_ctrl);
        }
    });

    connect(ui->water_btn, &QPushButton::clicked, this, [=](){//喷水
        if (this->power)
        {
            this->water_led.setOn(this->water_ctrl = !this->water_ctrl);
        }
    });

    connect(ui->tb_btn, &QPushButton::clicked, this, [=](){
        if (this->power)
        {
            this->tb_led.setOn(this->tb_ctrl = !this->tb_ctrl);
            this->l_ctrl = this->tb_ctrl;
            this->lf_ctrl = this->tb_ctrl;
            this->rf_ctrl = this->tb_ctrl;
            this->r_ctrl = this->tb_ctrl;
            this->tb_led.setOn(this->tb_ctrl);
            this->dataToNetData1();
        }
    });

    connect(ui->l_btn, &QPushButton::clicked, this, [=](){
        if (this->power)
        {
            this->l_ctrl = !this->l_ctrl;
            this->dataToNetData1();
        }
    });

    connect(ui->lf_btn, &QPushButton::clicked, this, [=](){
        if (this->power)
        {
            this->lf_ctrl = !this->lf_ctrl;
            this->dataToNetData1();
        }
    });

    connect(ui->rf_btn, &QPushButton::clicked, this, [=](){
        if (this->power)
        {
            this->rf_ctrl = !this->rf_ctrl;
            this->dataToNetData1();
        }
    });

    connect(ui->r_btn, &QPushButton::clicked, this, [=](){
        if (this->power)
        {
            this->r_ctrl = !this->r_ctrl;
            this->dataToNetData1();
        }
    });
    /////////////////////雾笛////////////////////////////////////////
}

void HxfzWidget::dataToNetData1()
{
    QByteArray data;
    data.resize(5);
    //转化区
    data[0] = 0xA2;
    data[1] = this->l_ctrl;
    data[2] = this->lf_ctrl;
    data[3] = this->rf_ctrl;
    data[4] = this->r_ctrl;
    emit this->sendData1(data);
}

void HxfzWidget::dataToNetData2()
{
    QByteArray data;
    //转化区

    emit this->sendData2(data);
}

void HxfzWidget::dataToNetData3()
{
    QByteArray data;
    //转化区

    emit this->sendData3(data);
}

void HxfzWidget::dataToNetData4()
{
    QByteArray data;
    //转化区

    emit this->sendData4(data);
}

void HxfzWidget::dataToNetData5()
{
    QByteArray data;
    //转化区

    emit this->sendData5(data);
}

void HxfzWidget::getData1(QByteArray data)//雨刮器
{
    this->l_state = static_cast<quint8>(data[1]);
    this->lf_state = static_cast<quint8>(data[2]);
    this->rf_state = static_cast<quint8>(data[3]);
    this->r_state = static_cast<quint8>(data[4]);
    this->l_led.setOn(this->l_state);
    this->lf_led.setOn(this->lf_state);
    this->rf_led.setOn(this->rf_state);
    this->r_led.setOn(this->r_state);
}

void HxfzWidget::getData2(QByteArray data)
{

}

void HxfzWidget::getData3(QByteArray data)
{

}

void HxfzWidget::getData4(QByteArray data)
{

}

void HxfzWidget::getData5(QByteArray data)
{

}


