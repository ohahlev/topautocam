#ifndef COLORCONTROLLER_H
#define COLORCONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT ColorController : public ApplicationController
{
    Q_OBJECT
public:
    ColorController() : ApplicationController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // COLORCONTROLLER_H
