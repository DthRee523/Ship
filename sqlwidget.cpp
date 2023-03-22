#include "sqlwidget.h"
#include "ui_sqlwidget.h"

SqlWidget::SqlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SqlWidget)
{
    ui->setupUi(this);
}

SqlWidget::~SqlWidget()
{
    delete ui;
}
