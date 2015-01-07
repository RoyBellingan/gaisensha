#include "src/campaign.h"

campaign_status::campaign_status() : bit_power(8){
    trait_txt = {"Pending", "Active_auto","Active_manual", "Hidden","Paused","Inactive","Paused_auto","Paused_manual"};
}

campaign_type::campaign_type() : bit_power(12){
   trait_txt = {"PPA", "PPC", "PPS", "PPL", "PPM", "Bonus", "Coreg", "Referral", "RTB", "Test", "Carlo"};

}


