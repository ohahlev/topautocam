#ifndef FUELTYPEVALIDATOR_H
#define FUELTYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT FuelTypeValidator : public TFormValidator
{
public:
    FuelTypeValidator();
};

Q_DECLARE_METATYPE(FuelTypeValidator)

#endif // FUELTYPEVALIDATOR_H
