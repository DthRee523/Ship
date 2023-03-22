#ifndef HXFZWIDGET_H
#define HXFZWIDGET_H

#include <QWidget>

namespace Ui {
class HxfzWidget;
}

class HxfzWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HxfzWidget(QWidget *parent = nullptr);
    ~HxfzWidget();
    void getlight(int index);

private:
    Ui::HxfzWidget *ui;
};

#endif // HXFZWIDGET_H
