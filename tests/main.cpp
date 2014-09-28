#include "qjsbasetest.h"
#include "qjsparsingtest.h"
#include "qjssharednodetest.h"
#include "qjsmappingtest.h"

int main(int argc, char *argv[])
{
    //количество тестов=67 (+2 на каждый класс)
    QJSBaseTest bt;
    QJSParsingTest pt;
    QJSSharedNodeTest snt;
    QJSMappingTest mapping;
    int result= QTest::qExec(&bt, argc, argv)+
            QTest::qExec(&pt, argc, argv)+
            QTest::qExec(&snt, argc, argv)+
            QTest::qExec(&mapping, argc, argv);
    if(result==0)qDebug()<<"Все тесты успешно пройдены";
    return result;
}
