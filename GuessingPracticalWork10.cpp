#include <iostream>
#include <time.h>

using namespace std;

short _firstNumber;
short _secondNumber;
short _thirdNumber;

bool _isGameOver;

void printInterface();
void handleUserInput();
short getRandomNumber(short min, short max);

int main()
{
    do {
        printInterface();
        handleUserInput();
    } while (!_isGameOver);
}

void generateNumbers() {
    srand(time(NULL));

    _firstNumber = getRandomNumber(1, 10);
    _secondNumber = getRandomNumber(1, 10);
    _thirdNumber = getRandomNumber(1, 10);
}

void printInterface() {
    cout << "[ Меню ]\n\n[1] Начать игру.\nВыйти.\n\n";
}

void handleUserInput() {
    char userInputChar;
    cin >> userInputChar;

    while (userInputChar == '1' || userInputChar == '2') {
        switch (userInputChar) {
        case '1': {
            generateNumbers();
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

short getRandomNumber(short min, short max) {
    return (rand() % (max - min) + min);
}