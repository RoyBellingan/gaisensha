#ifndef BIT_POWER_H
#define BIT_POWER_H

#include <QBitArray>
#include <QString>
#include <QStringList>
#include <vector>
#include <src/funkz.h>
#include <unordered_map>
/**
 * @brief The nullable_bit class is used for bit type column
 * if 0 than NULL is the returne value
 */

    enum class base_trait {
        uno,
        due
    };

class bit_power{
public:

    uint mask = 0;

    //this the vector who holds the string mapping, is static to avoid memory wasting ecc
    static std::unordered_map<uint,const char*> trait_txt;

    //this function is used so the inherited class access the redefined trait_txt insted of the base one, or does other strange stuff
    virtual std::unordered_map<uint,const char*> trait_list();

    base_trait trait;

    void i_set(uint x){
           mask = mask | x;
    }

    template <typename Enumeration>
    auto set(Enumeration const x) -> typename std::underlying_type<Enumeration>::type{
           mask = mask | as_integer(x);
    }



    template <typename Enumeration>
    auto clear(Enumeration const x) -> typename std::underlying_type<Enumeration>::type{
               mask = mask &~ as_integer(x);
    }

    bool check(uint x){
         return mask & x;
    }

    /**
     * @brief check if this flag is set
     * @param enumerator
     * @return bool
     */
    template <typename Enumeration>
    bool check(Enumeration const x){
         //return mask.at(as_integer(x));
         return mask & as_integer(x);
    }



    /**
     * @brief check if this flag is set, this is the same of check
     * @param enumerator
     * @return bool
     */
    template <typename Enumeration>
    bool operator==(Enumeration const x) {
        return mask & as_integer(x);
    }


    uint toInt();

    QString toCsv(char enc);
    QString toCsv();

    bit_power();
    ~bit_power();
};

#endif // BIT_POWER_H
