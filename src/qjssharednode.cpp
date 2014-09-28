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
            connect(this, SIGNAL(dataChanged(QJS*,QString,QJS*,QJS*)), sn, SLOT(applyChange(QJS*,QString,QJS*,QJS*)));
            connect(sn, SIGNAL(dataChanged(QJS*,QString,QJS*,QJS*)), this, SLOT(applyChange(QJS*,QString,QJS*,QJS*)));
            connect(sn, SIGNAL(dataChanged(QJS*,QString,QJS*,QJS*)), this, SIGNAL(changed(QJS*,QString,QJS*,QJS*)));
            connect(this, SIGNAL(dataChanged(QJS*,QString,QJS*,QJS*)), this, SIGNAL(changed(QJS*,QString,QJS*,QJS*)));
            connect(this, SIGNAL(subscribeAdded(QJSSharedNode*)), sn, SLOT(addSubscribe(QJSSharedNode*)));
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
    foreach (QJS node, _subscribes) {
        long long nodePointer = node.toLongLong();
        QJSSharedNode* sn = (QJSSharedNode*)nodePointer;
        if (sn!=this)
        {
            connect(this, SIGNAL(dataChanged(QJS*,QString,QJS*,QJS*)), sn, SLOT(applyChange(QJS*,QString,QJS*,QJS*)));
            connect(this, SIGNAL(subscribeAdded(QJSSharedNode*)), SLOT(addSubscribe(QJSSharedNode*)));
        }
    }
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
