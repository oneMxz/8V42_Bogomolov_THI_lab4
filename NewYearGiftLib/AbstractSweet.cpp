#include "AbstractSweet.h"

AbstractSweet::AbstractSweet(const std::string& name, double weight)
    : _Name(name), _Weight(weight) {}

AbstractSweet::~AbstractSweet() {}

std::string AbstractSweet::GetName() const {
    return _Name;
}

double AbstractSweet::GetWeight() const {
    return _Weight;
}
