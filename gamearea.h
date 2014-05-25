#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QFrame>

namespace Ui {
class gamearea;
}

class gamearea : public QFrame
{
    Q_OBJECT
    
public:
    explicit gamearea(QWidget *parent = 0);
    ~gamearea();
    
private:
    Ui::gamearea *ui;
};

#endif // GAMEAREA_H
