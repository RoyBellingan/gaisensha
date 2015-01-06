
#include <QHash>
#include <QBitArray>
#include <QString>
#include <QStringList>

using namespace std;


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
