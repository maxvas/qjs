#ifndef QJSLEAKSTEST_H
#define QJSLEAKSTEST_H

#include <QMutex>
#include "qjs_global.h"

class QJSSHARED_EXPORT QJSLeaksTest
{
public:
    static QJSLeaksTest* instance()
    {
        static QMutex mutex;
        if (!m_Instance)
        {
            mutex.lock();

            if (!m_Instance)
                m_Instance = new QJSLeaksTest;

            mutex.unlock();
        }

        return m_Instance;
    }

    static void drop()
    {
        static QMutex mutex;
        mutex.lock();
        delete m_Instance;
        m_Instance = 0;
        mutex.unlock();
    }

    bool QJS_leaksTest;
    int QJS_objectsCount;

private:
    QJSLeaksTest()
    {
        QJS_leaksTest = false;
        QJS_objectsCount = 0;
    }

    QJSLeaksTest(const QJSLeaksTest &); // hide copy constructor
    QJSLeaksTest& operator=(const QJSLeaksTest &); // hide assign op
                                 // we leave just the declarations, so the compiler will warn us
                                 // if we try to use those two functions by accident

    static QJSLeaksTest* m_Instance;
};

#endif // QJSLEAKSTEST_H
