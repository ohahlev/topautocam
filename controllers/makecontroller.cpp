#include "makecontroller.h"
#include "make.h"
#include "makevalidator.h"

void MakeController::index()
{
    auto makeList = Make::getAll();
    texport(makeList);
    render("index", "backend");
}

void MakeController::getCreate()
{
    render("create", "backend");
}

void MakeController::postCreate()
{
    QString notice;
    QString error;

    auto make = httpRequest().formItems("make");

    MakeValidator validator;
    if (!validator.validate(make))
    {
        exportValidationErrors(validator);
        texport(make);
        render("create", "backend");
        return;
    }

    TMultipartFormData &formdata = httpRequest().multipartFormData();
    QString origName = formdata.originalFileName("logo");
    QString under = "media/make";
    QString newName = QString("public/%1/%2").arg(under, origName);
    //tInfo("%s", newName.toLatin1().data());
    formdata.renameUploadedFile("logo", newName);

    make["logo"] = QString("/%1/%2").arg(under, origName);

    auto model = Make::create(make);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(make);
        render("create", "backend");
        return;
    }

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void MakeController::getSave(const QString &id)
{
    auto model = Make::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto make = model.toVariantMap();
    texport(make);
    render("save", "backend");
}

void MakeController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = Make::get(id.toInt());
    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/make", "save", id));
        return;
    }

    auto make = httpRequest().formItems("make");

    MakeValidator validator;
    if (!validator.validate(make))
    {
        exportValidationErrors(validator);
        make["logo"] = model.logo();
        texport(make);
        render("save", "backend");
        return;
    }

    //tInfo("%s vs %s", make["logo"].toString().toLatin1().data(), model.logo().toLatin1().data());
    if (make["logo"] != model.logo())
    {
        TMultipartFormData &formdata = httpRequest().multipartFormData();
        QString origName = formdata.originalFileName("logo");
        QString under = "media/make";
        QString newName = QString("public/%1/%2").arg(under, origName);
        //tInfo("%s", newName.toLatin1().data());
        formdata.renameUploadedFile("logo", newName);

        make["logo"] = QString("/%1/%2").arg(under, origName);
    }

    model.setProperties(make);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(make);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/make", "save", id));
}

void MakeController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto make = Make::get(id.toInt());
    bool removed = make.remove();

    QString notice;
    if(removed == true) {
      notice = "Removed successfully.";
    } else {
        notice = "Failed to remove.";
    }
    tflash(notice);
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(MakeController)
