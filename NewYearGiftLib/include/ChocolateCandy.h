#pragma once
#include "Candy.h"
#include "Export.h"

class NEWYEAR_GIFT_API ChocolateCandy : public Candy {
private:
    int _CocoaPercentage;       // процент какао (0-100)
    std::string _ChocolateType;  // молочный, горький, белый

public:
    ChocolateCandy(const std::string& name, double weight,
                   const std::string& fillingType, bool hasWrapper,
                   int cocoaPercentage, const std::string& chocolateType);
    
    int GetCocoaPercentage() const;
    std::string GetChocolateType() const;
};