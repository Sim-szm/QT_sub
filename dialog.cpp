#include "dialog.h"
#include "ui_input.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_btnOK_clicked()
{

}

void Dialog::on_btnQuit_clicked()
{

}
