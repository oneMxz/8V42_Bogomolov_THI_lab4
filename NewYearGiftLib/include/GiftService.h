#pragma once
#include "NewYearGift.h"
#include "SweetFactory.h"
#include "ILogger.h"
#include "Export.h"
#include <vector>

class NEWYEAR_GIFT_API GiftService {
private:
    NewYearGift _gift;
    ILogger* _logger;   // добавили логгер

public:
    GiftService(ILogger* logger = nullptr);  // можно передать логгер, можно нет

    void createNewGift();
    void addSweet(SweetFactory* factory, const std::string& name, double weight);
    double getTotalWeight() const;
    int getSweetCount() const;
    const NewYearGift* getGift() const;
    bool removeSweetByName(const std::string& name); 
    void clearGift();
};