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
    classes.cpp

LIBS += `mysql_config --cflags --libs` -lfcgi++ -lfcgi -lhiredis

HEADERS +=

#INCLUDEPATH += "/mnt/neuhome/home/roy/scaricati/gtest-1.7.0/include/"
#LIBS += -L/mnt/neuhome/home/roy/scaricati/gtest-1.7.0/lib/.libs/ -lgtest_main -lgtest

#DEPENDPATH += $$PWD/../../../../../../mnt/neuhome/home/roy/scaricati/gtest-1.7.0/lib/.libs
