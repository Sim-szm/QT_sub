#ifndef Input_H
#define Input_H

#include <QDialog>

#include "ui_input.h"

class Input : public QDialog, public Ui::Dialog
{
    Q_OBJECT
    
public:
    explicit Input(QWidget *parent = 0);
    ~Input();

    int score;
    int sum;
private slots:
    void on_btnOK_clicked();

    void on_btnQuit_clicked();
};

#endif // Input_H
