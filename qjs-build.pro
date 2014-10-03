TEMPLATE = subdirs

defineReplace(findQtDir){
    QTDIR=$$(QTDIR)
    !isEmpty(QTDIR){
        #message("Enviroment variable QTDIR has been setted. So, we simple use it")
        #message(QTDIR=$${QTDIR})
        return($${QTDIR});
    }
    message(Enviroment variable QTDIR is empty. We will try to get it by parsing PATH variable)
    PATH = $$(PATH)
    PATH_PARTS = $$split(PATH, :)
    FOUND = $$find(PATH_PARTS, Qt.*bin$)
    FOUND = $$first(FOUND)
    isEmpty(FOUND){
        error("Can't extract QTDIR from PATH")
    }
    names = $$split(FOUND, $${QMAKE_DIR_SEP})
    QTDIR=
    prev=
    for(name, names) {
        !isEmpty(prev){
            QTDIR=$$QTDIR$${QMAKE_DIR_SEP}$$prev
        }
        prev=$$name
    }
    message(QTDIR=$$QTDIR)
    return($$QTDIR)
}
QTDIR=$$findQtDir()

SUBDIRS = src/qjs.pro
