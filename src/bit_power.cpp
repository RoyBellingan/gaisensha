#include "bit_power.h"
#include <QDebug>
#include <src/funkz.h>


bit_power::~bit_power(){
}

bit_power::bit_power(){
    std::unordered_map<uint,const char*> trait_txt;
    trait_txt[1]="uno";
    trait_txt[2]="due";
}

std::unordered_map<uint,const char*> bit_power::trait_list(){
    //return trait_txt;
}

QString bit_power::toCsv(char enc) {
    QString enc2 = QString(enc);
    if (enc == ' ') {
        enc2.clear();
    }
    QString tmp;
    QStringList csv;
    for (uint var = 0; var < mask; ++var) {
        if (check(var)) {
            tmp.clear();

            tmp.append(enc2).append(trait_list().at (var)).append(enc2);
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

uint bit_power::toInt() {
    return mask;
}

