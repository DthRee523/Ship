#ifndef SQLWIDGET_H
#define SQLWIDGET_H

#include <QWidget>
#include <QSqlDriver>
#include <QSqlDatabase>

namespace Ui {
class SqlWidget;
}

class SqlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SqlWidget(QWidget *parent = nullptr);
    ~SqlWidget();

private:
    Ui::SqlWidget *ui;
};

#endif // SQLWIDGET_H
