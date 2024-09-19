
#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
#include <fstream>
#include "trox.h"
using namespace std;

// Функция для очистки ввода в случае ошибки
void clearInput() {
    cin.clear();
}
// Функция регистрации пользователя
void registerUser(Database& db, User& user) {

    cout << "Введите имя пользователя: ";
    cin >> user.username;
    cout << "Введите пароль: ";
    cin >> user.password;
    cout << "Введите рост (в см): ";
    while (!(cin >> user.height)) {
        cout << "Неправильный ввод. Введите рост (в см): ";

    }
    cout << "Введите вес (в кг): ";
    while (!(cin >> user.weight)) {
        cout << "Неправильный ввод. Введите вес (в кг): ";

    }

    cout << "Успешная регистрация" << endl;
    db.addUser(user);
}
void appendToFile(const std::string& filename, const std::string& lineToAdd) {
    ofstream outFile;
    outFile.open(filename, std::ios::app); // Открываем файл в режиме добавления

    // Проверяем, открылся ли файл
    if (outFile.is_open()) {
        outFile << lineToAdd << std::endl; // Записываем строку в файл
        outFile.close(); // Закрываем файл
        std::cout << "Строка успешно записана в файл!" << std::endl;
    }
    else {
        std::cerr << "Ошибка открытия файла!" << std::endl;
    }
}
// Функция для добавления информации о потребленных продуктах
void addFoodIntake(Database& db, const string& username) {
    Food food;
    cout << "Введите название продукта: ";
    cin >> food.name;
    cout << "Введите количество калорий: ";
    while (!(cin >> food.calories)) {
        cout << "Неправильный ввод. Введите количество калорий: ";
    }


    db.addFood(username, food);
}

// Функция для просмотра общего количества потребленных калорий
void viewTotalCalories(Database& db, const string& username) {
    double totalCalories = db.getTotalCalories(username);
    cout << "Общее количество потребленных калорий " << username << ": " << totalCalories << " ккал" << endl;
}
void registerUser1() {
    cout << "СЧЕТЧИК КАЛОРИЙ" << endl;
    cout << "1. зарегистрировать нового пользователя" << endl;
    cout << "2. войти в аккаунт" << endl;
    cout << "3. войти без регистрации" << endl;
}
// Функция для отображения меню
void displayMenu() {
    cout << "СЧЕТЧИК КАЛОРИЙ" << endl;
    cout << "1. Добавить информацию о продуктах" << endl;
    cout << "2. Посмотреть общее количество калорий" << endl;
    cout << "3. Калорий потреблено в прошлый раз:" << endl;
    cout << "4. Выход" << endl;
}
void writePersonToFile(const std::string& filename, User& person) {
    std::ofstream outFile;
    outFile.open(filename, std::ios_base::app); // Открываем файл в режиме добавления

    if (outFile.is_open()) {
        // Записываем данные структуры в файл через пробел
        outFile
            << person.username << "_"
            << person.password << "_"
            << person.height << "_"
            << person.weight << "_" << endl;

        outFile.close(); // Закрываем файл
        std::cout << "Данные успешно записаны в файл!" << std::endl;
    }
    else {
        std::cerr << "Ошибка открытия файла!" << std::endl;
    }
}

void createFile(User& user, int number) {
    // Получаем текущее время и форматируем его
    std::time_t t = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", std::localtime(&t));

    // Создаём полное имя файла с расширением .txt
    std::string filename1 = user.username + ".txt";

    // Открываем файл для записи
    std::ofstream outFile(filename1);
    if (!outFile) {
        std::cerr << "Ошибка при открытии файла для записи!" << std::endl;
        return;
    }

    // Записываем данные в файл
    outFile << "колорий получено: " << number << std::endl;
    outFile << "Дата: " << buffer << std::endl;

    // Закрываем файл
    outFile.close();
}

void readFile(User& user) {
    // Создаём полное имя файла с расширением .txt
    std::string filename1 = user.username + ".txt";

    // Открываем файл для чтения
    std::ifstream inFile(filename1);
    if (!inFile) {
        std::cerr << "Ошибка при открытии файла для чтения!" << std::endl;
        return;
    }

    // Читаем данные из файла и выводим их на экран
    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    // Закрываем файл
    inFile.close();
}
bool findConcatenatedString(const std::string& filename, const std::string& firstWord, const std::string& secondWord,
    std::string& firstString, int& firstInt, std::string& secondString, int& secondInt) {

    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return false;
    }

    // Склеиваем слова
    std::string searchString = firstWord + "_" + secondWord;
    std::string line;

    // Ищем строку
    while (std::getline(inFile, line)) {
        if (line.find(searchString) != std::string::npos) {
            std::istringstream iss(line);
            std::string tempString;

            // Читаем строку до первого подчеркивания
            if (std::getline(iss, tempString, '_')) {
                firstString = tempString; // Сохраняем первую строку
            }
            if (std::getline(iss, tempString, '_')) {
                secondString = tempString; // Сохраняем вторую строку
            }
            // Читаем целое число
            if (!(iss >> firstInt)) {
                std::cerr << "Ошибка при чтении первого числа." << std::endl;
                inFile.close();
                return false;
            }
            iss.ignore(); // Игнорируем следующий символ подчеркивания

            // Читаем вторую строку


            // Читаем второе целое число
            if (!(iss >> secondInt)) {
                std::cerr << "Ошибка при чтении второго числа." << std::endl;
                inFile.close();
                return false;
            }
            std::cout << "Успешный вход!" << std::endl;
            inFile.close();
            return true;
        }
    }

    std::cout << "Строка не найдена." << std::endl;
    inFile.close();
    return false;
}
