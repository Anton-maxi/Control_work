// Control_work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Point2D.h"
#include "Circle.h"
#include <string>
#include <windows.h>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <limits>

void showMenu() {
    std::cout << "\nОберіть примітив для додавання:" << std::endl;
    std::cout << "1 - Показати умову завдання" << std::endl;
    std::cout << "2 - Почати виконання завдання" << std::endl;
	std::cout << "3 - Показати додаткову інформацію" << std::endl;
    std::cout << "0 - Вихід без розрахунку" << std::endl;
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

void getSafeDouble(int minValue, double** values, int size) {
    for (int i = 0; i < size; i += 1) {
        // Якщо зчитування невдале або число не відповідає умові
        while (!(std::cin >> *values[i]) || *values[i] <= minValue) {
            std::cin.clear(); // Скидаємо стан помилки, якщо користувач ввів букву
            std::cin.ignore(10000, '\n'); // Знищуємо саме той некоректний символ, що зламав зчитування
            std::cout << "Помилка введення! Будь ласка, введіть число більше " << minValue << std::endl << "Будь ласка, перевведіть параметр " << (i + 1) << " та всі наступні параметри фігури: ";
        }
    }
    // Очищаємо залишок рядка (наприклад, натискання Enter) після того, як ВСІ елементи зчитано успішно
    std::cin.ignore(10000, '\n');
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
            if (choice == 1) {
                showTask();
            }
            else if (choice == 2) {
                std::cout << "Введіть довжину радіус першого кола: ";
                double r1;
				double* r1Ptr[] = { &r1 };
                getSafeDouble(0, r1Ptr, 1);
                Circle circle1(r1);
                std::cout << "Введіть координати центру першого кола (x y): ";
                double x1, y1;
				double* coords1Ptr[] = { &x1, &y1 };
				getSafeDouble(std::numeric_limits<int>::lowest(), coords1Ptr, 2);
                circle1.setCenter(Point2D(x1, y1));
                std::cout << "Введіть довжину радіус другого кола: ";
                double r2;
				double* r2Ptr[] = { &r2 };
                getSafeDouble(0, r2Ptr, 1);
                std::cout << "Введіть координати центру другого кола (x y): ";
                double x2, y2;
                double* coords2Ptr[] = { &x2, &y2 };
                getSafeDouble(std::numeric_limits<int>::lowest(), coords2Ptr, 2);
                Circle circle2(r2, Point2D(x2, y2));
                Circle resultCircle = circle1 * circle2;
                std::cout << "\nРезультуюче коло:" << std::endl;
                std::cout << resultCircle << std::endl;
                while (true) {
                    std::cout << "Бажаєте зберегти результат у файл? (1 - так, 0 - ні): ";
                    int saveChoice = getSafeInt();
                    if (saveChoice == 1) {
                        std::string filename;
                        std::cout << "Введіть назву файлу для збереження результату: ";
                        std::getline(std::cin, filename);
                        std::ofstream outFile(filename);
                        if (outFile.is_open()) {
                            outFile << resultCircle << std::endl;
                        }
                    }
                    else if (saveChoice == 0) {
                        std::cout << "Результат не збережено." << std::endl;
                    }
                    else {
                        std::cout << "Невірний вибір! Спробуйте ще раз." << std::endl;
                    }
                }
            }
            else if (choice == 0) {
                std::cout << "Вихід з програми..." << std::endl;
                break;
			}
            else {
                std::cout << "Невірний вибір! Будь ласка, виберіть 1 або 2." << std::endl;
			}
        }
        catch (const std::exception& ex) {
            std::cout << "Помилка: " << ex.what() << " Спробуйте знову.\n";
        }

    }
}
