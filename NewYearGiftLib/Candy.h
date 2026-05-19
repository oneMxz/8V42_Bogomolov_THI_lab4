#pragma once
#include "AbstractSweet.h"

class Candy : public AbstractSweet {
protected:
    std::string _FillingType;
    bool _HasWrapper;// есть ли обёртка

public:
    Candy(const std::string& name, double weight,
          const std::string& fillingType, bool hasWrapper);
    
    std::string GetFillingType() const;
    bool HasWrapper() const;
};