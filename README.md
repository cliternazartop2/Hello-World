# Calorie Counter

## Описание

Консольное приложение для подсчета калорий. Пользователи могут регистрироваться, добавлять информацию об употребленных продуктах и получать количество потребленных калорий.

## Требования к проекту

### Общие требования
1. Проект является консольным приложением.
2. Проект предоставляется в завершённом виде. Каждая написанная часть кода доведена до готового состояния. Отсутствуют недописанные или неиспользуемые части кода, нереализованные функции, пустые файлы и т. д.
3. Проект соответствует техническому заданию, описанному для темы, по которой он выполнен.
4. Проект реализован в процедурно-функциональном стиле с применением многофайловости.
5. С точки зрения пользователя – приложение понятное и удобное в использовании, даже если запускается впервые.
6. Код подробно описан посредством добавления комментариев. Комментарии обязательны для:
    - переменных;
    - функций;
    - управляющих конструкций (циклы, ветвления и т. д.);
    - сложных выражений;
    - и т. д.
7. Во время разработки проекта ведётся его подробная история в системе контроля версий Git через веб-сервис GitHub. Для репозитория также должен быть создан файл README.md с кратким описанием технического задания.

### Техническое задание

1. **Регистрация пользователя**
    - Пользователь должен иметь возможность зарегистрироваться, введя никнейм, пароль, рост и вес.
    - Информация о пользователе сохраняется в системе.

2. **Добавление информации о потребленных продуктах**
    - Пользователь должен иметь возможность добавлять информацию о потребленных продуктах, указав название продукта и количество калорий.

3. **Просмотр общего количества потребленных калорий**
    - Пользователь должен иметь возможность посмотреть общее количество потребленных калорий за все время.

### Основные файлы и функции

- **main.cpp**
    - Главный файл приложения, содержит точку входа и основной цикл программы.
    - Отображает меню и обрабатывает выбор пользователя.

- **Структуры и классы**
    - `User`: Структура для хранения информации о пользователе.
    - `Food`: Структура для хранения информации о продуктах.
    - `Database`: Класс для работы с базой данных, включает методы для добавления пользователя, добавления продуктов и расчета общего количества калорий.

- **Основные функции**
    - `clearInput()`: Очистка ввода в случае ошибки.
    - `registerUser(Database& db)`: Регистрация нового пользователя.
    - `addFoodIntake(Database& db, const string& username)`: Добавление информации о потребленных продуктах для конкретного пользователя.
    - `viewTotalCalories(Database& db, const string& username)`: Просмотр общего количества потребленных калорий для конкретного пользователя.

### Как использовать

1. Склонируйте репозиторий.
2. Скомпилируйте проект, используя команду:
    ```bash
    g++ -o calorie_counter main.cpp
    ```
3. Запустите исполняемый файл:
    ```bash
    ./calorie_counter
    ```
4. Следуйте инструкциям в меню для регистрации, добавления продуктов и просмотра калорий.

## Пример использования

1. **Регистрация пользователя**
    - Введите 1 для регистрации.
    - Введите никнейм, пароль, рост и вес.

2. **Добавление информации о продуктах**
    - Введите 2 для добавления продуктов.
    - Введите никнейм пользователя, название продукта и количество калорий.

3. **Просмотр общего количества калорий**
    - Введите 3 для просмотра калорий.
    - Введите никнейм пользователя для получения информации о потребленных калориях.

4. **Выход из приложения**
    - Введите 4 для выхода из приложения.

## История версий

История версий проекта ведётся в системе контроля версий Git и доступна на [GitHub](URL вашего репозитория).

## Лицензия

Этот проект лицензирован под лицензией MIT.