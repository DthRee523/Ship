#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "colorMeneger.h"
#include "eonic.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initWindow();
    this->mapInit();

    login_widget = new LoginWidget(this);
    network = new Network(this);
    //时间计时器
    timer = new QTimer(this);
    timer->setInterval(500);
    timer->start();

    this->connectFunctions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    painter = new QPainter(this);
    if (ui->light_comboBox->currentIndex() == 0)
    {
        painter->setPen(QPen(QColor("#0096ff"), 1));
    }
    else if (ui->light_comboBox->currentIndex() == 1)
    {
        painter->setPen(QPen(QColor("#0096ff"), 1));
    }
    else if (ui->light_comboBox->currentIndex() == 2)
    {
        painter->setPen(QPen(QColor("#505050"), 1));
    }
    painter->drawLine(0, 105, 1920, 105);
    painter->drawLine(1670, 0, 1670, 1920);
    painter->drawLine(312, 0, 312, 105);
    painter->drawLine(519, 0, 519, 105);
    painter->drawLine(762, 0, 762, 105);
    painter->drawLine(1012, 0, 1012, 105);
    painter->drawLine(762, 51, 1670, 51);
    painter->end();
}

void MainWindow::initWindow()
{
    this->setWindowTitle(QString::fromLocal8Bit("多功能船舶显示系统V1.0"));
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
}

void MainWindow::connectFunctions()
{
    connect(this->timer, &QTimer::timeout, this, &MainWindow::updateTimeLabel);
    connect(this->timer, &QTimer::timeout, ui->page, &HxInformaion::updateData);
    connect(this->timer, &QTimer::timeout, this, &MainWindow::updateData);
    connect(ui->close_button, &QPushButton::clicked, this, &MainWindow::close);
    //connect(ui->light_comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::changeLight);
    connect(ui->light_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeLight(int)));
    connect(ui->hxxx_button, &QPushButton::clicked, this, [=](){ updateAlarmInformation2(); ui->stackedWidget->setCurrentIndex(0); });
    connect(ui->bj_button, &QPushButton::clicked, this, [=](){ updateAlarmInformation2(); ui->stackedWidget->setCurrentIndex(1); });
    connect(ui->hxfz_button, &QPushButton::clicked, this, [=](){ updateAlarmInformation2(); ui->stackedWidget->setCurrentIndex(2); });
    connect(ui->sql_button, &QPushButton::clicked, this, [=]()
    {
        if (ui->stackedWidget->currentIndex() == 3)
            return;
        login_widget->getPassword(this->sqlPassword);
        login_widget->setVisible(true);
        login_widget->setWindowFocus();
    });
    connect(login_widget, &LoginWidget::open, this, [=](){
        updateAlarmInformation2();
        ui->stackedWidget->setCurrentIndex(3);
    });
    connect(ui->bj1_button, &QPushButton::clicked, this, [=]()
    {
        ui->alarm_info_lab1->clear();
        ui->alarm_info_lab2->clear();
        ui->alarm_time_lab1->clear();
        ui->alarm_time_lab2->clear();
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ui->map_button, &QPushButton::clicked, this, [=]()
    {
        updateAlarmInformation2();
        ui->stackedWidget->setCurrentIndex(5);
    });
    connect(this, &MainWindow::changeLightSignal, ui->page_4, &AlarmInformationWidget::changeLight);
    connect(this, &MainWindow::changeLightSignal, ui->page_2, &HxfzWidget::getlight);
    connect(this, &MainWindow::changeLightSignal, ui->page, &HxInformaion::changeLight);
    connect(this, &MainWindow::changeLightSignal, login_widget, &LoginWidget::changeLight);
    connect(network, &Network::sendHxData, ui->page, &HxInformaion::getData);
    connect(network, &Network::sendBaseData, this, &MainWindow::updateNetworkData);
    connect(ui->page_2, &HxfzWidget::sendData1, network, &Network::sendNetData1);
    connect(network, &Network::sendData1, ui->page_2, &HxfzWidget::getData1);
}

void MainWindow::updateTimeLabel()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    ui->timeLabel->setText(currentTime.toString("yyyy/MM/dd") + "\n" + currentTime.toString("hh:mm:ss"));

    if (ui->light_comboBox->currentIndex() == 0)
    {
        if(this->alarmColor)
        {
            ui->alarm_info_lab1->setStyleSheet("color: rgb(0, 255, 255);");
            ui->alarm_info_lab2->setStyleSheet("color: rgb(0, 255, 255);");
            ui->alarm_time_lab1->setStyleSheet("color: rgb(0, 255, 255);");
            ui->alarm_time_lab2->setStyleSheet("color: rgb(0, 255, 255);");
            this->alarmColor = !this->alarmColor;
        }
        else
        {
            ui->alarm_info_lab1->setStyleSheet("color: rgb(255, 0, 0);");
            ui->alarm_info_lab2->setStyleSheet("color: rgb(255, 0, 0);");
            ui->alarm_time_lab1->setStyleSheet("color: rgb(255, 0, 0);");
            ui->alarm_time_lab2->setStyleSheet("color: rgb(255, 0, 0);");
            this->alarmColor = !this->alarmColor;
        }
    }
    else if (ui->light_comboBox->currentIndex() == 2)
    {
        if(this->alarmColor)
        {
            ui->alarm_info_lab1->setStyleSheet("color: rgb(121, 121, 126);");
            ui->alarm_info_lab2->setStyleSheet("color: rgb(121, 121, 126);");
            ui->alarm_time_lab1->setStyleSheet("color: rgb(121, 121, 126);");
            ui->alarm_time_lab2->setStyleSheet("color: rgb(121, 121, 126);");
            this->alarmColor = !this->alarmColor;
        }
        else
        {
            ui->alarm_info_lab1->setStyleSheet("color: rgb(80, 80, 80);");
            ui->alarm_info_lab2->setStyleSheet("color: rgb(80, 80, 80);");
            ui->alarm_time_lab1->setStyleSheet("color: rgb(80, 80, 80);");
            ui->alarm_time_lab2->setStyleSheet("color: rgb(80, 80, 80);");
            this->alarmColor = !this->alarmColor;
        }
    }
    else if (ui->light_comboBox->currentIndex() == 1)
    {
        if (this->alarmColor)
        {
            ui->alarm_info_lab1->setStyleSheet("color: rgb(121, 121, 126);");
            ui->alarm_info_lab2->setStyleSheet("color: rgb(121, 121, 126);");
            ui->alarm_time_lab1->setStyleSheet("color: rgb(121, 121, 126);");
            ui->alarm_time_lab2->setStyleSheet("color: rgb(121, 121, 126);");
            this->alarmColor = !this->alarmColor;
        }
        else
        {
            ui->alarm_info_lab1->setStyleSheet("color: rgb(108, 14, 21);");
            ui->alarm_info_lab2->setStyleSheet("color: rgb(108, 14, 21);");
            ui->alarm_time_lab1->setStyleSheet("color: rgb(108, 14, 21);");
            ui->alarm_time_lab2->setStyleSheet("color: rgb(108, 14, 21);");
            this->alarmColor = !this->alarmColor;
        }
    }
}

void MainWindow::changeLight(int index)
{
    switch(index)
    {
    case 0://白天
    {
        this->setStyleSheet("MainWindow{background-color:rgb(6, 6, 29);}");
        ui->close_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->hxxx_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->bj_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->hxfz_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->sql_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->bj1_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->map_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->light_comboBox->setStyleSheet("background-color:rgb(0, 255, 255);selection-background-color:rgb(0, 255, 255);selection-color: rgb(0, 0, 0);");
        ui->timeLabel->setStyleSheet("color: rgb(0, 255, 255);");
        ui->label->setStyleSheet("color: rgb(0, 150, 255);");
        ui->label_2->setStyleSheet("color: rgb(0, 150, 255);");
        ui->label_3->setStyleSheet("color: rgb(0, 150, 255);");
        ui->label_4->setStyleSheet("color: rgb(0, 150, 255);");
        ui->position_lab->setStyleSheet("color: rgb(0, 255, 255);");
        ui->speed_lab->setStyleSheet("color: rgb(0, 255, 255);");
        ui->sx_lab->setStyleSheet("color: rgb(0, 255, 255);");
        ui->alarm_info_lab1->setStyleSheet("color: rgb(0, 255, 255);");
        ui->alarm_info_lab2->setStyleSheet("color: rgb(0, 255, 255);");
        ui->alarm_time_lab1->setStyleSheet("color: rgb(0, 255, 255);");
        ui->alarm_time_lab2->setStyleSheet("color: rgb(0, 255, 255);");
        ht_Palette(3);
        break;
    }
    case 1://黄昏
    {
        this->setStyleSheet("MainWindow{background-color:rgb(6, 6, 29);}");
        ui->close_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->hxxx_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->bj_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->hxfz_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->sql_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->bj1_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->map_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->light_comboBox->setStyleSheet("background-color: rgb(121, 121, 126);selection-background-color:rgb(121, 121, 126);selection-color: rgb(0, 0, 0);");
        ui->timeLabel->setStyleSheet("color: rgb(121, 121, 126);");
        ui->label->setStyleSheet("color: rgb(121, 121, 126);");
        ui->label_2->setStyleSheet("color: rgb(121, 121, 126);");
        ui->label_3->setStyleSheet("color: rgb(121, 121, 126);");
        ui->label_4->setStyleSheet("color: rgb(121, 121, 126);");
        ui->position_lab->setStyleSheet("color: rgb(121, 121, 126);");
        ui->speed_lab->setStyleSheet("color: rgb(121, 121, 126);");
        ui->sx_lab->setStyleSheet("color: rgb(121, 121, 126);");
        ui->alarm_info_lab1->setStyleSheet("color: rgb(121, 121, 126);");
        ui->alarm_info_lab2->setStyleSheet("color: rgb(121, 121, 126);");
        ui->alarm_time_lab1->setStyleSheet("color: rgb(121, 121, 126);");
        ui->alarm_time_lab2->setStyleSheet("color: rgb(121, 121, 126);");
        ht_Palette(0);
    }
        break;
    case 2://黑夜
    {
        this->setStyleSheet("MainWindow{background-color:rgb(0, 0, 0);}");
        ui->close_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->hxxx_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->bj_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->hxfz_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->sql_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->bj1_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->map_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->light_comboBox->setStyleSheet("background-color: rgb(80, 80, 80);selection-background-color:rgb(80, 80, 80);selection-color: rgb(0, 0, 0);");
        ui->timeLabel->setStyleSheet("color: rgb(80, 80, 80);");
        ui->label->setStyleSheet("color: rgb(80, 80, 80);");
        ui->label_2->setStyleSheet("color: rgb(80, 80, 80);");
        ui->label_3->setStyleSheet("color: rgb(80, 80, 80);");
        ui->label_4->setStyleSheet("color: rgb(80, 80, 80);");
        ui->position_lab->setStyleSheet("color: rgb(80, 80, 80);");
        ui->speed_lab->setStyleSheet("color: rgb(80, 80, 80);");
        ui->sx_lab->setStyleSheet("color: rgb(80, 80, 80);");
        ui->alarm_info_lab1->setStyleSheet("color: rgb(80, 80, 80);");
        ui->alarm_info_lab2->setStyleSheet("color: rgb(80, 80, 80);");
        ui->alarm_time_lab1->setStyleSheet("color: rgb(80, 80, 80);");
        ui->alarm_time_lab2->setStyleSheet("color: rgb(80, 80, 80);");
        ht_Palette(1);
        break;
    }
    }
    emit this->changeLightSignal(index);
}

void MainWindow::updateAlarmInformation(QStringList information)
{
    if (information.isEmpty())
    {
        this->alarmTitle1.clear();
        this->alarmTitle2.clear();
        this->alarmTitleTime1.clear();
        this->alarmTitleTime2.clear();
    }
    else if (information.size() == 1)
    {
        this->alarmTitleTime1 = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
        this->alarmTitle1 = information[0];

        this->alarmTitle2.clear();
        this->alarmTitleTime2.clear();
    }
    else
    {
        this->alarmTitleTime1 = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
        this->alarmTitle1 = information[0];

        this->alarmTitle2 = information[1];
        this->alarmTitleTime2 = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
    }

    ui->alarm_info_lab1->setText(this->alarmTitle1);
    ui->alarm_info_lab2->setText(this->alarmTitle2);
    ui->alarm_time_lab1->setText(this->alarmTitleTime1);
    ui->alarm_time_lab2->setText(this->alarmTitleTime2);

    ui->page_4->getAlarmInformationList(information);
}

void MainWindow::updateAlarmInformation2()
{
    ui->alarm_info_lab1->setText(this->alarmTitle1);
    ui->alarm_info_lab2->setText(this->alarmTitle2);
    ui->alarm_time_lab1->setText(this->alarmTitleTime1);
    ui->alarm_time_lab2->setText(this->alarmTitleTime2);
}

void MainWindow::mapInit()
{
    ht_SetDebugLevel(0);
    ht_Init("ECDIS");
    ht_Set_Central_Point(22.13, 114.5);
    ht_Set_mPixel(300);
    ht_Set_License("84065046023802818677");
    ht_Palette(3);
}

void MainWindow::updateData()
{
    //经纬度转度分秒
    QString lat_z = this->lat > 0 ? QString::fromLocal8Bit("N") : QString::fromLocal8Bit("S");
    QString lon_z = this->lon > 0 ? QString::fromLocal8Bit("E") : QString::fromLocal8Bit("W");
    int lat_d = qAbs((int)this->lat);
    int lat_f = (int)((qAbs(this->lat) - lat_d)*60);
    int lat_m = (int)(((qAbs(this->lat) - lat_d)*60 - lat_f) * 60);
    int lon_d = qAbs((int)this->lon);
    int lon_f = (int)((qAbs(this->lon) - lon_d)*60);
    int lon_m = (int)(((qAbs(this->lon) - lon_d)*60 - lon_f) * 60);
    ui->position_lab->setText(QString::number(lat_d) +
                              QString::fromLocal8Bit("°") +
                              QString::number(lat_f) +
                              QString::fromLocal8Bit("′") +
                              QString::number(lat_m) +
                              QString::fromLocal8Bit("″") +
                              lat_z +
                              QString::fromLocal8Bit("\n") +
                              QString::number(lon_d) +
                              QString::fromLocal8Bit("°") +
                              QString::number(lon_f) +
                              QString::fromLocal8Bit("′") +
                              QString::number(lon_m) +
                              QString::fromLocal8Bit("″") +
                              lon_z);
    ui->speed_lab->setText(QString::number(this->speed) + QString::fromLocal8Bit("Kn"));
    ui->sx_lab->setText(QString::number(this->sx) + QString::fromLocal8Bit("°"));
}

void MainWindow::updateNetworkData(double lat, double lon, int speed, int sx)
{
    this->lat = lat;
    this->lon = lon;
    this->speed = speed;
    this->sx = sx;
}

