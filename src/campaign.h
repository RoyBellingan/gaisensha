#ifndef CAMPAIGN_STATUS_H
#define CAMPAIGN_STATUS_H
#include <src/bit_power.h>

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

#endif // CAMPAIGN_STATUS_H
