// Control_work.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Point2D.h"
#include "Circle.h"
#include "CircleService.h"
#include <string>
#include <windows.h>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice = -1;
    std::vector<Circle> circles;
    Circle c1(1);
    Circle c2(1);
    Circle resultCircle(1);
    bool isTaskCalculated = false; // Прапорець перевірки виконання основного завдання

    while (true) {
        CircleService::showMenu();
        choice = CircleService::getSafeInt();

        try {
            if (choice == 1) {
                // Очищення екрану для відображення інформації виключно про поточну роботу
                //system("cls");
                CircleService::showTask();
            }
            else if (choice == 2) {
                //system("cls");

                // Введення даних через Сервіс
                c1 = CircleService::inputCircle(1);
                circles.push_back(c1);
                c2 = CircleService::inputCircle(2);
                circles.push_back(c2);

                // Виконання основної операції *
                resultCircle = c1 * c2;
                circles.push_back(resultCircle);
                isTaskCalculated = true;

                std::cout << "\nРезультат розрахунку:\n" << resultCircle << std::endl;
            }
            else if (choice == 3) {
                std::cout << "Всі створені кола:" << std::endl;
                for (int i = 0; i < circles.size(); i += 1) {
                    std::cout << "Коло " << (i + 1) << ": " << std::endl;
                    std::cout << circles[i] << std::endl;
                }
            }
            else if (choice == 4) {
                // Перевірка виконання умови ТЗ (пункт доступний лише після розрахунку)
                if (!isTaskCalculated) {
                    std::cout << "Помилка! Ви не можете сформувати звіт, оскільки основне завдання (пункт 2) ще не виконано!\n";
                }
                else {
                    //system("cls");
                    CircleService::saveToFile(c1, c2, resultCircle);
                }
            }
            else if (choice == 0) {
                std::cout << "Вихід з програми..." << std::endl;
                break;
            }
            else {
                std::cout << "Невірний вибір! Будь ласка, оберіть пункт від 0 до 4." << std::endl;
            }
        }
        catch (const std::invalid_argument& ex) {
            std::cout << "\nПомилка валідації даних: " << ex.what() << " Спробуйте знову.\n";  
        }
        catch (const std::runtime_error& ex) {
            std::cout << "\nПомилка виконання: " << ex.what() << " Перевірте права доступу.\n";
        }
        catch (const std::exception& ex) {
            std::cout << "\nНепередбачена помилка: " << ex.what() << "\n";
        }
    }

    return 0;
}
