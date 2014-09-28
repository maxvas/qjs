#-------------------------------------------------
#
# Project created by QtCreator 2014-04-21T04:04:30
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_qjstests

TEMPLATE = app

INCLUDEPATH += "../src"
LIBS += -L"../bin" -lqjs

SOURCES += \
    qjsbasetest.cpp \
    main.cpp \
    qjssharednodetest.cpp \
    qjsparsingtest.cpp \
    qjsmappingtest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    qjsbasetest.h \
    qjssharednodetest.h \
    qjsparsingtest.h \
    qjsmappingtest.h
