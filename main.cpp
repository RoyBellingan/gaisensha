#include <iostream>
#include </usr/include/fastcgi/fcgio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <QCoreApplication>
#include <QString>
#include <QHash>
#include <QUrl>
#include <QUrlQuery>

#include <mysql/mysql.h>
#include "/usr/local/include/hiredis/hiredis.h"


//#include </mnt/neuhome/home/roy/scaricati/gtest-1.7.0/include/gtest/gtest.h>
#include <src/bit_power.h>
#include <src/campaign.h>


using namespace std;

static void penv(const char * const * envp)
{
    cout << "<PRE>\n";
    for ( ; *envp; ++envp)
    {
        cout << *envp << "\n";
    }
    cout << "</PRE>\n";
}
int cinque(){
    return 5;
}

/**
 *@brief this is USUALLY used to return the numeric id of an enumerated variable
 *@example
 * enum c1;
 * c1=enum::Bonus;
 * as_integer(c1);
 */
template <typename Enumeration>
auto as_integer(Enumeration const value) -> typename std::underlying_type<Enumeration>::type {
    return static_cast<typename std::underlying_type<Enumeration>::type> (value);
}

/*
TEST (geppetto, interi) {
    cout << "facciamo altro ?" << cinque() << endl;
    EXPECT_EQ (5.0, cinque ());
}

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

*/

class test {
protected:
    QBitArray mask;
    std::vector<const char*> trait_txt;
    int val=50;


    public:

    enum class trait {
        ciao,
        miao
    };


    test(int size) {
        //const vector<const char*> bit_power::trait_txt = {"x", "intelligente", "veloce"};
        trait_txt = {"x", "intelligente", "veloce"};
        mask.resize(size);
    }


    template <typename Enumeration>
    auto set(Enumeration const x) -> typename underlying_type<Enumeration>::type {

        mask.setBit(as_integer(x));
        return 1; //static_cast<typename underlying_type<Enumeration>::type>(value);
    }

    /**
     * @brief toInt return the corresponding value if the bitmask is less than 64 bit
     * @return
     */
    uint toInt() {
        uint64_t sum = 0;
        for (int var = 0; var < mask.size(); ++var) {
            if (mask.testBit(var)) {
                sum += 1 << var;
            }
        }
        return sum;
    }

};

int main(int argc, char *argv[]) {

    bit_power tx=bit_power(4);
    tx.set(bit_power::trait::uno);
    tx.set(bit_power::trait::due);
    tx.clear(bit_power::trait::uno);
    //tx.set(bit_power::trait::miao);

    uint x1 = tx.toInt ();

    bool z = tx. bit_power::trait::due;

    if (tx == bit_power::trait::due){
        return 7;
    }

return x1;

    campaign_status cs =campaign_status();
    cs.set(campaign_status::trait::Active_auto);
    cout << cs.toCsv ('"').toStdString ()<< endl;
    cout << cs.toCsv ().toStdString ()<< endl;
    //cout << (int)cs.toInt << endl;

return 0;

/*
    gelato g1 = gelato(24);

    g1.set(gelato::trait::cremoso);
    //g1.set(gelato::trait::saporito);

    cout << g1.toCsv ('"').toStdString ()<< endl;
    cout << g1.toInt ()<< endl;
*/




    //QCoreApplication a(argc, argv);
    //return a.exec();

    int count=0;
    long pid = getpid();

    // Backup the stdio streambufs
    streambuf * cin_streambuf  = cin.rdbuf();
    streambuf * cout_streambuf = cout.rdbuf();
    streambuf * cerr_streambuf = cerr.rdbuf();

    FCGX_Request request;

    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    MYSQL *conn;
    conn = mysql_init(NULL);

    if (conn == NULL) {
        // printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "root", "", "advplace_login", 0, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
        // printf("Error %u: %s\n", mysql_errno(conn), mysql_error(conn));
        exit(1);
    }

    redisReply *reply;
    redisReply *single;

    redisContext *c = redisConnectUnix("/tmp/redis.sock");
    if (c->err) {
        // printf("Error: %s\n", c->errstr);
    }else{
        //printf("Connection Made! \n");
    }

    reply = (redisReply*)redisCommand(c,"PING");
    //printf("PING Response: %s\n", reply->str);
    freeReplyObject(reply);

    //http://codingsteps.com/installing-using-hiredis-c-client-library-for-redis/

    //https://github.com/redis/hiredis/blob/master/examples/example.c

    reply = (redisReply*)redisCommand(c, "keys %s", "*");
    /*
    if ( reply->type == REDIS_REPLY_ERROR )
            printf( "Error: %s\n", reply->str );
        else if ( reply->type != REDIS_REPLY_ARRAY )
            printf( "Unexpected type: %d\n", reply->type );
        else {
            for ( i=0;  reply->elements; ++i ){
                //if hset bla bla bla
                    single = (redisReply*)redisCommand(c,"get %s", reply->element[i]->str);

                   printf( "Result:%lu: %s e vale %s\n", i,
                          reply->element[i]->str,single->str  );
            }
        }
        printf( "Total Number of Results: %lu\n", i );
*/
    //return 0;

    while (FCGX_Accept_r(&request) == 0) {
        count++;
        fcgi_streambuf cin_fcgi_streambuf(request.in);
        fcgi_streambuf cout_fcgi_streambuf(request.out);
        fcgi_streambuf cerr_fcgi_streambuf(request.err);

        cin.rdbuf(&cin_fcgi_streambuf);
        cout.rdbuf(&cout_fcgi_streambuf);
        cerr.rdbuf(&cerr_fcgi_streambuf);

        QByteArray cookie_raw= FCGX_GetParam("HTTP_COOKIE", request.envp);
        QHash<QString, QString> cookie;

        foreach(QByteArray line, cookie_raw.split(';')){
            int colon = line.indexOf('=');
            QByteArray headerName = line.left(colon).trimmed();
            QByteArray headerValue = line.mid(colon + 1).trimmed();
            cookie.insertMulti(headerName, headerValue);
        }


        QString url= FCGX_GetParam("SCRIPT_URL", request.envp);
        QUrlQuery query;
        query.setQuery (FCGX_GetParam("QUERY_STRING", request.envp));

        cout << "Content-type: text/html\r\n"
             << "\r\n"
             << "<html>\n"
             << "  <head>\n"
             << "    <title>Hello, World!</title>\n"
             << "  </head>\n"
             << "  <body>\n"
             << "    <h1>Hello, World!</h1>\n"
             << "    per la " << count << " volta \n"
             << "<H4>da PID: " << pid << "</H4>\n"
             << cookie["WikiRoyUserName"].toStdString () << " + "
             << query.queryItemValue ("nyan").toStdString () << " +  " << url.toStdString () << "\n"
             << "</html>\n";

        cout << "<H4>Request Environment</H4>\n";
        penv(request.envp);

        // Note: the fcgi_streambuf destructor will auto flush
    }

    // restore stdio streambufs
    cin.rdbuf(cin_streambuf);
    cout.rdbuf(cout_streambuf);
    cerr.rdbuf(cerr_streambuf);

    return 0;
}
