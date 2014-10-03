#-------------------------------------------------
#
# Project created by QtCreator 2014-04-21T03:44:08
#
#-------------------------------------------------

QT       -= gui

DESTDIR = $$PWD/../bin

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
    target.path = /usr/lib
    includes.path =  /usr/include/qjs
    includes.files = $$HEADERS
} else {
    target.path = $$PWD/../install/lib
    includes.path =  $$PWD/../install/include
    includes.files = $$HEADERS
}
prffile = $$(QTDIR)/mkspecs/features/qjs.prf
unix{
    feature.path = $${QTDIR}/mkspecs/features
    feature.files = $$prffile
    feature.extra += echo "INCLUDEPATH += /usr/include/qjs" > $$prffile && echo "LIBS += -L/usr/lib -lqjs" >> $$prffile
}
win32{
    feature.path = $${QTDIR}/mkspecs/features
    feature.files = $$prffile
    feature.extra += echo "INCLUDEPATH += \"$$PWD/../install/lib\"" > $$prffile echo "LIBS += -L\"$$PWD/../install/lib\" -lqjs" >> $$prffile
}
INSTALLS += target includes feature
QMAKE_CLEAN += qjs.prf
QMAKE_CLEAN += -r $${DESTDIR}/*$${TARGET}*
unix {
    QMAKE_CLEAN += /usr/lib/*$${TARGET}*
    QMAKE_CLEAN += -r /usr/include/qjs
} else {
    QMAKE_CLEAN += -r $$PWD/../install/lib
    QMAKE_CLEAN += -r $$PWD/../install/include
}
QMAKE_CLEAN += $${QTDIR}/mkspecs/features/qjs.prf
