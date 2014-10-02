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
    target.path = /usr/lib/qjs
    includes.path =  /usr/include/qjs
    includes.files = $$HEADERS
} else {
    target.path = $$PWD/../install/lib
    includes.path =  $$PWD/../install/include
    includes.files = $$HEADERS
}
features_dir = $$(QTDIR)/mkspecs/features
qjs_feature.path = $$(QTDIR)/mkspecs/features
qjs_feature.files = $${OUT_PWD}/qjs.prf
unix{
	qjs_feature.extra += echo "INCLUDEPATH += /usr/include/qjs" > $${OUT_PWD}/qjs.prf && echo "LIBS += -L/usr/lib/qjs -lqjs" >> $${OUT_PWD}/qjs.prf
}
win32{
	qjs_feature.extra += echo "INCLUDEPATH += \"$$PWD/../install/lib\"" > $${OUT_PWD}/qjs.prf && echo "LIBS += -L\"$$PWD/../install/lib\" -lqjs" >> $${OUT_PWD}/qjs.prf
}
INSTALLS += target includes qjs_feature
QMAKE_CLEAN += $${OUT_PWD}/qjs.prf
QMAKE_CLEAN += -r $${DESTDIR}
