#include <TreeFrogModel>
#include "bodytype.h"
#include "sqlobjects/bodytypeobject.h"

BodyType::BodyType() :
    TAbstractModel(),
    d(new BodyTypeObject())
{
    // set the initial parameters
}

BodyType::BodyType(const BodyType &other) :
    TAbstractModel(),
    d(other.d)
{ }

BodyType::BodyType(const BodyTypeObject &object) :
    TAbstractModel(),
    d(new BodyTypeObject(object))
{ }

BodyType::~BodyType()
{
    // If the reference count becomes 0,
    // the shared data object 'BodyTypeObject' is deleted.
}

int BodyType::id() const
{
    return d->id;
}

QString BodyType::name() const
{
    return d->name;
}

void BodyType::setName(const QString &name)
{
    d->name = name;
}

QDateTime BodyType::createdAt() const
{
    return d->created_at;
}

QDateTime BodyType::updatedAt() const
{
    return d->updated_at;
}

BodyType &BodyType::operator=(const BodyType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

BodyType BodyType::create(const QString &name)
{
    BodyTypeObject obj;
    obj.name = name;
    if (!obj.create()) {
        return BodyType();
    }
    return BodyType(obj);
}

BodyType BodyType::create(const QVariantMap &values)
{
    BodyType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

BodyType BodyType::get(int id)
{
    TSqlORMapper<BodyTypeObject> mapper;
    return BodyType(mapper.findByPrimaryKey(id));
}

int BodyType::count()
{
    TSqlORMapper<BodyTypeObject> mapper;
    return mapper.findCount();
}

QList<BodyType> BodyType::getAll()
{
    return tfGetModelListByCriteria<BodyType, BodyTypeObject>(TCriteria());
}

QJsonArray BodyType::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<BodyTypeObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<BodyTypeObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(BodyType(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *BodyType::modelData()
{
    return d.data();
}

const TModelObject *BodyType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const BodyType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, BodyType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(BodyType)
