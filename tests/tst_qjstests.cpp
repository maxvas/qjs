#include <QtTest>
#include <QJS>
#include <QJSLeaksTest>
#include <QJSSharedNode>
#include <QDataStream>

class QJSTests : public QObject
{
    Q_OBJECT

public:
    QJSTests();
    QJS changedData;
    ~QJSTests();

private Q_SLOTS:
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
    //Parsing
    void testParseString1();
    void testParseStringArray();
    void testParseObjectWithBool();
    void testParseObjectWithDouble();
    void testParseText1();
    void testParseText2();
    //ParsingBinaryData
    void testParseBinaryString();
    void testParseBinaryNumber();
    void testParseBinaryObject();
    void testParseBinaryArray();
    void testParseBinaryComplex();
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
    void slotChanged(QJS* address, QString operation, QJS* newData, QJS* oldData);
    void testChanged1();
    //Тестирование QJSSharedNode
    void testQJSSharedNode1();
    void testQJSSharedNode2();
    void testQJSSharedNode3();
    void testQJSSharedNode4();
    //Тестирование ошибок при парсинге
    void testParsingError1();
    //Тест на size и clear
    void testArraySize4();
    //Тест на изменение типа qjs
//    void test
};

QJSTests::QJSTests()
{
    QJSLeaksTest::instance()->QJS_leaksTest = true;
}

QJSTests::~QJSTests()
{
}

void QJSTests::testConstructor_Null()
{
    QJS a;
    QVERIFY2(a.type()==QJS::Null, "Failure");
}

void QJSTests::testConstructor_Bool()
{
    QJS a = true;
    QVERIFY2(a.type()==QJS::Bool, "Failure");
}

void QJSTests::testConstructor_QJS()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QString sample = "{\n"
                "    \"authors\": [\n"
                "        null,\n"
                "        null,\n"
                "        \"Max\",\n"
                "        null,\n"
                "        \"Ann\",\n"
                "        null,\n"
                "        null,\n"
                "        \"Vas\"\n"
                "    ],\n"
                "    \"name\": \"paper\",\n"
                "    \"params\": {\n"
                "        \"a\": 4\n"
                "    },\n"
                "    \"title\": \"Hello world!\"\n"
                "}";
        QJS a = QJS::fromJson(sample);
        QJS b = a;
        a = false;
        //qDebug()<<sample;
        //qDebug()<<b.toString();
        QVERIFY2(b.toJson()==sample, "Failure");
    }
}

void QJSTests::testAssignmentBool_toBool_1()
{
    QJS a;
    a = true;
    QVERIFY2(a.toBool()==true, "Failure");
}

void QJSTests::testAssignmentBool_toBool_2()
{
    QJS a;
    a = false;
    QVERIFY2(a.toBool()==false, "Failure");
}

void QJSTests::testAssignmentInt_toInt()
{
    QJS a;
    a = 4;
    QVERIFY2(a.toInt()==4, "Failure");
}

void QJSTests::testAssignmentDouble_toDouble()
{
    QJS a;
    a = 4.1;
    QVERIFY2(a.toDouble()==4.1, "Failure");
}

void QJSTests::testAssignmentBool_Type()
{
    QJS a;
    a = true;
    QVERIFY2(a.type()==QJS::Bool, "Failure");
}

void QJSTests::testAssignmentInt_Type()
{
    QJS a;
    a = 4;
    QVERIFY2(a.type()==QJS::Number, "Failure");
}

void QJSTests::testAssignmentDouble_Type()
{
    QJS a;
    a = 4.1;
    QVERIFY2(a.type()==QJS::Number, "Failure");
}

void QJSTests::testAssignmentString_Type()
{
    QJS a;
    a = "blabla";
    QVERIFY2(a.type()==QJS::String, "Failure");
}

void QJSTests::testAssignmentBool_toString()
{
    QJS a;
    a = true;
    QVERIFY2(a.toJson()=="true", "Failure");
}

void QJSTests::testAssignmentInt_toString()
{
    QJS a;
    a = 4;
    QVERIFY2(a.toJson()=="4", "Failure");
}

void QJSTests::testAssignmentInt_toDouble()
{
    QJS a;
    a = 4;
    QVERIFY2(a.toDouble()==4, "Failure");
}

void QJSTests::testAssignmentDouble_toInt()
{
    QJS a;
    a = 4.0;
    QVERIFY2(a.toInt()==4, "Failure");
}

void QJSTests::testAssignmentDouble_toString()
{
    QJS a;
    a = 4.1;
    QVERIFY2(a.toJson()=="4.1", "Failure");
}

void QJSTests::testAssignmentString_toString()
{
    QJS a;
    a = "blabla";
    QVERIFY2(a.toJson()=="blabla", "Failure");
}

void QJSTests::testObjectAccessAssignmentBool()
{
    QJS a;
    a["test"] = true;
    QJS::Type type = a["test"].type();
    QVERIFY2(type==QJS::Bool, "Failure");
}

void QJSTests::testObjectAccessAssignmentInt()
{
    QJS a;
    a["test"] = 4;
    QJS::Type type = a["test"].type();
    QVERIFY2(type==QJS::Number, "Failure");
}

void QJSTests::testObjectAccessAssignmentString()
{
    QJS a;
    a["test"] = "123";
    QJS::Type type = a["test"].type();
    QVERIFY2(type==QJS::String, "Failure");
}

void QJSTests::testArrayAccessAssigmentBool()
{
    QJS a;
    a[5] = "123";
    QJS::Type type = a[5].type();
    QVERIFY2(type==QJS::String, "Failure");
}

void QJSTests::testObjectToString()
{
    QJS a;
    a["name"] = "circle";
    a["radius"] = 3.2;
    a["center"]["X"] = 5.1;
    a["center"]["Y"] = 7.0;
    QString str = a.toJson();
    QString right = "{\n"
            "    \"center\": {\n"
            "        \"X\": 5.1,\n"
            "        \"Y\": 7\n"
            "    },\n"
            "    \"name\": \"circle\",\n"
            "    \"radius\": 3.2\n"
            "}";
    //qDebug()<<str;
    //qDebug()<<right;
    QVERIFY2(str==right, "Failure");
}

void QJSTests::testObjectToString2()
{
    QJS a;
    a["name"] = "paper";
    a["title"] = "Hello world!";
    a["authors"][0] = "Max";
    a["authors"][1] = "Ann";
    a["authors"][2] = "Vas";
    QString str = a.toJson();
    QString right = "{\n"
            "    \"authors\": [\n"
            "        \"Max\",\n"
            "        \"Ann\",\n"
            "        \"Vas\"\n"
            "    ],\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    //qDebug()<<str;
    //qDebug()<<right;
    QVERIFY2(str==right, "Failure");
}

void QJSTests::testArraySize()
{
    QJS a;
    a["name"] = "paper";
    a["title"] = "Hello world!";
    a["authors"][2] = "Max";
    a["authors"][4] = "Ann";
    a["authors"][7] = "Vas";
    QString str = a.toJson();
    QString right = "{\n"
            "    \"authors\": [\n"
            "        null,\n"
            "        null,\n"
            "        \"Max\",\n"
            "        null,\n"
            "        \"Ann\",\n"
            "        null,\n"
            "        null,\n"
            "        \"Vas\"\n"
            "    ],\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    //qDebug()<<str;
    //qDebug()<<right;
    QVERIFY2(str==right, "Failure");
    QJS &authors = a["authors"];
    QVERIFY2(authors.size()==8, "Failure");
}

void QJSTests::testArraySize2()
{
    QJS a;
    a.append(5);
    a.append(7);
    a.append(14);
    QVERIFY2(a.size()==3, "Failure");
}

void QJSTests::testArraySize3()
{
    QJS a;
    a.append(1);
    a.append("abc");
    a.append(5.1);
    QVERIFY2(a.size()==3, "Failure");
}

void QJSTests::testArrayToString()
{
    QJS a;
    a.append(1);
    a.append("abc");
    a.append(5.1);
    a.append(7);
    a.remove(2);
    QString str = a.toJson();
    QString sample = "[\n"
            "    1,\n"
            "    \"abc\",\n"
            "    7\n"
            "]";
    //qDebug()<<str;
    //qDebug()<<sample;
    QVERIFY2(str==sample, "Failure");
}

void QJSTests::testArrayRemove()
{
    QJS a;
    a.append(1);
    a.append("abc");
    a.append(5.1);
    a.append(7);
    a[2].remove();
    QString str = a.toJson();
    QString sample = "[\n"
            "    1,\n"
            "    \"abc\",\n"
            "    7\n"
            "]";
    //qDebug()<<str;
    //qDebug()<<sample;
    QVERIFY2(str==sample, "Failure");
}

void QJSTests::testArrayPush()
{
    QJS a;
    a.append(5);
    QVERIFY2(a.type()==QJS::Array, "Failure");
}

void QJSTests::testObjectForeach()
{
    QJS a;
    a["a"] = 1;
    a["b"] = 2;
    a["c"] = 3;
    QJS b;
    foreach (QJS item, a) {
        b.append(item);
    }
    QVERIFY2(b.length()==3, "Failure");
}

void QJSTests::testArrayForeach()
{
    QJS a;
    a.append(1);
    a.append(2);
    a.append(3);
    QJS b;
    foreach (QJS item, a) {
        b.append(item);
    }
    QVERIFY2(b.length()==3, "Failure");
}

void QJSTests::testObjectKeysForeach()
{
    QJS a;
    a["a"] = 1;
    a["b"] = 2;
    a["c"] = 3;
    QJS b;
    foreach (QString key, a.keys()) {
        b.append(a[key]);
    }
    QVERIFY2(b.length()==3, "Failure");
}

void QJSTests::testParseString1()
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

void QJSTests::testParseStringArray()
{
    QString sample = "[\n"
            "    1,\n"
            "    \"abc\",\n"
            "    7\n"
            "]";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.toJson()==sample, "Failure");
}

void QJSTests::testParseObjectWithBool()
{
    QString sample = "{\n"
            "    \"b\": true,\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.toJson()==sample, "Failure");
}

void QJSTests::testParseObjectWithDouble()
{
    QString sample = "{\n"
            "    \"a\": 5.1,\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    QVERIFY2(a.toJson()==sample, "Failure");
}

void QJSTests::testParseText1()
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

void QJSTests::testParseText2()
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

void QJSTests::testParseBinaryString()
{
    QByteArray bytes;
    QDataStream out(&bytes,QIODevice::WriteOnly);
    QDataStream in(&bytes,QIODevice::ReadOnly);

    QJS a = "test тест 123";
//    QJS a = "test";
    a.toBinaryData(&out);

    QJS b=QJS::fromBinaryData(&in);
    QVERIFY2(a==b, "Failure");
}

void QJSTests::testParseBinaryNumber()
{
    QByteArray bytes;

    QDataStream out(&bytes,QIODevice::WriteOnly);
    QDataStream in(&bytes,QIODevice::ReadOnly);

    QJS aint=4;
    aint.toBinaryData(&out);
    QJS bint=QJS::fromBinaryData(&in);
    bytes.clear();

    QJS along=(long long)4346346;
    along.toBinaryData(&out);
    QJS blong=QJS::fromBinaryData(&in);
    bytes.clear();

    QJS adouble1=43.34;
    adouble1.toBinaryData(&out);
    QJS bdouble1=QJS::fromBinaryData(&in);
    bytes.clear();

    QJS adouble2=43e-3;
    adouble2.toBinaryData(&out);
    QJS bdouble2=QJS::fromBinaryData(&in);
    bytes.clear();

    QVERIFY2(aint==bint&&along==blong&&adouble1==bdouble1&&adouble2==bdouble2, "Failure");
}

void QJSTests::testParseBinaryObject()
{
    QJS a;
    a["num1"]=5;
    a["num2"]=34.12;
    a["num3"]=34e-1;
    a["string"]="test123: тестовая __&*$%__ строка";
    a["bool"]=false;

    QByteArray bytes;
    QDataStream out(&bytes,QIODevice::WriteOnly);
    QDataStream in(&bytes,QIODevice::ReadOnly);
    a.toBinaryData(&out);
    QJS b=QJS::fromBinaryData(&in);
    QVERIFY2(a==b, "Failure");
}

void QJSTests::testParseBinaryArray()
{
    QJS a;
    a[0]=5;
    a[1]=34.12;
    a.append(34e-1);
    a.append("test123: тестовая __&*$%__ строка");
    a.append(true);

    QByteArray bytes;
    QDataStream out(&bytes,QIODevice::WriteOnly);
    QDataStream in(&bytes,QIODevice::ReadOnly);
    a.toBinaryData(&out);
    QJS b=QJS::fromBinaryData(&in);
    QVERIFY2(a==b, "Failure");
}

void QJSTests::testParseBinaryComplex()
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

    QByteArray bytes;
    QDataStream out(&bytes,QIODevice::WriteOnly);
    QDataStream in(&bytes,QIODevice::ReadOnly);
    a_complex.toBinaryData(&out);
    QJS b=QJS::fromBinaryData(&in);
    QVERIFY2(a_complex==b, "Failure");
}


void QJSTests::testLeakConstructor()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QJS a;
        a = true;
    }
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSTests::testLeakParseObjectWithDouble()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QString sample = "{\n"
                "    \"a\": 5.1,\n"
                "    \"name\": \"paper\",\n"
                "    \"title\": \"Hello world!\"\n"
                "}";
        QJS a = QJS::fromJson(sample);
    }
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSTests::testLeakParseComplexObject()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QString sample = "{\n"
                "    \"authors\": [\n"
                "        null,\n"
                "        null,\n"
                "        \"Max\",\n"
                "        null,\n"
                "        \"Ann\",\n"
                "        null,\n"
                "        null,\n"
                "        \"Vas\"\n"
                "    ],\n"
                "    \"name\": \"paper\",\n"
                "    \"title\": \"Hello world!\"\n"
                "    \"params\": {"
                "        \"a\":4"
                "    }"
                "}";
        QJS a = QJS::fromJson(sample);
    }
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSTests::testLeakParseComplexObject2()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QString sample = "{\n"
                "    \"authors\": [\n"
                "        null,\n"
                "        null,\n"
                "        \"Max\",\n"
                "        null,\n"
                "        \"Ann\",\n"
                "        null,\n"
                "        null,\n"
                "        \"Vas\"\n"
                "    ],\n"
                "    \"name\": \"paper\",\n"
                "    \"title\": \"Hello world!\"\n"
                "    \"params\": {"
                "        \"a\":4"
                "    }"
                "}";
        QJS a = QJS::fromJson(sample);
    }
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSTests::testLeakObjectAccessAssignmentBool()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QJS a;
        a[5] = "123";
        //int objectsCount = QJSLeaksTest::instance()->QJS_objectsCount;
        //qDebug()<<objectsCount;
    }
    //int objectsCount = QJSLeaksTest::instance()->QJS_objectsCount;
    //qDebug()<<objectsCount;
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSTests::testLeakParse1()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QString sample = "{\n"
                "    \"authors\": [\n"
                "        null,\n"
                "        null,\n"
                "        \"Max\",\n"
                "        null,\n"
                "        \"Ann\",\n"
                "        null,\n"
                "        null,\n"
                "        \"Vas\"\n"
                "    ],\n"
                "    \"name\": \"paper\",\n"
                "    \"title\": \"Hello world!\"\n"
                "    \"params\": {"
                "        \"a\":4"
                "    }"
                "}";
        QJS a = QJS::fromJson(sample);
        QJS b = QJS::fromJson(sample);
        bool c = a==QJS::fromJson(sample);
        if (c==false)
        {
            QVERIFY2(c, "Failure");
        }
    }
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSTests::testLeakGet()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QJS a;
        a["123"];
        a.unsafeGet("123");
        a.unsafeGet(1);
    }
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSTests::testComparison1()
{
    QJS a = true;
    QJS b = true;
    QVERIFY2(a==b, "Failure");
}

void QJSTests::testComparison2()
{
    QJS a = true;
    QJS b = false;
    QVERIFY2(a!=b, "Failure");
}

void QJSTests::testComparison3()
{
    QJS a = 4;
    QJS b = 4.0;
    QVERIFY2(a==b, "Failure");
}

void QJSTests::testComparison4()
{
    QJS a = "abc";
    QJS b = "abc";
    QVERIFY2(a==b, "Failure");
}

void QJSTests::testComparison5()
{
    QString sample = "{\n"
            "    \"a\": 5.1,\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "}";
    QJS a = QJS::fromJson(sample);
    QJS b = QJS::fromJson(sample);
    QVERIFY2(a==b, "Failure");
}

void QJSTests::testComparison6()
{
    QString sample = "{\n"
            "    \"authors\": [\n"
            "        null,\n"
            "        null,\n"

            "        \"Max\",\n"
            "        null,\n"
            "        \"Ann\",\n"
            "        null,\n"
            "        null,\n"
            "        \"Vas\"\n"
            "    ],\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\"\n"
            "    \"params\": {"
            "        \"a\":4"
            "    }"
            "}";
    QJS a = QJS::fromJson(sample);
    QJS b = QJS::fromJson(sample);
    QVERIFY2(a==b, "Failure");
}

void QJSTests::slotChanged(QJS *address, QString operation, QJS *newData, QJS *oldData)
{
    QJS change;
    change["address"] = *address;
    change["operation"] = operation;
    change["newData"] = *newData;
    change["oldData"] = *oldData;
    this->changedData.append(change);
}

void QJSTests::testChanged1()
{
    QString sample = "{\n"
            "    \"authors\": [\n"
            "        null,\n"
            "        null,\n"
            "        \"Max\",\n"
            "        null,\n"
            "        \"Ann\",\n"
            "        null,\n"
            "        null,\n"
            "        \"Vas\"\n"
            "    ],\n"
            "    \"name\": \"paper\",\n"
            "    \"title\": \"Hello world!\",\n"
            "    \"params\": {"
            "        \"a\":4"
            "    }"
            "}";
    QJS data = QJS::fromJson(sample);
    data.enableSignals(true);
    connect(&data, SIGNAL(dataChanged(QJS*,QString,QJS*,QJS*)), SLOT(slotChanged(QJS*,QString,QJS*,QJS*)));
    data["params"]["a"] = 3;
    data["authors"].append("Alexander");
    data["params"]["b"] = 5;
    data["authors"] = QJS::Null;
    int changesCount = this->changedData.length();
    //qDebug()<<changedData.toJson();
    QVERIFY2(changesCount==4, "Failure");
}

void QJSTests::testQJSSharedNode1()
{
    QJSSharedNode a;
    //Инициализируем b с данными a и подписками на a
    QJSSharedNode b(a);
    b["a"] = 1;
    QVERIFY2(a["a"].toInt()==1, "Failure");
}

void QJSTests::testQJSSharedNode2()
{
    QJSSharedNode a;
    QJSSharedNode b(a);
    b["params"]["a"] = 1;
    QVERIFY2(a["params"]["a"].toInt()==1, "Failure");
}

void QJSTests::testQJSSharedNode3()
{
    QJSSharedNode a;
    QJSSharedNode b(a);
    QJSSharedNode c(a);
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

void QJSTests::testQJSSharedNode4()
{
    QJSSharedNode a;
    QJSSharedNode b(a);
    QJSSharedNode c(b);
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

void QJSTests::testParsingError1()
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

void QJSTests::testArraySize4()
{
    QJS a;
    a.append(1);
    a.append("test");
    a=QJS::Array;
    QVERIFY2(a.length()==0,"Failure");
}
//QTEST_APPLESS_MAIN(QJSTests)


#include "tst_qjstests.moc"
