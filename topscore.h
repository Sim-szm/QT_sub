#ifndef TOPSCORE_H
#define TOPSCORE_H

#include <QDialog>
#include <QSqlTableModel>
namespace Ui {
class topscore;
}

class topscore : public QDialog
{
    Q_OBJECT
    
public:
    explicit topscore(QWidget *parent = 0);
    ~topscore();
    QSqlTableModel * modelScore;
private:
    Ui::topscore *ui;
};

#endif // TOPSCORE_H
