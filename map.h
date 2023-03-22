#ifndef MAP_H
#define MAP_H

#include <QBasicTimer>
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>

class Map : public QOpenGLWidget
{
    Q_OBJECT
public:
    Map(QWidget* parent = nullptr);
    void updatePo(double lat, double lon);
    ~Map();

protected:
    void paintGL() override;
    void timerEvent(QTimerEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    QBasicTimer updateTimer;
    int mousex = 0;
    int mousey = 0;
    double lat = 22.13;//纬度
    double lon = 114.5;//经度
    int mPixel = 300;
};

#endif // MAP_H
