#include "vehiclevalidator.h"

VehicleValidator::VehicleValidator() : TFormValidator()
{
    setRule("title", Tf::Required, true, "title is required");
    setRule("title", Tf::MaxLength, 32, "title max length is 32");

    setRule("detail", Tf::Required, true, "detail is required");
    setRule("detail", Tf::MaxLength, 10240, "detail max length is 10240");

    setRule("manufacturingDate", Tf::Required, true, "manufacturing date is required");
    setRule("depositDate", Tf::Required, true, "deposit date is required");

    setRule("vehicleStatus", Tf::Required, true, "vehicle status is required");
    setRule("inventoryStatus", Tf::Required, true, "inventory status is required");

    setRule("frameNo", Tf::Required, true, "frame number is required");
    setRule("frameNo", Tf::MaxLength, 64, "frame number max length is 64");

    setRule("engine", Tf::Required, true, "engine is require");
    setRule("engine", Tf::MaxLength, 32, "engine max length is 32");

    setRule("mileage", Tf::Required, true, "mileage is required");
    setRule("mileage", Tf::MaxLength, 32, "mileage max length is 32");
}
