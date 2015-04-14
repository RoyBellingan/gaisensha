#include <QMap>
#include <thread>

template<class Key, class Payload>
class TTLCache {
    struct CacheInfo {
        u_int64_t time;
        Payload payload;
    };

    uint default_ttl;
    uint ttl_check_time;
    QMap<Key, CacheInfo> cache;


public:

    TTLCache (int ttl_ = 60){
        default_ttl=ttl_;
        ttl_check_time = ttl_/2;

    }
    /**
     * @brief start_ttl_flush
     * @todo ciao
     */
    void start_ttl_flush() {
        std::thread(&TTLCache::garbageCollect,this).detach ();
    }

    uint size(){
        return cache.size ();
    }

    void ttl_chekc(uint ttl_){
        default_ttl=ttl_;
        ttl_check_time = ttl_/2;
    }

    bool exists (const Key &key) {
        return cache.contains (key);
    }

    void remove (const Key &key) {
        cache.remove (key);
    }

    Payload fetch (const Key &key) {
        return cache.value (key).payload;
    }

    void insert (const Key &key, const Payload &payload, uint ttl = 0) {
        CacheInfo c;
        c.payload = payload;
        if(ttl==0){
            ttl=default_ttl;
        }
        c.time = time(NULL) + ttl;//QDateTime::currentMSecsSinceEpoch () + 60000; //preload the expiry date
        cache.insert (key, c);
    }


    /**
     * @brief garbageCollect run as a separate thread
     */
    void garbageCollect(){
        while(true){
            //qDebug() << "flush " << cache.size ();
            //            cache.clear ();
            //            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::this_thread::sleep_for(std::chrono::seconds(ttl_check_time));
            u_int64_t now = time(NULL);
            typename QMap<Key, CacheInfo>::iterator i = cache.begin();
            while (i != cache.end()) {
                if (i.value ().time <= now){
                    i = cache.erase(i);
                }else{
                    ++i;
                }
            }

        }
        std::peta::num;



    }
};
