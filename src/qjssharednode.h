#ifndef QJSSHAREDNODE_H
#define QJSSHAREDNODE_H

#include "QJS"
#include <QObject>

class QJSSHARED_EXPORT QJSSharedNode : public QJS
{
    Q_OBJECT
public:
    explicit QJSSharedNode(QByteArray initData);
    QJSSharedNode();
    QByteArray initData();

private:
    QString data();
    QString subscribes();
    QJS _subscribes;
    QMutex _mutex;

signals:
    void subscribeAdded(QJSSharedNode *sn);
    void changed(QByteArray address, QString operation, QByteArray newData, QByteArray oldData);
    void changed();

public slots:
    void addSubscribe(QJSSharedNode *sn);
    void myChanged(QByteArray address, QString operation, QByteArray newData, QByteArray oldData);

};

#endif // QJSSHAREDNODE_H
