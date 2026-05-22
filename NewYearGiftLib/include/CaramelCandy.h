#pragma once
#include "Candy.h"
#include "Export.h"

class NEWYEAR_GIFT_API CaramelCandy : public Candy {
private:
    std::string _CaramelType;   // мягкая, тягучая, твёрдая, солёная
    bool _HasSalt;              // солёная карамель или нет
public:
    CaramelCandy(const std::string& name, double weight, 
                 const std::string& fillingType, bool hasWrapper,
                 const std::string& caramelType, bool hasSalt);
    
    std::string GetCaramelType() const;
    bool HasSalt() const;

};