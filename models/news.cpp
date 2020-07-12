#include <TreeFrogModel>
#include "news.h"
#include "sqlobjects/newsobject.h"

News::News() : TAbstractModel(),
               d(new NewsObject())
{
    // set the initial parameters
}

News::News(const News &other) : TAbstractModel(),
                                d(other.d)
{
}

News::News(const NewsObject &object) : TAbstractModel(),
                                       d(new NewsObject(object))
{
}

News::~News()
{
    // If the reference count becomes 0,
    // the shared data object 'NewsObject' is deleted.
}

int News::id() const
{
    return d->id;
}

QString News::title() const
{
    return d->title;
}

void News::setTitle(const QString &title)
{
    d->title = title;
}

QString News::subline() const
{
    return d->subline;
}

void News::setSubline(const QString &subline)
{
    d->subline = subline;
}

QString News::status() const
{
    return d->status;
}

void News::setStatus(const QString &status)
{
    d->status = status;
}

QString News::line1() const
{
    return d->line1;
}

void News::setLine1(const QString &line1)
{
    d->line1 = line1;
}

QString News::line2() const
{
    return d->line2;
}

void News::setLine2(const QString &line2)
{
    d->line2 = line2;
}

QString News::line3() const
{
    return d->line3;
}

void News::setLine3(const QString &line3)
{
    d->line3 = line3;
}

QDateTime News::createdAt() const
{
    return d->created_at;
}

QDateTime News::updatedAt() const
{
    return d->updated_at;
}

News &News::operator=(const News &other)
{
    d = other.d; // increments the reference count of the data
    return *this;
}

News News::create(const QString &title, const QString &subline, const QString &status, const QString &line1, const QString &line2, const QString &line3)
{
    NewsObject obj;
    obj.title = title;
    obj.subline = subline;
    obj.status = status;
    obj.line1 = line1;
    obj.line2 = line2;
    obj.line3 = line3;
    if (!obj.create())
    {
        return News();
    }
    return News(obj);
}

News News::create(const QVariantMap &values)
{
    News model;
    model.setProperties(values);
    if (!model.d->create())
    {
        model.d->clear();
    }
    return model;
}

News News::get(int id)
{
    TSqlORMapper<NewsObject> mapper;
    return News(mapper.findByPrimaryKey(id));
}

int News::count()
{
    TSqlORMapper<NewsObject> mapper;
    return mapper.findCount();
}

QList<News> News::getAll()
{
    return tfGetModelListByCriteria<News, NewsObject>(TCriteria());
}

QList<News> News::getAllPublished()
{
    return tfGetModelListByCriteria<News, NewsObject>(TCriteria(NewsObject::Status, "PUBLISHED"));
}

QJsonArray News::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<NewsObject> mapper;

    if (mapper.find() > 0)
    {
        for (TSqlORMapperIterator<NewsObject> i(mapper); i.hasNext();)
        {
            array.append(QJsonValue(QJsonObject::fromVariantMap(News(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *News::modelData()
{
    return d.data();
}

const TModelObject *News::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const News &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, News &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(News)
