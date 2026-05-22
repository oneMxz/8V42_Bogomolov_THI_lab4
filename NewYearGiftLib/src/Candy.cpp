#include "Candy.h"

Candy::Candy(const std::string& name, double weight,
             const std::string& fillingType, bool hasWrapper)
    : AbstractSweet(name, weight),
      _FillingType(fillingType),
      _HasWrapper(hasWrapper) {}

std::string Candy::GetFillingType() const {
    return _FillingType;
}

bool Candy::HasWrapper() const {
    return _HasWrapper;
}