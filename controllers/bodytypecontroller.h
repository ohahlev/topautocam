#ifndef BODYTYPECONTROLLER_H
#define BODYTYPECONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT BodyTypeController : public BackendController
{
    Q_OBJECT
public:
    BodyTypeController() : BackendController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // BODYTYPECONTROLLER_H
