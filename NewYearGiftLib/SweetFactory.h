#pragma once
#include <string>
#include "AbstractSweet.h"

// Абстрактная фабрика для создания сладостей
class SweetFactory {
public:
    // Виртуальный деструктор обязателен для полиморфного удаления
    virtual ~SweetFactory() = default;
    
    // Создаёт сладость с заданными именем и весом
    // Все специфичные параметры (тип шоколада, вкус и т.д.). фабрика получает в конструкторе при создании
    virtual AbstractSweet* createSweet(const std::string& name, double weight) = 0;
};