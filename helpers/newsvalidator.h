#ifndef NEWSVALIDATOR_H
#define NEWSVALIDATOR_H

#include <TGlobal>
#include <TFormValidator>

class T_HELPER_EXPORT NewsValidator : public TFormValidator
{
public:
    NewsValidator();
};

Q_DECLARE_METATYPE(NewsValidator)

#endif // NEWSVALIDATOR_H
