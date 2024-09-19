#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <unordered_map>
#include <vector>

// Используем стандартное пространство имен
using namespace std;

// Структура для хранения информации о пользователе
struct User {
    string username; // имя пользователя
    string password; // пароль
    int height;      // рост
    int weight;      // вес
};

// Структура для хранения информации о продуктах
struct Food {
    string name;     // название продукта
    int calories;    // количество калорий
};

// Класс для работы с базой данных
class Database {
public:
    // Добавление пользователя в базу данных
    void addUser(const User& user) {
        users[user.username] = user;
    }

    // Добавление информации о продуктах для пользователя
    void addFood(const string& username, const Food& food) {
        foodIntake[username].push_back(food);
    }

    // Получение общего количества калорий, потребленных пользователем
    double getTotalCalories(const string& username) {
        double total = 0.0;
        for (const auto& food : foodIntake[username]) {
            total += food.calories;
        }
        return total;
    }

private:
    unordered_map<string, User> users;               // база данных пользователей
    unordered_map<string, vector<Food>> foodIntake;  // база данных продуктов, потребленных пользователями
};

// Функция для регистрации пользователя
void registerUser(Database& db, User& user);

// Функция для добавления строки в файл
void appendToFile(const string& filename, const string& lineToAdd);

// Функция для добавления информации о потреблении пищи
void addFoodIntake(Database& db, const string& username);

// Функция для просмотра общего количества калорий
void viewTotalCalories(Database& db, const string& username);
void displayMenu();
void registerUser1();
void writePersonToFile(const std::string& filename, User& person);
void createFile(User& user, int number);
void readFile(User& user);
bool findConcatenatedString(const std::string& filename, const std::string& firstWord, const std::string& secondWord,
    std::string& firstString, int& firstInt, std::string& secondString, int& secondInt);


