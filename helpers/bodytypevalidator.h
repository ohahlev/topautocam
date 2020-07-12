#ifndef BODYTYPEVALIDATOR_H
#define BODYTYPEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT BodyTypeValidator : public TFormValidator
{
public:
    BodyTypeValidator();
};

Q_DECLARE_METATYPE(BodyTypeValidator)

#endif // BODYTYPEVALIDATOR_H
