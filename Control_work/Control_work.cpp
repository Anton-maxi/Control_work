// Control_work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Point2D.h"
#include "Circle.h"
#include <string>
#include <windows.h>
#include <stdexcept>

void showMenu() {
    std::cout << "\nОберіть примітив для додавання:" << std::endl;
    std::cout << "1 - Показати умову завдання" << std::endl;
    std::cout << "2 - Почати виконання завдання" << std::endl;
    std::cout << "Ваш вибір: ";
}

void showTask() {
    std::cout << "\nУмова завдання:" << std::endl;
    std::cout << "Операція полягає у формуванні кола, площа якого дорівнює сумі площ кіл-операндів, \nа центр розташований посередині між центрами першого і другого операнда." << std::endl;
}

int getSafeInt() {
    int value;
    while (!(std::cin >> value)) {
        std::cin.clear(); // Скидаємо прапорець помилки cin
        std::cin.ignore(10000, '\n'); // Очищаємо буфер від неправильних символів
        std::cout << "Помилка введення! Будь ласка, введіть ціле число: ";
    }
    std::cin.ignore(10000, '\n'); // Очищаємо залишок рядка
    return value;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice = -1;
    while (true) {
        showMenu();
        choice = getSafeInt();
        try {

        }
        catch (const std::exception& ex) {
            std::cout << "Помилка: " << ex.what() << " Спробуйте знову.\n";
        }

    }
}
