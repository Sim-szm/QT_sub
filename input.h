#ifndef Input_H
#define Input_H

#include <QDialog>

namespace Ui {
class Input;
}

class Input : public QDialog
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

private:
    Ui::Input *ui;
};

#endif // Input_H
