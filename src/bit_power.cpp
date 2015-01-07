#include "bit_power.h"

bit_power::bit_power(uint size){
    trait_txt = {"uno","due"};
    mask.resize(size);
}

bit_power::~bit_power()
{

}


/**
 * @brief toInt return the corresponding value if the bitmask is less than 64 bit
 * @return
 */
uint bit_power::toInt() {
    uint64_t sum = 0;
    for (int var = 0; var < mask.size(); ++var) {
        if (mask.testBit(var)) {
            sum += 1 << var;
        }
    }
    return sum;
}


QString bit_power::toCsv(char enc) {
    QString enc2 = QString(enc);
    if (enc == ' ') {
        enc2.clear();
    }
    QString tmp;
    QStringList csv;
    for (int var = 0; var < mask.size(); ++var) {
        if (mask.testBit(var)) {
            tmp.clear();
            tmp.append(enc2).append(trait_txt[var]).append(enc2);
            csv.append(tmp);
        }
    }
    if (csv.length() > 0) {
        return csv.join(',');
    } else {
        QString tmp2 = "";
        return tmp2;
    }
}

QString bit_power::toCsv() {
    return toCsv(' ');
}
