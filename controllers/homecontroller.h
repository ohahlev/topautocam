#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT HomeController : public ApplicationController
{
    Q_OBJECT
public:
    HomeController() : ApplicationController() {}

private:
    void exportForSelectBoxes();

public slots:
    void index();
    void search();
    void detail(const QString &vehicleId);
};

#endif // HOMECONTROLLER_H
