#include "drivetypecontroller.h"
#include "drivetype.h"
#include "drivetypevalidator.h"

void DriveTypeController::index()
{
    auto driveTypeList = DriveType::getAll();
    texport(driveTypeList);
    render("index", "backend");
}

void DriveTypeController::getCreate()
{
    render("create", "backend");
}

void DriveTypeController::postCreate()
{
    QString notice;
    QString error;

    auto driveType = httpRequest().formItems("driveType");

    DriveTypeValidator validator;
    if (!validator.validate(driveType))
    {
        exportValidationErrors(validator);
        texport(driveType);
        render("create", "backend");
        return;
    }

    auto model = DriveType::create(driveType);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(driveType);
        render("create", "backend");
        return;
    }

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void DriveTypeController::getSave(const QString &id)
{
    auto model = DriveType::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto driveType = model.toVariantMap();
    texport(driveType);
    render("save", "backend");
}

void DriveTypeController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = DriveType::get(id.toInt());
    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/drive", "save", id));
        return;
    }

    auto driveType = httpRequest().formItems("driveType");

    DriveTypeValidator validator;
    if (!validator.validate(driveType))
    {
        exportValidationErrors(validator);
        texport(driveType);
        render("save", "backend");
        return;
    }

    model.setProperties(driveType);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(driveType);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/drive", "save", id));
}

void DriveTypeController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto driveType = DriveType::get(id.toInt());
    bool removed = driveType.remove();

    QString notice;
    if(removed == true) {
      notice = "Removed successfully.";
    } else {
        notice = "Failed to remove.";
    }
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(DriveTypeController)
