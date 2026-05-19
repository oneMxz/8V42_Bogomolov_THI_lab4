#pragma once
#include "ChocolateCandy.h"
#include "SweetFactory.h"

class ChocolateCandyFactory : public SweetFactory{
private:
    std::string _fillingType;
    bool _hasWrapper;
    int _cocoaPercentage;
    std::string _chocolateType;

public:
    ChocolateCandyFactory(const std::string& fillingType, bool hasWrapper, int cocoaPercentage, const std::string& chocolateType);
    AbstractSweet* createSweet(const std::string& name, double weight) override;
};