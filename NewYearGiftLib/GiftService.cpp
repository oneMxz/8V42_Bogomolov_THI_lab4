#include "GiftService.h"
#include <stdexcept>

GiftService::GiftService(ILogger* logger) : _logger(logger) {
    createNewGift();
    if (_logger) _logger->log("GiftService создан");
}

void GiftService::createNewGift() {
    _gift.Clear();   // ← изменено
    if (_logger) _logger->log("Создан новый пустой подарок");
}

void GiftService::addSweet(SweetFactory* factory, const std::string& name, double weight) {
    if (!factory) {
        if (_logger) _logger->logError("addSweet: фабрика == nullptr");
        throw std::invalid_argument("Factory is null");
    }
    if (weight <= 0) {
        if (_logger) _logger->logError("addSweet: вес <= 0");
        throw std::invalid_argument("Weight must be positive");
    }
    AbstractSweet* sweet = factory->createSweet(name, weight);
    _gift.AddSweet(sweet);
    if (_logger) {
        _logger->log("Добавлена сладость: " + name + ", вес: " + std::to_string(weight) + " г");
    }
}

double GiftService::getTotalWeight() const {
    double w = _gift.GetTotalWeight();
    if (_logger) _logger->log("Запрошен общий вес: " + std::to_string(w));
    return w;
}

int GiftService::getSweetCount() const {
    int c = _gift.GetSweetCount();
    if (_logger) _logger->log("Количество сладостей: " + std::to_string(c));
    return c;
}

const NewYearGift* GiftService::getGift() const {
    return &_gift;
}

void GiftService::clearGift() {
    _gift.Clear();   // ← изменено
    if (_logger) _logger->log("Подарок очищен");
}

bool GiftService::removeSweetByName(const std::string& name) {
    bool result = _gift.RemoveSweetByName(name);
    if (_logger) {
        if (result) {
            _logger->log("Удалена сладость: " + name);
        } else {
            _logger->logError("Сладость не найдена: " + name);
        }
    }
    return result;
}