#include <TreeFrogModel>
#include "drivetype.h"
#include "sqlobjects/drivetypeobject.h"

DriveType::DriveType() :
    TAbstractModel(),
    d(new DriveTypeObject())
{
    // set the initial parameters
}

DriveType::DriveType(const DriveType &other) :
    TAbstractModel(),
    d(other.d)
{ }

DriveType::DriveType(const DriveTypeObject &object) :
    TAbstractModel(),
    d(new DriveTypeObject(object))
{ }

DriveType::~DriveType()
{
    // If the reference count becomes 0,
    // the shared data object 'DriveTypeObject' is deleted.
}

int DriveType::id() const
{
    return d->id;
}

QString DriveType::name() const
{
    return d->name;
}

void DriveType::setName(const QString &name)
{
    d->name = name;
}

QDateTime DriveType::createdAt() const
{
    return d->created_at;
}

QDateTime DriveType::updatedAt() const
{
    return d->updated_at;
}

DriveType &DriveType::operator=(const DriveType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

DriveType DriveType::create(const QString &name)
{
    DriveTypeObject obj;
    obj.name = name;
    if (!obj.create()) {
        return DriveType();
    }
    return DriveType(obj);
}

DriveType DriveType::create(const QVariantMap &values)
{
    DriveType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

DriveType DriveType::get(int id)
{
    TSqlORMapper<DriveTypeObject> mapper;
    return DriveType(mapper.findByPrimaryKey(id));
}

int DriveType::count()
{
    TSqlORMapper<DriveTypeObject> mapper;
    return mapper.findCount();
}

QList<DriveType> DriveType::getAll()
{
    return tfGetModelListByCriteria<DriveType, DriveTypeObject>(TCriteria());
}

QJsonArray DriveType::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<DriveTypeObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<DriveTypeObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(DriveType(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *DriveType::modelData()
{
    return d.data();
}

const TModelObject *DriveType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const DriveType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, DriveType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(DriveType)
