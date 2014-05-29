#ifndef GAMEAREA_H
#define GAMEAREA_H
#include <QtGui/QFrame>
#include "myitem.h"
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <QFrame>

namespace gameArea {
class GameArea;
}

class GameArea : public QFrame
{
    Q_OBJECT
    
public:
    GameArea(QWidget *parent = 0);
    GameArea(int speed,QWidget *parent = 0);
    ~GameArea();
public:
    //public func
    void init_gameArea(int X,int Y,int frame_width,int frame_height,int width,int height,int boxStep,int start_x,int start_y);
    void moveOneStep();
    bool isMoveEnd();
    bool isGame_Over();
    void init_Game();
    void gameStart();
    void nextItem();
    int getFullRowNum();
    void do_MoveNext();
    void draw_gameArea();

    //color func
    void setGameAreaColor(QColor color=Qt::white);
    void setBoxBrushColor(QColor color=Qt::white);
    void setBoxPenColor(QColor color=Qt::white);
    void set_draw_box_picture(bool Bool=false);
    void setBoxPicture(QString fileName);

    void setKey_Down_Move_oneStep(bool Bool=false);
    void setDrawGrid(bool Bool=true);
    void setDrawNextItem(bool Bool=true);

    void setbox(int row,int col);
    int getscore()
    {
        return this->score;
    }
    int setscore(int i)
    {
        this->score=i;
        return 0;
    }

    int getmovespeed()
    {
        return this->moveSpeed;
    }
    void setmovespeed(int i)
    {
        this->moveSpeed=i;
    }


private:
    //private func
    void init_Map(unsigned char* initMap,int row,int col);
    void paintEvent(QPaintEvent* );
    void keyPressEvent(QKeyEvent *);
    void draw_Grid();
    void currentItem_to_currentMap();
    void copy_Map(unsigned char* theMap,unsigned char* toMap,int row,int col);

    void draw_currentMap();
    bool isMoveLeft();
    bool isMoveRight();
    void draw_nextItem();
    void do_itemChange();
    void clearRow();

private:
    //private var
    int gameArea_width;
    int gameArea_height;
    int map_row;
    int map_col;
    int startX;
    int startY;
    int step;
    int init_startX;
    int init_startY;

    unsigned char* currentMap;
    unsigned char* copyMap;

    QPixmap* pix_gameArea;
    MyItem* myItem;
    unsigned char* currentItem;
    unsigned char* theNextItem;
    bool isFirstItem;
    bool isGameOver;
    int fullRowNum;

    QColor gameAreaColor;
    QColor boxPenColor;
    QColor boxBrushColor;
    bool isKey_Down_Move_OneStep;
    bool isDrawGrid;
    bool isDrawNextItem;

    int theAngle;
    int gameArea_X;
    int gameArea_Y;
    int pix_X;
    int pix_Y;
    bool is_draw_box_picture;
    QString boxPicture;
    QTimer* moveTimer;
    int score;
    int moveSpeed;
private slots:
    void moveTimer_upDate();
};

#endif // GAMEAREA_H
