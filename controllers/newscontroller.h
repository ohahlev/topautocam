#ifndef NEWSCONTROLLER_H
#define NEWSCONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT NewsController : public BackendController
{
    Q_OBJECT
public:
    NewsController() : BackendController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // NEWSCONTROLLER_H
