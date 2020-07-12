#ifndef VEHICLECONTROLLER_H
#define VEHICLECONTROLLER_H

#include "applicationcontroller.h"

#include "vehiclegallery.h"

class T_CONTROLLER_EXPORT VehicleController : public ApplicationController
{
    Q_OBJECT
public:
    VehicleController() : ApplicationController() {}

public slots:
    void index();
    void getCreate();
    void postCreate();
    void getSave(const QString &id);
    void postSave(const QString &id);
    void postRemove(const QString &id);
    void postUpload(const QString &id);
    void postRemovePhoto(const QString &id);

public:
    void exportParentList();
    void exportGallery(const int id);
    bool isPhotoDuplicate(const int &vehicleId, const QString &photo);
    void upload(const int &vehicleId);
};

#endif // VEHICLECONTROLLER_H
