#ifndef DRIVETYPECONTROLLER_H
#define DRIVETYPECONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT DriveTypeController : public BackendController
{
    Q_OBJECT
public:
    DriveTypeController() : BackendController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // DRIVETYPECONTROLLER_H
