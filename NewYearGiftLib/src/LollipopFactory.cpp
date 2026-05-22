#include "LollipopFactory.h"

LollipopFactory::LollipopFactory(const std::string& flavor, bool onStick)
    : _flavor(flavor), _onStick(onStick) {}

AbstractSweet* LollipopFactory::createSweet(const std::string& name, double weight) {
    return new Lollipop(name, weight, _flavor, _onStick);
}