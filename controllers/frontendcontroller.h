#ifndef FRONTENDCONTROLLER_H
#define FRONTENDCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT FrontendController : public ApplicationController
{
    Q_OBJECT
public:
    FrontendController() : ApplicationController() { }

public slots:
    void index();
};

#endif // FRONTENDCONTROLLER_H
