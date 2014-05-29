#include "gamearea.h"
#include <QKeyEvent>
#include <QSound>
#include <QMessageBox>
#include "input.h"
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
void GameArea::do_MoveNext()
{
    this->currentItem_to_currentMap();
    this->draw_gameArea();
}
void GameArea::moveOneStep()
{
    startY+=step;
}
void GameArea::nextItem()
{
    copy_Map(currentMap,copyMap,map_row,map_col);
    this->draw_gameArea();
}
bool GameArea::isGame_Over()
{
    if(this->isGameOver)
        return true;
    else
        return false;
}
int GameArea::getFullRowNum()
{
    return fullRowNum;
}
void GameArea::setGameAreaColor(QColor color)
{
    gameAreaColor=color;
}
void GameArea::setBoxBrushColor(QColor color)
{
    boxBrushColor=color;
}
void GameArea::setBoxPenColor(QColor color)
{
    boxPenColor=color;
}
void GameArea::setBoxPicture(QString fileName)
{
    this->boxPicture=fileName;
}
void GameArea::set_draw_box_picture(bool Bool)
{
    this->is_draw_box_picture=Bool;
}
void GameArea::setKey_Down_Move_oneStep(bool Bool)
{
    this->isKey_Down_Move_OneStep=Bool;
}
void GameArea::setDrawGrid(bool Bool)
{
    isDrawGrid=Bool;
}
void GameArea::setDrawNextItem(bool Bool)
{
    isDrawNextItem=Bool;
}
void GameArea::setbox(int row, int col)
{
    *(copyMap+row*map_col+col)=1;
}


void GameArea::init_gameArea(int X, int Y, int frame_width, int frame_height, int width, int height, int boxStep, int start_x, int start_y)
{
    this->gameArea_width=width;
    this->gameArea_height=height;
    this->step=boxStep;
    this->init_startX=start_x;
    this->init_startY=start_y;
    this->map_row=gameArea_height/step;
    this->map_col=gameArea_width/step;

    this->resize(frame_width,frame_height);
    this->move(X,Y);
    pix_gameArea=new QPixmap(this->gameArea_width,this->gameArea_height);
    this->isKey_Down_Move_OneStep=true;

    this->isDrawGrid=true;
    this->isDrawNextItem=true;
    this->is_draw_box_picture=false;

    this->gameAreaColor=Qt::white;
    this->boxBrushColor=Qt::yellow;
    this->boxPenColor=Qt::green;
    this->theAngle=0;
    this->gameArea_X=0;
    this->gameArea_Y=0;
    this->pix_X=10;
    this->pix_Y=10;
    myItem=new MyItem();
    this->currentMap=new unsigned char[map_col*map_row];
    this->copyMap=new unsigned char[map_col*map_row];
}

void GameArea::init_Game()
{
    this->init_Map(currentMap,map_row,map_col);
    this->init_Map(copyMap,map_row,map_col);
    this->currentItem=this->currentMap;
    this->theNextItem=this->currentMap;
    isFirstItem=true;
    isGameOver=false;
    fullRowNum=0;
    this->draw_gameArea();
    this->score=0;
}

void GameArea::gameStart()
{
    this->startX=this->init_startX;
    this->startY=this->init_startY;
    fullRowNum=0;
    if(isFirstItem)
    {
        this->currentItem=myItem->getItem();
        isFirstItem=false;
    }
    else
        this->currentItem=this->theNextItem;
    this->theNextItem=myItem->getItem();
    this->currentItem_to_currentMap();
    this->draw_gameArea();
}
