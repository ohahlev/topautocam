#include <TreeFrogModel>
#include "fueltype.h"
#include "sqlobjects/fueltypeobject.h"

FuelType::FuelType() :
    TAbstractModel(),
    d(new FuelTypeObject())
{
    // set the initial parameters
}

FuelType::FuelType(const FuelType &other) :
    TAbstractModel(),
    d(other.d)
{ }

FuelType::FuelType(const FuelTypeObject &object) :
    TAbstractModel(),
    d(new FuelTypeObject(object))
{ }

FuelType::~FuelType()
{
    // If the reference count becomes 0,
    // the shared data object 'FuelTypeObject' is deleted.
}

int FuelType::id() const
{
    return d->id;
}

QString FuelType::name() const
{
    return d->name;
}

void FuelType::setName(const QString &name)
{
    d->name = name;
}

QDateTime FuelType::createdAt() const
{
    return d->created_at;
}

QDateTime FuelType::updatedAt() const
{
    return d->updated_at;
}

FuelType &FuelType::operator=(const FuelType &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

FuelType FuelType::create(const QString &name)
{
    FuelTypeObject obj;
    obj.name = name;
    if (!obj.create()) {
        return FuelType();
    }
    return FuelType(obj);
}

FuelType FuelType::create(const QVariantMap &values)
{
    FuelType model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

FuelType FuelType::get(int id)
{
    TSqlORMapper<FuelTypeObject> mapper;
    return FuelType(mapper.findByPrimaryKey(id));
}

int FuelType::count()
{
    TSqlORMapper<FuelTypeObject> mapper;
    return mapper.findCount();
}

QList<FuelType> FuelType::getAll()
{
    return tfGetModelListByCriteria<FuelType, FuelTypeObject>(TCriteria());
}

QJsonArray FuelType::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<FuelTypeObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<FuelTypeObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(FuelType(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *FuelType::modelData()
{
    return d.data();
}

const TModelObject *FuelType::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const FuelType &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, FuelType &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(FuelType)
