﻿#include "meterwidget.h"
#include "ui_meterwidget.h"

MeterWidget::MeterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MeterWidget)
{
    ui->setupUi(this);
    basicTimer.start(100, this);
    m_background = Qt::black;
    m_foreground = QColor(0, 255, 255);

    m_startAngle = 90;
    m_endAngle = 90;
    m_minValue = 0;
    m_maxValue = 180;
    m_scaleMajor = 6;//分度
    m_scaleMinor = 6;
    m_units = "";
    m_title = "";
    m_precision = 0;
    m_value = 90;

    setWindowFlags(Qt::FramelessWindowHint);//无窗体
    setAttribute(Qt::WA_TranslucentBackground);//背景透明
    resize(311, 201);
}

MeterWidget::~MeterWidget()
{
    delete ui;
}

void MeterWidget::UpdateAngle(int value)
{
    this->m_value = value;
}

void MeterWidget::updateLight(int index)
{
    this->light = index;
}

void MeterWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);//一个类中的this表示一个指向该类自己的指针
    if (this->light == 0)
    {
        this->m_foreground = QColor(0, 255, 255);
    }
    else if (this->light == 1)
    {
        this->m_foreground = QColor(121, 121, 126);
    }
    else if (this->light == 2)
    {
        this->m_foreground = QColor(80, 80, 80);
    }
    painter.setRenderHint(QPainter::Antialiasing);  /* 使用反锯齿(如果可用) */
    painter.translate(width() / 2, height() - 10);   /* 坐标变换为窗体中心 */
    int side = width();//qMin(width(), height());
    painter.scale(side / 200.0, side / 200.0);      /* 比例缩放 */

   //drawCrown(&painter);                                 /* 画表盘边框 */
   drawScaleNum(&painter);                          /* 画刻度数值值 */
   drawScale(&painter);                                 /* 画刻度线 */
   drawTitle(&painter);                                     /* 画单位 */
   drawNumericValue(&painter);                      /* 画数字显示 */
   drawIndicator(&painter);                             /* 画表针 */
}

void MeterWidget::drawCrown(QPainter *painter)
{
    painter->save();
    int radius = 100;
    QLinearGradient lg1(0, -radius, 0, radius);

    lg1.setColorAt(0, Qt::white); //设置渐变的颜色和路径比例
    lg1.setColorAt(1, Qt::gray); //只是粗略的颜色，具体的可以参考RGB颜色查询对照表

    painter->setBrush(lg1); // 创建QBrush对象,把这个渐变对象传递进去：
    painter->setPen(Qt::NoPen); //边框线无色
    painter->drawEllipse(-radius, -radius, radius << 1, radius << 1);
    painter->drawEllipse(-92, -92, 184, 184);
    painter->restore();
}

void MeterWidget::drawBackground(QPainter *painter)
{

}

void MeterWidget::drawScale(QPainter *painter)
{
    painter->save();
        painter->rotate(m_startAngle);
        int steps = (m_scaleMajor * m_scaleMinor); //相乘后的值是分的份数
        double angleStep = (360.0 - m_startAngle - m_endAngle) / steps; //每一个份数的角度

        // painter->setPen(m_foreground); //m_foreground是颜色的设置
        // QPen pen = painter->pen(); //第一种方法
        QPen pen ;
        pen.setColor(m_foreground); //推荐使用第二种方式
        for (int i = 0; i <= steps; i++)
        {
            if (i % m_scaleMinor == 0)//整数刻度显示加粗
            {
                pen.setWidth(1); //设置线宽
                painter->setPen(pen); //使用面向对象的思想，把画笔关联上画家。通过画家画出来
                painter->drawLine(0, 62, 0, 72); //两个参数应该是两个坐标值
            }
            else
            {
                pen.setWidth(0);
                painter->setPen(pen);
                painter->drawLine(0, 67, 0, 72);
            }
            painter->rotate(angleStep);
        }
        painter->restore();
}

void MeterWidget::drawScaleNum(QPainter *painter)
{
    painter->save();
        painter->setPen(m_foreground);
        //m_startAngle是起始角度，m_endAngle是结束角度，m_scaleMajor在一个量程中分成的刻度数
        double startRad = ( 270-m_startAngle) * (3.14 / 180);
        double deltaRad = (360 - m_startAngle - m_endAngle) * (3.14 / 180) / m_scaleMajor;
        double sina,cosa;
        int x, y;
        QFontMetricsF fm(this->font());
        double w, h, tmpVal;
        QString str;

        for (int i = 0; i <= m_scaleMajor; i++)
        {
            sina = sin(startRad - i * deltaRad);
            cosa = cos(startRad - i * deltaRad);

           //tmpVal = 1.0 * i *((m_maxValue - m_minValue) / m_scaleMajor) + m_minValue;
           if (i < 3)
           {
                tmpVal = 90 - i * 30;
           }
           else if (i == 3)
           {
                tmpVal = 0;
           }
           else if (i > 3)
           {
                tmpVal = (i - 3) * 30;
           }
           // tmpVal = 50;
            str = QString( "%1" ).arg(tmpVal);  //%1作为占位符   arg()函数比起 sprintf()来是类型安全的
            w = fm.size(Qt::TextSingleLine,str).width();
            h = fm.size(Qt::TextSingleLine,str).height();
            x = 82 * cosa - w / 2;
            y = -82 * sina + h / 4;
            painter->drawText(x, y, str); //函数的前两个参数是显示的坐标位置，后一个是显示的内容，是字符类型""

        }
        painter->restore();
}

void MeterWidget::drawTitle(QPainter *painter)
{
    painter->save();
    painter->setPen(m_foreground);
    QString str(m_title); //显示仪表的功能
    QFontMetricsF fm(this->font());
    double w = fm.size(Qt::TextSingleLine,str).width();
    painter->drawText(-w / 2, -30, str);
    painter->restore();
}

void MeterWidget::drawIndicator(QPainter *painter)
{
    painter->save();
    QPolygon pts;
    pts.setPoints(3, -2, 0, 2, 0, 0, 60);	/* (-2,0)/(2,0)/(0,60) *///第一个参数是 ，坐标的个数。后边的是坐标

    painter->rotate(m_startAngle);
    double degRotate = (360.0 - m_startAngle - m_endAngle) / (m_maxValue - m_minValue)*(m_value - m_minValue);

    //画指针
    painter->rotate(degRotate);  //顺时针旋转坐标系统
    QRadialGradient haloGradient(0, 0, 60, 0, 0);  //辐射渐变
    haloGradient.setColorAt(0, m_foreground);
    haloGradient.setColorAt(1, m_foreground);
    painter->setPen(m_foreground); //定义线条文本颜色  设置线条的颜色
    painter->setBrush(haloGradient);//刷子定义形状如何填满 填充后的颜色
    painter->drawConvexPolygon(pts); //这是个重载函数，绘制多边形。
    painter->restore();

    //画中心点
    QColor niceBlue(0, 255, 255);
    QConicalGradient coneGradient(0, 0, -90.0);  //角度渐变
    coneGradient.setColorAt(0.0, m_foreground);
    coneGradient.setColorAt(0.2, m_foreground);
    coneGradient.setColorAt(0.5, m_foreground);
    coneGradient.setColorAt(1.0, m_foreground);
    painter->setPen(Qt::NoPen);  //没有线，填满没有边界
    painter->setBrush(coneGradient);
    painter->drawEllipse(-5, -5, 10, 10);
}

void MeterWidget::drawNumericValue(QPainter *painter)
{
    QString str = QString("%1%2").arg(m_value, 0, 'f', m_precision).arg(m_units);
    QFontMetricsF fm(font());
    double w = fm.size(Qt::TextSingleLine,str).width();
    painter->setPen(m_foreground);
    painter->drawText(-w / 2, 42, str);
}

void MeterWidget::timerEvent(QTimerEvent *event)
{
    this->update();
}
