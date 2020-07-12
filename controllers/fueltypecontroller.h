#ifndef FUELTYPECONTROLLER_H
#define FUELTYPECONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT FuelTypeController : public ApplicationController
{
    Q_OBJECT
public:
    FuelTypeController() : ApplicationController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // FUELTYPECONTROLLER_H
