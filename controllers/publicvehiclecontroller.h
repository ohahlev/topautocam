#ifndef PUBLICVEHICLECONTROLLER_H
#define PUBLICVEHICLECONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT PublicvehicleController : public ApplicationController
{
    Q_OBJECT
public:
    PublicvehicleController() : ApplicationController() {}

public slots:
    void index();
};

#endif // PUBLICVEHICLECONTROLLER_H
