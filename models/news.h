#ifndef NEWS_H
#define NEWS_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class NewsObject;
class QJsonArray;

class T_MODEL_EXPORT News : public TAbstractModel
{
public:
    News();
    News(const News &other);
    News(const NewsObject &object);
    ~News();

    int id() const;
    QString title() const;
    void setTitle(const QString &title);
    QString subline() const;
    void setSubline(const QString &subline);
    QString status() const;
    void setStatus(const QString &status);
    QString line1() const;
    void setLine1(const QString &line1);
    QString line2() const;
    void setLine2(const QString &line2);
    QString line3() const;
    void setLine3(const QString &line3);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    News &operator=(const News &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save() override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static News create(const QString &title, const QString &subline, const QString &status, const QString &line1, const QString &line2, const QString &line3);
    static News create(const QVariantMap &values);
    static News get(int id);
    static int count();
    static QList<News> getAll();
    static QList<News> getAllPublished();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<NewsObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const News &model);
    friend QDataStream &operator>>(QDataStream &ds, News &model);
};

Q_DECLARE_METATYPE(News)
Q_DECLARE_METATYPE(QList<News>)

#endif // NEWS_H
