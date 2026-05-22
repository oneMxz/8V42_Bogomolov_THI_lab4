#include "Marshmallow.h"

Marshmallow::Marshmallow(const std::string& name, double weight,
                         const std::string& coatingType)
    : AbstractSweet(name, weight), _CoatingType(coatingType) {}

std::string Marshmallow::GetCoatingType() const {
    return _CoatingType;
}