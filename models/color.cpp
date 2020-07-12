#include <TreeFrogModel>
#include "color.h"
#include "sqlobjects/colorobject.h"

Color::Color() :
    TAbstractModel(),
    d(new ColorObject())
{
    // set the initial parameters
}

Color::Color(const Color &other) :
    TAbstractModel(),
    d(other.d)
{ }

Color::Color(const ColorObject &object) :
    TAbstractModel(),
    d(new ColorObject(object))
{ }

Color::~Color()
{
    // If the reference count becomes 0,
    // the shared data object 'ColorObject' is deleted.
}

int Color::id() const
{
    return d->id;
}

QString Color::name() const
{
    return d->name;
}

void Color::setName(const QString &name)
{
    d->name = name;
}

QDateTime Color::createdAt() const
{
    return d->created_at;
}

QDateTime Color::updatedAt() const
{
    return d->updated_at;
}

Color &Color::operator=(const Color &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Color Color::create(const QString &name)
{
    ColorObject obj;
    obj.name = name;
    if (!obj.create()) {
        return Color();
    }
    return Color(obj);
}

Color Color::create(const QVariantMap &values)
{
    Color model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Color Color::get(int id)
{
    TSqlORMapper<ColorObject> mapper;
    return Color(mapper.findByPrimaryKey(id));
}

int Color::count()
{
    TSqlORMapper<ColorObject> mapper;
    return mapper.findCount();
}

QList<Color> Color::getAll()
{
    return tfGetModelListByCriteria<Color, ColorObject>(TCriteria());
}

QJsonArray Color::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ColorObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ColorObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Color(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Color::modelData()
{
    return d.data();
}

const TModelObject *Color::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Color &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Color &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Color)
