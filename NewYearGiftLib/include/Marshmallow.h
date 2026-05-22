
#pragma once
#include "AbstractSweet.h"
#include "Export.h"

class NEWYEAR_GIFT_API Marshmallow : public AbstractSweet {
private:
    std::string _CoatingType;   // шоколадная, глазурь, без покрытия
public:
    Marshmallow(const std::string& name, double weight,
                const std::string& coatingType);
    
    std::string GetCoatingType() const;
};