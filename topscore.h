#ifndef TOPSCORE_H
#define TOPSCORE_H

#include <QDialog>
#include <QSqlTableModel>
namespace Ui {
class Topscore;
}

class Topscore : public QDialog
{
    Q_OBJECT
    
public:
    explicit Topscore(QWidget *parent = 0);
    ~Topscore();
    QSqlTableModel * modelScore;
private:
    Ui::Topscore *ui;
};

#endif // TOPSCORE_H
