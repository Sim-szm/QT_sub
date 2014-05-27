#include "mainform.h"
#include "ui_mainform.h"
#include <QtGui/QApplication>
#include <QtSql>
#include <QMessageBox>
#include "database.h"
mainform::mainform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainform)
{
    ui->setupUi(this);
}

mainform::~mainform()
{
    delete ui;
}

void mainform::timer_upDate(){
    this->gameArea->moveOneStep();
    if(this->gameArea->isMoveEnd()){
        if(this->gameArea->isGame_Over()){
            this->timer->stop();
            QMessageBox::warning(this,tr("warning"),tr("Game Over!"),QMessageBox::Yes);
            ui->btnStart->setEnabled(true);
            int minscore,count;
            if(!database::open()){
                QMessageBox::about(this,"Message","connect error");
                return ;
            }

            QSqlQuery query;
            query.exec("select min(score) from list");
            if(query.next())
                minscore=query.value(0).toInt();
            query.exec("select count(*) from list");
            if(query.next())
                count=query.value(0).toInt();
            database::close();
            if(num > minscore || count < 5){
                Input onrank;
                onrank.score=num;
                onrank.sum=count;
                onrank.show();
                onrank.exec();
            }
            else{
                QMessageBox::warning(this,tr("warning"),tr("so sorry !"),QMessageBox::Yes);
            }
            ui->lb_score->setText("0");
            this->gameArea->setscore(0);
        }
        else{
            this->gameArea->nextItem();
            num=this->gameArea->getscore();
            QString final_score=QString::number(num,10);
            ui->lb_score->setText(final_score);
            this->gameArea->gameStart();
        }
    }
    else{
        this->gameArea->do_MoveNext();
    }
}

void mainform::on_btnStart_clicked()
{
    this->gameArea->init_Game();
    this->gameArea->gameStart();
    this->timer->start(this->gameArea->getmovespeed());
    this->gameArea->setFocus();
    ui->btnStart->setEnabled(false);
}

void mainform::on_btnList_clicked()
{
    topscore diag;
    diag.show();
    diag.exec();
}

void mainform::on_btnSlowDown_clicked()
{
    this->gameArea->setmovespeed(200);
}

void mainform::on_btnSpeedUp_clicked()
{
    this->gameArea->setmovespeed(500);
}
