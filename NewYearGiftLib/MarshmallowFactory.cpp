#include "MarshmallowFactory.h"

MarshmallowFactory::MarshmallowFactory(const std::string& coatingType)
    : _coatingType(coatingType) {}

AbstractSweet* MarshmallowFactory::createSweet(const std::string& name, double weight) {
    return new Marshmallow(name, weight, _coatingType);
}