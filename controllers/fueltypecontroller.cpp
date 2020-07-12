#include "fueltypecontroller.h"
#include "fueltype.h"
#include "fueltypevalidator.h"

void FuelTypeController::index()
{
    auto fuelTypeList = FuelType::getAll();
    texport(fuelTypeList);
    render("index", "backend");
}

void FuelTypeController::getCreate()
{
    render("create", "backend");
}

void FuelTypeController::postCreate()
{
    QString notice;
    QString error;

    auto fuelType = httpRequest().formItems("fuelType");

    FuelTypeValidator validator;
    if (!validator.validate(fuelType))
    {
        exportValidationErrors(validator);
        texport(fuelType);
        render("create", "backend");
        return;
    }

    auto model = FuelType::create(fuelType);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(fuelType);
        render("create", "backend");
        return;
    }

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void FuelTypeController::getSave(const QString &id)
{
    auto model = FuelType::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto fuelType = model.toVariantMap();
    texport(fuelType);
    render("save", "backend");
}

void FuelTypeController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = FuelType::get(id.toInt());
    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/fuel", "save", id));
        return;
    }

    auto fuelType = httpRequest().formItems("fuelType");

    FuelTypeValidator validator;
    if (!validator.validate(fuelType))
    {
        exportValidationErrors(validator);
        texport(fuelType);
        render("save", "backend");
        return;
    }

    model.setProperties(fuelType);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(fuelType);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/fuel", "save", id));
}

void FuelTypeController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto fuelType = FuelType::get(id.toInt());
    bool removed = fuelType.remove();

    QString notice;
    if(removed == true) {
      notice = "Removed successfully.";
    } else {
        notice = "Failed to remove.";
    }
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(FuelTypeController)
