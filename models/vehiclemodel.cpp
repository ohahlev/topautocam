#include <TreeFrogModel>
#include "vehiclemodel.h"
#include "sqlobjects/vehiclemodelobject.h"

VehicleModel::VehicleModel() :
    TAbstractModel(),
    d(new VehicleModelObject())
{
    // set the initial parameters
}

VehicleModel::VehicleModel(const VehicleModel &other) :
    TAbstractModel(),
    d(other.d)
{ }

VehicleModel::VehicleModel(const VehicleModelObject &object) :
    TAbstractModel(),
    d(new VehicleModelObject(object))
{ }

VehicleModel::~VehicleModel()
{
    // If the reference count becomes 0,
    // the shared data object 'VehicleModelObject' is deleted.
}

int VehicleModel::id() const
{
    return d->id;
}

QString VehicleModel::name() const
{
    return d->name;
}

void VehicleModel::setName(const QString &name)
{
    d->name = name;
}

QString VehicleModel::logo() const
{
    return d->logo;
}

void VehicleModel::setLogo(const QString &logo)
{
    d->logo = logo;
}

QDateTime VehicleModel::createdAt() const
{
    return d->created_at;
}

QDateTime VehicleModel::updatedAt() const
{
    return d->updated_at;
}

VehicleModel &VehicleModel::operator=(const VehicleModel &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

VehicleModel VehicleModel::create(const QString &name, const QString &logo)
{
    VehicleModelObject obj;
    obj.name = name;
    obj.logo = logo;
    if (!obj.create()) {
        return VehicleModel();
    }
    return VehicleModel(obj);
}

VehicleModel VehicleModel::create(const QVariantMap &values)
{
    VehicleModel model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

VehicleModel VehicleModel::get(int id)
{
    TSqlORMapper<VehicleModelObject> mapper;
    return VehicleModel(mapper.findByPrimaryKey(id));
}

int VehicleModel::count()
{
    TSqlORMapper<VehicleModelObject> mapper;
    return mapper.findCount();
}

QList<VehicleModel> VehicleModel::getAll()
{
    return tfGetModelListByCriteria<VehicleModel, VehicleModelObject>(TCriteria());
}

QJsonArray VehicleModel::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<VehicleModelObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<VehicleModelObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(VehicleModel(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *VehicleModel::modelData()
{
    return d.data();
}

const TModelObject *VehicleModel::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const VehicleModel &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, VehicleModel &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(VehicleModel)
