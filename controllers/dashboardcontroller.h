#ifndef DASHBOARDCONTROLLER_H
#define DASHBOARDCONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT DashboardController : public BackendController
{
    Q_OBJECT
public:
    DashboardController() : BackendController() {}

public slots:
    void index();
};

#endif // DASHBOARDCONTROLLER_H
