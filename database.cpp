#include "database.h"
database::database(){

}

QSqlDatabase database::db=QSqlDatabase::addDatabase("QMYSQL");
bool database::open(){
    db.setHostName(QLatin1String("localhost"));
    db.setUserName("root");
    db.setPassword("xianszm007");
    db.setDatabaseName("tetrix");
    if(!db.open()){
        return false;
    }
    return true;
}

void database::close(){
    db.close();
}
