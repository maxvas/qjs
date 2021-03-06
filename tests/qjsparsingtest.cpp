#include "qjsparsingtest.h"
#include <QJS>

QJSParsingTest::QJSParsingTest(QObject *parent) :
    QObject(parent)
{
}

void QJSParsingTest::testParseString1()
{
    QString sample = "{\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.toJson()==sample, "Failure");
    QVERIFY2(a["name"].toString()=="paper", "Failure");
    QVERIFY2(a["title"].toString()=="Hello world!", "Failure");
}

void QJSParsingTest::testParseStringArray()
{
    QString sample = "[\n"
            "    1,\n"
            "    \"abc\",\n"
            "    7\n"
            "]";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.toJson()==sample, "Failure");
}

void QJSParsingTest::testParseObjectWithBool()
{
    QString sample = "{\n"
            "    \"b\": true,\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.toJson()==sample, "Failure");
}

void QJSParsingTest::testParseObjectWithDouble()
{
    QString sample = "{\n"
            "    \"a\": 5.1,\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.toJson()==sample, "Failure");
}

void QJSParsingTest::testParseText1()
{
    QString sample = "{\n"
            "    \"a\": 5.1,\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    a["title"] = "Привет мир!";
    QString str = a.toJson();
    QJS b = QJS::fromJson(str);
    QVERIFY2(b["title"]=="Привет мир!", "Failure");
}

void QJSParsingTest::testParseText2()
{
    QString sample = "{\n"
            "    \"a\": 5.1,\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    a["title"] = "Привет, мир! (А тут будет \"з@ковыристый:\"\tтекст)";
    QString str = a.toJson();
    //qDebug()<<str;
    QJS b = QJS::fromJson(str);
    QVERIFY2(b["title"]=="Привет, мир! (А тут будет \"з@ковыристый:\"\tтекст)", "Failure");
}

void QJSParsingTest::testParseEmptyObject1()
{
    QString sample = "{\n}";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.hasParsingError()==false, "Failure");
}

void QJSParsingTest::testParseEmptyObject2()
{
    QString sample = "{\n}";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a==QJS::Object, "Failure");
}

void QJSParsingTest::testParseEmptyArray1()
{
    QString sample = "[\n]";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.hasParsingError()==false, "Failure");
}

void QJSParsingTest::testParseEmptyArray2()
{
    QString sample = "[\n]";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a==QJS::Array, "Failure");
}

void QJSParsingTest::testParseBinaryString()
{
    QJS a = "test тест 123";
    QByteArray bytes= a.toByteArray();
    QJS b = QJS::fromByteArray(bytes);
    QVERIFY2(a==b, "Failure");
}

void QJSParsingTest::testParseBinaryNumber()
{
    QJS aint=4;
    QByteArray bytes = aint.toByteArray();
    QJS bint=QJS::fromByteArray(bytes);
    bytes.clear();

    QJS along=(long long)4346346;
    bytes = along.toByteArray();
    QJS blong=QJS::fromByteArray(bytes);
    bytes.clear();

    QJS adouble1=43.34;
    bytes = adouble1.toByteArray();
    QJS bdouble1=QJS::fromByteArray(bytes);
    bytes.clear();

    QJS adouble2=43e-3;
    bytes = adouble2.toByteArray();
    QJS bdouble2=QJS::fromByteArray(bytes);
    bytes.clear();

    QVERIFY2(aint==bint&&along==blong&&adouble1==bdouble1&&adouble2==bdouble2, "Failure");
}

void QJSParsingTest::testParseBinaryObject()
{
    QJS a;
    a["num1"]=5;
    a["num2"]=34.12;
    a["num3"]=34e-1;
    a["string"]="test123: тестовая __&*$%__ строка";
    a["bool"]=false;

    QByteArray bytes = a.toByteArray();
    QJS b=QJS::fromByteArray(bytes);
    QVERIFY2(a==b, "Failure");
}

void QJSParsingTest::testParseBinaryArray()
{
    QJS a;
    a[0]=5;
    a[1]=34.12;
    a.append(34e-1);
    a.append("test123: тестовая __&*$%__ строка");
    a.append(true);

    QByteArray bytes = a.toByteArray();
    QJS b=QJS::fromByteArray(bytes);
    QVERIFY2(a==b, "Failure");
}

void QJSParsingTest::testParseBinaryComplex()
{
    QString sample = "{\n"
            "    \"a\": 5.1,\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    a["title"] = "Привет, мир! (А тут будет \"з@ковыристый:\"\tтекст)";
    QJS a_complex;
    a_complex["a"]="a";
    a_complex["b"]=12;
    a_complex["c"]=true;
    a_complex["object"]=a;
    a_complex["array"].append(1);
    a_complex["array"].append("test123: тестовая __&*$%__ строка");
    a_complex["array"].append(a);

    QByteArray bytes = a_complex.toByteArray();
    QJS b=QJS::fromByteArray(bytes);
    QVERIFY2(a_complex==b, "Failure");
}

void QJSParsingTest::testParsingError1()
{
    QJS a;
    QString failed_sample = "{\n"
            "    \"authors\": [\n"
            "        null,\n"
            "        null,\n"
            "        \"Max\",\n"
            "        null,\n"
            "        \"Ann\",\n"
            "        null,\n"
            "        null,\n"
            "        \"Vas\"\n"
            "    ]\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\",\n"
            "    \"params\": {"
            "        \"a\":4"
            "    }"
            "}";
    a=QJS::fromJson(failed_sample);
    QVERIFY2(a.parsingErrorString()=="JSON parsing error: \",\" or \"}\" expected at line: 12, column: 6." , "Failure");
}
