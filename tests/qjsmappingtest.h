#ifndef QJSMAPPINGTEST_H
#define QJSMAPPINGTEST_H

#include <QObject>
#include <QtTest>
#include <QJSMapping>



class MappingTester1 : public QJSMapping
{
    Q_OBJECT
public:
    QJS_MAPPING_QSTRING("test", test, setTest)
    QJS_MAPPING_QSTRING("test1", test1, setTest1)
    QJS_MAPPING_QSTRING("test2", test2, setTest2)
};

class MappingTester2 : public QJSMapping
{
    Q_OBJECT
public:
    QJS_MAPPING_OBJECT("obj", object1, setObject1, MappingTester1)
};

class MappingTester3 : public QJSMapping
{
    Q_OBJECT
public:
    QJS_MAPPING_ARRAY("arr", getArray, addTester1, MappingTester1)
};

class MappingTester4 : public QJSMapping
{
    Q_OBJECT
public:
    QJS_MAPPING_STRINGHASH("dict", dict, getDictItem, setDictItem, MappingTester1)
};

class QJSMappingTest : public QObject
{
    Q_OBJECT
public:
    explicit QJSMappingTest(QObject *parent = 0);

signals:

private slots:
    void fieldGetter();
    void fieldSetter();
    void objectGetter();
    void objectSetter();
    void arrayTest();
    void stringHashTester1();
    void stringHashTester2();

};

#endif // QJSMAPPINGTEST_H
