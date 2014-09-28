#include "qjsmappingtest.h"

QJSMappingTest::QJSMappingTest(QObject *parent) :
    QObject(parent)
{
}

void QJSMappingTest::fieldGetter()
{
    MappingTester1 t;
    t["test"] = "123";
    QString str = t.test();
    QVERIFY2(str=="123", "Failure");
}

void QJSMappingTest::fieldSetter()
{
    MappingTester1 t;
    t.setTest("123");
    QString str = t.test();
    QVERIFY2(str=="123", "Failure");
}

void QJSMappingTest::objectGetter()
{
    MappingTester1 o1;
    o1.setTest("123");
    MappingTester2 o2;
    o2["obj"] = o1;
    MappingTester1 o3 = o2.object1();
    QVERIFY2(o3.test()=="123", "Failure");
}

void QJSMappingTest::objectSetter()
{
    MappingTester1 o1;
    o1.setTest("123");
    MappingTester2 o2;
    o2.setObject1(o1);
    MappingTester1 o3 = o2.object1();
    QVERIFY2(o3.test()=="123", "Failure");
}

void QJSMappingTest::arrayTest()
{
    MappingTester1 o1;
    o1.setTest("1");
    MappingTester1 o2;
    o2.setTest("2");
    MappingTester1 o3;
    o3.setTest("3");
    MappingTester3 a;
    a.addTester1(o1);
    a.addTester1(o2);
    a.addTester1(o3);
    QString res = "";
    foreach(QJS elem, a.getArray())
    {
        res+=((MappingTester1&)elem).test();
    }
    QVERIFY2(res=="123", "Failure");
}

void QJSMappingTest::stringHashTester1()
{
    MappingTester1 o1;
    o1.setTest("1");
    MappingTester1 o2;
    o2.setTest("2");
    MappingTester1 o3;
    o3.setTest("3");
    MappingTester4 a;
    a.setDictItem("key1", o1);
    a.setDictItem("key2", o2);
    a.setDictItem("key3", o3);
    QJS dict = a.dict();
    QVERIFY2(dict.count()==3, "Failure");
}

void QJSMappingTest::stringHashTester2()
{
    MappingTester1 o1;
    o1.setTest("1");
    MappingTester1 o2;
    o2.setTest("2");
    MappingTester1 o3;
    o3.setTest("3");
    MappingTester4 a;
    a.setDictItem("key1", o1);
    a.setDictItem("key2", o2);
    a.setDictItem("key3", o3);
    QVERIFY2(a.getDictItem("key1").test()=="1", "Failure");
}
