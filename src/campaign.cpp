#include "src/campaign.h"

campaign_status::campaign_status() : bit_power(){

    std::unordered_map<uint,const char*> trait_txt;
    trait_txt[1]="Pending";
    trait_txt[2]="Active_auto";
    trait_txt[4]="Active_manual";
    trait_txt[8]="Hidden";
    trait_txt[16]="Paused";
    trait_txt[32]="Inactive";
}


campaign_type::campaign_type() : bit_power(){
    std::unordered_map<uint,const char*> trait_txt;
    trait_txt[1]="PPA";
    trait_txt[2]="PPC";
    trait_txt[4]="PPS";
    trait_txt[8]="PPL";
    trait_txt[16]="PPM";
    trait_txt[32]="Bonus";
}


