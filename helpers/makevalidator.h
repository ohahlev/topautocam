#ifndef MAKEVALIDATOR_H
#define MAKEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT MakeValidator : public TFormValidator
{
public:
    MakeValidator();
};

Q_DECLARE_METATYPE(MakeValidator)

#endif // MAKEVALIDATOR_H
