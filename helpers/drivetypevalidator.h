#ifndef DRIVETYPEVALIDATOR_H
#define DRIVETYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT DriveTypeValidator : public TFormValidator
{
public:
    DriveTypeValidator();
};

Q_DECLARE_METATYPE(DriveTypeValidator)

#endif // DRIVETYPEVALIDATOR_H
