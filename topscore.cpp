#include "topscore.h"
#include "ui_topscore.h"
#include <QtSql>
#include <QMessageBox>
#include "database.h"
topscore::topscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::topscore)
{
    ui->setupUi(this);
    if(!database::open()){
        QMessageBox::about(this,"Message","connect error");
        return ;
    }
    modelScore=new QSqlTableModel(this);
    modelScore->setTable("list");
    modelScore->select();

    modelScore->setHeaderData(0,Qt::Horizontal,tr("ID"));
    modelScore->setHeaderData(1,Qt::Horizontal,tr("Name"));
    modelScore->setHeaderData(2,Qt::Horizontal,tr("Score"));
    ui->tvList->setModel(modelScore);
    ui->tvList->sortByColumn(2);
    database::close();
}

topscore::~topscore()
{
    delete ui;
}
