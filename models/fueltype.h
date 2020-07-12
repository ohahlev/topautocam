#ifndef FUELTYPE_H
#define FUELTYPE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FuelTypeObject;
class QJsonArray;


class T_MODEL_EXPORT FuelType : public TAbstractModel
{
public:
    FuelType();
    FuelType(const FuelType &other);
    FuelType(const FuelTypeObject &object);
    ~FuelType();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    FuelType &operator=(const FuelType &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static FuelType create(const QString &name);
    static FuelType create(const QVariantMap &values);
    static FuelType get(int id);
    static int count();
    static QList<FuelType> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<FuelTypeObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const FuelType &model);
    friend QDataStream &operator>>(QDataStream &ds, FuelType &model);
};

Q_DECLARE_METATYPE(FuelType)
Q_DECLARE_METATYPE(QList<FuelType>)

#endif // FUELTYPE_H
