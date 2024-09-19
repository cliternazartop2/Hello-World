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

// Структура для хранения информации о пользователе

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
                break;
            }
            

        case 3:
            cout << "a";
            displayMenu();
            int choice;
            std::cin >> choice;
            switch (choice) {
            case 1:
                addFoodIntake(db, username1);
                break;
            case 2:
                viewTotalCalories(db, username1);
                break;
            case 3:
                readFile(User);
                break;
            case 4:
                createFile(User, db.getTotalCalories(username1));
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
