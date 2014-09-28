#include "qjssharednodetest.h"
#include <QJSSharedNode>

QJSSharedNodeTest::QJSSharedNodeTest(QObject *parent) :
    QObject(parent)
{
}

void QJSSharedNodeTest::testQJSSharedNode1()
{
    QJSSharedNode a;
    //Инициализируем b с данными a и подписками на a
    QJSSharedNode b(a.initData());
    b["a"] = 1;
    QVERIFY2(a["a"].toInt()==1, "Failure");
}

void QJSSharedNodeTest::testQJSSharedNode2()
{
    QJSSharedNode a;
    QJSSharedNode b(a.initData());
    b["params"]["a"] = 1;
    QVERIFY2(a["params"]["a"].toInt()==1, "Failure");
}

void QJSSharedNodeTest::testQJSSharedNode3()
{
    QJSSharedNode a;
    QJSSharedNode b(a.initData());
    QJSSharedNode c(a.initData());
    b["params"]["a"] = 1;
    c["params"]["b"] = 2;
//    qDebug()<<"a:\n";
//    qDebug()<<a.toJson();
//    qDebug()<<"b:\n";
//    qDebug()<<b.toJson();
//    qDebug()<<"c:\n";
//    qDebug()<<c.toJson();
    QVERIFY2(a.toJson()==b.toJson() && a.toJson()==c.toJson() && c["params"]["a"].toInt()==1 && c["params"]["b"].toInt()==2, "Failure");
}

void QJSSharedNodeTest::testQJSSharedNode4()
{
    QJSSharedNode a;
    QJSSharedNode b(a.initData());
    QJSSharedNode c(b.initData());
    b["params"]["a"] = 1;
    c["params"]["b"] = 2;
//    qDebug()<<"a:\n";
//    qDebug()<<a.toJson();
//    qDebug()<<"b:\n";
//    qDebug()<<b.toJson();
//    qDebug()<<"c:\n";
//    qDebug()<<c.toJson();
    QVERIFY2(a.toJson()==b.toJson() && a.toJson()==c.toJson() && c["params"]["a"].toInt()==1 && c["params"]["b"].toInt()==2, "Failure");
}
