#include "loginwidget.h"
#include "ui_loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    this->setVisible(false);
    this->setWindowModality(Qt::ApplicationModal);
    this->setMaximumSize(431, 261);
    this->setMinimumSize(431, 261);
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    this->move(1240, 450),
    ui->password_line->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    connect(ui->login_button, &QPushButton::clicked, this, [=](){
        QByteArray inputPassword;
        inputPassword = QCryptographicHash::hash(QString::number(ui->password_line->text().toInt()).toLatin1(),QCryptographicHash::Md5);
        if (inputPassword == this->realPassword)
        {
            this->setVisible(false);
            emit this->open();
        }
        else
        {
            ui->label_2->setText(QString::fromLocal8Bit("密码错误！"));
            QTimer::singleShot(2000, this, [=](){ ui->label_2->setText(QString::fromLocal8Bit(""));});
        }
    });
    connect(ui->cancel_button, &QPushButton::clicked, this, [=](){
        this->setVisible(false);
    });
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::setWindowFocus()
{
    ui->password_line->setFocus();
}

void LoginWidget::changeLight(int index)
{
    switch(index)
    {
    case 0:
        this->setStyleSheet("QDialog{background-color:rgb(6, 6, 29);border:2px solid rgb(0, 150, 255);}");
        ui->label->setStyleSheet("color: rgb(0, 255, 255);");
        ui->login_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->cancel_button->setStyleSheet("background-color:rgb(0, 255, 255);");
        ui->password_line->setStyleSheet("color: rgb(0, 255, 255);border:2px solid rgb(0, 150, 255);background-color:rgb(6, 6, 29);");
        ui->label_2->setStyleSheet("color: rgb(255, 0, 0);");
        break;
    case 1:
        this->setStyleSheet("QDialog{background-color:rgb(6, 6, 29);border:2px solid rgb(121, 121, 126);}");
        ui->label->setStyleSheet("color: rgb(121, 121, 126);");
        ui->login_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->cancel_button->setStyleSheet("background-color: rgb(121, 121, 126);");
        ui->password_line->setStyleSheet("color: rgb(121, 121, 126);border:2px solid rgb(121, 121, 126);background-color:rgb(6, 6, 29);");
        ui->label_2->setStyleSheet("color: rgb(108, 14, 21);");
        break;
    case 2:
        this->setStyleSheet("QDialog{background-color:rgb(0, 0, 0);border:2px solid rgb(80, 80, 80);}");
        ui->label->setStyleSheet("color: rgb(80, 80, 80);");
        ui->login_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->cancel_button->setStyleSheet("background-color: rgb(80, 80, 80);");
        ui->password_line->setStyleSheet("color: rgb(80, 80, 80);border:2px solid rgb(80, 80, 80);background-color:rgb(0, 0, 0);");
        ui->label_2->setStyleSheet("color: rgb(121, 121, 126);");
        break;
    }
}

void LoginWidget::getPassword(int password)
{
    this->password = password;
    this->realPassword = QCryptographicHash::hash(QString::number(this->password).toLatin1(),QCryptographicHash::Md5);
}

void LoginWidget::getMd5Password(QByteArray password)
{
    this->realPassword = password;
}
