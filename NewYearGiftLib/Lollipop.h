#pragma once
#include "AbstractSweet.h"

class Lollipop : public AbstractSweet {
private:
    std::string _Flavor;   // вкус: клубника, лимон, мята, корица
    bool _OnStick;         // на палочке или нет

public:
    Lollipop(const std::string& name, double weight,
             const std::string& flavor, bool onStick);
    
    std::string GetFlavor() const;
    bool IsOnStick() const;
};