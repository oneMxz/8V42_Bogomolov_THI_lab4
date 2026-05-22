#include "Lollipop.h"

Lollipop::Lollipop(const std::string& name, double weight,
                   const std::string& flavor, bool onStick)
    : AbstractSweet(name, weight), _Flavor(flavor), _OnStick(onStick) {}

std::string Lollipop::GetFlavor() const {
    return _Flavor;
}

bool Lollipop::IsOnStick() const {
    return _OnStick;
}