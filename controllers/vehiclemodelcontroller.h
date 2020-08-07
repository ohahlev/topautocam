#ifndef VEHICLEMODELCONTROLLER_H
#define VEHICLEMODELCONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT VehicleModelController : public BackendController
{
    Q_OBJECT
public:
    VehicleModelController() : BackendController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // VEHICLEMODELCONTROLLER_H
