#ifndef ZHFSWIDGET_H
#define ZHFSWIDGET_H

#include <QWidget>

namespace Ui {
class ZhfsWidget;
}

class ZhfsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ZhfsWidget(QWidget *parent = nullptr);
    ~ZhfsWidget();

private:
    Ui::ZhfsWidget *ui;
};

#endif // ZHFSWIDGET_H
