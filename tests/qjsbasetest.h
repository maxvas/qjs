#ifndef QJSBASETEST_H
#define QJSBASETEST_H

#include <QtTest>
#include <QJSLeaksTest>
#include <QJS>

class QJSBaseTest : public QObject
{
    Q_OBJECT
public:
    explicit QJSBaseTest(QObject *parent = 0);
    QJS changedData;

private slots:
    //Конструктор
    void testConstructor_Null();
    void testConstructor_Bool();
    void testConstructor_QJS();
    //Присваивание
    void testAssignmentBool_toBool_1();
    void testAssignmentBool_toBool_2();
    void testAssignmentInt_toInt();
    void testAssignmentDouble_toDouble();
    void testAssignmentBool_Type();
    void testAssignmentInt_Type();
    void testAssignmentDouble_Type();
    void testAssignmentString_Type();
    void testAssignmentString_toString();
    void testAssignmentInt_toString();
    void testAssignmentInt_toDouble();
    void testAssignmentDouble_toInt();
    void testAssignmentDouble_toString();
    void testAssignmentBool_toString();
    //Присваивание объекту через квадратные скобки
    void testObjectAccessAssignmentBool();
    void testObjectAccessAssignmentInt();
    void testObjectAccessAssignmentString();
    //Присваивание массиву через квадратные скобки
    void testArrayAccessAssigmentBool();
    //Object to String
    void testObjectToString();
    void testObjectToString2();
    //Array
    void testArraySize();
    void testArraySize2();
    void testArraySize3();
    void testArrayToString();
    void testArrayRemove();
    void testArrayPush();
    //foreach
    void testObjectForeach();
    void testArrayForeach();
    void testObjectKeysForeach();
    //Test memory leaks
    void testLeakConstructor();
    void testLeakParseObjectWithDouble();
    void testLeakParseComplexObject();
    void testLeakParseComplexObject2();
    void testLeakObjectAccessAssignmentBool();
    void testLeakParse1();
    void testLeakGet();
    //Сравнение
    void testComparison1();
    void testComparison2();
    void testComparison3();
    void testComparison4();
    void testComparison5();
    void testComparison6();
    //Сигнал changed
    void slotChanged(QByteArray addressData, QString operation, QByteArray newDataData, QByteArray oldDataData);
    void testChanged1();
    //Тест на size и clear
    void testArraySize4();
    //Тест на изменение типа qjs
    void testObjectToArrayTransform();
    void testObjectToArrayTransform2();
    void testArrayToObjectTransform();
    void testArrayToObjectTransform2();
    //Тест на size() object'a
    void testObjectSize();

};

#endif // QJSBASETEST_H
