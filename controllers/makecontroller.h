#ifndef MAKECONTROLLER_H
#define MAKECONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT MakeController : public BackendController
{
    Q_OBJECT
public:
    MakeController() : BackendController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // MAKECONTROLLER_H
