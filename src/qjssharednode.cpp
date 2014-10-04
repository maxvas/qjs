#include "qjssharednode.h"
#include <QDebug>

QJSSharedNode::QJSSharedNode(QByteArray initData) :
    QJS(), _subscribes()
{
    QJS d = QJS::fromJson(QString::fromUtf8(initData));
    set(d["data"]);
    _subscribes = d["subscribes"];
    _subscribes.append((long long) this);
    //_allNodes.assign(QJS::fromJson(allNodes));
    foreach (QJS node, _subscribes) {
        long long nodePointer = node.toLongLong();
        QJSSharedNode* sn = (QJSSharedNode*)nodePointer;
        if (sn!=this)
        {
            connect(this, SIGNAL(dataChanged(QByteArray,QString,QByteArray,QByteArray)), sn, SLOT(applyChange(QByteArray,QString,QByteArray,QByteArray)));
            connect(sn, SIGNAL(dataChanged(QByteArray,QString,QByteArray,QByteArray)), this, SLOT(applyChange(QByteArray,QString,QByteArray,QByteArray)));
            connect(sn, SIGNAL(dataChanged(QByteArray,QString,QByteArray,QByteArray)), this, SIGNAL(changed(QByteArray,QString,QByteArray,QByteArray)));
            connect(this, SIGNAL(dataChanged(QByteArray,QString,QByteArray,QByteArray)), this, SIGNAL(changed(QByteArray,QString,QByteArray,QByteArray)));
            connect(this, SIGNAL(subscribeAdded(QJSSharedNode*)), sn, SLOT(addSubscribe(QJSSharedNode*)));
            connect(sn, SIGNAL(dataChanged(QByteArray,QString,QByteArray,QByteArray)), this, SLOT(myChanged(QByteArray,QString,QByteArray,QByteArray)));
            connect(this, SIGNAL(dataChanged(QByteArray,QString,QByteArray,QByteArray)), sn, SLOT(myChanged(QByteArray,QString,QByteArray,QByteArray)));
        }
    }
    enableSignals();
    emit subscribeAdded(this);
}

QJSSharedNode::QJSSharedNode():
    QJS(), _subscribes()
{
    //_allNodes.assign(QJS::fromJson(allNodes));
    _subscribes.append((long long) this);
    enableSignals();
    emit subscribeAdded(this);
}

QByteArray QJSSharedNode::initData()
{
    QJS d;
    d["data"] = (*this);
    d["subscribes"] = _subscribes;
    return d.toJson().toUtf8();
}

QString QJSSharedNode::data()
{
    return toJson();
}

QString QJSSharedNode::subscribes()
{
    return _subscribes.toJson();
}

void QJSSharedNode::addSubscribe(QJSSharedNode *sn)
{
    _subscribes.append((long long)sn);
}

void QJSSharedNode::myChanged(QByteArray address, QString operation, QByteArray newData, QByteArray oldData)
{
    //TODO: Выяснить, почему не работает сигнал chenged со всеми аргументами. Сейчас работает только по-тупому. changed()
    emit changed();
}
