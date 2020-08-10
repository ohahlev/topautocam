#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include "applicationcontroller.h"

class T_CONTROLLER_EXPORT HomeController : public ApplicationController
{
    Q_OBJECT
public:
    HomeController() : ApplicationController() {}

public slots:
    void index();

    //makeId=:param&modelId=:param&bodyId=:param&driveId=:param&colorId=:param&gradeId=:param&fuelId=:param
    void search(const QString &makeId, const QString &modelId, const QString &bodyId,
                const QString &driveId, const QString &colorId, const QString &gradeId,
                const QString &fuelId);
};

#endif // HOMECONTROLLER_H
