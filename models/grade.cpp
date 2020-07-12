#include <TreeFrogModel>
#include "grade.h"
#include "sqlobjects/gradeobject.h"

Grade::Grade() :
    TAbstractModel(),
    d(new GradeObject())
{
    // set the initial parameters
}

Grade::Grade(const Grade &other) :
    TAbstractModel(),
    d(other.d)
{ }

Grade::Grade(const GradeObject &object) :
    TAbstractModel(),
    d(new GradeObject(object))
{ }

Grade::~Grade()
{
    // If the reference count becomes 0,
    // the shared data object 'GradeObject' is deleted.
}

int Grade::id() const
{
    return d->id;
}

QString Grade::name() const
{
    return d->name;
}

void Grade::setName(const QString &name)
{
    d->name = name;
}

QDateTime Grade::createdAt() const
{
    return d->created_at;
}

QDateTime Grade::updatedAt() const
{
    return d->updated_at;
}

Grade &Grade::operator=(const Grade &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Grade Grade::create(const QString &name)
{
    GradeObject obj;
    obj.name = name;
    if (!obj.create()) {
        return Grade();
    }
    return Grade(obj);
}

Grade Grade::create(const QVariantMap &values)
{
    Grade model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Grade Grade::get(int id)
{
    TSqlORMapper<GradeObject> mapper;
    return Grade(mapper.findByPrimaryKey(id));
}

int Grade::count()
{
    TSqlORMapper<GradeObject> mapper;
    return mapper.findCount();
}

QList<Grade> Grade::getAll()
{
    return tfGetModelListByCriteria<Grade, GradeObject>(TCriteria());
}

QJsonArray Grade::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<GradeObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<GradeObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Grade(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Grade::modelData()
{
    return d.data();
}

const TModelObject *Grade::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Grade &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Grade &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Grade)
