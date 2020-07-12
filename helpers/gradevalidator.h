#ifndef GRADEVALIDATOR_H
#define GRADEVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT GradeValidator : public TFormValidator
{
public:
    GradeValidator();
};

Q_DECLARE_METATYPE(GradeValidator)

#endif // GRADEVALIDATOR_H
