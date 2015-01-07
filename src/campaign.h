#ifndef CAMPAIGN_H
#define CAMPAIGN_H
#include <src/bit_power.h>


/**
 * @brief The campaign_status enum
 * paused is deprecated, define if is the auto pause for capping reason or the manual one
 */
class campaign_status : public bit_power{
public:
    campaign_status();
    enum class trait {
        Pending = 0,
        Active_auto = 1,
        Active_manual = 2,
        Hidden = 3,
        Paused = 4,
        Inactive = 5,
        Paused_auto = 6,
        Paused_manual = 7
    };

};


/**
 * @brief The campaign_type enum
 * https://advplace.com/bugme/show_bug.cgi?id=1061
 *
 */
class campaign_type : public bit_power{
public:
    campaign_type();
    enum class trait {
        PPA = 0,
        PPC = 1,
        PPS,
        PPL,
        PPM,
        Bonus,
        Coreg,
        Referral,
        RTB,
        Test,
        Carlo
        //recurring is deprecated and I've not found any real use
    };
};


class campaign {
    uint id_x;
    QString id;
    campaign_status status;
    campaign_type type;


};



#endif // CAMPAIGN_H
