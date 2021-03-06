#include <iostream>
#include <fastcgi/fcgio.h>
#include <fastcgi/fcgiapp.h>
#include <fastcgi/fcgi_config.h>
#include <sys/types.h>
#include <sys/stat.h> //for umask
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QHash>
#include <QUrl>
#include <QUrlQuery>
#include <QElapsedTimer>
#include <QDateTime>
#include <QDebug>

#include <mysql/mysql.h>
#include "/usr/include/hiredis/hiredis.h"

//#include </mnt/neuhome/home/roy/scaricati/gtest-1.7.0/include/gtest/gtest.h>
#include <src/bit_power.h>
#include <src/campaign.h>
#include <src/affiliate.h>
#include <src/funkz.h>
#include <src/impression.h>



#define THREAD_COUNT 8
#define SOCKET_PATH "/srv/gsn/gaisensha.sock"
static int socketId;

unsigned int request_count;
//mysql thread pool array, redis
//cache for user stuff...


using namespace std;


int main (){
    affiliate aff1;
    aff1.settings.i_set(3);
    aff1.settings.set(affiliate_setting::DisplayOk);



    qDebug() << aff1.settings.toCsv();
    qDebug() << aff1.settings.toInt();

}












static void *doit(void *a)
{
    int rc;
    FCGX_Request request;

    if(FCGX_InitRequest(&request, socketId, 0) != 0) {
        printf("Can not init request\n");
        return NULL;
    }


    redisContext *c = redisConnectUnix("/tmp/redis.sock");

    if (c->err) {
        printf("Error with redis: %s\n", c->errstr);
    } else {
        //printf("Connection Made! \n");
    }

    redisReply *reply;
    reply = (redisReply*)redisCommand(c,"PING");
    printf("PING Response: %s\n", reply->str);

    impression imp;

    QString content;
    //loop forever!
    for(;;) {
        content.clear ();
        static pthread_mutex_t accept_mutex = PTHREAD_MUTEX_INITIALIZER;
        //stay here waiting for an accepted connection
        pthread_mutex_lock(&accept_mutex);
        rc = FCGX_Accept_r(&request);
        pthread_mutex_unlock(&accept_mutex);

        //From here we are processing a new request
        request_count++;


        if(rc < 0) {
            printf("Can not accept new request\n");
            break;
        }

        if(check_user_agent( FCGX_GetParam("HTTP_USER_AGENT", request.envp))) {
            empty_response();
            continue;
        }

        //Just Enought Cookie Handling
        // penv(request.envp);
        QByteArray cookie_raw= FCGX_GetParam("HTTP_COOKIE", request.envp);
        QHash<QString, QString> cookie;

        foreach(QByteArray line, cookie_raw.split(';')) {
            int colon = line.indexOf('=');
            QByteArray headerName = line.left(colon).trimmed();
            QByteArray headerValue = line.mid(colon + 1).trimmed();
            cookie.insertMulti(headerName, headerValue);
        }



        //Well Enought GET parameter handling
        QString url= FCGX_GetParam("REQUEST_URI", request.envp);
        QUrlQuery query;
        query.setQuery (FCGX_GetParam("QUERY_STRING", request.envp));

        content.append ("Content-type: text/html\r\n");
        content.append(set_header_no_cache ());
        content.append("\r\n");
        content.append("richiesta: ").append (QString::number (request_count) + "<br>\n").append(url);
        QHashIterator<QString, QString> i(cookie);
        while (i.hasNext()) {
            i.next();
            content.append(i.key() + " : " + i.value() + "<br>\n");
        }

        //Performance based requires to be selected both group and banner id


        //Long list of requestable item here

        //IF an item requires login... well check the login!



        //Requesting for a banner
        if((query.queryItemValue ("g").toInt () > 0) && (query.queryItemValue ("bx").toInt () > 0)) {
            content.append (query.toString ());
            imp.check_group (query.queryItemValue ("g").toInt ());
            imp.check_banner (query.queryItemValue ("bx").toInt ());
            FCGX_PutS(content.toStdString ().c_str (), request.out);
            FCGX_Finish_r(&request);
            continue;
        }

        content.append("nothing to to here");
        FCGX_PutS(content.toStdString ().c_str (), request.out);
        FCGX_Finish_r(&request);
        continue;

        /*

                content.append ("Content-type: text/html\r\n\r\n"
                                "<html> <head> <title>FastCGI Hello! (multi-threaded C, fcgiapp library)</title> </head> \
                                <body> <h1>FastCGI Hello! (multi-threaded C, fcgiapp library)</h1> </body>\r\n");

        */


    }
    return NULL;
}



/*
int main(void)
{
    int i;
    pthread_t id[THREAD_COUNT];

    FCGX_Init();
    printf("FCGX is inited\n");
    umask(0);
    socketId = FCGX_OpenSocket(SOCKET_PATH, 2000);
    if(socketId < 0) {
        printf("Socket opening Error \n");
        return 1;
    }
    printf("Socket is opened\n");


    for(i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&id[i], NULL, doit, NULL);
    }

    for(i = 0; i < THREAD_COUNT; i++) {
        pthread_join(id[i], NULL);
    }

    return 0;
}
*/





















////int argc, char *argv[]
//int main() {

//    unsigned int count=0;
//    long pid = getpid();
//    QElapsedTimer request_timer;    //printf("Request is inited\n");
//    unsigned int request_time;
//    unsigned int zone_id;
//    bool is_popunder;
//    unsigned int banner_id_x;
//    unsigned int campaign_id_x;
//    unsigned int group_id_x;

//    unsigned int t1;
//    unsigned int t2;



//    // Backup the stdio streambufs
//    streambuf * cin_streambuf  = cin.rdbuf();
//    streambuf * cout_streambuf = cout.rdbuf();
//    streambuf * cerr_streambuf = cerr.rdbuf();

//    FCGX_Request request;

//    FCGX_Init();

//    if(FCGX_InitRequest(&request, socketId, 0) != 0)
//    {
//        printf("Can not init reques    FCGX_InitRequest(&request, 0, 0);t\n");
//        return NULL;
//    }
//    printf("Request is inited\n");


//    while (FCGX_Accept_r(&request) == 0) {

//        request_timer.start(); //page timing execution started
//        request_time= QDateTime::currentMSecsSinceEpoch ();//request execution started at
//        count++;
//        impression imp;

//        //don't kwnow, but required
//        fcgi_streambuf cin_fcgi_streambuf(request.in);
//        fcgi_streambuf cout_fcgi_str    FCGX_InitRequest(&request, 0, 0);eambuf(request.out);
//        fcgi_streambuf cerr_fcgi_streambuf(request.err);
//        cin.rdbuf(&cin_fcgi_streambuf);
//        cout.rdbuf(&cout_fcgi_streambuf);
//        cerr.rdbuf(&cerr_fcgi_streambuf);

//        //Usual Check
//        if(check_user_agent( FCGX_GetParam("HTTP_USER_AGENT", request.envp))){
//            empty_response();
//            continue;
//        }


//        //Just Enought Cookie Handling
//        QByteArray cookie_raw= FCGX_GetParam("HTTP_COOKIE", request.envp);
//        QHash<QString, QString> cookie;

//        foreach(QByteArray line, cookie_raw.split(';')){
//            int colon = line.indexOf('=');
//            QByteArray headerName = li    FCGX_InitRequest(&request, 0, 0);ne.left(colon).trimmed();
//            QByteArray headerValue = line.mid(colon + 1).trimmed();
//            cookie.insertMulti(headerName, headerValue);
//        }

//        //Well Enought GET parameter handling
//        QString url= FCGX_GetParam("SCRIPT_URL", request.envp);
//        QUrlQuery query;
//        query.setQuery (FCGX_GetParam("QUERY_STRING", request.envp));


//        //Zone



//        //Performance based requires to be selected both group and banner id

//        if((query.queryItemValue ("g").toInt () > 0) && (query.queryItemValue ("bx").toInt () > 0)){
//            cout << "Content-type: text/html\r\n"
//                 << set_header_no_cache ()
//                 << "\r\n"
//                 << "ciao" << query.queryItemValue ("g").toInt ();
//            imp.check_group (query.queryItemValue ("g").toInt ());
//            imp.check_banner (query.queryItemValue ("bx").toInt ());


//    FCGX_InitRequest(&request, 0, 0);


//            continue;
//        }


//        //if I'm here something went wrong...
//        empty_response();
//        continue;



//        //All the approved get parameter




//        //Real handling begins here

//        cout << "Content-type: text/html\r\n"
//             << set_header_no_cache ()
//             << "\r\n"
//             << "<html>\n"
//             << "  <head>\n"    FCGX_InitRequest(&request, 0, 0);
//             << "    <title>Hello, World!</title>\n"
//             << "  </head>\n"
//             << "  <body>\n"
//             << "    <h1>Hello, World!</h1>\n"
//             << "    per la " << count << " volta \n"
//             << "<H4>da PID: " << pid << "</H4>\n"
//             << cookie["utz"].toStdString () << " + "
//             << query.queryItemValue ("nyan").toStdString () << " +  " << url.toStdString () << "\n"
//             << "script requested started @ " << request_time << "\n"
//             << "last " << request_timer.nsecsElapsed ()
//             << "</html>\n";

//        cout << "<H4>Request Environment</H4>\n";
//        penv(request.envp);

//        // Note: the fcgi_streambuf destructor will auto flush
//    }

//    // restore stdio streambufs
//    cin.rdbuf(cin_streambuf);
//    cout.rdbuf(cout_streambuf);
//    cerr.rdbuf(cerr_streambuf);

//    return 0;
//}



//int cinque(){
//    return 5;
//}

//bit_power tx=bit_power(4);
//tx.set(bit_power::trait::uno);
//tx.set(bit_power::trait::due);
//tx.clear(bit_power::trait::uno);
////tx.set(bit_power::trait::miao);

//uint x1 = tx.toInt ();

//bool z = tx.check(bit_power::trait::uno);
///*
//if (tx == bit_power::trait::due){
//    return z;
//}

//return z;
//*/
//campaign_status cs =campaign_status();
//cs.set(campaign_status::trait::Active_auto);
//cout << cs.toCsv ('"').toStdString ()<< endl;
//cout << cs.toCsv ().toStdString ()<< endl;
////cout << (int)cs.toInt << endl;

////return 0;

///*
//gelato g1 = gelato(24);

//g1.set(gelato::trait::cremoso);
////g1.set(gelato::trait::saporito);

//cout << g1.toCsv ('"').toStdString ()<< endl;
//cout << g1.toInt ()<< endl;
//*/




///**
// *@brief this is USUALLY used to return the numeric id of an enumerated variable
// *@example
// * enum c1;
// * c1=enum::Bonus;
// * as_integer(c1);
// */
//template <typename Enumeration>
//auto as_integer(Enumeration const value) -> typename std::underlying_type<Enumeration>::type {
//    return static_cast<typename std::underlying_type<Enumeration>::type> (value);
//}

///*
//TEST (geppetto, interi) {
//    cout << "facciamo altro ?" << cinque() << endl;
//    EXPECT_EQ (5.0, cinque ());
//}

//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();

//*/

//class test {
//protected:
//    QBitArray mask;
//    std::vector<const char*> trait_txt;
//    int val=50;


//    public:

//    enum class trait {
//        ciao,
//        miao
//    };


//    test(int size) {
//        //const vector<const char*> bit_power::trait_txt = {"x", "intelligente", "veloce"};
//        trait_txt = {"x", "intelligente", "veloce"};
//        mask.resize(size);
//    }


//    template <typename Enumeration>
//    auto set(Enumeration const x) -> typename underlying_type<Enumeration>::type {

//        mask.setBit(as_integer(x));
//        return 1; //static_cast<typename underlying_type<Enumeration>::type>(value);
//    }

//    /**
//     * @brief toInt return the corresponding value if the bitmask is less than 64 bit
//     * @return
//     */
//    uint toInt() {
//        uint64_t sum = 0;
//        for (int var = 0; var < mask.size(); ++var) {
//            if (mask.testBit(var)) {
//                sum += 1 << var;
//            }
//        }
//        return sum;
//    }

//};


////QCoreApplication a(argc, argv);
////return a.exec();


//MYSQL *conn;
//conn = mysql_init(NULL);

//if (conn == NULL) {
//    // printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
//    exit(1);
//}

//if (mysql_real_connect(conn, "localhost", "root", "", "advplace_login", 0, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
//    // printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
//    exit(1);
//}

//redisReply *reply;
////redisReply *single;

//redisContext *c = redisConnectUnix("/tmp/redis.sock");
//if (c->err) {
//    //printf("Error: %s\n", c->errstr);
//}else{
//    //printf("Connection Made! \n");
//}

//reply = (redisReply*)redisCommand(c,"PING");
////printf("PING Response: %s\n", reply->str);
//freeReplyObject(reply);

////http://codingsteps.com/installing-using-hiredis-c-client-library-for-redis/

////https://github.com/redis/hiredis/blob/master/examples/example.c

//reply = (redisReply*)redisCommand(c, "keys %s", "*");
///*
//if ( reply->type == REDIS_REPLY_ERROR )
//        printf( "Error: %s\n", reply->str );
//    else if ( reply->type != REDIS_REPLY_ARRAY )
//        printf( "Unexpected type: %d\n", reply->type );
//    else {
//        for ( i=0;  reply->elements; ++i ){
//            //if hset bla bla bla
//                single = (redisReply*)redisCommand(c,"get %s", reply->element[i]->str);

//               printf( "Result:%lu: %s e vale %s\n", i,
//                      reply->element[i]->str,single->str  );
//        }
//    }
//    printf( "Total Number of Results: %lu\n", i );
//*/
////return 0;
