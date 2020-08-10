#include <TreeFrogModel>
#include "vehicle.h"
#include "sqlobjects/vehicleobject.h"
#include "sqlobjects/makeobject.h"
#include "sqlobjects/vehiclemodelobject.h"
#include "sqlobjects/bodytypeobject.h"
#include "sqlobjects/drivetypeobject.h"
#include "sqlobjects/fueltypeobject.h"
#include "sqlobjects/colorobject.h"
#include "sqlobjects/gradeobject.h"

Vehicle::Vehicle() : TAbstractModel(),
                     d(new VehicleObject())
{
    // set the initial parameters
}

Vehicle::Vehicle(const Vehicle &other) : TAbstractModel(),
                                         d(other.d)
{
}

Vehicle::Vehicle(const VehicleObject &object) : TAbstractModel(),
                                                d(new VehicleObject(object))
{
}

Vehicle::~Vehicle()
{
    // If the reference count becomes 0,
    // the shared data object 'VehicleObject' is deleted.
}

int Vehicle::id() const
{
    return d->id;
}

QString Vehicle::title() const
{
    return d->title;
}

void Vehicle::setTitle(const QString &title)
{
    d->title = title;
}

QString Vehicle::detail() const
{
    return d->detail;
}

void Vehicle::setDetail(const QString &detail)
{
    d->detail = detail;
}

QString Vehicle::code() const
{
    return d->code;
}

void Vehicle::setCode(const QString &code)
{
    d->code = code;
}

QString Vehicle::frameNo() const
{
    return d->frame_no;
}

void Vehicle::setFrameNo(const QString &frameNo)
{
    d->frame_no = frameNo;
}

QString Vehicle::manufacturingDate() const
{
    return d->manufacturing_date.toString("yyyy-MM-dd");
}

QDateTime Vehicle::getXManufacturingDate() const
{
    return d->manufacturing_date;
}

void Vehicle::setManufacturingDate(const QDateTime &manufacturingDate)
{
    d->manufacturing_date = manufacturingDate;
}

QDateTime Vehicle::depositDate() const
{
    return d->deposit_date;
}

void Vehicle::setDepositDate(const QDateTime &depositDate)
{
    d->deposit_date = depositDate;
}

QString Vehicle::engine() const
{
    return d->engine;
}

void Vehicle::setEngine(const QString &engine)
{
    d->engine = engine;
}

QString Vehicle::mileage() const
{
    return d->mileage;
}

void Vehicle::setMileage(const QString &mileage)
{
    d->mileage = mileage;
}

QDateTime Vehicle::createdAt() const
{
    return d->created_at;
}

QDateTime Vehicle::updatedAt() const
{
    return d->updated_at;
}

QString Vehicle::vehicleStatus() const
{
    return d->vehicle_status;
}

void Vehicle::setVehicleStatus(const QString &vehicleStatus)
{
    d->vehicle_status = vehicleStatus;
}

QString Vehicle::inventoryStatus() const
{
    return d->inventory_status;
}

void Vehicle::setInventoryStatus(const QString &inventoryStatus)
{
    d->inventory_status = inventoryStatus;
}

double Vehicle::price() const
{
    return d->price;
}

void Vehicle::setPrice(double price)
{
    d->price = price;
}

int Vehicle::makeId() const
{
    return d->make_id;
}

void Vehicle::setMakeId(int makeId)
{
    d->make_id = makeId;
}

int Vehicle::modelId() const
{
    return d->model_id;
}

void Vehicle::setModelId(int modelId)
{
    d->model_id = modelId;
}

int Vehicle::colorId() const
{
    return d->color_id;
}

void Vehicle::setColorId(int colorId)
{
    d->color_id = colorId;
}

int Vehicle::gradeId() const
{
    return d->grade_id;
}

void Vehicle::setGradeId(int gradeId)
{
    d->grade_id = gradeId;
}

int Vehicle::driveId() const
{
    return d->drive_id;
}

void Vehicle::setDriveId(int driveId)
{
    d->drive_id = driveId;
}

int Vehicle::fuelId() const
{
    return d->fuel_id;
}

void Vehicle::setFuelId(int fuelId)
{
    d->fuel_id = fuelId;
}

int Vehicle::bodyId() const
{
    return d->body_id;
}

void Vehicle::setBodyId(int bodyId)
{
    d->body_id = bodyId;
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
    d = other.d; // increments the reference count of the data
    return *this;
}

Vehicle Vehicle::create(const QString &title, const QString &detail, const QString &code, const QString &frameNo, const QDateTime &manufacturingDate, const QDateTime &depositDate, const QString &engine, const QString &mileage, const QString &vehicleStatus, const QString &inventoryStatus, double price, int makeId, int modelId, int colorId, int gradeId, int driveId, int fuelId, int bodyId)
{
    VehicleObject obj;
    obj.title = title;
    obj.detail = detail;
    obj.code = code;
    obj.frame_no = frameNo;
    obj.manufacturing_date = manufacturingDate;
    obj.deposit_date = depositDate;
    obj.engine = engine;
    obj.mileage = mileage;
    obj.vehicle_status = vehicleStatus;
    obj.inventory_status = inventoryStatus;
    obj.price = price;
    obj.make_id = makeId;
    obj.model_id = modelId;
    obj.color_id = colorId;
    obj.grade_id = gradeId;
    obj.drive_id = driveId;
    obj.fuel_id = fuelId;
    obj.body_id = bodyId;
    if (!obj.create())
    {
        return Vehicle();
    }
    return Vehicle(obj);
}

Vehicle Vehicle::create(const QVariantMap &values)
{
    Vehicle model;
    model.setProperties(values);
    if (!model.d->create())
    {
        model.d->clear();
    }
    return model;
}

Vehicle Vehicle::get(int id)
{
    TSqlORMapper<VehicleObject> mapper;
    return Vehicle(mapper.findByPrimaryKey(id));
}

int Vehicle::count()
{
    TSqlORMapper<VehicleObject> mapper;
    return mapper.findCount();
}

QList<Vehicle> Vehicle::getAll()
{
    return tfGetModelListByCriteria<Vehicle, VehicleObject>(TCriteria());
}

//makeId=:param&modelId=:param&bodyId=:param&driveId=:param&colorId=:param&gradeId=:param&fuelId=:param
QList<Vehicle> Vehicle::search(const int makeId, const int modelId, const int bodyId,
                               const int driveId, const int colorId, const int gradeId,
                               const int fuelId)
{
    TCriteria crt(MakeObject::Id, makeId);
    crt.add(VehicleModelObject::Id, modelId);
    crt.add(BodyTypeObject::Id, bodyId);
    crt.add(DriveTypeObject::Id, driveId);
    crt.add(ColorObject::Id, colorId);
    crt.add(GradeObject::Id, gradeId);
    crt.add(FuelTypeObject::Id, fuelId);

    return tfGetModelListByCriteria<Vehicle, VehicleObject>(crt);
}

QJsonArray Vehicle::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<VehicleObject> mapper;

    if (mapper.find() > 0)
    {
        for (TSqlORMapperIterator<VehicleObject> i(mapper); i.hasNext();)
        {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Vehicle(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Vehicle::modelData()
{
    return d.data();
}

const TModelObject *Vehicle::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Vehicle &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Vehicle &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

Make Vehicle::getMake() const
{
    TSqlORMapper<MakeObject> mapper;
    return Make(mapper.findByPrimaryKey(d->make_id));
}

VehicleModel Vehicle::getModel() const
{
    TSqlORMapper<VehicleModelObject> mapper;
    return VehicleModel(mapper.findByPrimaryKey(d->model_id));
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Vehicle)
