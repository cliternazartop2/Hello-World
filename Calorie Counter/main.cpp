#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
#include <fstream>
using namespace std;
//чтото менятся
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
    int calories{}; // количество калорий
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
    cout << "Общее количество потребленных калорий " << username << ": " << totalCalories << " ккал" << endl;
}
void registerUser1() {
    cout << "1. зарегистрировать нового пользователя" << endl;
    cout << "2. войти в аккаунт" << endl;
    cout << "3. войти без регистрации" << endl;
}
// Функция для отображения меню
void displayMenu() {
    cout << "СЧЕТЧИК КАЛОРИЙ" << endl;
    cout << "1. Добавить информацию о продуктах" << endl;
    cout << "2. Посмотреть общее количество калорий" << endl;
    cout << "3. получено калорий в прошлы раз" << endl;
    cout << "4. выход" << endl;
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

// Главная функция
int main() {
    setlocale(LC_ALL, "rus");
    bool wrong = false;
    std::string username1;
    std::string password1;
    Food food;
    User User;
    FILE* fp;
    const char* path = { "starybox1.txt" };
    Database db;
    int choice;
    int choise1;
    string username;
    registerUser1();
    cin >> choise1;
    while (true) {
        switch (choise1) {
        case 1:
            registerUser(db, User);  // Assuming registerUser handles user data appropriately
            writePersonToFile(path, User); // Write to file
            choise1 = 3; // Move to the main menu after registration
            break;

        case 2:
            std::cout << "Введите имя пользователя: ";
            std::cin >> username1;
            std::cout << "Введите пароль: ";
            std::cin >> password1;

            if (findConcatenatedString(path, username1, password1, User.username, User.height, User.password, User.weight)) {
                choise1 = 3; // Move to the main menu after successful login
            }
            else {
                std::cout << "Неправильные учетные данные. Пожалуйста, попробуйте снова." << std::endl;
                wrong = true; // Indicate a wrong choice
            }
            break;

        case 3:
            displayMenu();
            int choice;
            std::cin >> choice;
            switch (choice) {
            case 1:
                addFoodIntake(db, username1);
                break;
            case 2:
                viewTotalCalories(db, username1);
                createFile(User, db.getTotalCalories(username));
                break;
            case 3:
                readFile(User);
                break;
            case 4:
                return 0; // Exit the program
            default:
                std::cout << "Неправильный выбор. Пожалуйста, попробуйте снова." << std::endl;
                wrong = true; // Indicate a wrong choice
            }
            break;

        default:
            std::cout << "Неправильный ввод" << std::endl;
            wrong = true; // Flag a wrong choice
        }

        // Check for wrong input to break the loop
        if (wrong) {
            break;
        }
    }
    return 0;
}
