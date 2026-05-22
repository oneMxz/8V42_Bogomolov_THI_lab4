#include "ChocolateCandy.h"

ChocolateCandy::ChocolateCandy(const std::string& name, double weight,
                               const std::string& fillingType, bool hasWrapper,
                               int cocoaPercentage, const std::string& chocolateType)
    : Candy(name, weight, fillingType, hasWrapper),
      _CocoaPercentage(cocoaPercentage),
      _ChocolateType(chocolateType) {}

int ChocolateCandy::GetCocoaPercentage() const {
    return _CocoaPercentage;
}

std::string ChocolateCandy::GetChocolateType() const {
    return _ChocolateType;
}