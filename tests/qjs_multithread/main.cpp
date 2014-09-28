#include <QCoreApplication>
#include "qjsdatathread.h"
#include "qjsworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QJSDataThread dataThread;
    dataThread.start();
    QThread::sleep(1);
    QJSWorker worker1(dataThread.data);
    worker1.start();
    QJSWorker worker2(dataThread.data);
    worker2.start();
    QJSWorker worker3(dataThread.data);
    worker3.start();
    QJSWorker worker4(dataThread.data);
    worker4.start();
    return a.exec();
}
