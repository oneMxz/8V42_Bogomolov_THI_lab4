#pragma once
#include <string>
#include "Export.h"

class NEWYEAR_GIFT_API AbstractSweet {
protected:
    std::string _Name;
    double _Weight;         // вес в граммах
    
public:
    AbstractSweet(const std::string& name, double weight);
    virtual ~AbstractSweet() = 0;   // чисто виртуальный -> абстрактный класс

    std::string GetName() const;
    double GetWeight() const;
};