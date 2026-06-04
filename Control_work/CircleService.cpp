#include "CircleService.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>

void CircleService::showMenu() {
	std::cout << "Меню:" << std::endl;
    std::cout << "1 - Показати умову завдання" << std::endl;
    std::cout << "2 - Виконати основне завдання" << std::endl;
    std::cout << "3 - Показати всі створені кола" << std::endl;
    std::cout << "4 - Сформувати текстовий файл" << std::endl;
    std::cout << "0 - Вихід з програми" << std::endl;
    std::cout << "Ваш вибір: ";
}

void CircleService::showTask() {
    std::cout << "\nУмова завдання:" << std::endl;
    std::cout << "Класс описує коло, положення якого задається координатами центру та радіусом." << std::endl;
    std::cout << "Операція * полягає у формуванні кола, площа якого дорівнює сумі площ кіл-операндів," << std::endl;
    std::cout << "а центр розташований посередині між центрами першого і другого операнда." << std::endl;
    std::cout << "Об'єкт має містити атрибут кольору." << std::endl;
}

int CircleService::getSafeInt() {
    int value;
    while (!(std::cin >> value)) {
        std::cin.clear(); // Скидаємо прапорець помилки cin
        std::cin.ignore(10000, '\n'); // Очищаємо буфер від неправильних символів
        std::cout << "Помилка введення! Будь ласка, введіть ціле число: ";
    }
    std::cin.ignore(10000, '\n'); // Очищаємо залишок рядка
    return value;
}

void CircleService::getSafeDouble(int minValue, double** values, int size) {
    for (int i = 0; i < size; i += 1) {
        // Якщо зчитування невдале або число не відповідає умові
        while (!(std::cin >> *values[i]) || *values[i] <= minValue) {
            std::cin.clear(); // Скидаємо стан помилки, якщо користувач ввів букву
            std::cin.ignore(10000, '\n'); // Знищуємо саме той некоректний символ, що зламав зчитування
            std::cout << "Помилка введення! Будь ласка, введіть число більше " << minValue << std::endl << "Будь ласка, перевведіть параметр " << (i + 1) << " та всі наступні параметри фігури: ";
        }
    }
    std::cin.ignore(10000, '\n');
}

Color CircleService::chooseColorMenu() {
    while (true) {
        std::cout << "Оберіть колір кола:" << std::endl;
        std::cout<< "1 - Червоний" << std::endl;
        std::cout<<"2 - Зелений" << std::endl;
        std::cout<<"3 - Синій" << std::endl;
        std::cout<<"4 - Жовтий" << std::endl;
        std::cout<<"5 - Білий" << std::endl;
        std::cout << "Ваш вибір: ";
        int choice = getSafeInt();
        switch (choice) {
        case 1: return Color::Red;
        case 2: return Color::Green;
        case 3: return Color::Blue;
        case 4: return Color::Yellow;
        case 5: return Color::White;
        default: std::cout << "Некоректний вибір кольору! Спробуйте знову.\n";
        }
    }
}

Circle CircleService::inputCircle(int orderNumber) {
    std::cout << "\nВведення даних для кола #" << orderNumber << std::endl;
    std::cout << "Введіть довжину радіуса: ";
    double r;
    double* rPtr[] = { &r };
    getSafeDouble(0, rPtr, 1); // Радіус має бути строго > 0

    std::cout << "Введіть координати центру (x y): ";
    double x, y;
    double* coordsPtr[] = { &x, &y };
    getSafeDouble(std::numeric_limits<int>::lowest(), coordsPtr, 2);

    Color c = chooseColorMenu();

    return Circle(r, Point2D(x, y), c);
}

void CircleService::saveToFile(const Circle& c1, const Circle& c2, const Circle& res) {
    std::string filename;
    std::cout << "Введіть назву файлу для збереження звіту (напр. report.txt): ";

    // Безпечне зчитування рядка із очищенням залишків буфера
    std::getline(std::cin, filename);
    if (filename.empty()) {
        std::getline(std::cin, filename);
    }
    std::string extension = ".txt";
    if (filename.length() < extension.length() || filename.substr(filename.length() - extension.length()) != extension) {
        filename += extension;
    }

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw std::runtime_error("Не вдалося створити або відкрити файл для запису!");
    }
    outFile << "Вхідне коло 1:\n" << c1 << "\n\n";
    outFile << "Вхідне коло 2:\n" << c2 << "\n\n";
    outFile << "Результат операції множення (c1 * c2):\n" << res << std::endl;

    outFile.close();
    std::cout << "Звіт успішно збережено у файл \"" << filename << "\"!\n";
}