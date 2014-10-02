#include "qjs.h"
#include "qjsleakstest.h"
#include <QMutexLocker>

QJS::const_iterator QJS::begin() const
{
    return const_iterator(_arrayData.constBegin(), _objectData.constBegin(), _type);
}

QJS::const_iterator QJS::end() const
{
    return const_iterator(_arrayData.constEnd(), _objectData.constEnd(), _type);
}

QJS::iterator QJS::begin()
{
    return iterator(_arrayData.begin(), _objectData.begin(), _type);
}

QJS::iterator QJS::end()
{
    return iterator(_arrayData.end(), _objectData.end(), _type);
}

QJS::QJS(QJS *parent, QJS::Type desirebleParentType)
    :QObject(0), _doNotCopy(false), _hasParsingError(false)
{
    _parent = parent;
    _type = QJS::Null;
    _desirebleParentType = desirebleParentType;
    _exists = false;
    _index = -1;
    _size = 0;
    if (parent!=0)
    {
        _signalsEnabled = parent->signalsEnabled();
        _parent->addChild(this);
    }
    else
        _signalsEnabled = false;
    if (QJSLeaksTest::instance()->QJS_leaksTest)
        QJSLeaksTest::instance()->QJS_objectsCount++;
}

QJS &QJS::null()
{
    QJS *object = new QJS();
    return *object;
}

QJS::QJS(const QJS &val)
    :QObject(0), _parent(0), _doNotCopy(false), _hasParsingError(false)
{
    _parent = 0;
    _type = QJS::Null;
    _exists = false;
    _index = -1;
    _signalsEnabled = false;
    this->set(val);
    if (QJSLeaksTest::instance()->QJS_leaksTest)
        QJSLeaksTest::instance()->QJS_objectsCount++;
    //if (val._doNotCopy)
        //delete &val;
}

QJS::QJS(bool val)
    :QObject(0), _parent(0), _doNotCopy(false), _hasParsingError(false), _signalsEnabled(false)
{
    (*this) = val;
}

QJS::QJS(int val)
    :QObject(0), _parent(0), _doNotCopy(false), _hasParsingError(false), _signalsEnabled(false)
{
    (*this) = val;
}

QJS::QJS(double val)
    :_parent(0), _doNotCopy(false), _hasParsingError(false), _signalsEnabled(false)
{
    (*this) = val;
}

QJS::QJS(long long val)
    :_parent(0), _doNotCopy(false), _hasParsingError(false), _signalsEnabled(false)
{
    (*this) = val;
}

QJS::QJS(QString val)
    :QObject(0), _parent(0), _doNotCopy(false), _hasParsingError(false), _signalsEnabled(false)
{
    (*this) = val;
}

QJS::QJS(const char *val)
    :QObject(0), _parent(0), _doNotCopy(false), _hasParsingError(false), _signalsEnabled(false)
{
    (*this) = val;
}

QJS::QJS(QJS::Type type)
    :QObject(0), _type(type), _parent(0), _doNotCopy(false), _hasParsingError(false), _signalsEnabled(false)
{
}

QJS::~QJS()
{
    foreach (QJS* js, _objectData)
    {
        delete js;
    }
    _objectData.clear();
    foreach (QJS* js, _arrayData)
    {
        delete js;
    }
    _arrayData.clear();
    foreach (QJS* js, _nonExistsObjects)
    {
        delete js;
    }
    _nonExistsObjects.clear();
    if (QJSLeaksTest::instance()->QJS_leaksTest)
        QJSLeaksTest::instance()->QJS_objectsCount--;
}

QJS &QJS::operator=(bool val)
{
    this->set(val);
    return *this;
}

QJS& QJS::operator=(int val)
{
    this->set(val);
    return *this;
}

QJS &QJS::operator=(double val)
{
    this->set(val);
    return *this;
}

QJS &QJS::operator=(long long val)
{
    this->set(val);
    return *this;
}

QJS &QJS::operator=(QString val)
{
    this->set(val);
    return *this;
}

QJS &QJS::operator=(const char* val)
{
    this->set(val);
    return *this;
}

QJS &QJS::operator=(QJS& val)
{
    this->set(val);
    return *this;
}

QJS &QJS::operator=(const QJS &val)
{
    this->set(val);
    return *this;
}

QJS &QJS::operator=(QJS::Type type)
{
    this->set(type);
    return *this;
}

void QJS::set(bool val)
{
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(*this);
    }
    this->clear();
    _data = val;
    _type = QJS::Bool;
    transformParent();
    if (_signalsEnabled)
    {
        newData = new QJS(*this);
        address = new QJS(QJS::Array);
        _changed(address, "assign", newData, oldData);
    }
}

void QJS::set(int val)
{
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(*this);
    }
    this->clear();
    _data = val;
    _type = QJS::Number;
    transformParent();
    if (_signalsEnabled)
    {
        newData = new QJS(*this);
        address = new QJS(QJS::Array);
        _changed(address, "assign", newData, oldData);
    }
}

void QJS::set(double val)
{
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(*this);
    }
    this->clear();
    _data = val;
    _type = QJS::Number;
    transformParent();
    if (_signalsEnabled)
    {
        newData = new QJS(*this);
        address = new QJS(QJS::Array);
        _changed(address, "assign", newData, oldData);
    }
}

void QJS::set(long long val)
{
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(*this);
    }
    this->clear();
    _data = val;
    _type = QJS::Number;
    transformParent();
    if (_signalsEnabled)
    {
        newData = new QJS(*this);
        address = new QJS(QJS::Array);
        _changed(address, "assign", newData, oldData);
    }
}

void QJS::set(QString val)
{
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(*this);
    }
    this->clear();
    _data = val;
    _type = QJS::String;
    transformParent();
    if (_signalsEnabled)
    {
        newData = new QJS(*this);
        address = new QJS(QJS::Array);
        _changed(address, "assign", newData, oldData);
    }
}

void QJS::set(const char *val)
{
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(*this);
    }
    this->clear();
    _data = QString(val);
    _type = QJS::String;
    transformParent();
    if (_signalsEnabled)
    {
        newData = new QJS(*this);
        address = new QJS(QJS::Array);
        _changed(address, "assign", newData, oldData);
    }
}

void QJS::set(const QJS &val)
{
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(*this);
    }
    //Присваивание
    this->clear();
    switch (val._type) {
    case QJS::Bool:
        this->set(val.toBool());
        break;
    case QJS::String:
        this->set(val.toString());
        break;
    case QJS::Number:
        this->set(val.toDouble());
        break;
    case QJS::Object:
        //val.mutex.lock();
        foreach(QString key, val._objectData.keys())
        {
            QJS &v = get(key);
            v.set(*(val._objectData[key]));
        }
        //val.mutex.unlock();
        break;
    case QJS::Array:
        //val.mutex.lock();
        foreach(QJS* v, val._arrayData)
        {
            QJS *newElement = new QJS(this);
            newElement->set(*v);
            this->_arrayData.push_back(newElement);
        }
        //val.mutex.unlock();
        this->setType(QJS::Array);
        this->_size = _arrayData.size();
        break;
    default:
        break;
    }
    _type = val._type;
    _hasParsingError = val._hasParsingError;
    _parsingErrorString = val._parsingErrorString;
    //_key = val._key;
    //_index = val._index;
    transformParent();
    if (val._doNotCopy)
        delete &val;
    //Обработка сигналов
    if (_signalsEnabled)
    {
        newData = new QJS(*this);
        address = new QJS(QJS::Array);
        _changed(address, "assign", newData, oldData);
    }
}

void QJS::set(QJS::Type type)
{
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(*this);
    }
    this->clear();
    _type = type;
    transformParent();
    if (_signalsEnabled)
    {
        newData = new QJS(*this);
        address = new QJS(QJS::Array);
        _changed(address, "assign", newData, oldData);
    }
}

void QJS::set(QString name, QJS *val)
{
    if (_type!=QJS::Object)
    {
        clear();
    }
    setType(QJS::Object);
    _objectData[name] = val;
    _size = _arrayData.size();
}

void QJS::set(int index, QJS *val)
{
    if (_type!=QJS::Array)
    {
        clear();
    }
    setType(QJS::Array);
    while (_arrayData.size()<index+1)
    {
        _arrayData.push_back(0);
    }
    _arrayData[index] = val;
    _size = _arrayData.size();
}

QJS::Type QJS::type() const
{
    return _type;
}

bool QJS::toBool() const
{
    return _data.toBool();
}

int QJS::toInt() const
{
    return _data.toInt();
}

long long QJS::toLongLong() const
{
    return _data.toLongLong();
}

double QJS::toDouble() const
{
    return _data.toDouble();
}

QString QJS::toString() const
{
    return _data.toString();
}

QString QJS::toJson() const
{
    switch (this->_type)
    {
    case QJS::Bool:
    {
        bool b = _data.toBool();
        if (b)
            return "true";
        else
            return "false";
    }
    case QJS::Number:
        if (_data.type()==QVariant::Double)
        {
            QString n = QString::number(_data.toDouble());
            if (n.contains("e"))
            {
                n = QString::number(_data.toLongLong());
            }
            return n;
        }
        if (_data.type()==QVariant::Int)
            return QString::number(_data.toInt());
        if (_data.type()==QVariant::LongLong)
            return QString::number(_data.toLongLong());
    case QJS::String:
        return escapeString(_data.toString());
    case QJS::Object:
    {
        QString result = "{\n";
        QList<QString> keys = _objectData.keys();
        qSort(keys);
        int i=0;
        foreach (QString key, keys) {
            QString value = _objectData[key]->toJson();
            if (_objectData[key]->_type==QJS::String)
                value = "\"" + value + "\"";
            QString value2 = value.replace("\n", "\n    ");
            result += QString("    ") + "\"" + key + "\": " + value2;
            if (i<keys.size()-1)
                result += ",\n";
            else
                result += "\n";
            i++;
        }
        result += "}";
        return result;
    }
    case QJS::Array:
    {
        QString result = "[\n";
        for (int i=0; i<this->size(); i++)
        {
            QString value = _arrayData[i]->toJson();
            if (_arrayData[i]->_type==QJS::String)
                value = "\"" + value + "\"";
            result += "    " + value.replace("\n", "\n    ");
            if (i<_size-1)
                result += ",\n";
            else
                result += "\n";
        }
        result += "]";
        return result;
    }
    case QJS::Null:
        return "null";
    }
    return "";
}

void QJS::setType(QJS::Type type)
{
    _type = type;
}

void QJS::clear()
{
    foreach (QJS* js, _objectData)
    {
        delete js;
    }
    _objectData.clear();
    foreach (QJS* js, _arrayData)
    {
        delete js;
    }
    foreach (QJS* js, _nonExistsObjects)
    {
        delete js;
    }
    _nonExistsObjects.clear();
    _arrayData.clear();
    _size=0;
}

bool QJS::operator==(const QJS &other) const
{
    if (this == &other)
           return true;
    if (this->_type!=other._type)
        return false;
    switch (_type) {
    case QJS::Bool:
        return this->_data==other._data;
    case QJS::Number:
        return (this->_data.toDouble()-other._data.toDouble()<0.00000001);
    case QJS::String:
        return this->_data==other._data;
    case QJS::Array:
    {
        if (this->_size!=other._size)
            return false;
        for (int i=0; i<_size; i++)
        {
            QJS &a = *this->_arrayData[i];
            const QJS &b = *other._arrayData[i];
            if (a!=b)
            {
                return false;
            }
        }
        return true;
    }
    case QJS::Object:
    {
        if (this->_objectData.count()!=other._objectData.count())
            return false;
        foreach (QString key, this->_objectData.keys()) {
            QJS &a = *this->_objectData[key];
            const QJS &b = *other._objectData[key];
            if (a!=b)
                return false;
        }
        return true;
    }
    case QJS::Null:
    {
        return true;
    }
    default:
        break;
    }
    return false;
}

bool QJS::operator!=(const QJS &other) const
{
    return !(*this==other);
}

QJS *QJS::parent()
{
    return _parent;
}

int QJS::index()
{
    return _index;
}

QString QJS::key()
{
    return _key;
}

void QJS::enableSignals(bool enable)
{
    _signalsEnabled = enable;
    if (_type==QJS::Object)
    {
        foreach (QString key, _objectData.keys()) {
            _objectData[key]->enableSignals(enable);
        }
    }
    if (_type==QJS::Array)
    {
        foreach (QJS *js, _arrayData) {
            js->enableSignals(enable);
        }
    }
}

void QJS::enableSignals()
{
    enableSignals(true);
}

void QJS::disableSignals()
{
    enableSignals(false);
}

bool QJS::signalsEnabled()
{
    return _signalsEnabled;
}

bool QJS::isBool()
{
    return _type==QJS::Bool;
}

bool QJS::isNumber()
{
    return _type==QJS::Number;
}

bool QJS::isString()
{
    return _type==QJS::String;
}

bool QJS::isArray()
{
    return _type==QJS::Array;
}

bool QJS::isObject()
{
    return _type==QJS::Object;
}

bool QJS::isNull()
{
    return _type==QJS::Null;
}

QVector<QJS *> QJS::toArray()
{
    return _arrayData;
}

QJS &QJS::operator[](QString key)
{
    return get(key);
}

QJS &QJS::operator[](int index)
{
    return get(index);
}

QJS &QJS::get(QString key)
{
    QJS *result;
    if (_type==QJS::Object)
    {
        if (_objectData.contains(key))
            result = _objectData[key];
        else
        {
            result = new QJS((QJS*)this, QJS::Object);
            result->moveToThread(this->thread());
            result->_key = key;
            _nonExistsObjects[result] = result;
        }
    } else
    {
        result = new QJS((QJS*)this, QJS::Object);
        result->moveToThread(this->thread());
        result->_key = key;
        _nonExistsObjects[result] = result;
    }
    return *result;
}

QJS &QJS::get(int index)
{
    QJS *result = 0;
    if (_arrayData.size()>index)
        result = _arrayData[index];
    else
        result = 0;
    if (!result)
    {
        result = new QJS((QJS*)this, QJS::Array);
        result->moveToThread(this->thread());
        _nonExistsObjects[result] = result;
    }
    result->_index = index;
    return *result;
}

QJS &QJS::getByAddress(const QJS &address)
{
    QJS *r = this;
    foreach(QJS key, address)
    {
        if (key._type==QJS::String)
            r = &(r->get(key.toString()));
        if (key._type==QJS::Number)
            r = &(r->get(key.toInt()));
    }
    return *r;
}

int QJS::size() const
{
    switch(_type){
    case QJS::Object:
        return _objectData.size();
    case QJS::Array:
        return _arrayData.size();
    default: return 0;
    }
}

int QJS::length() const
{
    return size();
}

int QJS::count() const
{
    return size();
}

void QJS::append(bool value)
{
    (*this).get(_size).set(value);
}

void QJS::append(int value)
{
    (*this).get(_size).set(value);
}

void QJS::append(double value)
{
    (*this).get(_size).set(value);
}

void QJS::append(long long value)
{
    (*this).get(_size).set(value);
}

void QJS::append(const char *value)
{
    (*this).get(_size).set(value);
}

void QJS::append(QString value)
{
    (*this).get(_size).set(value);
}

void QJS::append(QJS &value)
{
    (*this).get(_size).set(value);
}

void QJS::append(QJS *value)
{
    this->set(_size, value);
}

void QJS::append(QJS::Type type)
{
    (*this).get(_size).set(type);
}

void QJS::prepend(bool value)
{
    _arrayData.prepend(new QJS(value));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::prepend(int value)
{    
    _arrayData.prepend(new QJS(value));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::prepend(double value)
{
    _arrayData.prepend(new QJS(value));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::prepend(long long value)
{
    _arrayData.prepend(new QJS(value));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::prepend(const char *value)
{
    _arrayData.prepend(new QJS(value));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::prepend(QString value)
{
    _arrayData.prepend(new QJS(value));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::prepend(QJS &value)
{
    _arrayData.prepend(new QJS(value));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::prepend(QJS *value)
{
    _arrayData.prepend(new QJS(value));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::prepend(QJS::Type type)
{
    _arrayData.prepend(new QJS(type));
    _size = _arrayData.size();
    QJS *oldData, *newData, *address;
    if (_signalsEnabled)
    {
        oldData = new QJS(this, QJS::Null);  //создаем oldData со значением null
        newData = new QJS(*this);  //newData будет содержать только что записанное значение
        address = new QJS(QJS::Array);
        _parent->_changed(address, "prepend", newData, oldData);
    }
}

void QJS::remove(int index)
{
    if (_type==QJS::Array)
    {
        _arrayData.remove(index);
        this->_size = _arrayData.size();
    }
}

void QJS::remove(QString key)
{
    if (_type==QJS::Object)
    {
        _objectData.remove(key);
    }
}

void QJS::remove()
{
    if (!_parent)
        return;
    switch (_parent->_type) {
    case QJS::Array:
        _parent->remove(_index);
        return;
    case QJS::Object:
        _parent->_objectData.remove(_key);
        return;
    default:
        return;
    }
}

QList<QString> QJS::keys() const
{
    return _objectData.keys();
}

QChar getChar(QString str, int pos)
{
    if (pos<0)
        return QChar(0);
    if (pos>str.length())
        return QChar(0);
    return str[pos];
}

void QJS::skipOtherChars(QString str, int &pos, int &line, int &column, bool &error, QString errorString)
{
    QString symbols = ",[]{}:\"-_";
    QChar c;
    while (true)
    {
        c = getChar(str, pos);
        column++;
        if (c==0)
        {
            parsingError("unexpected end of document", line, column, error, errorString);
            break;
        }
        if (c=='\n')
        {
            line++;
            column = 0;
        }
        if (symbols.contains(c) || c.isLetterOrNumber())
        {
            break;
        }
        pos++;
    }
}

QString QJS::extractKey(QString str, int &pos, int &line, int &column, bool &error, QString &errorString)
{
    QChar c;
    QString acceptedSymbols = "-_.\"";
    QString result;
    while (true)
    {
        c = getChar(str, pos);
        if (c.isLetter() || c.isDigit() || acceptedSymbols.contains(c))
        {
            result += c;
        } else
        {
            break;
        }
        column++;
        if (c=='\n')
        {
            parsingError("unexpected end of line", line, column, error, errorString);
            return "";
        }
        pos++;
    }
    if (result.startsWith("\""))
    {
        result = result.mid(1);
    }
    if (result.endsWith("\""))
    {
        result = result.mid(0, result.length()-1);
    }
    return result;
}

QJS *QJS::extractString(QString str, int &pos, int &line, int &column, bool &error, QString &errorString)
{
    QJS *result = new QJS();
    pos++;
    QString resultStr = "";
    while (pos<str.length())
    {
        if (str[pos]=='\n')
        {
            parsingError("unexpected end of line", line, column, error, errorString);
            return result;
        }
        column++;
        if (str[pos]=='\"')
            break;
        if (str[pos]=='\\')
        {
            pos++;
            QChar c = getChar(str, pos);
            switch (c.toLatin1())
            {
                case 'n':
                    resultStr+='\n';
                    break;
                case 't':
                    resultStr+='\t';
                    break;
                case 'r':
                    resultStr+='\r';
                    break;
                case 'f':
                    resultStr+='\f';
                    break;
                case 'b':
                    resultStr+='\b';
                    break;
                case '\\':
                    resultStr+=c;
                    break;
                case '\"':
                    resultStr+=c;
                    break;
                case 'u':
                {
                    QString strCode;
                    for (int i=0; i<4; i++)
                    {
                        pos++;
                        QChar c = getChar(str, pos);
                        if (c==0)
                        {
                            parsingError("unexpected end of document", line, column, error, errorString);
                            return result;
                        }
                        strCode += c;
                    }
                    bool ok = true;
                    int code = strCode.toInt(&ok, 16);
                    resultStr += QChar(code);
                    break;
                }
                default:
                {
                    parsingError("unexpected symbol", line, column, error, errorString);
                    return result;
                }
            }
            pos++;
            continue;
        }
        resultStr += str[pos];
        pos++;
    }
    if (getChar(str, pos)!='\"')
    {
        if (getChar(str, pos)==0)
        {
            parsingError("unexpected end of document", line, column, error, errorString);
            return result;
        } else
        {
            parsingError("unknown error while parsing string value", line, column, error, errorString);
            return result;
        }
    }
    pos++;
    (*result) = resultStr;
    return result;
}

QJS *QJS::extractArray(QString str, int &pos, int &line, int &column, bool &error, QString &errorString)
{
    QJS *result = new QJS();
    QChar c = getChar(str, pos);
    if (c!='[')
    {
        parsingError("\"[\" expected", line, column, error, errorString);
        return result;
    }
    pos++;
    while (true)
    {
        skipOtherChars(str, pos, line, column, error, errorString);
        if (error)
        {
            return result;
        }
        c = getChar(str, pos);
        if (c==']')
        {
            pos++;
            result->setType(QJS::Array);
            return result;
        }
        QJS *value = extractValue(str, pos, line, column, error, errorString);
        if (error)
        {
            return result;
        }
        result->append(value);
        skipOtherChars(str, pos, line, column, error, errorString);
        if (error)
        {
            return result;
        }
        c = getChar(str, pos);
        if (c!=',' && c!=']')
        {
            parsingError("\",\" or \"]\" expected", line, column, error, errorString);
            return result;
        }
        pos++;
        if (c==']')
            break;
    }
    return result;
}

QJS *QJS::extractBool(QString str, int &pos, int &line, int &column, bool &error, QString &errorString)
{
    QJS *result = new QJS();
    if (str.mid(pos, 4)=="true")
    {
        (*result) = true;
        pos += 4;
        return result;
    }
    if (str.mid(pos, 5)=="false")
    {
        (*result) = false;
        pos += 5;
        return result;
    }
    parsingError("\"true\" or \"false\" expected", line, column, error, errorString);
    return result;
}

QJS *QJS::extractNumber(QString str, int &pos, int &line, int &column, bool &error, QString &errorString)
{
    QString s;
    QString digits = "0123456789.-e";
    QJS* result = new QJS();
    while (true)
    {
        QChar c = getChar(str, pos);
        if (!digits.contains(c))
            break;
        s += c;
        pos++;
    }
    bool ok = false;
    long long l = s.toLongLong(&ok);
    if (!ok)
    {
        double d = s.toDouble(&ok);
        if (!ok)
        {
            parsingError("number parsing error", line, column, error, errorString);
            return result;
        }
        (*result) = d;
    } else
        (*result) = l;
    return result;
}

void QJS::parsingError(QString message, int line, int column, bool &error, QString &errorString)
{
    error = true;
    errorString = "JSON parsing error: "+message+" at line: " + QString::number(line+1) + ", column: " + QString::number(column+1) + ".";
}

void QJS::_changed(QJS *address, QString operation, QJS *newData, QJS *oldData)
{
    emit dataChanged(address, operation, newData, oldData);
    if (_parent==0)
    {
        delete newData;
        delete oldData;
        delete address;
        return;
    }
    switch (_parent->_type) {
    case QJS::Array:
    {
        int index = this->index();
        if (index == -1)
        {
            delete newData;
            delete oldData;
            delete address;
            return;
        }
        address->prepend(index);
        break;
    }
    case QJS::Object:
    {
        QString name = this->key();
        if (name.length()==0)
        {
            delete newData;
            delete oldData;
            delete address;
            return;
        }
        address->prepend(name);
        break;
    }
    default:
        break;
    }
    _parent->_changed(address, operation, newData, oldData);
}

bool QJS::applyChange(QJS *address, QString operation, QJS *newData, QJS *oldData)
{
    (void)oldData;
    bool isSignalsEnabled = signalsEnabled();
    enableSignals(false);
    QJS &node = getByAddress(*address);
    if (operation=="assign")
    {
        node.set(*newData);
    }
    if (operation=="prepend")
    {
        node.prepend(*newData);
    }
    enableSignals(isSignalsEnabled);
    return true;
}

QString QJS::escapeString(QString str)
{
    QString res;
    res.reserve(str.length());
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == QLatin1Char('\b')) {
            res += QLatin1String("\\b");
        } else if (str[i] == QLatin1Char('\f')) {
            res += QLatin1String("\\f");
        } else if (str[i] == QLatin1Char('\n')) {
            res += QLatin1String("\\n");
        } else if (str[i] == QLatin1Char('\r')) {
            res += QLatin1String("\\r");
        } else if (str[i] == QLatin1Char('\t')) {
            res += QLatin1String("\\t");
        } else if (str[i] == QLatin1Char('\"')) {
            res += QLatin1String("\\\"");
        } else if (str[i] == QLatin1Char('\\')) {
            res += QLatin1String("\\\\");
        } else if (str[i].unicode() > 127) {
            res += QLatin1String("\\u") + QString::number(str[i].unicode(), 16).rightJustified(4, QLatin1Char('0'));
        } else {
            res += str[i];
        }
    }
    return res;
}

QJS *QJS::parseBinaryData(QDataStream *in,bool &error)
{
    qint8 type;
    *in>>type;
    QJS* qjs=new QJS();

    switch ((Type)type)
    {
    case QJS::Bool:
    {
        bool data;
        *in>>data;
        qjs->set(data);
        return qjs;
    }
    case QJS::Number:
         qint8 ntype;
         *in>>ntype;
        if (((QVariant::Type)ntype)==QVariant::Double){
            double data;
            *in>>data;
            qjs->set(data);
//            (*qjs)=data;
            return qjs;
        }

        if (((QVariant::Type)ntype)==QVariant::Int){
            qint32 data;
            *in>>data;
            qjs->set((int)data);
            return qjs;
        }
        if (((QVariant::Type)ntype)==QVariant::LongLong){
            qint64 data;
            *in>>data;
            qjs->set((long long)data);
            return qjs;
        }
    case QJS::String:
    {
        qint32 len;
        *in>>len;
        char* str=new char[len];
        int bnum=in->readRawData(str,len);
        if(bnum<0){
            error=true;
            return qjs;
        }
        else{
            qjs->set(QString::fromUtf8(str,len));
            return qjs;
        }
    }
    case QJS::Object:
    {
        qint16 size,len;
        *in>>size;
        for(int i=0;i<(int)size;i++){
            *in>>len;
            char* str=new char[len];
            int bnum=in->readRawData(str,(int)len);
            if(bnum<0){
                error=true;
                return qjs;
            }
            else{
                QJS* q=QJS::parseBinaryData(in,error);
                QString key=QString::fromUtf8(str,len);
                qjs->set(key,q);
            }
        }
        return qjs;
    }
    case QJS::Array:
    {
        qint32 size;
        *in>>size;
        for (int i=0; i<(int)size; i++)
        {
            QJS* q=QJS::parseBinaryData(in,error);
            qjs->append(q);
        }
        return qjs;
    }
    case QJS::Null:
        return qjs;
    default:
        error=true;
    }
    return qjs;
}

QJS *QJS::extractValue(QString str, int &pos, int &line, int &column, bool &error, QString &errorString)
{
    QChar c = getChar(str, pos);
    if (c==0)
    {
        parsingError("unexpected end of document", line, column, error, errorString);
        return new QJS();
    }
    if (c=='{')
    {
        return extractObject(str, pos, line, column, error, errorString);
    }
    if (c=='\"')
    {
        return extractString(str, pos, line, column, error, errorString);
    }
    if (c=='[')
    {
        return extractArray(str, pos, line, column, error, errorString);
    }
    if (c.isDigit()||c=='-')
    {
        return extractNumber(str, pos, line, column, error, errorString);
    }
    if (c=='t' || c=='f')
    {
        return extractBool(str, pos, line, column, error, errorString);
    }
    if (c=='n')
    {
        if (str.mid(pos, 4)=="null")
        {
            pos += 4;
            return new QJS();
        }else
        {
            parsingError("\"null\" expected", line, column, error, errorString);
            return new QJS();
        }
    }
    parsingError("value extracting error", line, column, error, errorString);
    return new QJS();
}

QJS *QJS::extractObject(QString str, int &pos, int &line, int &column, bool &error, QString &errorString)
{
    QChar c = getChar(str, pos);
    QJS *result = new QJS();
    if (c!='{')
    {
        parsingError("\"{\" expected", line, column, error, errorString);
        return result;
    }
    pos++;
    while (true)
    {
        skipOtherChars(str, pos, line, column, error, errorString);
        if (error)
        {
            return result;
        }
        c = getChar(str, pos);
        if (c=='}')
        {
            pos++;
            result->setType(QJS::Object);
            return result;
        }
        QString key = extractKey(str, pos, line, column, error, errorString);
        skipOtherChars(str, pos, line, column, error, errorString);
        if (error)
        {
            return result;
        }
        c = getChar(str, pos);
        if (c!=':')
        {
            parsingError("\":\" expected", line, column, error, errorString);
            return result;
        }
        pos++;
        skipOtherChars(str, pos, line, column, error, errorString);
        if (error)
        {
            return result;
        }
        QJS *value = extractValue(str, pos, line, column, error, errorString);
        if (error)
        {
            return result;
        }
        result->set(key, value);
        skipOtherChars(str, pos, line, column, error, errorString);
        if (error)
        {
            return result;
        }
        c = getChar(str, pos);
        if (c!=',' && c!='}')
        {
            parsingError("\",\" or \"}\" expected", line, column, error, errorString);
            return result;
        }
        pos++;
        if (c=='}')
            break;
    }
    return result;
}

QJS QJS::fromJson(QString str)
{
    int pos = 0;
    int line = 0;
    int column = 0;
    bool error = false;
    QString errorString;
    QJS &result = *extractValue(str, pos, line, column, error, errorString);
    result._hasParsingError = error;
    result._parsingErrorString = errorString;
    result._doNotCopy = true;
    return result;
}

void QJS::toBinaryData(QDataStream *out) const
{
    *out<<(qint8)(this->_type);
    switch (this->_type)
    {
    case QJS::Bool:
    {
        bool b = _data.toBool();
        *out<<b;
        break;
    }
    case QJS::Number:
    {
        *out<<(qint8)_data.type();
        if (_data.type()==QVariant::Double)
            *out<<_data.toDouble();
        if (_data.type()==QVariant::Int)
            *out<<(qint32)_data.toInt();
        if (_data.type()==QVariant::LongLong)
            *out<<(qint64)_data.toInt();
        break;
    }
    case QJS::String:
    {
        QString string=_data.toString();
        int len=string.toUtf8().size();
        *out<<(qint32)len;
        out->writeRawData(string.toUtf8().data(),len);
        break;
    }
    case QJS::Object:
    {
        QList<QString> keys = _objectData.keys();
        *out<<(qint16)_objectData.size();
        qSort(keys);
        foreach (QString key, keys) {
            qint16 len=key.length();
//            qint16 len=key.toUtf8().size();
            *out<<len;
            out->writeRawData(key.toUtf8().data(),len);
            _objectData[key]->toBinaryData(out);
        }
        break;
    }
    case QJS::Array:
    {
        *out<<(qint32)this->size();
        for (int i=0; i<this->size(); i++)
        {
            _arrayData[i]->toBinaryData(out);
        }
        break;
    }
    case QJS::Null:
        break;
    default:
        break;
    }
}

QJS QJS::fromBinaryData(QDataStream *in)
{
    //TODO: Сделать правильный вывод ошибок
    bool error = false;
    QJS &result = *QJS::parseBinaryData(in,error);
    result._hasParsingError = error;
    if(error)result._parsingErrorString = "Невалидные бинарные данные";
    result._doNotCopy = true;
    return result;
}

bool QJS::isParsingError()
{
    return _hasParsingError;
}

bool QJS::hasParsingError()
{
    return _hasParsingError;
}

QString QJS::parsingErrorString()
{
    return _parsingErrorString;
}

void QJS::transformParent()
{
    if (_parent==0)
        return;
    //QMutexLocker locker(&_parent->mutex);
    if((_parent->_type!=QJS::Null)&&(_parent->_type!=_desirebleParentType)){ //todo: more elegant
        if (_desirebleParentType==QJS::Array){
            foreach (QJS* js, _parent->_objectData)
            {
                delete js;
            }
            _parent->_objectData.clear();
            _parent->_size=_parent->_arrayData.size();
        }
        if (_desirebleParentType==QJS::Object){
            foreach (QJS* js, _parent->_arrayData)
            {
                delete js;
            }
            _parent->_arrayData.clear();
            _parent->_size=_parent->_objectData.size();
        }
    }
    if (_desirebleParentType!=QJS::Null)
    {
        if (_desirebleParentType==QJS::Array)
            _parent->setType(QJS::Array);
        if (_desirebleParentType==QJS::Object)
            _parent->setType(QJS::Object);
        if (_parent!=0)
        {
            if (_parent->_type==QJS::Array)
            {
                if (_index+1>_parent->_size)
                    _parent->setSize(_index+1);
                if (!_exists)
                {
                    while (_index>_parent->_arrayData.size())
                    {
                        _parent->_arrayData.append(new QJS(_parent, QJS::Null));
                    }
                    if (_index==_parent->_arrayData.size())
                        _parent->_arrayData.append(0);
                    _parent->_arrayData[this->_index] = this;
                    if (_parent->_nonExistsObjects.contains(this))
                        _parent->_nonExistsObjects.remove(this);
                    _exists = true;
                }
            }
            if (_parent->_type==QJS::Object)
            {
                if (!_exists)
                {
                    _parent->_objectData[this->_key] = this;
                    if (_parent->_nonExistsObjects.contains(this))
                        _parent->_nonExistsObjects.remove(this);
                    _exists = true;
                }
            }
        }
    }
    _exists = true;
    _parent->transformParent();
}

void QJS::setSize(int size)
{
    _size = size;
}

void QJS::addChild(QJS *child)
{
    (void)child;
    //QMutexLocker lock(&mutex);
    //_children[child] = child;
}

void QJS::removeChild(QJS *child)
{
    (void)child;
    //QMutexLocker lock(&mutex);
    //if (_children.contains(child))
        //_children.remove(child);
}
