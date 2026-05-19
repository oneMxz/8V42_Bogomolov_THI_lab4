#pragma once
#include "SweetFactory.h"
#include "Lollipop.h"

class LollipopFactory : public SweetFactory {
private:
    std::string _flavor;   // вкус
    bool _onStick;         // на палочке или нет

public:
    LollipopFactory(const std::string& flavor, bool onStick);
    
    AbstractSweet* createSweet(const std::string& name, double weight) override;
};