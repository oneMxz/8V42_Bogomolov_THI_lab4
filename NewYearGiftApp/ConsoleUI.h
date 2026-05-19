#pragma once
#include "GiftService.h"

class ConsoleUI {
private:
    GiftService* _service;

    void showMenu();
    void handleChoice(int choice);
    void showGiftInfo();
    void addSweetInteractive();
    void removeSweetInteractive();

public:
    ConsoleUI(GiftService* service);
    void run();  // главный цикл
};