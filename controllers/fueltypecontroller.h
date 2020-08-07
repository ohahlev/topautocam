#ifndef FUELTYPECONTROLLER_H
#define FUELTYPECONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT FuelTypeController : public BackendController
{
    Q_OBJECT
public:
    FuelTypeController() : BackendController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // FUELTYPECONTROLLER_H
