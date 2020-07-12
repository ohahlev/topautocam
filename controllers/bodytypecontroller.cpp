#include "bodytypecontroller.h"
#include "bodytype.h"
#include "bodytypevalidator.h"

void BodyTypeController::index()
{
    auto bodyTypeList = BodyType::getAll();
    texport(bodyTypeList);
    render("index", "backend");
}

void BodyTypeController::getCreate()
{
    render("create", "backend");
}

void BodyTypeController::postCreate()
{
    QString notice;
    QString error;

    auto bodyType = httpRequest().formItems("bodyType");

    BodyTypeValidator validator;
    if (!validator.validate(bodyType))
    {
        exportValidationErrors(validator);
        texport(bodyType);
        render("create", "backend");
        return;
    }

    auto model = BodyType::create(bodyType);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(bodyType);
        render("create", "backend");
        return;
    }

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void BodyTypeController::getSave(const QString &id)
{
    auto model = BodyType::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto bodyType = model.toVariantMap();
    texport(bodyType);
    render("save", "backend");
}

void BodyTypeController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = BodyType::get(id.toInt());
    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/body", "save", id));
        return;
    }

    auto bodyType = httpRequest().formItems("bodyType");

    BodyTypeValidator validator;
    if (!validator.validate(bodyType))
    {
        exportValidationErrors(validator);
        texport(bodyType);
        render("save", "backend");
        return;
    }

    model.setProperties(bodyType);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(bodyType);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/body", "save", id));
}

void BodyTypeController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto bodyType = BodyType::get(id.toInt());
    bool removed = bodyType.remove();

    QString notice;
    if(removed == true) {
      notice = "Removed successfully.";
    } else {
        notice = "Failed to remove.";
    }
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(BodyTypeController)
