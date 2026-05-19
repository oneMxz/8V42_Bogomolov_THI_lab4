#include "ConsoleUI.h"
#include "GiftService.h"
#include "ConsoleLoggerFactory.h"
#include "FileLoggerFactory.h"
#include <iostream>
#include <limits>

int main() {
    std::cout << "=== Выбор типа логирования ===\n";
    std::cout << "1. Вывод в консоль\n";
    std::cout << "2. Запись в файл (log.txt)\n";
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    LoggerFactory* loggerFactory = nullptr;
    ILogger* logger = nullptr;

    switch (choice) {
        case 1:
            loggerFactory = new ConsoleLoggerFactory();
            break;
        case 2:
            loggerFactory = new FileLoggerFactory("log.txt");
            break;
        default:
            std::cout << "Неверный выбор. Используем консольный логгер.\n";
            loggerFactory = new ConsoleLoggerFactory();
            break;
    }

    logger = loggerFactory->createLogger();

    GiftService service(logger);
    ConsoleUI ui(&service);
    ui.run();

    delete logger;
    delete loggerFactory;

    return 0;
}