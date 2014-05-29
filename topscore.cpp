#include <QtSql>
#include <QMessageBox>
#include "database.h"
#include "topscore.h"

Topscore::Topscore(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
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
    tvList->setModel(modelScore);
    tvList->sortByColumn(2);
    database::close();
}

Topscore::~Topscore()
{
}
