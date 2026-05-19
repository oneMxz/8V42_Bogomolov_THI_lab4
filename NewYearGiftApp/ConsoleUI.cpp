#include "ConsoleUI.h"
#include "ChocolateCandyFactory.h"
#include "CaramelCandyFactory.h"
#include "LollipopFactory.h"
#include "MarshmallowFactory.h"
#include <iostream>
#include <limits>

ConsoleUI::ConsoleUI(GiftService* service) : _service(service) {}

void ConsoleUI::run() {
    int choice;
    do {
        showMenu();
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Попробуйте снова.\n";
            continue;
        }
        handleChoice(choice);
    } while (choice != 0);
}

void ConsoleUI::showMenu() {
    std::cout << "\n=== Новогодний подарок ===\n";
    std::cout << "1. Создать стандартный подарок\n";
    std::cout << "2. Добавить сладость\n";
    std::cout << "3. Показать содержимое подарка\n";
    std::cout << "4. Показать общий вес\n";
    std::cout << "5. Очистить подарок\n";
    std::cout << "6. Удалить сладость по названию\n";
    std::cout << "0. Выход\n";
    std::cout << "Выбор: ";
}

void ConsoleUI::handleChoice(int choice) {
    switch (choice) {
        case 1:
            _service->createNewGift();
            // Добавим стандартный набор сладостей (через фабрики)
            {
                ChocolateCandyFactory chocoFact("Молочная", true, 40, "Молочный");
                _service->addSweet(&chocoFact, "Алёнка", 15.0);
                
                CaramelCandyFactory caramelFact("Мятная", true, "Твёрдая", false);
                _service->addSweet(&caramelFact, "Мятная карамель", 7.0);
                
                LollipopFactory lollipopFact("Клубника", true);
                _service->addSweet(&lollipopFact, "Чупа-Чупс", 12.0);
                
                MarshmallowFactory marshFact("Шоколадная");
                _service->addSweet(&marshFact, "Зефир шоколадный", 25.0);
            }
            std::cout << "Стандартный подарок создан.\n";
            break;
        case 2:
            addSweetInteractive();
            break;
        case 3:
            showGiftInfo();
            break;
        case 4:
            std::cout << "Общий вес подарка: " << _service->getTotalWeight() << " г\n";
            break;
        case 5:
            _service->clearGift();
            std::cout << "Подарок очищен.\n";
            break;
        case 6:
            removeSweetInteractive();
            break;
        case 0:
            std::cout << "До свидания!\n";
            break;
        default:
            std::cout << "Неверный выбор.\n";
    }
}

void ConsoleUI::showGiftInfo() {
    const NewYearGift* gift = _service->getGift();
    if (!gift || _service->getSweetCount() == 0) {
        std::cout << "Подарок пуст.\n";
        return;
    }
    // К сожалению, NewYearGift не предоставляет итератор по сладостям.
    // Для вывода имён нужно добавить метод в NewYearGift (например, PrintContents).
    // Пока просто выведем количество.
    std::cout << "В подарке " << _service->getSweetCount() << " сладостей.\n";
    std::cout << "Общий вес: " << _service->getTotalWeight() << " г\n";
}

void ConsoleUI::addSweetInteractive() {
    int type;
    std::cout << "Выберите тип сладости:\n";
    std::cout << "1. Шоколадная конфета\n";
    std::cout << "2. Карамель\n";
    std::cout << "3. Леденец\n";
    std::cout << "4. Зефир\n";
    std::cout << "Ваш выбор: ";
    std::cin >> type;

    std::string name;
    double weight;
    std::cout << "Название: ";
    std::cin >> name;
    std::cout << "Вес (г): ";
    std::cin >> weight;

    try {
        switch (type) {
            case 1: {
                std::string filling, chocoType;
                bool wrapper;
                int cocoa;
                std::cout << "Тип начинки: ";
                std::cin >> filling;
                std::cout << "Есть обёртка (1 - да, 0 - нет): ";
                std::cin >> wrapper;
                std::cout << "Процент какао: ";
                std::cin >> cocoa;
                std::cout << "Тип шоколада (молочный, горький, белый): ";
                std::cin >> chocoType;
                ChocolateCandyFactory factory(filling, wrapper, cocoa, chocoType);
                _service->addSweet(&factory, name, weight);
                break;
            }
            case 2: {
                std::string filling, caramelType;
                bool wrapper, salt;
                std::cout << "Тип начинки: ";
                std::cin >> filling;
                std::cout << "Есть обёртка (1/0): ";
                std::cin >> wrapper;
                std::cout << "Тип карамели (мягкая, тягучая, твёрдая, солёная): ";
                std::cin >> caramelType;
                std::cout << "Содержит соль (1/0): ";
                std::cin >> salt;
                CaramelCandyFactory factory(filling, wrapper, caramelType, salt);
                _service->addSweet(&factory, name, weight);
                break;
            }
            case 3: {
                std::string flavor;
                bool stick;
                std::cout << "Вкус: ";
                std::cin >> flavor;
                std::cout << "На палочке (1/0): ";
                std::cin >> stick;
                LollipopFactory factory(flavor, stick);
                _service->addSweet(&factory, name, weight);
                break;
            }
            case 4: {
                std::string coating;
                std::cout << "Тип покрытия (шоколадная, глазурь, без покрытия): ";
                std::cin >> coating;
                MarshmallowFactory factory(coating);
                _service->addSweet(&factory, name, weight);
                break;
            }
            default:
                std::cout << "Неверный тип.\n";
                return;
        }
        std::cout << "Сладость добавлена.\n";
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
}

void ConsoleUI::removeSweetInteractive() {
    std::string name;
    std::cout << "Введите название сладости для удаления: ";
    std::cin >> name;
    
    if (_service->removeSweetByName(name)) {
        std::cout << "Сладость \"" << name << "\" удалена.\n";
    } else {
        std::cout << "Сладость \"" << name << "\" не найдена.\n";
    }
}