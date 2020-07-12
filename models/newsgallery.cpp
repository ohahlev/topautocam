#include <TreeFrogModel>
#include "newsgallery.h"
#include "sqlobjects/newsgalleryobject.h"

NewsGallery::NewsGallery() :
    TAbstractModel(),
    d(new NewsGalleryObject())
{
    // set the initial parameters
}

NewsGallery::NewsGallery(const NewsGallery &other) :
    TAbstractModel(),
    d(other.d)
{ }

NewsGallery::NewsGallery(const NewsGalleryObject &object) :
    TAbstractModel(),
    d(new NewsGalleryObject(object))
{ }

NewsGallery::~NewsGallery()
{
    // If the reference count becomes 0,
    // the shared data object 'NewsGalleryObject' is deleted.
}

int NewsGallery::id() const
{
    return d->id;
}

QString NewsGallery::image() const
{
    return d->image;
}

void NewsGallery::setImage(const QString &image)
{
    d->image = image;
}

QString NewsGallery::status() const
{
    return d->status;
}

void NewsGallery::setStatus(const QString &status)
{
    d->status = status;
}

QDateTime NewsGallery::createdAt() const
{
    return d->created_at;
}

QDateTime NewsGallery::updatedAt() const
{
    return d->updated_at;
}

NewsGallery &NewsGallery::operator=(const NewsGallery &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

NewsGallery NewsGallery::create(const QString &image, const QString &status)
{
    NewsGalleryObject obj;
    obj.image = image;
    obj.status = status;
    if (!obj.create()) {
        return NewsGallery();
    }
    return NewsGallery(obj);
}

NewsGallery NewsGallery::create(const QVariantMap &values)
{
    NewsGallery model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

NewsGallery NewsGallery::get(int id)
{
    TSqlORMapper<NewsGalleryObject> mapper;
    return NewsGallery(mapper.findByPrimaryKey(id));
}

int NewsGallery::count()
{
    TSqlORMapper<NewsGalleryObject> mapper;
    return mapper.findCount();
}

QList<NewsGallery> NewsGallery::getAll()
{
    return tfGetModelListByCriteria<NewsGallery, NewsGalleryObject>(TCriteria());
}

QJsonArray NewsGallery::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<NewsGalleryObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<NewsGalleryObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(NewsGallery(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *NewsGallery::modelData()
{
    return d.data();
}

const TModelObject *NewsGallery::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const NewsGallery &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, NewsGallery &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(NewsGallery)
