#include "affiliate.h"
#include <src/bit_power.h>
#include <unordered_map>

std::unordered_map<uint,const char*> affiliate_setting_handler::trait_txt;

affiliate_setting_handler::affiliate_setting_handler() : bit_power(){

}

std::unordered_map<uint,const char*> affiliate_setting_handler::trait_list(){
    return trait_txt;
}

affiliate::affiliate(){

}
/*
affiliate::value_at(uint pos){
    switch(pos){
        case 1:
            return "Subscribed_to_Newsletters";
            break;

    }



        std::unordered_map<uint,const char*> trait_txt;
    trait_txt[1]="Subscribed_to_Newsletters";
    trait_txt[2]="Monthly_Resume";
    trait_txt[4]="Weekly_Resume";
    trait_txt[8]="SubAffiliate_Inscription";
    trait_txt[16]="NewCommission";
    trait_txt[32]="DisplayOk";
}
*/

affiliate::~affiliate(){

}

