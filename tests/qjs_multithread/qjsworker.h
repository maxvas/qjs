#ifndef QJSWORKER_H
#define QJSWORKER_H

#include <QThread>
#include <QJS>

class QJSWorker : public QThread
{
    Q_OBJECT
public:
    explicit QJSWorker(QJS *data);
    void run();
    void iteration(QJS &data);

private:
    QJS *_data;
signals:

public slots:

};

#endif // QJSWORKER_H
