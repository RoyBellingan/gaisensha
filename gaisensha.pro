#-------------------------------------------------
#
# Project created by QtCreator 2014-12-20T15:15:39
#
#-------------------------------------------------
QT       += core

TARGET = gaisensha
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += c++11
TEMPLATE = app


SOURCES += main.cpp \
    src/affiliate.cpp \
    src/funkz.cpp \
    src/bid_offer.cpp \
    src/bit_power.cpp \
    src/campaign.cpp \
    src/impression.cpp

LIBS += `mysql_config --cflags --libs` -lfcgi++ -lfcgi -lhiredis

HEADERS += \
    src/affiliate.h \
    src/bid_offer.h \
    src/bit_power.h \
    src/campaign.h \
    src/impression.h

#INCLUDEPATH += "/mnt/neuhome/home/roy/scaricati/gtest-1.7.0/include/"
#LIBS += -L/mnt/neuhome/home/roy/scaricati/gtest-1.7.0/lib/.libs/ -lgtest_main -lgtest

#DEPENDPATH += $$PWD/../../../../../../mnt/neuhome/home/roy/scaricati/gtest-1.7.0/lib/.libs
