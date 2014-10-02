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
    qjsmapping.h \
    QJS \
    QJSMapping
    
unix {
    target.path = /usr/lib/qjs
    includes.path =  /usr/include/qjs
    includes.files = $$HEADERS
} else {
    target.path = ../install/lib
    includes.path =  ../install/include
    includes.files = $$HEADERS
}
features_dir = $$(QTDIR)/mkspecs/features
qjs_feature.path = $$(QTDIR)/mkspecs/features
qjs_feature.files = qjs.prf
qjs_feature.extra += echo "INCLUDEPATH += /usr/include/qjs" > qjs.prf; \
echo "LIBS += -L/usr/lib/qjs -lqjs" >> qjs.prf
INSTALLS += target includes qjs_feature
QMAKE_CLEAN += qjs.prf
QMAKE_CLEAN += -r $${DESTDIR}
