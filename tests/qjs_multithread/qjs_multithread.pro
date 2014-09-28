#-------------------------------------------------
#
# Project created by QtCreator 2014-05-18T16:05:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = qjs_multithread
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += "../../src"
LIBS += -L"../../bin" -lqjs

SOURCES += main.cpp \
    qjsdatathread.cpp \
    qjsworker.cpp

HEADERS += \
    qjsdatathread.h \
    qjsworker.h
