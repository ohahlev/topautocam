#ifndef VEHICLEMODELVALIDATOR_H
#define VEHICLEMODELVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT VehicleModelValidator : public TFormValidator
{
public:
    VehicleModelValidator();
};

Q_DECLARE_METATYPE(VehicleModelValidator)

#endif // VEHICLEMODELVALIDATOR_H
