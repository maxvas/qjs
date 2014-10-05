#ifndef QJS_H
#define QJS_H

#include "qjs_global.h"
#include <QObject>
#include <QVariant>
#include <QHash>
#include <QVector>
#include <QMutex>
#include <QDataStream>

class QJSSHARED_EXPORT QJS : public QObject
{
    Q_OBJECT
public:
    //Тип данных
    enum Type {
        Bool,
        Number,
        String,
        Object,
        Array,
        Null
    };

    class QJSSHARED_EXPORT const_iterator
    {
        public:
        const_iterator(QVector< QJS* >::const_iterator _arrayIterator, QHash<QString, QJS* >::const_iterator _objectIterator, QJS::Type _type)
            :_arrayIterator(_arrayIterator), _objectIterator(_objectIterator), _type(_type)
        {}
        const QJS& operator*()
            {
                if (_type==QJS::Object)
                    return **_objectIterator;
                return **_arrayIterator;
            }
            bool operator!=( const const_iterator& val) const
            {
                if (_type==QJS::Object)
                    return _objectIterator!=val._objectIterator;
                if (_type==QJS::Array)
                    return _arrayIterator!=val._arrayIterator;
                return false;
            }
            const_iterator& operator++()
            {
                if (_type==QJS::Array)
                    _arrayIterator++;
                if (_type==QJS::Object)
                    _objectIterator++;
                return *this;
            }
    private:
            QVector< QJS* >::const_iterator _arrayIterator;
            QHash< QString, QJS* >::const_iterator _objectIterator;
            QJS::Type _type;
    };

    const_iterator begin() const;
    const_iterator end() const;

    class QJSSHARED_EXPORT iterator
    {
        public:
        iterator(QVector< QJS* >::iterator _arrayIterator, QHash<QString, QJS* >::iterator _objectIterator, QJS::Type _type)
            :_arrayIterator(_arrayIterator), _objectIterator(_objectIterator), _type(_type)
        {}
        QJS& operator*()
            {
                if (_type==QJS::Object)
                    return **_objectIterator;
                return **_arrayIterator;
            }
            bool operator!=( const iterator& val) const
            {
                if (_type==QJS::Object)
                    return _objectIterator!=val._objectIterator;
                if (_type==QJS::Array)
                    return _arrayIterator!=val._arrayIterator;
                return false;
            }
            iterator& operator++()
            {
                if (_type==QJS::Array)
                    _arrayIterator++;
                if (_type==QJS::Object)
                    _objectIterator++;
                return *this;
            }
    private:
            QVector< QJS* >::iterator _arrayIterator;
            QHash< QString, QJS* >::iterator _objectIterator;
            QJS::Type _type;
    };

    iterator begin();
    iterator end();

    explicit QJS(QJS *parent = 0, QJS::Type _desirebleParentType = QJS::Null);
    static QJS &null();
    QJS(const QJS &val);
    QJS(bool val);
    QJS(int val);
    QJS(double val);
    QJS(long long val);
    QJS(QString val);
    QJS(const char *val);
    QJS(QJS::Type type);
    //QJS(QJS &val);
    ~QJS();
    //Запись
    QJS &operator=(bool val);
    QJS &operator=(int val);
    QJS &operator=(double val);
    QJS &operator=(long long val);
    QJS &operator=(QString val);
    QJS &operator=(const char *val);
    QJS &operator=(QJS& val);
    QJS &operator=(const QJS& val);
    QJS &operator=(QJS::Type type);
    //Присваивание
    void set(bool val);
    void set(int val);
    void set(double val);
    void set(long long val);
    void set(QString val);
    void set(const char *val);
    void set(const QJS &val);
    void set(QJS::Type type);
    void set(QString name, QJS* val);
    void set(int index, QJS* val);
    QJS::Type type() const;
    //Преобразование
    bool toBool() const;
    int toInt() const;
    long long toLongLong() const;
    double toDouble() const;
    QString toString() const;
    //Доступ
    virtual QJS &operator[](QString name);
    virtual QJS &operator[](int index);
    virtual QJS &get(QString name);
    virtual QJS &get(int index);
    virtual QJS &getByAddress(const QJS &address);
    //Работа с массивами
    int size() const;
    int length() const;
    int count() const;
    void append(bool value);
    void append(int value);
    void append(double value);
    void append(long long value);
    void append(const char *value);
    void append(QString value);
    void append(QJS &value);
    void append(QJS *value);
    void append(QJS::Type type);
    void prepend(bool value);
    void prepend(int value);
    void prepend(double value);
    void prepend(long long value);
    void prepend(const char *value);
    void prepend(QString value);
    void prepend(QJS &value);
    void prepend(QJS *value);
    void prepend(QJS::Type type);
    void remove(int index);
    void remove(QString key);
    void remove();
    QList<QString> keys() const;
    //Парсинг
    QString toJson() const;
    static QJS fromJson(QString str);
    void toDataStream(QDataStream &out) const;
    static QJS fromDataStream(QDataStream &in);
    QByteArray toByteArray();
    static QJS fromByteArray(QByteArray data);
    bool isParsingError();
    bool hasParsingError();
    QString parsingErrorString();
    //Трансформация типа
    void setType(QJS::Type type);
    //Оператор ==
    bool operator==(const QJS &other) const;
    bool operator!=(const QJS &other) const;
    //Получение родителя
    QJS *parent();
    //Индекс
    int index();
    QString key();
    //Включить/отключить сигналы
    void enableSignals(bool enable);
    void enableSignals();
    void disableSignals();
    //Определить, включены ли сигналы
    bool signalsEnabled();
    //Проверка типа данных
    bool isBool();
    bool isNumber();
    bool isString();
    bool isArray();
    bool isObject();
    bool isNull();

    QVector< QJS* > toArray();

private:
    QVariant _data;//Для хранения данных простого типа
    QVector< QJS* > _arrayData; //Для хранения массивов
    QHash<QString, QJS* > _objectData; //Для хранения объектов
    QJS::Type _type; //Для хранения типа данных
    QJS::Type _desirebleParentType; //Желаемый тип предка (если мы делаем обращение к элементу через [])
    QJS* _parent; //Указатель на предка
    QHash< QJS*, QJS* > _nonExistsObjects; //Указатели на несуществующие объекты
    void transformParent();
//    void setSize(int size);
    //int _size;
    int _index;
    QString _key;
    bool _exists;
    bool _doNotCopy;
    bool _hasParsingError;
    QString _parsingErrorString;
    bool _signalsEnabled;
    //QHash<QJS*, QJS* > _children;
    void addChild(QJS *child);
    void removeChild(QJS *child);

    //Очистка
    void clear();

    static void skipOtherChars(QString str, int &pos, int &line, int &column, bool &error, QString errorString);
    static QString extractKey(QString str, int &pos, int &line, int &column, bool &error, QString &errorString);
    static QJS *extractValue(QString str, int &pos, int &line, int &column, bool &error, QString &errorString);
    static QJS *extractObject(QString str, int &pos, int &line, int &column, bool &error, QString &errorString);
    static QJS *extractString(QString str, int &pos, int &line, int &column, bool &error, QString &errorString);
    static QJS *extractArray(QString str, int &pos, int &line, int &column, bool &error, QString &errorString);
    static QJS *extractBool(QString str, int &pos, int &line, int &column, bool &error, QString &errorString);
    static QJS *extractNumber(QString str, int &pos, int &line, int &column, bool &error, QString &errorString);
    static QString escapeString(QString str);
    static QJS *parseBinaryData(QDataStream &in, bool &error);

    static void parsingError(QString message, int line, int column, bool &error, QString &errorString);

    void _changed(QJS* address, QString operation, QJS *newData, QJS *oldData);

signals:
    void dataChanged(QByteArray address, QString operation, QByteArray newData, QByteArray oldData);

public slots:
    //Применить операцию изменения данных, получаемую из сигнала changed
    bool applyChange(QByteArray addressData, QString operation, QByteArray newDataData, QByteArray oldDataData);
};


typedef QJS (*QJSFunction)(QJS);
#endif // QJS_H
