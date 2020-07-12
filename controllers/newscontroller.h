#ifndef NEWSCONTROLLER_H
#define NEWSCONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT NewsController : public ApplicationController
{
    Q_OBJECT
public:
    NewsController() : ApplicationController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // NEWSCONTROLLER_H
