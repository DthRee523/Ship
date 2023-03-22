#include "alarminformationwidget.h"
#include "ui_alarminformationwidget.h"

AlarmInformationWidget::AlarmInformationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmInformationWidget)
{
    ui->setupUi(this);
    tableInit();
    timerInit();
}

AlarmInformationWidget::~AlarmInformationWidget()
{
    delete ui;
}

void AlarmInformationWidget::timerInit()
{
    timer = new QTimer(this);
    timer->setInterval(500);
    timer->start();
    connect(timer, &QTimer::timeout, this, &AlarmInformationWidget::changeColor);
}

void AlarmInformationWidget::tableInit()
{
    QStringList strs = {QString::fromLocal8Bit("时间"), QString::fromLocal8Bit("报警信息"), QString::fromLocal8Bit("时间"), QString::fromLocal8Bit("报警信息")};
    ui->tableWidget->setHorizontalHeaderLabels(strs);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止编辑
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setColumnWidth(0, 350);
    ui->tableWidget->setColumnWidth(1, 475);
    ui->tableWidget->setColumnWidth(2, 350);
    ui->tableWidget->setColumnWidth(3, 475);
}

void AlarmInformationWidget::changeLight(int index)
{
    switch (index)
    {
    case 0:
        ui->tableWidget->setStyleSheet("QTableWidget{\
                                       gridline-color:rgb(0, 150, 255);\
                                       background-color:rgb(6, 6, 29);\
                                       color: rgb(0, 255, 255);\
                                       selection-background-color:rgb(6, 6, 29);\
                                       selection-color:rgb(0, 255, 255);\
                                   }\
                                   QHeaderView::section {\
                                       background-color:rgb(6, 6, 29);\
                                       color: rgb(0, 255, 255);\
                                       selection-background-color:rgb(6, 6, 29);\
                                       selection-color:rgb(0, 255, 255);\
                                   }");
        break;
    case 1:
        ui->tableWidget->setStyleSheet("QTableWidget{\
                                       gridline-color:rgb(0, 150, 255);\
                                       background-color:rgb(6, 6, 29);\
                                       color: rgb(121, 121, 126);\
                                       selection-background-color:rgb(6, 6, 29);\
                                       selection-color:rgb(121, 121, 126);\
                                   }\
                                   QHeaderView::section {\
                                       background-color:rgb(6, 6, 29);\
                                       color: rgb(121, 121, 126);\
                                       selection-background-color:rgb(6, 6, 29);\
                                       selection-color:rgb(121, 121, 126);\
                                   }");
        break;
    case 2:
        ui->tableWidget->setStyleSheet("QTableWidget{\
                                       gridline-color:rgb(0, 150, 255);\
                                       background-color:rgb(0, 0, 0);\
                                       color: rgb(80, 80, 80);\
                                       selection-background-color:rgb(0, 0, 0);\
                                       selection-color:rgb(80, 80, 80);\
                                   }\
                                   QHeaderView::section {\
                                       background-color:rgb(0, 0, 0);\
                                       color: rgb(80, 80, 80);\
                                       selection-background-color:rgb(0, 0, 0);\
                                       selection-color:rgb(80, 80, 80);\
                                   }");
        break;
    }
    this->light = index;
}

void AlarmInformationWidget::getAlarmInformationList(QStringList list)
{
    ui->tableWidget->clearContents();//清理内容 不清理表头
    if (list.size() <= 29)
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (i != 0)
                ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(list[i]));
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss")));
        }
    }
    else
    {
        for (int i = 0; i < 29; i++)
        {
            if (i != 0)
                ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(list[i]));
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss")));
        }
        for (int j = 0; j < list.size() - 29; j++)
        {
            ui->tableWidget->setItem(j, 3, new QTableWidgetItem(list[j]));
            ui->tableWidget->setItem(j, 2, new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss")));
        }
    }
}

void AlarmInformationWidget::changeColor()
{
    if (this->light == 2)
    {
        if (this->color)
        {
            ui->tableWidget->setStyleSheet("QTableWidget{\
                                           gridline-color:rgb(0, 150, 255);\
                                           background-color:rgb(0, 0, 0);\
                                           color: rgb(80, 80, 80);\
                                           selection-background-color:rgb(0, 0, 0);\
                                           selection-color:rgb(80, 80, 80);\
                                       }\
                                       QHeaderView::section {\
                                           background-color:rgb(0, 0, 0);\
                                           color: rgb(80, 80, 80);\
                                           selection-background-color:rgb(0, 0, 0);\
                                           selection-color:rgb(80, 80, 80);\
                                       }");
            color = !color;
        }
        else
        {
        ui->tableWidget->setStyleSheet("QTableWidget{\
                                       gridline-color:rgb(0, 150, 255);\
                                       background-color:rgb(0, 0, 0);\
                                       color: rgb(121, 121, 126);\
                                       selection-background-color:rgb(0, 0, 0);\
                                       selection-color:rgb(80, 80, 80);\
                                   }\
                                   QHeaderView::section {\
                                       background-color:rgb(0, 0, 0);\
                                       color: rgb(80, 80, 80);\
                                       selection-background-color:rgb(0, 0, 0);\
                                       selection-color:rgb(80, 80, 80);\
                                   }");
            color = !color;
        }
    }
    else if (this->light == 0)
    {
        if (this->color)
        {
            ui->tableWidget->setStyleSheet("QTableWidget{\
                                           gridline-color:rgb(0, 150, 255);\
                                           background-color:rgb(6, 6, 29);\
                                           color: rgb(0, 255, 255);\
                                           selection-background-color:rgb(6, 6, 29);\
                                           selection-color:rgb(0, 255, 255);\
                                       }\
                                       QHeaderView::section {\
                                           background-color:rgb(6, 6, 29);\
                                           color: rgb(0, 255, 255);\
                                           selection-background-color:rgb(6, 6, 29);\
                                           selection-color:rgb(0, 255, 255);\
                                       }");
            color = !color;
        }
        else
        {
        ui->tableWidget->setStyleSheet("QTableWidget{\
                                       gridline-color:rgb(0, 150, 255);\
                                       background-color:rgb(6, 6, 29);\
                                       color: rgb(255, 0, 0);\
                                       selection-background-color:rgb(6, 6, 29);\
                                       selection-color:rgb(0, 255, 255);\
                                   }\
                                   QHeaderView::section {\
                                       background-color:rgb(6, 6, 29);\
                                       color: rgb(0, 255, 255);\
                                       selection-background-color:rgb(6, 6, 29);\
                                       selection-color:rgb(0, 255, 255);\
                                   }");
            color = !color;
        }
    }
    else if(this->light == 1)
    {
        if (this->color)
        {
            ui->tableWidget->setStyleSheet("QTableWidget{\
                                           gridline-color:rgb(0, 150, 255);\
                                           background-color:rgb(6, 6, 29);\
                                           color: rgb(121, 121, 126);\
                                           selection-background-color:rgb(6, 6, 29);\
                                           selection-color:rgb(121, 121, 126);\
                                       }\
                                       QHeaderView::section {\
                                           background-color:rgb(6, 6, 29);\
                                           color: rgb(121, 121, 126);\
                                           selection-background-color:rgb(6, 6, 29);\
                                           selection-color:rgb(121, 121, 126);\
                                       }");
            color = !color;
        }
        else
        {
            ui->tableWidget->setStyleSheet("QTableWidget{\
                               gridline-color:rgb(0, 150, 255);\
                               background-color:rgb(6, 6, 29);\
                               color: rgb(108, 14, 21);\
                               selection-background-color:rgb(6, 6, 29);\
                               selection-color:rgb(121, 121, 126);\
                           }\
                           QHeaderView::section {\
                               background-color:rgb(6, 6, 29);\
                               color: rgb(121, 121, 126);\
                               selection-background-color:rgb(6, 6, 29);\
                               selection-color:rgb(121, 121, 126);\
                           }");
            color = !color;
        }
    }
}
