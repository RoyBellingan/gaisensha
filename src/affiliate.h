#ifndef AFFILIATE_H
#define AFFILIATE_H
#include <QString>
#include <src/bit_power.h>

class affiliate_setting : public bit_power{
public:
    affiliate_setting() : bit_power(6){
        trait_txt = {"Subscribed_to_Newsletters", "Monthly_Resume", "Weekly_Resume","SubAffiliate_Inscription","NewCommission","DisplayOk"};
    }
    enum class trait {
        Subscribed_to_Newsletters = 0,
        Monthly_Resume,
        Weekly_Resume,
        SubAffiliate_Inscription,
        NewCommission,
        DisplayOk = 5
    };
};

class affiliate
{
public:
    uint id_x;
    QString id;
    QString uid_sugar;
    QString name;
    u_int status;
    affiliate_setting settings;

    affiliate();
    ~affiliate();
};

#endif // AFFILIATE_H
