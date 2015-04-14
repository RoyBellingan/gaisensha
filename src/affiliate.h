#ifndef AFFILIATE_H
#define AFFILIATE_H
#include <QString>
#include <src/bit_power.h>

class affiliate_setting : public bit_power{
public:
    std::vector<const char*>& trait_h() { return trait_txt; }
    static std::vector<const char*> trait_txt;
    affiliate_setting();
    enum class trait {
        Subscribed_to_Newsletters = 0,
        Monthly_Resume,
        Weekly_Resume,
        SubAffiliate_Inscription,
        NewCommission,
        DisplayOk = 5
    };
};

class affiliate_class{
public:
    u_int32_t id_x;
    QString id;
    QString uid_sugar;
    //QString name;
    u_int8_t status;
    affiliate_setting settings;

    bool display_enabled();

    affiliate_class();
    ~affiliate_class();
};

#endif // AFFILIATE_H
