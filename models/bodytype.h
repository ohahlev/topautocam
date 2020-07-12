#ifndef BODYTYPE_H
#define BODYTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class BodyTypeObject;
class QJsonArray;


class T_MODEL_EXPORT BodyType : public TAbstractModel
{
public:
    BodyType();
    BodyType(const BodyType &other);
    BodyType(const BodyTypeObject &object);
    ~BodyType();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    BodyType &operator=(const BodyType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static BodyType create(const QString &name);
    static BodyType create(const QVariantMap &values);
    static BodyType get(int id);
    static int count();
    static QList<BodyType> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<BodyTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const BodyType &model);
    friend QDataStream &operator>>(QDataStream &ds, BodyType &model);
};

Q_DECLARE_METATYPE(BodyType)
Q_DECLARE_METATYPE(QList<BodyType>)

#endif // BODYTYPE_H
