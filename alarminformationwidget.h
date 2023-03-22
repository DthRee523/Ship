#ifndef ALARMINFORMATIONWIDGET_H
#define ALARMINFORMATIONWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QDateTime>

namespace Ui {
class AlarmInformationWidget;
}

class AlarmInformationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmInformationWidget(QWidget *parent = nullptr);
    ~AlarmInformationWidget();

    void tableInit();
    void timerInit();
    void getAlarmInformationList(QStringList list);

public slots:
    void changeLight(int index);
    void changeColor();

private:
    Ui::AlarmInformationWidget *ui;
    QTimer *timer;
    int color = 0;
    int light = 0;
};

#endif // ALARMINFORMATIONWIDGET_H
