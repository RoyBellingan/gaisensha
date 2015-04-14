#ifndef IN_HANDLER_WE_TRUST_H
#define IN_HANDLER_WE_TRUST_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

class in_handler_we_trust
{
public:
    uint64_t thread_id;
    QString  thread_name;
    QSqlDatabase db;
    QSqlQuery* query;

//funkzioni
    in_handler_we_trust();
    ~in_handler_we_trust();

    /**
     * @brief this function tries to connect to mysql,
     */
    bool le_db_connect();

    /**
     * @brief in case of query fail this function is called to check if the connection is still alive
     * @return
     */
    bool le_db_check();



};

#endif // IN_HANDLER_WE_TRUST_H
