#ifndef DASHBOARDCONTROLLER_H
#define DASHBOARDCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT DashboardController : public ApplicationController
{
    Q_OBJECT
public:
    DashboardController() : ApplicationController() { }

public slots:
    void index();
    bool preFilter();
};

#endif // DASHBOARDCONTROLLER_H
