#include "widget.h"
#include "ui_widget.h"
#include "QMessageBox"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->CheckStatus();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::CheckStatus(){
    if (this->money >= 200){
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(true);
    }
    else if(this->money >= 150){
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(true);
        ui->pushButton_7->setEnabled(false);
    }
    else if(this->money >= 100){
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
    }
    else{
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
    }
}
void Widget::MoneyProcess(int money){
    this->money += money;
    ui->lcdNumber->display(this->money);
    this->CheckStatus();
}

void Widget::Change(){
    char buf[64];
    int tmp[4] = {0,};
    tmp[0] = this->money / 500;
    this->money %= 500;
    tmp[1] = this->money / 100;
    this->money %= 100;
    tmp[2] = this->money / 50;
    this->money %= 50;
    tmp[3] = this->money / 10;
    this->money %= 10;
    sprintf(buf, "500: %d  100: %d  50: %d  10: %d  ", tmp[0], tmp[1], tmp[2], tmp[3]);
    this->MoneyProcess(-money);
    QMessageBox m;
    m.information(nullptr, "Alert", buf);
}


void Widget::on_pushButton_clicked()
{
    this->MoneyProcess(10);
}

void Widget::on_pushButton_2_clicked()
{
    this->MoneyProcess(50);
}

void Widget::on_pushButton_3_clicked()
{
    this->MoneyProcess(100);
}

void Widget::on_pushButton_4_clicked()
{
    this->MoneyProcess(500);
}

void Widget::on_pushButton_5_clicked()
{
    this->MoneyProcess(-100);
}

void Widget::on_pushButton_6_clicked()
{
    this->MoneyProcess(-150);
}

void Widget::on_pushButton_7_clicked()
{
    this->MoneyProcess(-200);
}

void Widget::on_pushButton_8_clicked()
{
    this->Change();
}
