#ifndef MAINFORM_H
#define MAINFORM_H

#include <QWidget>
#include <time.h>
#include "gamearea.h"
namespace Ui {
class mainform;
}

class mainform : public QWidget
{
    Q_OBJECT
    
public:
    explicit mainform(QWidget *parent = 0);
    ~mainform();
    int score;
private slots:
    void on_btnStart_clicked();

    void on_btnList_clicked();

    void on_btnSlowDown_clicked();

    void on_btnSpeedUp_clicked();

private:
    Ui::mainform *ui;
    GameArea * gameArea;
    QTimer * timer;
    int num;
};

#endif // MAINFORM_H
