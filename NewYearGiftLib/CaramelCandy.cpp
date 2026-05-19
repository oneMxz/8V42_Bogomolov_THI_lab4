#include "CaramelCandy.h"

CaramelCandy::CaramelCandy(const std::string& name, double weight,
                           const std::string& fillingType, bool hasWrapper,
                           const std::string& caramelType, bool hasSalt)
    : Candy(name, weight, fillingType, hasWrapper),
      _CaramelType(caramelType),
      _HasSalt(hasSalt) {}

std::string CaramelCandy::GetCaramelType() const {
    return _CaramelType;
}

bool CaramelCandy::HasSalt() const {
    return _HasSalt;
}