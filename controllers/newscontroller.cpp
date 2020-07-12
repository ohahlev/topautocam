#include "newscontroller.h"
#include "news.h"
#include "newsvalidator.h"

void NewsController::index()
{
    auto newsList = News::getAll();
    texport(newsList);
    render("index", "backend");
}

void NewsController::getCreate()
{
    render("create", "backend");
}

void NewsController::postCreate()
{
    QString notice;
    QString error;

    auto news = httpRequest().formItems("news");

    // check validation
    NewsValidator validator;
    if (!validator.validate(news))
    {
        exportValidationErrors(validator);
        texport(news);
        render("create", "backend");
        return;
    }

    // check error from database
    auto model = News::create(news);
    if (model.isNull())
    {
        error = "Failed to create.";
        texport(error);
        texport(news);
        render("create", "backend");
        return;
    }

    notice = "Created successfully.";
    tflash(notice);
    redirect(urla("index"));
}

void NewsController::getSave(const QString &id)
{
    auto model = News::get(id.toInt());
    if (model.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto news = model.toVariantMap();
    texport(news);
    render("save", "backend");
}

void NewsController::postSave(const QString &id)
{
    QString notice;
    QString error;

    auto model = News::get(id.toInt());
    if (model.isNull())
    {
        notice = "Original data not found. It may have been updated/removed by another transaction.";
        tflash(notice);
        redirect(url("admin/headline", "save", id));
        return;
    }

    auto news = httpRequest().formItems("news");
    NewsValidator validator;
    if (!validator.validate(news))
    {
        exportValidationErrors(validator);
        texport(news);
        render("save", "backend");
        return;
    }

    model.setProperties(news);
    if (!model.save())
    {
        error = "Failed to update.";
        texport(error);
        texport(news);
        render("save", "backend");
        return;
    }

    notice = "Updated successfully.";
    tflash(notice);
    redirect(url("admin/headline", "save", id));
}

void NewsController::postRemove(const QString &id)
{
    auto news = News::get(id.toInt());
    if (news.isNull())
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    news.remove();

    QString notice = "Removed successfully.";
    tflash(notice);
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(NewsController)
