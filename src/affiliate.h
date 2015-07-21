#ifndef AFFILIATE_H
#define AFFILIATE_H
#include <QString>
#include <src/bit_power.h>
#include <unordered_map>


enum class affiliate_setting {
    Subscribed_to_Newsletters = 1,
    Monthly_Resume = 2,
    Weekly_Resume = 4,
    SubAffiliate_Inscription = 8,
    NewCommission = 16,
    DisplayOk = 32
};

class affiliate_setting_handler : public bit_power{
public:
    static std::unordered_map<uint,const char*> trait_txt;
    std::unordered_map<uint,const char*> trait_list();

    affiliate_setting_handler();
    affiliate_setting trait;
};


class affiliate{
public:
    u_int32_t id_x;
    QString id;
    QString uid_sugar;
    //QString name;
    u_int8_t status;
    affiliate_setting_handler settings;

    bool display_enabled();

    affiliate();
    ~affiliate();
};

#endif // AFFILIATE_H
