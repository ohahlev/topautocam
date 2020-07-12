#include <TreeFrogModel>
#include "vehiclegallery.h"
#include "sqlobjects/vehiclegalleryobject.h"

VehicleGallery::VehicleGallery() :
    TAbstractModel(),
    d(new VehicleGalleryObject())
{
    // set the initial parameters
}

VehicleGallery::VehicleGallery(const VehicleGallery &other) :
    TAbstractModel(),
    d(other.d)
{ }

VehicleGallery::VehicleGallery(const VehicleGalleryObject &object) :
    TAbstractModel(),
    d(new VehicleGalleryObject(object))
{ }

VehicleGallery::~VehicleGallery()
{
    // If the reference count becomes 0,
    // the shared data object 'VehicleGalleryObject' is deleted.
}

int VehicleGallery::id() const
{
    return d->id;
}

QString VehicleGallery::photo() const
{
    return d->photo;
}

void VehicleGallery::setPhoto(const QString &photo)
{
    d->photo = photo;
}

QDateTime VehicleGallery::createdAt() const
{
    return d->created_at;
}

QDateTime VehicleGallery::updatedAt() const
{
    return d->updated_at;
}

int VehicleGallery::vehicleId() const
{
    return d->vehicle_id;
}

void VehicleGallery::setVehicleId(int vehicleId)
{
    d->vehicle_id = vehicleId;
}

VehicleGallery &VehicleGallery::operator=(const VehicleGallery &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VehicleGallery VehicleGallery::create(const QString &photo, int vehicleId)
{
    VehicleGalleryObject obj;
    obj.photo = photo;
    obj.vehicle_id = vehicleId;
    if (!obj.create()) {
        return VehicleGallery();
    }
    return VehicleGallery(obj);
}

VehicleGallery VehicleGallery::create(const QVariantMap &values)
{
    VehicleGallery model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VehicleGallery VehicleGallery::get(int id)
{
    TSqlORMapper<VehicleGalleryObject> mapper;
    return VehicleGallery(mapper.findByPrimaryKey(id));
}

int VehicleGallery::count()
{
    TSqlORMapper<VehicleGalleryObject> mapper;
    return mapper.findCount();
}

QList<VehicleGallery> VehicleGallery::getAll()
{
    return tfGetModelListByCriteria<VehicleGallery, VehicleGalleryObject>(TCriteria());
}

QList<VehicleGallery> VehicleGallery::getAllByVehicle(const int vehicleId)
{
    return tfGetModelListByCriteria<VehicleGallery, VehicleGalleryObject>(TCriteria(VehicleGalleryObject::VehicleId, vehicleId));
}

QJsonArray VehicleGallery::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<VehicleGalleryObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<VehicleGalleryObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(VehicleGallery(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *VehicleGallery::modelData()
{
    return d.data();
}

const TModelObject *VehicleGallery::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VehicleGallery &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VehicleGallery &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VehicleGallery)
