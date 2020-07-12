#ifndef NEWSGALLERY_H
#define NEWSGALLERY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class NewsGalleryObject;
class QJsonArray;


class T_MODEL_EXPORT NewsGallery : public TAbstractModel
{
public:
    NewsGallery();
    NewsGallery(const NewsGallery &other);
    NewsGallery(const NewsGalleryObject &object);
    ~NewsGallery();

    int id() const;
    QString image() const;
    void setImage(const QString &image);
    QString status() const;
    void setStatus(const QString &status);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    NewsGallery &operator=(const NewsGallery &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static NewsGallery create(const QString &image, const QString &status);
    static NewsGallery create(const QVariantMap &values);
    static NewsGallery get(int id);
    static int count();
    static QList<NewsGallery> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<NewsGalleryObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const NewsGallery &model);
    friend QDataStream &operator>>(QDataStream &ds, NewsGallery &model);
};

Q_DECLARE_METATYPE(NewsGallery)
Q_DECLARE_METATYPE(QList<NewsGallery>)

#endif // NEWSGALLERY_H
