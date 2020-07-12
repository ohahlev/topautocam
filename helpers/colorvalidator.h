#ifndef COLORVALIDATOR_H
#define COLORVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT ColorValidator : public TFormValidator
{
public:
    ColorValidator();
};

Q_DECLARE_METATYPE(ColorValidator)

#endif // COLORVALIDATOR_H
