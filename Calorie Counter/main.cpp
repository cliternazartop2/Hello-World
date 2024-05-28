#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

// Структура для хранения информации о пользователе
struct User {
    string username; // имя пользователя
    string password; // пароль
    double height;   // рост
    double weight;   // вес
};

// Структура для хранения информации о продуктах
struct Food {
    string name;     // название продукта
    double calories; // количество калорий
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

// Функция для очистки ввода в случае ошибки
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функция регистрации пользователя
void registerUser(Database& db) {
    User user;
    cout << "Введите имя пользователя: ";
    cin >> user.username;
    clearInput();
    cout << "Введите пароль: ";
    cin >> user.password;
    clearInput();
    cout << "Введите рост (в см): ";
    while (!(cin >> user.height)) {
        cout << "Неправильный ввод. Введите рост (в см): ";
        clearInput();
    }
    clearInput();
    cout << "Введите вес (в кг): ";
    while (!(cin >> user.weight)) {
        cout << "Неправильный ввод. Введите вес (в кг): ";
        clearInput();
    }
    clearInput();

    db.addUser(user);
}

// Функция для добавления информации о потребленных продуктах
void addFoodIntake(Database& db, const string& username) {
    Food food;
    cout << "Введите название продукта: ";
    cin >> food.name;
    clearInput();
    cout << "Введите количество калорий: ";
    while (!(cin >> food.calories)) {
        cout << "Неправильный ввод. Введите количество калорий: ";
        clearInput();
    }
    clearInput();

    db.addFood(username, food);
}

// Функция для просмотра общего количества потребленных калорий
void viewTotalCalories(Database& db, const string& username) {
    double totalCalories = db.getTotalCalories(username);
    cout << "Общее количество потребленных калорий для " << username << ": " << totalCalories << " ккал" << endl;
}

// Функция для отображения меню
void displayMenu() {
    cout << "1. Регистрация" << endl;
    cout << "2. Добавить информацию о продуктах" << endl;
    cout << "3. Посмотреть общее количество калорий" << endl;
    cout << "4. Выход" << endl;
}

// Главная функция
int main() {
    Database db;
    int choice;
    string username;

    while (true) {
        displayMenu();
        cin >> choice;
        clearInput(); // Очистка ввода после выбора

        switch (choice) {
        case 1:
            registerUser(db);
            break;
        case 2:
            cout << "Введите имя пользователя: ";
            cin >> username;
            clearInput();
            addFoodIntake(db, username);
            break;
        case 3:
            cout << "Введите имя пользователя: ";
            cin >> username;
            clearInput();
            viewTotalCalories(db, username);
            break;
        case 4:
            return 0;
        default:
            cout << "Неправильный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    }

    return 0;
}
