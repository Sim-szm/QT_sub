#include <QApplication>
#include "mainform.h"
#include "gamearea.h"
#include "topscore.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainform w;
    w.show();
    
    return a.exec();
}
