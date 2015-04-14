#include "in_handler_we_trust.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

in_handler_we_trust::in_handler_we_trust()
{

}

in_handler_we_trust::~in_handler_we_trust()
{

}

bool in_handler_we_trust::le_db_connect (){
    db = QSqlDatabase::addDatabase("QMYSQL",thread_name);
    db.setConnectOptions ("MYSQL_OPT_RECONNECT=true;");
    db.setHostName("localhost");
    db.setDatabaseName("advplace_login");
    db.setUserName("root");
    bool ok = db.open();
    if(!ok){
        qDebug() << "crisi con mysql";
        return 0;
    }
    query = new QSqlQuery(db);
}

bool in_handler_we_trust::le_db_check(){

}

/*
bool in_handler_we_trust::geppetto(){

}
*/
