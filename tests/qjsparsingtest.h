#ifndef QJSPARSINGTEST_H
#define QJSPARSINGTEST_H

#include <QtTest>
#include <QJSLeaksTest>

class QJSParsingTest : public QObject
{
    Q_OBJECT
public:
    explicit QJSParsingTest(QObject *parent = 0);

private slots:
    //Parsing
    void testParseString1();
    void testParseStringArray();
    void testParseObjectWithBool();
    void testParseObjectWithDouble();
    void testParseText1();
    void testParseText2();
    void testParseEmptyObject1();
    void testParseEmptyObject2();
    void testParseEmptyArray1();
    void testParseEmptyArray2();
    //ParsingBinaryData
    void testParseBinaryString();
    void testParseBinaryNumber();
    void testParseBinaryObject();
    void testParseBinaryArray();
    void testParseBinaryComplex();
    //Тестирование ошибок при парсинге
    void testParsingError1();

};

#endif // QJSPARSINGTEST_H
