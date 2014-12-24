#include <stdio.h>
using namespace std;
#include <QHash>
/**
 *@brief this is USUALLY used to return the numeric id of an enumerated variable
 *@example
 * enum c1;
 * c1=enum::Bonus;
 * as_integer(c1);
 */
template <typename Enumeration>
auto as_integer(Enumeration const value) -> typename std::underlying_type<Enumeration>::type{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}


class bid_offer{
public:
    int x;
};

enum colors_t {black=1, blue=2, green, cyan, red, purple, yellow, white};


class dsp{
public:
    /**
     * @brief dsp_id is our (advplace) assigned id to this dsp
     *  a list can be found here
     */
    int dsp_id;
    QHash<int, bid_offer> bid_list;
    QString buyeruid;
};


enum class earn_source_enum{
    afs=0,
    rtb,
    passback
};
//spam me earn_source_enum
const char* earn_source_txt[] = {"afs", "rtb", "passback"} ;

enum class trx_status{
    Pending = 0,
    Approved = 1,
    Declined = 2,
    Paid = 3,
    Paying = 4
};
//spam me trx_status
const char* trx_status_txt[] = {"Pending", "Approved", "Declined","Paid","Paying"} ;



/**
 * @brief The campaign_status enum
 * paused is deprecated, define if is the auto pause for capping reason or the manual one
 */
enum class campaign_status{
    Pending = 0,
    Active_auto = 1,
    Active_manual = 2,
    Hidden = 3,
    Paused = 4,
    Inactive = 5,
    Paused_auto = 6,
    Paused_manual = 7
};


/**
 * @brief The campaign_type enum
 * https://advplace.com/bugme/show_bug.cgi?id=1061
 *
 */
enum class campaign_type{
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

const char* campaign_type_txt[] = {"PPA", "PPC", "PPS", "PPL", "PPM", "Bonus", "Coreg", "Referral", "RTB", "Test", "Carlo"} ;

class campaign{
public:
    campaign_type type;

    const char* get_type(){
        return get_type('a');
    }

    int get_type(int i){
        return as_integer(type);
    }

    const char* get_type(char i){
        return campaign_type_txt[as_integer(type)];
    }

};

class affiliate_class{

};

class banner_class{
private:


};

class proposed_banner_class{

};



class zone_class{
public:
    uint id;

};

class impression{
public:
    zone_class zone;
    /** this is a popside request ? */
    bool popside = 0;
    bool cookie_sync_on = 0;
    bool no_pk=0;
    bool redirect=0;

    uint afsu;

    QHash<int, proposed_banner_class> proposed_banner;
    QHash<int, QString> deferred_query;
    QHash<int, QString> deferred_redis;

    earn_source_enum earn_source;

    impression(){


    }


};

class rtb_impression : public impression{
    uint bid_request_id;
    u_int32_t bit_flag;
};






