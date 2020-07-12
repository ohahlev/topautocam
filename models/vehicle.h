#ifndef VEHICLE_H
#define VEHICLE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

#include "make.h"
#include "vehiclemodel.h"

class TModelObject;
class VehicleObject;
class QJsonArray;

class T_MODEL_EXPORT Vehicle : public TAbstractModel
{
public:
    Vehicle();
    Vehicle(const Vehicle &other);
    Vehicle(const VehicleObject &object);
    ~Vehicle();

    int id() const;
    QString title() const;
    void setTitle(const QString &title);
    QString detail() const;
    void setDetail(const QString &detail);
    QString code() const;
    void setCode(const QString &code);
    QString frameNo() const;
    void setFrameNo(const QString &frameNo);
    QString manufacturingDate() const;
    QDateTime getXManufacturingDate() const;
    void setManufacturingDate(const QDateTime &manufacturingDate);
    QDateTime depositDate() const;
    void setDepositDate(const QDateTime &depositDate);
    QString engine() const;
    void setEngine(const QString &engine);
    QString mileage() const;
    void setMileage(const QString &mileage);
    QDateTime createdAt() const;
    QDateTime updatedAt() const;
    QString vehicleStatus() const;
    void setVehicleStatus(const QString &vehicleStatus);
    QString inventoryStatus() const;
    void setInventoryStatus(const QString &inventoryStatus);
    double price() const;
    void setPrice(double price);
    int makeId() const;
    void setMakeId(int makeId);
    int modelId() const;
    void setModelId(int modelId);
    int colorId() const;
    void setColorId(int colorId);
    int gradeId() const;
    void setGradeId(int gradeId);
    int driveId() const;
    void setDriveId(int driveId);
    int fuelId() const;
    void setFuelId(int fuelId);
    int bodyId() const;
    void setBodyId(int bodyId);
    Vehicle &operator=(const Vehicle &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save() override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Vehicle create(const QString &title, const QString &detail, const QString &code, const QString &frameNo, const QDateTime &manufacturingDate, const QDateTime &depositDate, const QString &engine, const QString &mileage, const QString &vehicleStatus, const QString &inventoryStatus, double price, int makeId, int modelId, int colorId, int gradeId, int driveId, int fuelId, int bodyId);
    static Vehicle create(const QVariantMap &values);
    static Vehicle get(int id);
    static int count();
    static QList<Vehicle> getAll();
    static QJsonArray getAllJson();

    /**
     * ahlev
     */
    Make getMake() const;
    VehicleModel getModel() const;

private:
    QSharedDataPointer<VehicleObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Vehicle &model);
    friend QDataStream &operator>>(QDataStream &ds, Vehicle &model);
};

Q_DECLARE_METATYPE(Vehicle)
Q_DECLARE_METATYPE(QList<Vehicle>)

#endif // VEHICLE_H
