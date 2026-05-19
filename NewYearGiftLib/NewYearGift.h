#pragma once
#include <vector>
#include <string>
#include "AbstractSweet.h"

class NewYearGift {
private:
    std::vector<AbstractSweet*> _Sweets;
public:
    NewYearGift();
    virtual ~NewYearGift();

    NewYearGift(const NewYearGift&) = delete;
    NewYearGift& operator=(const NewYearGift&) = delete;

    void AddSweet(AbstractSweet* sweet);
    void Clear();                     // <-- добавить
    double GetTotalWeight() const;
    int GetSweetCount() const;
    bool RemoveSweetByName(const std::string& name);
};