#include "homecontroller.h"
#include "vehicle.h"
#include "make.h"
#include "vehiclemodel.h"
#include "color.h"
#include "grade.h"
#include "drivetype.h"
#include "bodytype.h"
#include "fueltype.h"

void HomeController::index()
{

    auto vehicleList = Vehicle::getAll();
    texport(vehicleList);

    auto makeList = Make::getAll();
    texport(makeList);

    auto modelList = VehicleModel::getAll();
    texport(modelList);

    auto bodyTypeList = BodyType::getAll();
    texport(bodyTypeList);

    auto driveTypeList = DriveType::getAll();
    texport(driveTypeList);

    auto colorList = Color::getAll();
    texport(colorList);

    auto gradeList = Grade::getAll();
    texport(gradeList);

    auto fuelTypeList = FuelType::getAll();
    texport(fuelTypeList);

    render("index");
}

/**
 * makeId/modelId/bodyId/driveId/colorId/gradeId/fuelId
 */

void HomeController::search(const QString &makeId, const QString &modelId, const QString &bodyId,
                            const QString &driveId, const QString &colorId, const QString &gradeId,
                            const QString &fuelId)
{

    tInfo("make id = %s, model id = %s, body id = %s, drive id = %s, color id = %s, grade id = %s, fuel id = %s",
          makeId.toUtf8().constData(), modelId.toUtf8().constData(), bodyId.toUtf8().constData(),
          driveId.toUtf8().constData(), colorId.toUtf8().constData(), gradeId.toUtf8().constData(),
          fuelId.toUtf8().constData());

    auto vehicleList = Vehicle::search(makeId.toInt(), modelId.toInt(), bodyId.toInt(),
                                       driveId.toInt(), colorId.toInt(), gradeId.toInt(),
                                       fuelId.toInt());
    texport(vehicleList);

    render("index");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(HomeController)
