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
    
build_dir = $${PWD}/../build
message(Bilding files will be placed in $$build_dir)

Release:OBJECTS_DIR = $${build_dir}/release/.obj
Release:MOC_DIR = $${build_dir}/release/.moc
Release:RCC_DIR = $${build_dir}/release/.rcc
Release:UI_DIR = $${build_dir}/release/.ui

Debug:OBJECTS_DIR = $${build_dir}/debug/.obj
Debug:MOC_DIR = $${build_dir}/debug/.moc
Debug:RCC_DIR = $${build_dir}/debug/.rcc
Debug:UI_DIR = $${build_dir}/debug/.ui

#STEP2: make feature

unix{
    feature.commands += echo "INCLUDEPATH += /usr/include/qjs" > qjs.prf && echo "LIBS += -L/usr/lib -lqjs" >> qjs.prf
}
win32{
    feature.commands += echo "INCLUDEPATH += \"$$PWD/../install/lib\"" > qjs.prf & echo "LIBS += -L\"$$PWD/../install/lib\" -lqjs" >> qjs.prf
}

QMAKE_EXTRA_TARGETS += feature
#STEP3: make install
unix {
    target.path = /usr/lib
    includes.path =  /usr/include/qjs
    includes.files = $$HEADERS
} else {
    target.path = $$PWD/../install/lib
    includes.path =  $$PWD/../install/include
    includes.files = $$HEADERS
}
features_dir = $$(QTDIR)/mkspecs/features
qjs_feature.path = $$(QTDIR)/mkspecs/features
qjs_feature.files = qjs.prf
INSTALLS += target includes qjs_feature
QMAKE_CLEAN += qjs.prf
QMAKE_CLEAN += -r $${DESTDIR}/*$${TARGET}*
unix {
    QMAKE_CLEAN += /usr/lib/*$${TARGET}*
    QMAKE_CLEAN += -r /usr/include/qjs
} else {
    QMAKE_CLEAN += -r $$PWD/../install/lib
    QMAKE_CLEAN += -r $$PWD/../install/include
}
QMAKE_CLEAN += $$(QTDIR)/mkspecs/features/qjs.prf
