#include "vehiclemodelcontroller.h"
#include "vehiclemodel.h"
#include "vehiclemodelvalidator.h"

void VehicleModelController::index()
{
    auto vehicleModelList = VehicleModel::getAll();
    texport(vehicleModelList);
    render("index", "backend");
}

void VehicleModelController::getCreate()
{
    render("create", "backend");
}

void VehicleModelController::postCreate()
{
    QString notice;
    QString error;

    auto vehicleModel = httpRequest().formItems("vehicleModel");

    // check validation
    VehicleModelValidator validator;
    if (!validator.validate(vehicleModel))
    {
        exportValidationErrors(validator);
        texport(vehicleModel);
        render("create", "backend");
        return;
    }

    TMultipartFormData &formdata = httpRequest().multipartFormData();
    QString origName = formdata.originalFileName("logo");
    QString under = "media/model";
    QString newName = QString("public/%1/%2").arg(under, origName);
    //tInfo("%s", newName.toLatin1().data());
    formdata.renameUploadedFile("logo", newName);

    vehicleModel["logo"] = QString("/%1/%2").arg(under, origName);

    auto model = VehicleModel::create(vehicleModel);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(vehicleModel);
        render("create", "backend");
        return;
    }

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void VehicleModelController::getSave(const QString &id)
{
    auto model = VehicleModel::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto vehicleModel = model.toVariantMap();
    texport(vehicleModel);
    render("save", "backend");
}

void VehicleModelController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = VehicleModel::get(id.toInt());

    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/model", "save", id));
        return;
    }

    auto vehicleModel = httpRequest().formItems("vehicleModel");
    VehicleModelValidator validator;
    if (!validator.validate(vehicleModel))
    {
        exportValidationErrors(validator);
        vehicleModel["logo"] = model.logo();
        texport(vehicleModel);
        render("save", "backend");
        return;
    }

    if (vehicleModel["logo"] != model.logo())
    {
        TMultipartFormData &formdata = httpRequest().multipartFormData();
        QString origName = formdata.originalFileName("logo");
        QString under = "media/model";
        QString newName = QString("public/%1/%2").arg(under, origName);
        //tInfo("%s", newName.toLatin1().data());
        formdata.renameUploadedFile("logo", newName);

        vehicleModel["logo"] = QString("/%1/%2").arg(under, origName);
    }

    model.setProperties(vehicleModel);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(vehicleModel);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/model", "save", id));
}

void VehicleModelController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto vehicleModel = VehicleModel::get(id.toInt());
    bool removed = vehicleModel.remove();

    QString notice;
    if (removed == true)
    {
        notice = "Removed successfully.";
    }
    else
    {
        notice = "Failed to remove.";
    }
    tflash(notice);
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(VehicleModelController)
