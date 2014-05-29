#include <QtSql>
#include <QMessageBox>

#include "database.h"
#include "input.h"


Input::Input(QWidget *parent) : QDialog(parent)
{
    setupUi(this);
}

Input::~Input()
{

}

void Input::on_btnOK_clicked()
{
    QString tempscore=QString::number(this->score,10);
    QString tempname= leName->text();
    QString id;
    if(!database::open()){
        QMessageBox::about(this,"Message","connect error");
        return ;
    }
    QSqlQuery query;
    query.exec("select max(ID) from list");
    if(!query.next()){
        return ;
    }
    else{
        id=QString::number(query.value(0).toInt()+1);
    }
    if(sum<5){
        query.exec("insert into list value('"+id+"','"+tempname+"','"+tempscore+"')");
    }else if(sum>=5){
        QString tempid;
        query.exec("select max(ID) from list group by Score having Score <= all(select min(Score) from list)");
        if(query.next()){
            tempid=query.value(0).toString();
        }
        query.exec("delete from list where ID="+tempid);
        query.exec("insert into list values('"+tempid+"','"+tempname+"','"+tempscore+"')");
    }
    database::close();
    this->close();
}

void Input::on_btnQuit_clicked()
{
    this->close();
}
