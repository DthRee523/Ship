#include "map.h"

#include "eonic.h"
#include <QDebug>

Map::Map(QWidget* parent)
    : QOpenGLWidget(parent)
{
    this->updateTimer.start(10, this);
}

Map::~Map()
{

}

void Map::paintGL()
{
    ht_Set_Viewport(0, 0, this->width(), this->height());
    ht_Draw_Flash();
}

void Map::timerEvent(QTimerEvent* event)
{
    this->update();
}

void Map::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        ht_UI_to_BL((mousex - event->pos().x())*1.5, (event->pos().y() - mousey)*1.5, &this->lat, &this->lon);//设置中心点
        ht_Set_Central_Point(this->lat, this->lon);
        this->mousex = event->pos().x();
        this->mousey = event->pos().y();
    }
}

void Map::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        this->mousex = event->pos().x();
        this->mousey = event->pos().y();
    }
}

void Map::updatePo(double lat, double lon)
{
    this->lat = lat;
    this->lon = lon;
    ht_Set_Central_Point(this->lat, this->lon);
}

void Map::wheelEvent(QWheelEvent *event)
{
    if(event->delta() > 0){
        this->mPixel -= 10;
        ht_Set_mPixel(this->mPixel);//放大
    }else{
        this->mPixel += 10;
        ht_Set_mPixel(this->mPixel);//缩小
    }
}
