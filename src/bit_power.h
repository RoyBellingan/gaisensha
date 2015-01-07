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
    auto set(Enumeration const x) -> typename std::underlying_type<Enumeration>::type{
           mask.setBit(as_integer(x));
           return 1;
    }

    template <typename Enumeration>
    auto clear(Enumeration const x) -> typename std::underlying_type<Enumeration>::type{
               mask.clearBit (as_integer(x));
               return 0;
    }


    /**
     * @brief check if this flag is set
     * @param enumerator
     * @return bool
     */
    template <typename Enumeration>
    bool check(Enumeration const x){
         return mask.at(as_integer(x));
    }

    /**
     * @brief check if this flag is set, this is the same of check
     * @param enumerator
     * @return bool
     */
    template <typename Enumeration>
    bool operator==(Enumeration const x) {
        return mask.at(as_integer(x));
    }


    uint toInt();

    QString toCsv(char enc);
    QString toCsv();


    ~bit_power();
};

#endif // BIT_POWER_H
