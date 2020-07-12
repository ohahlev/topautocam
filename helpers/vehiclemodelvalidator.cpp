#include "vehiclemodelvalidator.h"

VehicleModelValidator::VehicleModelValidator() : TFormValidator()
{
    setRule("name", Tf::Required, true, "name is required");
    setRule("name", Tf::MaxLength, 32, "name max length is 32");
    setRule("logo", Tf::Required, true, "logo is required");
}
