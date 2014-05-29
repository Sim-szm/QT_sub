#ifndef TOPSCORE_H
#define TOPSCORE_H

#include <QDialog>
#include <QSqlTableModel>

#include "ui_topscore.h"

class Topscore : public QDialog, public Ui::topscore
{
    Q_OBJECT
    
public:
    explicit Topscore(QWidget *parent = 0);
    ~Topscore();
    QSqlTableModel * modelScore;
};

#endif // TOPSCORE_H
