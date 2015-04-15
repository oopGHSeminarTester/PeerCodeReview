#include<iostream>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<cmath>
using namespace std;

#include "BullsAndCows.h"
int const MIN_SIZE = 2;
int const MAX_SIZE = 4;

bool BullsAndCows::validateNumber(int number, int size) {
	int digits[sizeOfContainer], i = sizeOfContainer - 1;
	if (number < pow(10, size) && number >= pow(10, size - 1)) {
		while (number != 0) {
			digits[i] = number % 10;
			number /= 10;
			i--;
		}
		return validateNumber(digits, sizeOfContainer);
	} else
		return 0;
}

bool BullsAndCows::validateNumber(int digits[], int size) {
	if (digits[0] != 0) { //Проверяваме дали първата цифра е 0
		for (int i = size - 1; i > 0; i--) { // Проверяваме дали имаме повтарящи се цифри
			for (int j = 0; j < i; j++) {
				if (digits[i] == digits[j]) {
					return 0;
				}
			}
		}
		return true;

	} else
		return false;
}

int* BullsAndCows::randomNumber(int from, int to) {
	bool differentDigits;
	int number, i, countOfDigits, changeTime = 0;
	int* digits = new int[sizeOfContainer];
	to = to - from - 1;
	do {
		differentDigits = true;
		srand(time(NULL) + changeTime);
		number = rand() % to + from;
		i = 0;
		countOfDigits = 0;
		while (number != 0) { // Записваме цифрите на числото в масив и броим колко цифри има
			digits[i] = number % 10;
			number /= 10;
			countOfDigits++;
			i++;
		}
		differentDigits = validateNumber(digits, countOfDigits);
		changeTime++;
	} while (!differentDigits);
	return digits;
}

BullsAndCows::BullsAndCows(int size) {
	SetContainerSize(size);
	int* digits = randomNumber(pow(10, sizeOfContainer - 1),
			pow(10, sizeOfContainer) - 1);
	SetContainer(digits);
	delete[] digits;
	numberOfGuesses = 0;
}

BullsAndCows::BullsAndCows(int numbers[], int size) {
	SetContainerSize(size);
	SetContainer(numbers);
	numberOfGuesses = 0;
}

void BullsAndCows::SetContainerSize(int size) {
	if (size >= MIN_SIZE && size <= MAX_SIZE) {
		sizeOfContainer = size;
	} else { // Ако size не е валиден го правим колкото MAX_SIZE
		cout << "Invalid size. Size was automatically changed to " << MAX_SIZE
				<< endl;
		sizeOfContainer = MAX_SIZE;
	}

}

void BullsAndCows::SetContainer(int* container) {
	if (validateNumber(container, sizeOfContainer)) {
		numbersContainer = new int[sizeOfContainer];
		for (int i = 0; i < sizeOfContainer; i++) {
			numbersContainer[i] = container[i];
		}
	} else { // Ако числото не е валидно взимаме произволно валидно число.
		cout << "Invalid number." << endl;
		int* container = randomNumber(pow(10, sizeOfContainer - 1),
				pow(10, sizeOfContainer) - 1);
		for (int i = 0; i < sizeOfContainer; i++) {
			numbersContainer[i] = container[i];
		}
		delete[] container;
	}
}

bool BullsAndCows::IsInsideContainer(int number) {
	for (int i = 0; i < sizeOfContainer; i++) {
		if (numbersContainer[i] == number)
			return true;
	}
	return false;
}

bool BullsAndCows::CowElement(int* arr, int position, int value) {
	for (int i = 0; i < sizeOfContainer; i++) {
		if (arr[i] == value && arr[position] != value) {
			return true;
		}
	}
	return false;
}

bool BullsAndCows::BullElement(int* arr, int position, int value) {
	if (arr[position] == value) {
		return true;
	}
	return false;
}

char* BullsAndCows::TryToGuess(int myGuess) {
	int gamerGuess[sizeOfContainer], bulls = 0, cows = 0;
	bool win = true;
	char* pointer = new char[40];
	char firstMessage[] = "Congratualtions! You made a right guess!";
	char secondMessage[] = "Cows:x    Bulls:y"; // [5] и [16]"
	for (int i = sizeOfContainer - 1; i >= 0; i--) {
		gamerGuess[i] = myGuess % 10;
		myGuess /= 10;
		if (numbersContainer[i] != gamerGuess[i])
			win = false;
	}
	if (win) {
		strcpy(pointer, firstMessage);
	} else {
		for (int i = 0; i < sizeOfContainer; i++) {
			if (IsInsideContainer(gamerGuess[i])
					&& BullElement(numbersContainer, i, gamerGuess[i])) {
				bulls++;
			}
			if (IsInsideContainer(gamerGuess[i])
					&& CowElement(numbersContainer, i, gamerGuess[i])) {
				cows++;
			}
		}
		secondMessage[5] = cows + 48;
		secondMessage[16] = bulls + 48;
		strcpy(pointer, secondMessage);
	}
	return pointer;
}

void BullsAndCows::Start() {
	int gamerGuess, i = 0, numberToGuess = 0;
	while (i < sizeOfContainer) {
		// записваме числото което трябва да познаем в една променлива
		numberToGuess = numberToGuess
				+ numbersContainer[i] * pow(10, sizeOfContainer - 1 - i);
		i++;
	}
	char* message;
	do {
		i = 0;
		cout << "Your guess:";
		cin >> gamerGuess;
		if (validateNumber(gamerGuess, sizeOfContainer)) {
			cout << "                       [" << gamerGuess << "] => ";
			message = TryToGuess(gamerGuess);
			while (message[i] != '\0') {
				cout << message[i];
				i++;
			}
			numberOfGuesses++;
			cout << endl;
		} else
			cout << "                       Invalid number." << endl;
	} while (gamerGuess != numberToGuess);
	cout << endl;
	cout << "               It took you " << numberOfGuesses
			<< " guesses to finish the game.";
	delete[] message;
}
BullsAndCows::~BullsAndCows() {
	delete[] numbersContainer;
}
