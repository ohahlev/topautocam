#include "gradecontroller.h"
#include "grade.h"
#include "gradevalidator.h"

void GradeController::index()
{
    auto gradeList = Grade::getAll();
    texport(gradeList);
    render("index", "backend");
}

void GradeController::getCreate()
{
    render("create", "backend");
}

void GradeController::postCreate()
{
    QString notice;
    QString error;

    auto grade = httpRequest().formItems("grade");

    GradeValidator validator;
    if (!validator.validate(grade))
    {
        exportValidationErrors(validator);
        texport(grade);
        render("create", "backend");
        return;
    }

    auto model = Grade::create(grade);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(grade);
        render("create", "backend");
        return;
    }

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void GradeController::getSave(const QString &id)
{
    auto model = Grade::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto grade = model.toVariantMap();
    texport(grade);
    render("save", "backend");
}

void GradeController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = Grade::get(id.toInt());
    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/grade", "save", id));
        return;
    }

    auto grade = httpRequest().formItems("grade");

    GradeValidator validator;
    if (!validator.validate(grade))
    {
        exportValidationErrors(validator);
        texport(grade);
        render("save", "backend");
        return;
    }

    model.setProperties(grade);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(grade);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/grade", "save", id));
}

void GradeController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto grade = Grade::get(id.toInt());
    bool removed = grade.remove();

    QString notice;
    if(removed == true) {
    notice = "Removed successfully.";
    } else {
        notice = "Failed to remove.";
    }
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(GradeController)
