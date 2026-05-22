#include "NewYearGift.h"

NewYearGift::NewYearGift() {}

NewYearGift::~NewYearGift() {
    Clear();
}

void NewYearGift::AddSweet(AbstractSweet* sweet) {
    if (sweet != nullptr) {
        _Sweets.push_back(sweet);
    }
}

void NewYearGift::Clear() {
    for (auto sweet : _Sweets) {
        delete sweet;
    }
    _Sweets.clear();
}

double NewYearGift::GetTotalWeight() const {
    double totalWeight = 0.0;
    for (const auto& sweet : _Sweets) {
        totalWeight += sweet->GetWeight();
    }
    return totalWeight;
}

int NewYearGift::GetSweetCount() const {
    return static_cast<int>(_Sweets.size());
}

bool NewYearGift::RemoveSweetByName(const std::string& name) {
    for (auto it = _Sweets.begin(); it != _Sweets.end(); ++it) {
        if ((*it)->GetName() == name) {
            delete *it;           
            _Sweets.erase(it);    
            return true;
        }
    }
    return false;  // не найдено
}