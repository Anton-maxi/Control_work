#pragma once
#include "Circle.h"
#include <string>

class CircleService {
public:
    static void showMenu();
    static void showTask();

    // Надійне зчитування цілих чисел
    static int getSafeInt();

    // Надійне зчитування double параметрів
    static void getSafeDouble(int minValue, double** values, int size);

    // Допоміжний метод для вибору кольору з меню
    static Color chooseColorMenu();

    // Метод для створення об'єкта користувачем
    static Circle inputCircle(int orderNumber);

    // Метод для збереження результату в текстовий звіт
    static void saveToFile(const Circle& c1, const Circle& c2, const Circle& res);
};