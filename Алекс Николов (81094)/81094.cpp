#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include "bullsandcows.h"

using namespace std;

BullsAndCows::BullsAndCows(int size)
{
    if (size < 2 || size > 4)
        cout << "Error: size = " << size << ", expected 2, 3 or 4.";
    else
    {
        numbersContainer = new int[size];
        SetContainerSize(size);
        for (int i = 0; i < sizeOfContainer; i++)
            numbersContainer[i] = -1;
        numberOfGuesses = 0;
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            if (i == 0)
                numbersContainer[i] = 1 + rand() % 9;
            else
            {
                int randomDigit;
                do
                {
                    randomDigit = rand() % 10;
                } while (IsInsideContainer(randomDigit));
                numbersContainer[i] = randomDigit;
            }

        }
    }
}


BullsAndCows::BullsAndCows(int numbers[], int size)
{
    bool error = false;
    if (numbers[0] == 0)
        error = true;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (numbers[i] == numbers[j] || numbers[i] < 0 || numbers[i] > 9 ||
                numbers[j] < 0 || numbers[j] > 9)
            {
                error = true;
                break;
            }
        }
    }
    if (error)
        cout << "Error: Invalid input of number array.";
    else
    {
        numberOfGuesses = 0;
        SetContainerSize(size);
        SetContainer(numbers);
    }
}

BullsAndCows::~BullsAndCows()
{
    delete[] numbersContainer;
}

void BullsAndCows::SetContainerSize(int size)
{
    sizeOfContainer = size;
}

void BullsAndCows::SetContainer(int* container)
{
    int counter = 0;
    while (*(container + counter) >= 0 && *(container + counter) <= 9)
        counter ++;
    if (counter != sizeOfContainer)
        cout << "Error: Invalid container size." << endl;
    for (int i = 0; i < sizeOfContainer; i ++)
    {
        if (i == 0)
        {
            if (container[i] < 1 || container[i] > 9)
            {
                cout << "Error: Incorrect value ot container.";
                return;
            }
        }
        else
        {
            if (container[i] < 0 || container[i] > 9)
            {
                cout << "Error: Incorrect value ot container.";
                return;
            }
        }
    }
    numbersContainer = new int[sizeOfContainer];
    for (int i = 0; i < sizeOfContainer; i++)
        numbersContainer[i] = container[i];
}

bool BullsAndCows::CowElement(int* arr, int position, int value)
{
    for (int i = 0; i < sizeOfContainer; i++)
    {
        if (i != position && arr[i] == value)
            return true;
    }
    return false;
}

bool BullsAndCows::BullElement(int* arr, int position, int value)
{
    return arr[position] == value;
}


bool BullsAndCows::IsInsideContainer(int number)
{
    for (int i = 0; i < sizeOfContainer; i++)
    {
        if (numbersContainer[i] == number)
            return true;
    }
    return false;
}

char* BullsAndCows::TryToGuess(int myGuess)
{
    int bulls = 0, cows = 0, currentPosition = sizeOfContainer - 1;
    while (myGuess > 0)
    {
        int currentDigit = myGuess % 10;
        myGuess /= 10;
        if (BullElement(numbersContainer, currentPosition, currentDigit))
            bulls++;
        else
        {
            for (int i = 0; i < sizeOfContainer; i++)
            {
                if (i != currentPosition && CowElement(numbersContainer, currentPosition, currentDigit))
                {
                    cows++;
                    break;
                }
            }
        }
        currentPosition--;
    }
    numberOfGuesses++;
    if (bulls == sizeOfContainer && cows == 0)
        return "Congratulations! You made a right guess!";
    string result = "Cows:";
    char c = char(cows + '0');
    result += c;
    result += "    Bulls:";
    char b = char(bulls + '0');
    result += b;
    char* finalResult = new char[18];
    strcpy(finalResult, result.c_str());
    return finalResult;
}

bool hasDifferentDigits(int number)
{
    while (number > 0)
    {
        int currentDigit = number % 10;
        number /= 10;
        int copyNumber = number;
        while (copyNumber > 0)
        {
            if (currentDigit == copyNumber % 10)
                return false;
            copyNumber /= 10;
        }
    }
    return true;
}

void BullsAndCows::start()
{
    char* result;
    bool done = false;
    int guess;
    do
    {
        do
        {
            cout << "Your guess:";
            cin >> guess;
            if (guess < pow(10, sizeOfContainer - 1) || guess >= pow(10, sizeOfContainer))
                cout << "Error: Your number must have " << sizeOfContainer << " digits.\n\n";
            if (!hasDifferentDigits(guess))
                cout << "Error: Your number's digits are not unique.\n\n";
        } while (guess < pow(10, sizeOfContainer - 1) ||
                 guess >= pow(10, sizeOfContainer) ||
                 !hasDifferentDigits(guess));
        result = TryToGuess(guess);
        cout << "\t\t\t[" << guess << "] => " << result << endl;
        done = strcmp(result, "Congratulations! You made a right guess!") == 0;
        delete[] result;
    } while (!done);
    cout << "\n\n\t\t It took you " << numberOfGuesses << " guesses to finish the game.\n";
}

