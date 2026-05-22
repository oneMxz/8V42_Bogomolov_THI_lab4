#include "ChocolateCandyFactory.h"

ChocolateCandyFactory::ChocolateCandyFactory(const std::string& fillingType, bool hasWrapper,
                                             int cocoaPercentage, const std::string& chocolateType)
    : _fillingType(fillingType)
    , _hasWrapper(hasWrapper)
    , _cocoaPercentage(cocoaPercentage)
    , _chocolateType(chocolateType) {}

AbstractSweet* ChocolateCandyFactory::createSweet(const std::string& name, double weight) {
    // Создаём и возвращаем объект ChocolateCandy,
    // используя переданные имя/вес и сохранённые в фабрике параметры
    return new ChocolateCandy(name, weight, _fillingType, _hasWrapper,
                              _cocoaPercentage, _chocolateType);
}