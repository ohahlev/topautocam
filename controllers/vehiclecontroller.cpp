#include "vehiclecontroller.h"
#include "vehicle.h"
#include "vehiclevalidator.h"
#include "make.h"
#include "vehiclemodel.h"
#include "drivetype.h"
#include "bodytype.h"
#include "color.h"
#include "grade.h"
#include "fueltype.h"
#include "vehiclegallery.h"
#include <QFileInfo>

void VehicleController::exportParentList()
{
    auto makeList = Make::getAll();
    auto modelList = VehicleModel::getAll();
    auto bodyList = BodyType::getAll();
    auto driveList = DriveType::getAll();
    auto colorList = Color::getAll();
    auto fuelList = FuelType::getAll();
    auto gradeList = Grade::getAll();

    texport(makeList);
    texport(modelList);
    texport(bodyList);
    texport(driveList);
    texport(colorList);
    texport(fuelList);
    texport(gradeList);
}

void VehicleController::exportGallery(const int id)
{
    auto vehicleGallery = VehicleGallery::getAllByVehicle(id);
    texport(vehicleGallery);
}

void VehicleController::index()
{
    auto vehicleList = Vehicle::getAll();
    texport(vehicleList);
    render("index", "backend");
}

void VehicleController::getCreate()
{
    exportParentList();
    render("create", "backend");
}

void VehicleController::postCreate()
{
    QString notice;
    QString error;

    auto vehicle = httpRequest().formItems("vehicle");

    VehicleValidator validator;
    if (!validator.validate(vehicle))
    {
        exportParentList();
        exportValidationErrors(validator);
        texport(vehicle);
        render("create", "backend");
        return;
    }

    //qDebug() << QVariant(QVariantList{QVariant(vehicle)});

    Vehicle model = Vehicle::create(vehicle);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(vehicle);
        render("create", "backend");
        return;
    }

    upload(model.id());

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void VehicleController::getSave(const QString &id)
{
    auto model = Vehicle::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    exportParentList();
    exportGallery(id.toInt());

    auto vehicle = model.toVariantMap();
    texport(vehicle);
    render("save", "backend");
}

void VehicleController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = Vehicle::get(id.toInt());
    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/vehicle", "save", id));
        return;
    }

    auto vehicle = httpRequest().formItems("vehicle");

    VehicleValidator validator;
    if (!validator.validate(vehicle))
    {
        exportParentList();
        exportValidationErrors(validator);
        texport(vehicle);
        render("save", "backend");
        return;
    }

    model.setProperties(vehicle);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(vehicle);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/vehicle", "save", id));
}

void VehicleController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto vehicle = Vehicle::get(id.toInt());
    vehicle.remove();
    
    QString notice = "Removed successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void VehicleController::postRemovePhoto(const QString &id) {
    
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }
    auto vehicleGallery = VehicleGallery::get(id.toInt());
    vehicleGallery.remove();
    QString notice = QString("vehicle image = %1 is removed").arg(vehicleGallery.photo());
    tflash(notice);
    redirect(url("admin/vehicle", "save", vehicleGallery.vehicleId()));
}

bool VehicleController::isPhotoDuplicate(const int &vehicleId, const QString &photo) {
    
    qDebug() << " vehicle id = " <<  vehicleId <<  "photo = " << photo;

    QList<VehicleGallery> vehicleGalleryList = VehicleGallery::getAllByVehicle(vehicleId);

    qDebug() << vehicleGalleryList.count();

    for(int i = 0; i < vehicleGalleryList.count(); i++) {
        VehicleGallery vg = vehicleGalleryList.at(i);
        QString bareName = vg.photo().right(vg.photo().length() - vg.photo().lastIndexOf("/") - 1);
        //qDebug() << " bareName = " <<  bareName <<  "photo = " << photo;
        if(QString::compare(bareName, photo, Qt::CaseInsensitive) == 0) {
            //qDebug() << "found it" << vg.photo();
            return true;
        }
    }
    return false;
}

void VehicleController::upload(const int &vehicleId) {

    QList<TMimeEntity> lst = httpRequest().multipartFormData().entityList("picture[]");
    //tInfo("number of file upload = %d", lst.length());
    for (QListIterator<TMimeEntity> it(lst); it.hasNext();)
    {
        TMimeEntity e = it.next();
        QString origName = e.originalFileName(); // original name
        QString under = QString("media/vehicle/%1").arg(vehicleId);

        QString newName = QString("public/%1/%2").arg(under, origName);
        
        QDir dir(QString("public/%1").arg(under));
        if (!dir.exists())
            dir.mkpath(".");

        if(isPhotoDuplicate(vehicleId, origName)) {
            QString notice = QString("vehicle image file = %1 already exists").arg(origName);
            tflash(notice);
            redirect(url("admin/vehicle", "save", vehicleId));
            return;
        }

        e.renameUploadedFile(newName); // rename file

        QVariantMap picture;
        QString newNameForDb = QString("/%1/%2").arg(under, origName);
        picture["photo"] = newNameForDb;
        picture["vehicleId"] = vehicleId;
        auto model = VehicleGallery::create(picture);
        if (model.isNull())
        {
            QString notice = QString("can not save image = %1 into database").arg(newNameForDb);
            tflash(notice);
            redirect(url("admin/vehicle", "save", vehicleId));
            return;
        }
    }

} 

void VehicleController::postUpload(const QString &id)
{

    Vehicle vehicle = Vehicle::get(id.toInt());
    if(vehicle.isNull()) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    upload(id.toInt());

    QString notice = "Upload files successfully";
    tflash(notice);
    redirect(url("admin/vehicle", "save", id));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(VehicleController)
