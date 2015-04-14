#include <iostream>
#include <QHash>
#include <QBitArray>
#include <QString>
#include <QStringList>
#include <src/funkz.h>
#include <QDebug>


/**
 * @brief set headers to NOT cache a page
 */
QString set_header_no_cache(){
    QString hh = QString("Cache-Control: no-cache, must-revalidate\r\n"
                       "Expires: Sat, 26 Jul 1997 05:00:00 GMT\r\n");
    return hh;
}


void penv(const char * const * envp){
    std::cout << "<PRE>\n";
    for ( ; *envp; ++envp)
    {
        std::cout << *envp << "\n";
    }
    std::cout << "</PRE>\n";
}


/**
 * @brief check_user_agent
 * @param user_agent
 * @return 1 if a bad user agent is used
 */
bool check_user_agent(char*  user_agent){
    QString ua = QString(user_agent);
    if (ua.length ()==0){ //if empty
        return 1;
    }

    for (int var = 0; var < bad_user_agent_list.count (); ++var) {
        //qDebug() << ua << bad_user_agent_list.at(var);
        if (ua.contains (bad_user_agent_list.at(var))){
          //qDebug() << "match";
            return 1;
        }else{
          // no match

        }
    }
    return 0;
}


void empty_response(){
    std::cout << "Content-type: text/html\r\n\r\n";
}



unsigned int afsu(){

}
