#include "newsgallerycontroller.h"
#include "newsgallery.h"

void NewsGalleryController::index()
{
    auto newsGalleryList = NewsGallery::getAll();
    texport(newsGalleryList);
    render("index", "backend");
}

void NewsGalleryController::postUpload()
{
    //tInfo("%s", "postUpload...");

    QList<TMimeEntity> lst = httpRequest().multipartFormData().entityList("picture[]");
    //tInfo("number of file upload = %d", lst.length());
    for (QListIterator<TMimeEntity> it(lst); it.hasNext();)
    {
        TMimeEntity e = it.next();
        QString origName = e.originalFileName(); // original name
        QString under = "media/news";
        QString newName = QString("public/%1/%2").arg(under, origName);
        tInfo("%s", newName.toLatin1().data());
        e.renameUploadedFile(newName); // rename file

        QVariantMap picture;
        picture["image"] = QString("/%1/%2").arg(under, origName);
        picture["status"] = "PUBLISHED";
        auto model = NewsGallery::create(picture);
        if (model.isNull())
        {
            QString notice = QString("can not save image = %1 into database").arg(newName);
            tflash(notice);
            redirect(urla("index"));
            break;
        }
    }

    /*
    TMultipartFormData &formdata = httpRequest().multipartFormData();
    QString origName = formdata.originalFileName("picture");
    QString newName = QString("%1/%2").arg("public/media/news", origName);
    tInfo("%s", newName.toLatin1().data());
    formdata.renameUploadedFile("picture", newName);
    */

    QString notice = "Upload files successfully";
    tflash(notice);
    redirect(urla("index"));
}

void NewsGalleryController::postRemove(const QString &id)
{
    if (httpRequest().method() != Tf::Post)
    {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto newsGallery = NewsGallery::get(id.toInt());
    newsGallery.remove();

    QString notice = "Removed successfully.";
    tflash(notice);
    redirect(urla("index"));
}

// Don't remove below this line
T_DEFINE_CONTROLLER(NewsGalleryController)
