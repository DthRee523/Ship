#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QDialog>
#include <QTimer>
#include <QRegExpValidator>

namespace Ui {
class LoginWidget;
}

class LoginWidget : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();
    void setWindowFocus();//设置焦点

signals:
    void open();

public slots:
    void changeLight(int index);
    void getPassword(int password);

private:
    Ui::LoginWidget *ui;
    int password;
};

#endif // LOGINWIDGET_H
