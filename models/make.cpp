#include <TreeFrogModel>
#include "make.h"
#include "sqlobjects/makeobject.h"

Make::Make() :
    TAbstractModel(),
    d(new MakeObject())
{
    // set the initial parameters
}

Make::Make(const Make &other) :
    TAbstractModel(),
    d(other.d)
{ }

Make::Make(const MakeObject &object) :
    TAbstractModel(),
    d(new MakeObject(object))
{ }

Make::~Make()
{
    // If the reference count becomes 0,
    // the shared data object 'MakeObject' is deleted.
}

int Make::id() const
{
    return d->id;
}

QString Make::name() const
{
    return d->name;
}

void Make::setName(const QString &name)
{
    d->name = name;
}

QString Make::logo() const
{
    return d->logo;
}

void Make::setLogo(const QString &logo)
{
    d->logo = logo;
}

QDateTime Make::createdAt() const
{
    return d->created_at;
}

QDateTime Make::updatedAt() const
{
    return d->updated_at;
}

Make &Make::operator=(const Make &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Make Make::create(const QString &name, const QString &logo)
{
    MakeObject obj;
    obj.name = name;
    obj.logo = logo;
    if (!obj.create()) {
        return Make();
    }
    return Make(obj);
}

Make Make::create(const QVariantMap &values)
{
    Make model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Make Make::get(int id)
{
    TSqlORMapper<MakeObject> mapper;
    return Make(mapper.findByPrimaryKey(id));
}

int Make::count()
{
    TSqlORMapper<MakeObject> mapper;
    return mapper.findCount();
}

QList<Make> Make::getAll()
{
    return tfGetModelListByCriteria<Make, MakeObject>(TCriteria());
}

QJsonArray Make::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<MakeObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<MakeObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Make(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Make::modelData()
{
    return d.data();
}

const TModelObject *Make::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Make &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Make &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Make)
