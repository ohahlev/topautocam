#ifndef VEHICLEVALIDATOR_H
#define VEHICLEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT VehicleValidator : public TFormValidator
{
public:
    VehicleValidator();
};

Q_DECLARE_METATYPE(VehicleValidator)

#endif // VEHICLEVALIDATOR_H
