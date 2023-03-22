#include "hxinformaion.h"
#include "ui_hxinformaion.h"

HxInformaion::HxInformaion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HxInformaion)
{
    ui->setupUi(this);
    ui->pBar_left->setMaximum(100);
    ui->pBar_right->setMaximum(100);
    ui->pBar_ym->setMaximum(100);
    ui->pBar_ym_1->setMaximum(100);
    ui->pBar_ry->setMaximum(100);
    ui->pBar_left->setValue(this->power_left_gk * 100);
    ui->pBar_right->setValue(this->power_right_gk * 100);
    ui->pBar_ym->setValue(this->ym_value);
    ui->pBar_ym_1->setValue(this->ym_value_1);
    ui->pBar_ry->setValue(this->ry_value);
    //ui->pBar_left->setStyleSheet("QProgressBar{background:rgb(255,255,255);} QProgressBar::chunk{background:rgb(0,0,255)}");
    ui->power_left_gk_lab->setText(QString::number(this->power_left_gk));
    ui->power_right_gk_lab->setText(QString::number(this->power_right_gk));
    ui->ym_lab->setText(QString::number(this->ym_value) + "%");
    ui->ym_lab_1->setText(QString::number(this->ym_value_1) + "%");
    ui->ry_lab->setText(QString::number(this->ry_value) + "%");
    ui->power_left_dw->setText(this->updateDw(this->power_left_dw));
    ui->power_right_dw->setText(this->updateDw(this->power_right_dw));
    ui->ele_state_1->setText(this->updateEleState(this->ele1_state));
    ui->ele1_V->setText(QString::number(this->ele1_V) + "V");
    ui->ele1_A->setText(QString::number(this->ele1_A) + "A");
    ui->ele_state_2->setText(this->updateEleState(this->ele2_state));
    ui->ele2_V->setText(QString::number(this->ele2_V) + "V");
    ui->ele2_A->setText(QString::number(this->ele2_A) + "A");
    this->updateEleAnState(this->ele_an_state);
    ui->ele_an_V->setText(QString::number(this->ele_an_V) + "V");
    ui->ele_an_A->setText(QString::number(this->ele_an_A) + "A");
    this->updatePower1State(this->power_left_state);
    this->updatePower2State(this->power_right_state);
    this->updateEle1State(this->ele1_state_1);
    this->updateEle2State(this->ele2_state_2);
}

HxInformaion::~HxInformaion()
{
    delete ui;
}

void HxInformaion::changeLight(int index)
{
    switch (index) {
    case 0:
        ui->pBar_left->setStyleSheet(pBarQss1);
        ui->pBar_right->setStyleSheet(pBarQss1);
        ui->pBar_ym->setStyleSheet(pBarQss1);
        ui->pBar_ym_1->setStyleSheet(pBarQss1);
        ui->pBar_ry->setStyleSheet(pBarQss1);
        ui->label_4->setStyleSheet(textQss1);
        ui->label_5->setStyleSheet(textQss1);
        ui->label_6->setStyleSheet(textQss1);
        ui->label_7->setStyleSheet(textQss1);
        ui->label_8->setStyleSheet(textQss1);
        ui->label_9->setStyleSheet(textQss1);
        ui->label_11->setStyleSheet(textQss1);
        ui->label_12->setStyleSheet(textQss1);
        ui->label_13->setStyleSheet(textQss1);
        ui->label_14->setStyleSheet(textQss1);
        ui->label_15->setStyleSheet(textQss1);
        ui->label_16->setStyleSheet(textQss1);
        ui->label_17->setStyleSheet(textQss1);
        ui->label_18->setStyleSheet(textQss1);
        ui->label_19->setStyleSheet(textQss1);
        ui->label_20->setStyleSheet(textQss1);
        ui->label_21->setStyleSheet(textQss1);
        ui->power_left_gk_lab->setStyleSheet(valueQss1);
        ui->power_left_dw->setStyleSheet(valueQss1);
        ui->power_right_gk_lab->setStyleSheet(valueQss1);
        ui->power_right_dw->setStyleSheet(valueQss1);
        ui->ym_lab->setStyleSheet(valueQss1);
        ui->ym_lab_1->setStyleSheet(valueQss1);
        ui->ry_lab->setStyleSheet(valueQss1);
        ui->ele1_V->setStyleSheet(valueQss1);
        ui->ele1_A->setStyleSheet(valueQss1);
        ui->ele_state_1->setStyleSheet(valueQss1);
        ui->ele2_V->setStyleSheet(valueQss1);
        ui->ele2_A->setStyleSheet(valueQss1);
        ui->ele_state_2->setStyleSheet(valueQss1);
        ui->ele_an_V->setStyleSheet(valueQss1);
        ui->ele_an_A->setStyleSheet(valueQss1);
        ui->ele_an_state->setStyleSheet(valueQss1);
        ui->label->setStyleSheet(titleQss1);
        ui->label_2->setStyleSheet(titleQss1);
        ui->label_3->setStyleSheet(titleQss1);
        ui->label_10->setStyleSheet(titleQss1);
        break;
    case 1:
        ui->pBar_left->setStyleSheet(pBarQss2);
        ui->pBar_right->setStyleSheet(pBarQss2);
        ui->pBar_ym->setStyleSheet(pBarQss2);
        ui->pBar_ym_1->setStyleSheet(pBarQss2);
        ui->pBar_ry->setStyleSheet(pBarQss2);
        ui->label_4->setStyleSheet(textQss2);
        ui->label_5->setStyleSheet(textQss2);
        ui->label_6->setStyleSheet(textQss2);
        ui->label_7->setStyleSheet(textQss2);
        ui->label_8->setStyleSheet(textQss2);
        ui->label_9->setStyleSheet(textQss2);
        ui->label_11->setStyleSheet(textQss2);
        ui->label_12->setStyleSheet(textQss2);
        ui->label_13->setStyleSheet(textQss2);
        ui->label_14->setStyleSheet(textQss2);
        ui->label_15->setStyleSheet(textQss2);
        ui->label_16->setStyleSheet(textQss2);
        ui->label_17->setStyleSheet(textQss2);
        ui->label_18->setStyleSheet(textQss2);
        ui->label_19->setStyleSheet(textQss2);
        ui->label_20->setStyleSheet(textQss2);
        ui->label_21->setStyleSheet(textQss2);
        ui->power_left_gk_lab->setStyleSheet(valueQss2);
        ui->power_left_dw->setStyleSheet(valueQss2);
        ui->power_right_gk_lab->setStyleSheet(valueQss2);
        ui->power_right_dw->setStyleSheet(valueQss2);
        ui->ym_lab->setStyleSheet(valueQss2);
        ui->ym_lab_1->setStyleSheet(valueQss2);
        ui->ry_lab->setStyleSheet(valueQss2);
        ui->ele1_V->setStyleSheet(valueQss2);
        ui->ele1_A->setStyleSheet(valueQss2);
        ui->ele_state_1->setStyleSheet(valueQss2);
        ui->ele2_V->setStyleSheet(valueQss2);
        ui->ele2_A->setStyleSheet(valueQss2);
        ui->ele_state_2->setStyleSheet(valueQss2);
        ui->ele_an_V->setStyleSheet(valueQss2);
        ui->ele_an_A->setStyleSheet(valueQss2);
        ui->ele_an_state->setStyleSheet(valueQss2);
        ui->label->setStyleSheet(titleQss2);
        ui->label_2->setStyleSheet(titleQss2);
        ui->label_3->setStyleSheet(titleQss2);
        ui->label_10->setStyleSheet(titleQss2);
        break;
    case 2:
        ui->pBar_left->setStyleSheet(pBarQss3);
        ui->pBar_right->setStyleSheet(pBarQss3);
        ui->pBar_ym->setStyleSheet(pBarQss3);
        ui->pBar_ym_1->setStyleSheet(pBarQss3);
        ui->pBar_ry->setStyleSheet(pBarQss3);
        ui->label_4->setStyleSheet(textQss3);
        ui->label_5->setStyleSheet(textQss3);
        ui->label_6->setStyleSheet(textQss3);
        ui->label_7->setStyleSheet(textQss3);
        ui->label_8->setStyleSheet(textQss3);
        ui->label_9->setStyleSheet(textQss3);
        ui->label_11->setStyleSheet(textQss3);
        ui->label_12->setStyleSheet(textQss3);
        ui->label_13->setStyleSheet(textQss3);
        ui->label_14->setStyleSheet(textQss3);
        ui->label_15->setStyleSheet(textQss3);
        ui->label_16->setStyleSheet(textQss3);
        ui->label_17->setStyleSheet(textQss3);
        ui->label_18->setStyleSheet(textQss3);
        ui->label_19->setStyleSheet(textQss3);
        ui->label_20->setStyleSheet(textQss3);
        ui->label_21->setStyleSheet(textQss3);
        ui->power_left_gk_lab->setStyleSheet(valueQss3);
        ui->power_left_dw->setStyleSheet(valueQss3);
        ui->power_right_gk_lab->setStyleSheet(valueQss3);
        ui->power_right_dw->setStyleSheet(valueQss3);
        ui->ym_lab->setStyleSheet(valueQss3);
        ui->ym_lab_1->setStyleSheet(valueQss3);
        ui->ry_lab->setStyleSheet(valueQss3);
        ui->ele1_V->setStyleSheet(valueQss3);
        ui->ele1_A->setStyleSheet(valueQss3);
        ui->ele_state_1->setStyleSheet(valueQss3);
        ui->ele2_V->setStyleSheet(valueQss3);
        ui->ele2_A->setStyleSheet(valueQss3);
        ui->ele_state_2->setStyleSheet(valueQss3);
        ui->ele_an_V->setStyleSheet(valueQss3);
        ui->ele_an_A->setStyleSheet(valueQss3);
        ui->ele_an_state->setStyleSheet(valueQss3);
        ui->label->setStyleSheet(titleQss3);
        ui->label_2->setStyleSheet(titleQss3);
        ui->label_3->setStyleSheet(titleQss3);
        ui->label_10->setStyleSheet(titleQss3);
        break;
    }
    ui->duo_widget->updateLight(index);
    ui->duo1_widget->updateLight(index);
    this->light = index;
}

void HxInformaion::updateData()
{
    ui->pBar_left->setValue(this->power_left_gk * 100);
    ui->pBar_right->setValue(this->power_right_gk * 100);
    ui->pBar_ym->setValue(this->ym_value);
    ui->pBar_ym_1->setValue(this->ym_value_1);
    ui->power_left_gk_lab->setText(QString::number(this->power_left_gk));
    ui->power_right_gk_lab->setText(QString::number(this->power_right_gk));
    ui->ym_lab->setText(QString::number(this->ym_value) + "%");
    ui->ym_lab_1->setText(QString::number(this->ym_value_1) + "%");
    ui->ry_lab->setText(QString::number(this->ry_value) + "%");
    ui->power_left_dw->setText(this->updateDw(this->power_left_dw));
    ui->power_right_dw->setText(this->updateDw(this->power_right_dw));
    ui->ele_state_1->setText(this->updateEleState(this->ele1_state));
    ui->ele1_V->setText(QString::number(this->ele1_V) + "V");
    ui->ele1_A->setText(QString::number(this->ele1_A) + "A");
    ui->ele_state_2->setText(this->updateEleState(this->ele2_state));
    ui->ele2_V->setText(QString::number(this->ele2_V) + "V");
    ui->ele2_A->setText(QString::number(this->ele2_A) + "A");
    this->updateEleAnState(this->ele_an_state);
    ui->ele_an_V->setText(QString::number(this->ele_an_V) + "V");
    ui->ele_an_A->setText(QString::number(this->ele_an_A) + "A");
    this->updatePower1State(this->power_left_state);
    this->updatePower2State(this->power_right_state);
    this->updateEle1State(this->ele1_state_1);
    this->updateEle2State(this->ele2_state_2);
}

QString HxInformaion::updateDw(int index)
{
    QString dw;
    switch(index)
    {
    case 0:
        dw = QString::fromLocal8Bit("慢车");
        break;
    case 1:
        dw = QString::fromLocal8Bit("1档");
        break;
    case 2:
        dw = QString::fromLocal8Bit("2档");
        break;
    case 3:
        dw = QString::fromLocal8Bit("3档");
        break;
    }
    return dw;
}

QString HxInformaion::updateEleState(int index)
{
    QString state;
    switch(index)
    {
    case 0:
        state = QString::fromLocal8Bit("断开");
        break;
    case 1:
        state = QString::fromLocal8Bit("接通");
        break;
    }
    return state;
}

void HxInformaion::updateEleAnState(int index)
{
    if (this->light == 0)
    {
        if (index)
        {
            ui->ele_an_state->setStyleSheet("border:2px solid rgb(0, 150, 255);\
                                            background-color: rgb(17, 180, 6);\
                                            color:rgb(0, 255, 255);");
        }
        else
        {
            ui->ele_an_state->setStyleSheet("border:2px solid rgb(0, 150, 255);\
                                            color:rgb(0, 255, 255);");
        }
    }
    else if (this->light == 1)
    {
        if (index)
        {
            ui->ele_an_state->setStyleSheet("border:2px solid rgb(121, 121, 126);\
                                            background-color: rgb(14, 100, 0);\
                                            color:rgb(121, 121, 126);");
        }
        else
        {
            ui->ele_an_state->setStyleSheet("border:2px solid rgb(121, 121, 126);\
                                            color:rgb(121, 121, 126);");
        }
    }
    else if (this->light == 2)
    {
        if (index)
        {
            ui->ele_an_state->setStyleSheet("border:2px solid rgb(80, 80, 80);\
                                            background-color: rgb(80, 80, 80);\
                                            ");
        }
        else
        {
            ui->ele_an_state->setStyleSheet("border:2px solid rgb(80, 80, 80);\
                                            color:rgb(80, 80, 80);");
        }
    }
}

void HxInformaion::updatePower1State(int index)
{
    switch(index)
    {
    case 0:
        ui->power_left->setStyleSheet("border-image: url(:/image/engine0.png);");break;
    case 1:
        ui->power_left->setStyleSheet("border-image: url(:/image/engine1.png);");break;
    case 2:
        ui->power_left->setStyleSheet("border-image: url(:/image/engine2.png);");break;
    case 3:
        ui->power_left->setStyleSheet("border-image: url(:/image/engine3.png);");break;
    }
}

void HxInformaion::updatePower2State(int index)
{
    switch(index)
    {
    case 0:
        ui->power_right->setStyleSheet("border-image: url(:/image/engine0.png);");break;
    case 1:
        ui->power_right->setStyleSheet("border-image: url(:/image/engine1.png);");break;
    case 2:
        ui->power_right->setStyleSheet("border-image: url(:/image/engine2.png);");break;
    case 3:
        ui->power_right->setStyleSheet("border-image: url(:/image/engine3.png);");break;
    }
}

void HxInformaion::updateEle1State(int index)
{
    switch(index)
    {
    case 0:
        ui->ele_1->setStyleSheet("border-image: url(:/image/leftOne.png);");break;
    case 1:
        ui->ele_1->setStyleSheet("border-image: url(:/image/leftTwo.png);");break;
    case 2:
        ui->ele_1->setStyleSheet("border-image: url(:/image/leftThree.png);");break;
    case 3:
        ui->ele_1->setStyleSheet("border-image: url(:/image/leftFour.png);");break;
    }
}

void HxInformaion::updateEle2State(int index)
{
    switch(index)
    {
    case 0:
        ui->ele_2->setStyleSheet("border-image: url(:/image/rightOne.png);");break;
    case 1:
        ui->ele_2->setStyleSheet("border-image: url(:/image/rightTwo.png);");break;
    case 2:
        ui->ele_2->setStyleSheet("border-image: url(:/image/rightThree.png);");break;
    case 3:
        ui->ele_2->setStyleSheet("border-image: url(:/image/rightFour.png);");break;
    }
}
