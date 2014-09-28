#include "qjsbasetest.h"

QJSBaseTest::QJSBaseTest(QObject *parent) :
    QObject(parent)
{
    QJSLeaksTest::instance()->QJS_leaksTest = true; //Максим, зачем это надо??
}

void QJSBaseTest::testConstructor_Null()
{
    QJS a;
    QVERIFY2(a.type()==QJS::Null, "Failure");
}

void QJSBaseTest::testConstructor_Bool()
{
    QJS a = true;
    QVERIFY2(a.type()==QJS::Bool, "Failure");
}

void QJSBaseTest::testConstructor_QJS()
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

void QJSBaseTest::testAssignmentBool_toBool_1()
{
    QJS a;
    a = true;
    QVERIFY2(a.toBool()==true, "Failure");
}

void QJSBaseTest::testAssignmentBool_toBool_2()
{
    QJS a;
    a = false;
    QVERIFY2(a.toBool()==false, "Failure");
}

void QJSBaseTest::testAssignmentInt_toInt()
{
    QJS a;
    a = 4;
    QVERIFY2(a.toInt()==4, "Failure");
}

void QJSBaseTest::testAssignmentDouble_toDouble()
{
    QJS a;
    a = 4.1;
    QVERIFY2(a.toDouble()==4.1, "Failure");
}

void QJSBaseTest::testAssignmentBool_Type()
{
    QJS a;
    a = true;
    QVERIFY2(a.type()==QJS::Bool, "Failure");
}

void QJSBaseTest::testAssignmentInt_Type()
{
    QJS a;
    a = 4;
    QVERIFY2(a.type()==QJS::Number, "Failure");
}

void QJSBaseTest::testAssignmentDouble_Type()
{
    QJS a;
    a = 4.1;
    QVERIFY2(a.type()==QJS::Number, "Failure");
}

void QJSBaseTest::testAssignmentString_Type()
{
    QJS a;
    a = "blabla";
    QVERIFY2(a.type()==QJS::String, "Failure");
}

void QJSBaseTest::testAssignmentBool_toString()
{
    QJS a;
    a = true;
    QVERIFY2(a.toJson()=="true", "Failure");
}

void QJSBaseTest::testAssignmentInt_toString()
{
    QJS a;
    a = 4;
    QVERIFY2(a.toJson()=="4", "Failure");
}

void QJSBaseTest::testAssignmentInt_toDouble()
{
    QJS a;
    a = 4;
    QVERIFY2(a.toDouble()==4, "Failure");
}

void QJSBaseTest::testAssignmentDouble_toInt()
{
    QJS a;
    a = 4.0;
    QVERIFY2(a.toInt()==4, "Failure");
}

void QJSBaseTest::testAssignmentDouble_toString()
{
    QJS a;
    a = 4.1;
    QVERIFY2(a.toJson()=="4.1", "Failure");
}

void QJSBaseTest::testAssignmentString_toString()
{
    QJS a;
    a = "blabla";
    QVERIFY2(a.toJson()=="blabla", "Failure");
}

void QJSBaseTest::testObjectAccessAssignmentBool()
{
    QJS a;
    a["test"] = true;
    QJS::Type type = a["test"].type();
    QVERIFY2(type==QJS::Bool, "Failure");
}

void QJSBaseTest::testObjectAccessAssignmentInt()
{
    QJS a;
    a["test"] = 4;
    QJS::Type type = a["test"].type();
    QVERIFY2(type==QJS::Number, "Failure");
}

void QJSBaseTest::testObjectAccessAssignmentString()
{
    QJS a;
    a["test"] = "123";
    QJS::Type type = a["test"].type();
    QVERIFY2(type==QJS::String, "Failure");
}

void QJSBaseTest::testArrayAccessAssigmentBool()
{
    QJS a;
    a[5] = "123";
    QJS::Type type = a[5].type();
    QVERIFY2(type==QJS::String, "Failure");
}

void QJSBaseTest::testObjectToString()
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

void QJSBaseTest::testObjectToString2()
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

void QJSBaseTest::testArraySize()
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

void QJSBaseTest::testArraySize2()
{
    QJS a;
    a.append(5);
    a.append(7);
    a.append(14);
    QVERIFY2(a.size()==3, "Failure");
}

void QJSBaseTest::testArraySize3()
{
    QJS a;
    a.append(1);
    a.append("abc");
    a.append(5.1);
    QVERIFY2(a.size()==3, "Failure");
}

void QJSBaseTest::testArrayToString()
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

void QJSBaseTest::testArrayRemove()
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

void QJSBaseTest::testArrayPush()
{
    QJS a;
    a.append(5);
    QVERIFY2(a.type()==QJS::Array, "Failure");
}

void QJSBaseTest::testObjectForeach()
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

void QJSBaseTest::testArrayForeach()
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

void QJSBaseTest::testObjectKeysForeach()
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

void QJSBaseTest::testLeakConstructor()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QJS a;
        a = true;
    }
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSBaseTest::testLeakParseObjectWithDouble()
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

void QJSBaseTest::testLeakParseComplexObject()
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

void QJSBaseTest::testLeakParseComplexObject2()
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

void QJSBaseTest::testLeakObjectAccessAssignmentBool()
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

void QJSBaseTest::testLeakParse1()
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

void QJSBaseTest::testLeakGet()
{
    QJSLeaksTest::instance()->QJS_objectsCount = 0;
    {
        QJS a;
        a["123"];
        a.get("123");
        a.get(1);
    }
    QVERIFY2(QJSLeaksTest::instance()->QJS_objectsCount==0, "Memory leak");
}

void QJSBaseTest::testComparison1()
{
    QJS a = true;
    QJS b = true;
    QVERIFY2(a==b, "Failure");
}

void QJSBaseTest::testComparison2()
{
    QJS a = true;
    QJS b = false;
    QVERIFY2(a!=b, "Failure");
}

void QJSBaseTest::testComparison3()
{
    QJS a = 4;
    QJS b = 4.0;
    QVERIFY2(a==b, "Failure");
}

void QJSBaseTest::testComparison4()
{
    QJS a = "abc";
    QJS b = "abc";
    QVERIFY2(a==b, "Failure");
}

void QJSBaseTest::testComparison5()
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

void QJSBaseTest::testComparison6()
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

void QJSBaseTest::slotChanged(QJS *address, QString operation, QJS *newData, QJS *oldData)
{
    QJS change;
    change["address"] = *address;
    change["operation"] = operation;
    change["newData"] = *newData;
    change["oldData"] = *oldData;
    this->changedData.append(change);
}

void QJSBaseTest::testChanged1()
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
    qDebug()<<changedData.toJson();
    QVERIFY2(changesCount==4, "Failure");
}

void QJSBaseTest::testArraySize4()
{
    QJS a;
    a.append(1);
    a.append("test");
    a=QJS::Array;
    QVERIFY2(a.length()==0,"Failure");
}

void QJSBaseTest::testObjectToArrayTransform()
{
    QJS test;
    test["as"]=2;
    test.append(3);
    int x=test[0].toInt();
    int y=test["as"].toInt();
    QVERIFY2((x==3)&&(y==0),"Failure");
}

void QJSBaseTest::testObjectToArrayTransform2()
{
    QJS test;
    test[0]=4;
    test["as"]=2;
    test.append(3);
    int x=test[0].toInt();
    int y=test["as"].toInt();
    QVERIFY2((x==3)&&(y==0),"Failure");
}

void QJSBaseTest::testArrayToObjectTransform()
{
    QJS test;
    test[0]=4;
    test["as"]=2;
    int x=test[0].toInt();
    int y=test["as"].toInt();
    QVERIFY2((x==0)&&(y==2),"Failure");
}

void QJSBaseTest::testArrayToObjectTransform2()
{
    QJS test;
    test["as"]=1;
    test[0]=4;
    test["as"]=2;
    int x=test[0].toInt();
    int y=test["as"].toInt();
    QVERIFY2((x==0)&&(y==2),"Failure");
}

void QJSBaseTest::testObjectSize()
{
    QJS test;
    test["a"]["a"] = 1;
    test["a"]["b"] = 2;
    test["a"]["c"] = 3;
    QVERIFY2(test["a"].size()==3, "Failure");
}
