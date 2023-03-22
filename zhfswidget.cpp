#include "zhfswidget.h"
#include "ui_zhfswidget.h"

ZhfsWidget::ZhfsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZhfsWidget)
{
    ui->setupUi(this);
}

ZhfsWidget::~ZhfsWidget()
{
    delete ui;
}
