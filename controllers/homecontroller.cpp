#include "homecontroller.h"
#include "vehicle.h"
#include "make.h"
#include "vehiclemodel.h"
#include "color.h"
#include "grade.h"
#include "drivetype.h"
#include "bodytype.h"
#include "fueltype.h"
#include "vehiclegallery.h"


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
 * makeId/modelId/bodyId/colorId/gradeId/fuelId/driveId
 */

void HomeController::search()
{

    QStringList makes = httpRequest().allQueryItemValues("make");
    QStringList models = httpRequest().allQueryItemValues("model");
    QStringList bodies = httpRequest().allQueryItemValues("body");
    QStringList colors = httpRequest().allQueryItemValues("color");
    QStringList grades = httpRequest().allQueryItemValues("grade");
    QStringList fuels = httpRequest().allQueryItemValues("fuel");
    QStringList drives = httpRequest().allQueryItemValues("drive");

    if((makes.size() == 0) || 
        (models.size() == 0) ||
        (bodies.size() == 0) ||
        (colors.size() == 0) ||
        (grades.size() == 0) ||
        (fuels.size() == 0) ||
        (drives.size() == 0)) {
        renderErrorResponse(Tf::NotFound);
    }

    tInfo("filter vehicles: make = %s, model = %s, body = %s, color = %s, grade = %s, fuel = %s, drive = %s",
     makes.at(0).toUtf8().constData(), models.at(0).toUtf8().constData(),
      bodies.at(0).toUtf8().constData(), colors.at(0).toUtf8().constData(), 
      grades.at(0).toUtf8().constData(), fuels.at(0).toUtf8().constData(),
      drives.at(0).toUtf8().constData());
    
    int make = makes.at(0).toInt();
    int model = models.at(0).toInt();
    int body = bodies.at(0).toInt();
    int color = colors.at(0).toInt();
    int grade = grades.at(0).toInt();
    int fuel = fuels.at(0).toInt();
    int drive = drives.at(0).toInt();

    auto vehicleList = Vehicle::search(make, model, body, color, grade, fuel, 
        drive);

    texport(make);
    texport(model);
    texport(body);
    texport(color);
    texport(grade);
    texport(fuel);
    texport(drive);

    exportForSelectBoxes();
    texport(vehicleList);
    
    render("index");
}

void HomeController::exportForSelectBoxes() {

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
}

void HomeController::detail(const QString &id) {
    
    Vehicle vehicle = Vehicle::get(id.toInt());
    if(vehicle.isNull()) {
        renderErrorResponse(Tf::NotFound);
    }

    QList<VehicleGallery> vehicleGalleryList = VehicleGallery::getAllByVehicle(id.toInt());
    
    texport(vehicle);
    texport(vehicleGalleryList);

    render("detail");
}

// Don't remove below this line
T_DEFINE_CONTROLLER(HomeController)
