#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    srand(time(0)); // Инициализация генератора случайных чисел

    while (true) {
        cout << "Меню:\n\n1. \x1b[96mНачать игру\x1b[0m\n2. \x1b[91mВыйти\x1b[0m\n\nВведите номер пункта меню: ";

        short userChoice;
        cin >> userChoice;

        if (userChoice == 1) {
            // Генерация трех уникальных чисел от 1 до 10
            vector<int> numbers(3);
            for (int i = 0; i < 3; ++i) {
                numbers[i] = rand() % 10 + 1;
            }
            sort(numbers.begin(), numbers.end()); // Сортировка для удобства проверки

            int guessedNumbers = 0;
            int attempts = 5;
            int currentNumberIndex = 0; // Индекс текущего числа для угадывания

            system("cls");

            cout << "\x1b[94m[ ПОДСКАЗКА ДЛЯ ОТЛАДКИ ] Загаданные числа: "; // ПОДСКАЗКА ДЛЯ ОТЛАДКИ
            for (int i = 0; i < 3; ++i) {
                cout << numbers[i] << " ";
            }
            cout << "\x1b[0m\n";

            while (attempts > 0 && guessedNumbers < 3) {
                cout << "\n[ + ] Угаданных чисел: [ \x1b[96m" << guessedNumbers << " / 3\x1b[0m ]";
                cout << "\n[ + ] Попыток: [ \x1b[91m" << attempts << "\x1b[0m ]\n";
                cout << "\n[ > ] Угадать число (от 1 до 10 включительно): ";

                int guess;
                cin >> guess;

                if (guess < 1 || guess > 10) {
                    cout << "\n[ - ] Введите число \x1b[91mот 1 до 10 (включительно)\x1b[0m!\n";
                    continue;
                }

                // Проверка текущего числа
                if (guess == numbers[currentNumberIndex]) {
                    cout << "\n[ + ] Вы \x1b[95mугадали число\x1b[0m!\n";
                    guessedNumbers++;
                    currentNumberIndex++; // Переход к следующему числу
                }
                else {
                    cout << "\n[ - ] Вы \x1b[91mне угадали число\x1b[0m!\n";
                    attempts--;
                }
            }

            if (guessedNumbers == 3) {
                system("cls");
                cout << "[ + ] \x1b[92mПоздравляем\x1b[0m! Вы угадали все числа!\n\n";
            }
            else {
                system("cls");
                cout << "[ - ] \x1b[91mВы проиграли\x1b[0m! Числа были: \x1b[94m";
                for (int i = 0; i < 3; ++i) {
                    cout << numbers[i] << " ";
                }
                cout << "\x1b[0m\n\n";
            }
        }
        else if (userChoice == 2) {
            cout << "\n\x1b[91mВыход из приложения\x1b[0m.\n\n";
            break;
        }
        else {
            cout << "\n\x1b[91mНекорректный ввод\x1b[0m. Пожалуйста, выберите 1 или 2.\n";
        }
    }

    return 0;
}