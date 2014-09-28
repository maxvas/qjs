#ifndef QJSDATATHREAD_H
#define QJSDATATHREAD_H

#include <QThread>
#include <QJS>

class QJSDataThread : public QThread
{
    Q_OBJECT
public:
    explicit QJSDataThread(QObject *parent = 0);
    void run();
    QJS *data;

signals:

public slots:

};

#endif // QJSDATATHREAD_H
