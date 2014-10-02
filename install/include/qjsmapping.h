#ifndef QJSMAPPING_H
#define QJSMAPPING_H

#include "QJS"
#include <QObject>

#define QJS_MAPPING_QSTRING(field, getter, setter) \
    QString getter(){return (*this)[field].toString();} \
    void setter(QString value){(*this)[field] = value;}

#define QJS_MAPPING_INT(field, getter, setter) \
    int getter(){return (*this)[field].toInt();} \
    void setter(int value){(*this)[field] = value;}

#define QJS_MAPPING_BOOL(field, getter, setter) \
    bool getter(){return (*this)[field].toBool();} \
    void setter(bool value){(*this)[field] = value;}

#define QJS_MAPPING_OBJECT(field, getter, setter, type) \
    type &getter(){return (type&)(*this)[field];} \
    void setter(type &value){(*this)[field] = value;}

#define QJS_MAPPING_ARRAY(field, getter, addMethod, type) \
    QJS &getter(){\
        return (*this)[field];\
    } \
    void addMethod(type &value){\
        (*this)[field].append(value);\
    }

#define QJS_MAPPING_STRINGHASH(field, getAll, getOne, setOne, type) \
    QJS &getAll(){\
        return (*this)[field];\
    } \
    type &getOne(QString key){\
        return (type&)(*this)[field][key];\
    }\
    void setOne(QString key, type value){\
        (*this)[field][key] = value;\
    }

class QJSSHARED_EXPORT QJSMapping : public QJS
{
    Q_OBJECT
public:
    explicit QJSMapping(QJS data = QJS::Null);

signals:

public slots:

};

#endif // QJSMAPPING_H
