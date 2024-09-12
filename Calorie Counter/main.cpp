#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
#include <fstream>

using namespace std;

// Структура для хранения информации о пользователе
struct User {
    string username; // имя пользователя
    string password; // пароль
    int height;   // рост
    int weight;   // вес
};

// Структура для хранения информации о продуктах
struct Food {
    string name;     // название продукта
    int calories; // количество калорий
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
    cin.ignore(numeric_limits<streamsize>::max(), 'n');
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
    cout << "Общее количество потребленных калорий для " << username << ": " << totalCalories << " ккал" << endl;
}
void registerUser1() {
    cout << "1. зарегистрировать нового пользователя";
    cout << "2. войти в аккаунт";
}
// Функция для отображения меню
void displayMenu() {
    cout << "СЧЕТЧИК КАЛОРИЙ" << endl;
    cout << "1. Добавить информацию о продуктах" << endl;
    cout << "2. Посмотреть общее количество калорий" << endl;
    cout << "3. Выход" << endl;
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
// нахождение строчек в фаиле 
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

            std::cout << "Найдена строка: " << line << std::endl;
            inFile.close();
            return true;
        }
    }

    std::cout << "Строка не найдена." << std::endl;
    inFile.close();
    return false;
}
// Главная функция
int main() {
    setlocale(LC_ALL, "rus");
    std::string username1;
    std::string password1;
    User User;
    FILE* fp;
    const char* path = { "starybox.txt" };
    Database db;
    int choice;
    int choise1;
    string username;
    registerUser1();
    cin >> choise1;
    while (true) {
        switch (choise1) {
        case 1:
            registerUser(db, User);
            writePersonToFile(path, User);
            choise1 = 3;
            break;
        case 2:
            std::cout << "Введите имя пользователя: ";
            std::cin >> username1;
            std::cout << "Введите пароль: ";
            std::cin >> password1;
            if (findConcatenatedString(path, username1, password1, User.username, User.height, User.password, User.weight)) {
                choise1 = 3;
            }
            break;
        case 3:
            displayMenu();
            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Введите имя пользователя: ";
                cin >> username;
                addFoodIntake(db, username);
                break;
            case 2:
                cout << "Введите имя пользователя: ";
                cin >> username;
                viewTotalCalories(db, username);
                break;
            case 3:
                return 0;
            default:
                cout << "Неправильный выбор. Пожалуйста, попробуйте снова." << endl;
            }
            break;
        }
    }

    return 0;
}
