#ifndef gaisenshaTEST_H
#define gaisenshaTEST_H

#include <QtCore/QObject>
#include <QtTest/QTest>

class gaisenshaTest : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();
    void someTest();
};

#endif // gaisenshaTEST_H
