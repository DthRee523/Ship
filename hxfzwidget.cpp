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
    ui->wd_power_layout->addWidget(&wd_power_led);
    ui->lf1_window_layout->addWidget(&l1_wd_led);
    ui->lf2_window_layout->addWidget(&l2_wd_led);
    ui->l1_window_layout->addWidget(&l3_wd_led);
    ui->l2_window_layout->addWidget(&l4_wd_led);
    ui->rf1_window_layout->addWidget(&r1_wd_led);
    ui->rf2_window_layout->addWidget(&r2_wd_led);
    ui->r1_window_layout->addWidget(&r3_wd_led);
    ui->r2_window_layout->addWidget(&r4_wd_led);
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
        ui->background_lab_2->setStyleSheet(backQss1);
        ui->background_lab_3->setStyleSheet(backQss1);
        ui->background_lab_4->setStyleSheet(backQss1);
        ui->background_lab_9->setStyleSheet(backQss1);
        ui->background_lab->setStyleSheet(backQss1);
        ui->label_10->setStyleSheet(valueQss1);
        ui->label_11->setStyleSheet(valueQss1);
        ui->label_12->setStyleSheet(valueQss1);
        ui->label_20->setStyleSheet(valueQss1);
        ui->label_21->setStyleSheet(valueQss1);
        ui->label->setStyleSheet(textQss1);
        ui->label_2->setStyleSheet(textQss1);
        ui->label_5->setStyleSheet(textQss1);
        ui->du_120_btn->setStyleSheet(buttonQss1);
        ui->dudada_120_btn->setStyleSheet(buttonQss1);
        ui->dudu_120_btn->setStyleSheet(buttonQss1);
        ui->dudadada_120_btn->setStyleSheet(buttonQss1);
        ui->du_60_btn->setStyleSheet(buttonQss1);
        ui->daduda_60_btn->setStyleSheet(buttonQss1);
        ui->wd_open_btn->setStyleSheet(buttonQss1);
        ui->wd_close_btn->setStyleSheet(buttonQss1);
        ui->label_22->setStyleSheet(textQss1);
        ui->label_23->setStyleSheet(textQss1);
        ui->label_24->setStyleSheet(textQss1);
        ui->label_25->setStyleSheet(textQss1);
        ui->label_26->setStyleSheet(textQss1);
        ui->label_27->setStyleSheet(textQss1);
        ui->label_28->setStyleSheet(textQss1);
        ui->label_9->setStyleSheet(textQss1);
        ui->l_window_btn->setStyleSheet(buttonQss1);
        ui->lf_window_btn->setStyleSheet(buttonQss1);
        ui->rf_window_btn->setStyleSheet(buttonQss1);
        ui->r_window_btn->setStyleSheet(buttonQss1);
        ui->l_window_back_lab->setStyleSheet(back1Qss1);
        ui->lf_window_back_lab->setStyleSheet(back1Qss1);
        ui->rf_window_back_lab->setStyleSheet(back1Qss1);
        ui->r_window_back_lab->setStyleSheet(back1Qss1);
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
        ui->background_lab_2->setStyleSheet(backQss2);
        ui->background_lab_3->setStyleSheet(backQss2);
        ui->background_lab_4->setStyleSheet(backQss2);
        ui->background_lab_9->setStyleSheet(backQss2);
        ui->background_lab->setStyleSheet(backQss2);
        ui->label_10->setStyleSheet(valueQss2);
        ui->label_11->setStyleSheet(valueQss2);
        ui->label_12->setStyleSheet(valueQss2);
        ui->label_20->setStyleSheet(valueQss2);
        ui->label_21->setStyleSheet(valueQss2);
        ui->label->setStyleSheet(textQss2);
        ui->label_2->setStyleSheet(textQss2);
        ui->label_5->setStyleSheet(textQss2);
        ui->du_120_btn->setStyleSheet(buttonQss2);
        ui->dudada_120_btn->setStyleSheet(buttonQss2);
        ui->dudu_120_btn->setStyleSheet(buttonQss2);
        ui->dudadada_120_btn->setStyleSheet(buttonQss2);
        ui->du_60_btn->setStyleSheet(buttonQss2);
        ui->daduda_60_btn->setStyleSheet(buttonQss2);
        ui->wd_open_btn->setStyleSheet(buttonQss2);
        ui->wd_close_btn->setStyleSheet(buttonQss2);
        ui->label_22->setStyleSheet(textQss2);
        ui->label_23->setStyleSheet(textQss2);
        ui->label_24->setStyleSheet(textQss2);
        ui->label_25->setStyleSheet(textQss2);
        ui->label_26->setStyleSheet(textQss2);
        ui->label_27->setStyleSheet(textQss2);
        ui->label_28->setStyleSheet(textQss2);
        ui->label_9->setStyleSheet(textQss2);
        ui->l_window_btn->setStyleSheet(buttonQss2);
        ui->lf_window_btn->setStyleSheet(buttonQss2);
        ui->rf_window_btn->setStyleSheet(buttonQss2);
        ui->r_window_btn->setStyleSheet(buttonQss2);
        ui->l_window_back_lab->setStyleSheet(back1Qss2);
        ui->lf_window_back_lab->setStyleSheet(back1Qss2);
        ui->rf_window_back_lab->setStyleSheet(back1Qss2);
        ui->r_window_back_lab->setStyleSheet(back1Qss2);
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
        ui->background_lab_2->setStyleSheet(backQss3);
        ui->background_lab_3->setStyleSheet(backQss3);
        ui->background_lab_4->setStyleSheet(backQss3);
        ui->background_lab_9->setStyleSheet(backQss3);
        ui->background_lab->setStyleSheet(backQss3);
        ui->label_10->setStyleSheet(valueQss3);
        ui->label_11->setStyleSheet(valueQss3);
        ui->label_12->setStyleSheet(valueQss3);
        ui->label_20->setStyleSheet(valueQss3);
        ui->label_21->setStyleSheet(valueQss3);
        ui->label->setStyleSheet(textQss3);
        ui->label_2->setStyleSheet(textQss3);
        ui->label_5->setStyleSheet(textQss3);
        ui->du_120_btn->setStyleSheet(buttonQss3);
        ui->dudada_120_btn->setStyleSheet(buttonQss3);
        ui->dudu_120_btn->setStyleSheet(buttonQss3);
        ui->dudadada_120_btn->setStyleSheet(buttonQss3);
        ui->du_60_btn->setStyleSheet(buttonQss3);
        ui->daduda_60_btn->setStyleSheet(buttonQss3);
        ui->wd_open_btn->setStyleSheet(buttonQss3);
        ui->wd_close_btn->setStyleSheet(buttonQss3);
        ui->label_22->setStyleSheet(textQss3);
        ui->label_23->setStyleSheet(textQss3);
        ui->label_24->setStyleSheet(textQss3);
        ui->label_25->setStyleSheet(textQss3);
        ui->label_26->setStyleSheet(textQss3);
        ui->label_27->setStyleSheet(textQss3);
        ui->label_28->setStyleSheet(textQss3);
        ui->label_9->setStyleSheet(textQss3);
        ui->l_window_btn->setStyleSheet(buttonQss3);
        ui->lf_window_btn->setStyleSheet(buttonQss3);
        ui->rf_window_btn->setStyleSheet(buttonQss3);
        ui->r_window_btn->setStyleSheet(buttonQss3);
        ui->l_window_back_lab->setStyleSheet(back1Qss3);
        ui->lf_window_back_lab->setStyleSheet(back1Qss3);
        ui->rf_window_back_lab->setStyleSheet(back1Qss3);
        ui->r_window_back_lab->setStyleSheet(back1Qss3);
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
    this->wd_power_led.changeLight(index);
    this->l1_wd_led.changeLight(index);
    this->l2_wd_led.changeLight(index);
    this->l3_wd_led.changeLight(index);
    this->l4_wd_led.changeLight(index);
    this->r1_wd_led.changeLight(index);
    this->r2_wd_led.changeLight(index);
    this->r3_wd_led.changeLight(index);
    this->r4_wd_led.changeLight(index);
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


