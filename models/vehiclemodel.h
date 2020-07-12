#ifndef VEHICLEMODEL_H
#define VEHICLEMODEL_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VehicleModelObject;
class QJsonArray;


class T_MODEL_EXPORT VehicleModel : public TAbstractModel
{
public:
    VehicleModel();
    VehicleModel(const VehicleModel &other);
    VehicleModel(const VehicleModelObject &object);
    ~VehicleModel();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    QString logo() const;
    void setLogo(const QString &logo);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    VehicleModel &operator=(const VehicleModel &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VehicleModel create(const QString &name, const QString &logo);
    static VehicleModel create(const QVariantMap &values);
    static VehicleModel get(int id);
    static int count();
    static QList<VehicleModel> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<VehicleModelObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VehicleModel &model);
    friend QDataStream &operator>>(QDataStream &ds, VehicleModel &model);
};

Q_DECLARE_METATYPE(VehicleModel)
Q_DECLARE_METATYPE(QList<VehicleModel>)

#endif // VEHICLEMODEL_H
