#pragma once
#include "SweetFactory.h"
#include "Marshmallow.h"

class MarshmallowFactory : public SweetFactory {
private:
    std::string _coatingType;   // тип покрытия

public:
    MarshmallowFactory(const std::string& coatingType);
    
    AbstractSweet* createSweet(const std::string& name, double weight) override;
};