#pragma once
#include "SweetFactory.h"
#include "CaramelCandy.h"
#include "Export.h"


class NEWYEAR_GIFT_API CaramelCandyFactory : public SweetFactory {
private:
    std::string _fillingType;
    bool _hasWrapper;
    std::string _caramelType;   // мягкая, тягучая, твёрдая, солёная
    bool _hasSalt;

public:
    CaramelCandyFactory(const std::string& fillingType, bool hasWrapper, const std::string& caramelType, bool hasSalt);
    
    AbstractSweet* createSweet(const std::string& name, double weight) override;
};