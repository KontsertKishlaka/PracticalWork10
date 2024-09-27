#include <iostream>
#include <time.h>

using namespace std;

short _firstGuessNumber;
short _secondGuessNumber;
short _thirdGuessNumber;

short _guessedNumberCount = 0; // Количество угаданных чисел
short _remainAttemptsNumber = 5; // Количество попыток

bool _isGameOver = false;
bool _isAllNumbersGuessed = false;

void handleUserInput();
void startGame();
bool checkGameOver(short userInput);

void showWinInterface();

void generateNumbers();
short getRandomNumber(short min, short max);

int main()
{
    setlocale(0, "");

    generateNumbers();

    while (!_isGameOver) {
        cout << "Меню\n\n1. Начать игру.\n2. Выйти.\n\n";
        handleUserInput();
        _isAllNumbersGuessed = false;
        showWinInterface();
    }

    return 0;
}

void handleUserInput() {
    _guessedNumberCount = 0;
    _remainAttemptsNumber = 5;

    char userInputChar;
    cin >> userInputChar;

    while (userInputChar == '1' || userInputChar == '2') {
        switch (userInputChar) {
        case '1': {
            startGame();
            return;
        }
        case '2': {
            _isGameOver = true;
            return;
        }
        default:
            cout << "Введена некорректная операция. Повторите ввод.";
            break;
        }
    }
}

void startGame() {
    short userInput;

    while (_remainAttemptsNumber < 1 || !_isAllNumbersGuessed) {
        system("cls");

        cout << "firstGuessNumber = " << _firstGuessNumber << "\n";
        cout << "secondGuessNumber = " << _secondGuessNumber << "\n";
        cout << "thirdGuessNumber = " << _thirdGuessNumber << "\n";

        cout << "\nУгаданных чисел: " << _guessedNumberCount << " из 3\nОсталось попыток: " << _remainAttemptsNumber << "\n\nУгадать число: ";
        cin >> userInput;

        if (userInput == _firstGuessNumber && checkGameOver(userInput)) {
            cout << "[+] Вы угадали число!";
            _guessedNumberCount++;
        }
        else {
            cout << "[+] Вы не угадали число!";
            _remainAttemptsNumber--;
        }

        system("cls");

        cout << "firstGuessNumber = " << _firstGuessNumber << "\n";
        cout << "secondGuessNumber = " << _secondGuessNumber << "\n";
        cout << "thirdGuessNumber = " << _thirdGuessNumber << "\n";

        cout << "\nУгаданных чисел: " << _guessedNumberCount << " из 3\nОсталось попыток: " << _remainAttemptsNumber << "\n\nУгадать число: ";
        cin >> userInput;

        if (userInput == _secondGuessNumber && checkGameOver(userInput)) {
            cout << "[+] Вы угадали число!";
            _guessedNumberCount++;
        }
        else {
            cout << "[+] Вы не угадали число!";
            _remainAttemptsNumber--;
        }

        system("cls");

        cout << "firstGuessNumber = " << _firstGuessNumber << "\n";
        cout << "secondGuessNumber = " << _secondGuessNumber << "\n";
        cout << "thirdGuessNumber = " << _thirdGuessNumber << "\n";

        cout << "\nУгаданных чисел: " << _guessedNumberCount << " из 3\nОсталось попыток: " << _remainAttemptsNumber << "\n\nУгадать число: ";
        cin >> userInput;

        if (userInput == _thirdGuessNumber && checkGameOver(userInput)) {
            cout << "[+] Вы угадали число!";
            _guessedNumberCount++;
        }
        else {
            cout << "[+] Вы не угадали число!";
            _remainAttemptsNumber--;
        }

        _isAllNumbersGuessed = true;
    }
}

bool checkGameOver(short userInput) {
    if (userInput < 1 || userInput > 10)
        return false;

    return true;
}

void showWinInterface() {
    system("cls");

    cout << "Вы молодец, все числа угаданы!\n\n";
}

// Блок генерации чисел
void generateNumbers() {
    srand(time(NULL));

    _firstGuessNumber = getRandomNumber(1, 10);
    _secondGuessNumber = getRandomNumber(1, 10);
    _thirdGuessNumber = getRandomNumber(1, 10);
}

short getRandomNumber(short min, short max) {
    return (rand() % (max - min) + min);
}