#ifndef GRADECONTROLLER_H
#define GRADECONTROLLER_H

#include "backendcontroller.h"

class T_CONTROLLER_EXPORT GradeController : public BackendController
{
    Q_OBJECT
public:
    GradeController() : BackendController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
};

#endif // GRADECONTROLLER_H
