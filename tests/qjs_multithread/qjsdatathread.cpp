#include "qjsdatathread.h"

QJSDataThread::QJSDataThread(QObject *parent) :
    QThread(parent)
{
}

void QJSDataThread::run()
{
    data = new QJS();
}
