#-------------------------------------------------
#
# Project created by QtCreator 2014-04-21T03:44:08
#
#-------------------------------------------------

QT       -= gui

DESTDIR = ../bin

TARGET = qjs
TEMPLATE = lib

DEFINES += QJS_LIBRARY

SOURCES += qjs.cpp \
    qjsleakstest.cpp \
    qjssharednode.cpp \
    qjsmapping.cpp

HEADERS += qjs.h\
        qjs_global.h \
    qjsleakstest.h \
    QJSLeaksTest \
    qjssharednode.h \
    QJSSharedNode \
    qjsmapping.h
    
unix {
    target.path = /usr/lib/qjs
    includes.path =  /usr/include/qjs
    includes.files = $$HEADERS
    INSTALLS += target
}

OTHER_FILES += \
    QJS \
    QJSMapping
