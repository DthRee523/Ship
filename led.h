#ifndef LED_H
#define LED_H

#include <QWidget>
#include <QPainter>
#include <QBasicTimer>

namespace Ui {
class LED;
}

class LED : public QWidget
{
    Q_OBJECT

public:
    explicit LED(QWidget *parent = nullptr);
    ~LED();
    void setOn(int isOn);
    void changeLight(int index);

private:
    Ui::LED *ui;
    int isOn = 0;
    int light = 0;
    QBasicTimer timer;

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
};

#endif // LED_H
