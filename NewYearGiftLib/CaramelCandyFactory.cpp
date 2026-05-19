#include "CaramelCandyFactory.h"

CaramelCandyFactory::CaramelCandyFactory(const std::string& fillingType, bool hasWrapper,
                                         const std::string& caramelType, bool hasSalt)
    : _fillingType(fillingType)
    , _hasWrapper(hasWrapper)
    , _caramelType(caramelType)
    , _hasSalt(hasSalt) {}

AbstractSweet* CaramelCandyFactory::createSweet(const std::string& name, double weight) {
    return new CaramelCandy(name, weight, _fillingType, _hasWrapper,
                            _caramelType, _hasSalt);
}