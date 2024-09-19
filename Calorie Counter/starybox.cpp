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
