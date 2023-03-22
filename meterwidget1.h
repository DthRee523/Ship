#ifndef METERWIDGET1_H
#define METERWIDGET1_H

#include <QWidget>
#include <QPaintEvent>
#include <QTimer>
#include <QPainter>
#include <QDebug>
#include <QBasicTimer>

namespace Ui {
class MeterWidget1;
}

class MeterWidget1 : public QWidget
{
    Q_OBJECT

public:
    explicit MeterWidget1(QWidget *parent = nullptr);
    ~MeterWidget1();

private:
    Ui::MeterWidget1 *ui;
    QColor m_background;
    QColor m_foreground;

    int m_maxValue;
    int m_minValue;
    int m_startAngle;
    int m_endAngle;

    int m_scaleMajor;
    int m_scaleMinor;
    double m_value;
    int m_precision;
    QString m_units;
    QString m_title;

    int light = 0;
    QBasicTimer basicTimer;
public Q_SLOTS:
    void UpdateAngle(int value);
    void updateLight(int index);


protected:
    void paintEvent(QPaintEvent *event) override;
    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawIndicator(QPainter *painter);
    void drawNumericValue(QPainter *painter);
    void timerEvent(QTimerEvent *event);
};

#endif // METERWIDGET1_H
