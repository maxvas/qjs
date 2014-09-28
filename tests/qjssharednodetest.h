#ifndef QJSSHAREDNODETEST_H
#define QJSSHAREDNODETEST_H

#include <QtTest>
#include <QJSLeaksTest>

class QJSSharedNodeTest : public QObject
{
    Q_OBJECT
public:
    explicit QJSSharedNodeTest(QObject *parent = 0);

private slots:
    //Тестирование QJSSharedNode
    void testQJSSharedNode1();
    void testQJSSharedNode2();
    void testQJSSharedNode3();
    void testQJSSharedNode4();

};

#endif // QJSSHAREDNODETEST_H
