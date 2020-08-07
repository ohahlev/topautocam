#ifndef BACKENDCONTROLLER_H
#define BACKENDCONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT BackendController : public ApplicationController
{
    Q_OBJECT
public:
    BackendController() : ApplicationController() {}

public slots:
    void index();
    bool preFilter();
};

#endif // BACKENDCONTROLLER_H
