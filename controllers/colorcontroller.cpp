#include "colorcontroller.h"
#include "color.h"
#include "colorvalidator.h"

void ColorController::index()
{
    auto colorList = Color::getAll();
    texport(colorList);
    render("index", "backend");
}

void ColorController::getCreate()
{
    render("create", "backend");
}

void ColorController::postCreate()
{
    QString notice;
    QString error;

    auto color = httpRequest().formItems("color");

    ColorValidator validator;
    if (!validator.validate(color))
    {
        exportValidationErrors(validator);
        texport(color);
        render("create", "backend");
        return;
    }

    auto model = Color::create(color);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(color);
        render("create", "backend");
        return;
    }

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void ColorController::getSave(const QString &id)
{
    auto model = Color::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto color = model.toVariantMap();
    texport(color);
    render("save", "backend");
}

void ColorController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = Color::get(id.toInt());
    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/color", "save", id));
        return;
    }

    auto color = httpRequest().formItems("color");

    ColorValidator validator;
    if (!validator.validate(color))
    {
        exportValidationErrors(validator);
        texport(color);
        render("save", "backend");
        return;
    }

    model.setProperties(color);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(color);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/color", "save", id));
}

void ColorController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto color = Color::get(id.toInt());
    bool removed = color.remove();

    QString notice;
    if(removed == true) {
      notice = "Removed successfully.";
    } else {
        notice = "Failed to remove.";
    }
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ColorController)
