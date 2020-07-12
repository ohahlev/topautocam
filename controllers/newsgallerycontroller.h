#ifndef NEWSGALLERYCONTROLLER_H
#define NEWSGALLERYCONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT NewsGalleryController : public ApplicationController
{
    Q_OBJECT
public:
    NewsGalleryController() : ApplicationController() {}

public slots:
    void index();
    void postUpload();
    void postRemove(const QString &id);
};

#endif // NEWSGALLERYCONTROLLER_H
