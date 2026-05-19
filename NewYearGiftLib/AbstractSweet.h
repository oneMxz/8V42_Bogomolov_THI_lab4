#pragma once
#include <string>

class AbstractSweet {
protected:
    std::string _Name;
    double _Weight;         // вес в граммах
    
public:
    AbstractSweet(const std::string& name, double weight);
    virtual ~AbstractSweet() = 0;   // чисто виртуальный -> абстрактный класс

    std::string GetName() const;
    double GetWeight() const;
};