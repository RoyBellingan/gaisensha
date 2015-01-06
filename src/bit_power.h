#ifndef BIT_POWER_H
#define BIT_POWER_H

#include <QBitArray>
#include <QString>
#include <QStringList>
#include <vector>
/**
 * @brief The nullable_bit class is used for bit type column
 * if 0 than NULL is the returne value
 */
class bit_power{
public:

    QBitArray mask;
    std::vector<const char*> trait_txt;
    int val;
    enum class trait {
        uno,
        due
    };

    bit_power(uint size);


    template <typename Enumeration>
    auto set(Enumeration const x) -> typename std::underlying_type<Enumeration>::type;

    template <typename Enumeration>
    auto clear(Enumeration const x) -> typename std::underlying_type<Enumeration>::type;

    uint toInt();

    QString toCsv(char enc);
    QString toCsv();


    ~bit_power();
};

#endif // BIT_POWER_H
