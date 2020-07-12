#ifndef VEHICLEGALLERY_H
#define VEHICLEGALLERY_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class VehicleGalleryObject;
class QJsonArray;


class T_MODEL_EXPORT VehicleGallery : public TAbstractModel
{
public:
    VehicleGallery();
    VehicleGallery(const VehicleGallery &other);
    VehicleGallery(const VehicleGalleryObject &object);
    ~VehicleGallery();

    int id() const;
    QString photo() const;
    void setPhoto(const QString &photo);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    int vehicleId() const;
    void setVehicleId(int vehicleId);
    VehicleGallery &operator=(const VehicleGallery &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static VehicleGallery create(const QString &photo, int vehicleId);
    static VehicleGallery create(const QVariantMap &values);
    static VehicleGallery get(int id);
    static int count();
    static QList<VehicleGallery> getAll();
    static QList<VehicleGallery> getAllByVehicle(const int vehicleId);
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<VehicleGalleryObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const VehicleGallery &model);
    friend QDataStream &operator>>(QDataStream &ds, VehicleGallery &model);
};

Q_DECLARE_METATYPE(VehicleGallery)
Q_DECLARE_METATYPE(QList<VehicleGallery>)

#endif // VEHICLEGALLERY_H
