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
    
private:

};

#endif // GAMEAREA_H
