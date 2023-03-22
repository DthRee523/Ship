#include "hxfzwidget.h"
#include "ui_hxfzwidget.h"

HxfzWidget::HxfzWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HxfzWidget)
{
    ui->setupUi(this);
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
        ui->tabWidget->setStyleSheet(qss);break;
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
        ui->tabWidget->setStyleSheet(qss);break;
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
        ui->tabWidget->setStyleSheet(qss);break;
    }
}
