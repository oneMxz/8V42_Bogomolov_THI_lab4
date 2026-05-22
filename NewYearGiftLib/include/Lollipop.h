#pragma once
#include "AbstractSweet.h"
#include "Export.h"

class NEWYEAR_GIFT_API 
Lollipop : public AbstractSweet {
private:
    std::string _Flavor;   // вкус: клубника, лимон, мята, корица
    bool _OnStick;         // на палочке или нет

public:
    Lollipop(const std::string& name, double weight,
             const std::string& flavor, bool onStick);
    
    std::string GetFlavor() const;
    bool IsOnStick() const;
};