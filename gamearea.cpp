#include "gamearea.h"

GameArea::GameArea(QWidget *parent) :
    QFrame(parent)
{
    this->init_gameArea(6,6,430,430,200,400,20,60,0);
    this->init_Game();
}

GameArea::GameArea(int speed, QWidget *parent):
    QFrame(parent)
{
    this->init_gameArea(6,6,430,430,200,400,20,60,0);
    this->init_Game();
    this->moveSpeed=speed;
    this->gameStart();
}

GameArea::~GameArea()
{

}
