#ifndef FUNKZ_H
#define FUNKZ_H


#include <iostream>
#include <QHash>
#include <QBitArray>
#include <QString>
#include <QStringList>


/**
 *@brief this is USUALLY used to return the numeric id of an enumerated variable
 *@example
 * enum c1;
 * c1=enum::Bonus;
 * as_integer(c1);
 */
template <typename Enumeration>
auto as_integer(Enumeration const value) -> typename std::underlying_type<Enumeration>::type {
    return static_cast<typename std::underlying_type<Enumeration>::type> (value);
}


void penv(const char * const * envp);


/**
 * @brief set headers to NOT cache a page
 */
QString set_header_no_cache();



static QStringList bad_user_agent_list(QStringList() << "YandexBot"); // << "Firefox");
bool check_user_agent(char *);
void empty_response();

/**
 * @brief afsu the afs unique id for this user
 * @return the afs unique id for this user
 */
unsigned int afsu();

#endif // FUNKZ_H

