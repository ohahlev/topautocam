#ifndef NEWSGALLERYCONTROLLER_H
#define NEWSGALLERYCONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT NewsGalleryController : public BackendController
{
    Q_OBJECT
public:
    NewsGalleryController() : BackendController() {}

public slots:
    void index();
    void postUpload();
    void postRemove(const QString &id);
};

#endif // NEWSGALLERYCONTROLLER_H
