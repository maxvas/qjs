#include "qjsworker.h"
#include <QDebug>

QJSWorker::QJSWorker(QJS *data) :
    QThread(0)
{
    _data = data;
}

void QJSWorker::run()
{
    for (int i=0; i<3000; i++)
    {
        iteration(*_data);
        qDebug()<<i;
    }
    qDebug()<<"ok";
}

void QJSWorker::iteration(QJS &data)
{
    data["array1"].append(1);
    data["array1"].append(true);
    data["array1"].append("123");
    data["array2"].prepend(1);
    data["array2"].prepend(true);
    data["array2"].prepend("123");
    QJS object;
    object["a"] = 2;
    object["b"] = "123";
    object["c"] = true;
    object["d"] = QString("1234");
    object["e"] = 2.3;
    object["f"] = (long long)_data;
    data["h"] = object;
    int a = data["h"]["a"].toInt();
    QJS::Type t = data["h"]["a"].type();
    int len = data["array"].length();
    len = data["array"].size();
    len = data["array"].count();
    data["array"].key();
    data["array1"][0].index();
    data["array1"][0] = 2;
}
