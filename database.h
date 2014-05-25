#ifndef DATABASE_H
#define DATABASE_H
#include <QtSqlDatabase>
class database{
public:
    database();
    static QSqlDatabase db;
    static bool open();
    static void close();
};
#endif // DATABASE_H
