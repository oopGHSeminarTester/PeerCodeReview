#ifndef _BULLSANDCOWS_H
#define _BULLSANDCOWS_H
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
class BullsAndCows{
public:
	void Start();

	
	BullsAndCows(int size); 
	BullsAndCows(int numbers[], int size); 
	void SetContainerSize(int size);
	void SetContainer(int* container);
	


	void SetRandomContainer();

	bool IsInsideContainer(int number);
	
	
	bool CowElement(int* arr, int position, int value);
	bool BullElement(int* arr, int position, int value);
	char* TryToGuess(int myGuess);

	~BullsAndCows() {
		delete numbersContainer;
	}
private:
	int sizeOfContainer;
	int* numbersContainer;
	int numberOfGuesses;
	bool is_it_right;
};

#endif


//---------------
/*void delay(clock_t sec) {
	clock_t start_time = clock();
	clock_t end_time = sec * 1000 + start_time;
	while (clock() <= end_time)
		;
}

void BullsAndCows::randomNumber(int from, int to) {
	bool differentDigits;
	int number, i, j, countOfDigits = 0, copyOfNumber, digits[10];
	to = to - from - 1;
	do {
		differentDigits = true;
		srand(time(NULL));
		number = rand() % to + from;
		copyOfNumber = number;
		i = 0;
		while (copyOfNumber != 0) {
			digits[i] = copyOfNumber % 10;
			copyOfNumber /= 10;
			countOfDigits++;
			i++;
		}
		for (i = countOfDigits - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (digits[i] == digits[j]) {
					differentDigits = false;

				}
			}
		}
		if (!differentDigits)
			delay(1000);
		cout << number << ":" << differentDigits << endl;

	} while (!differentDigits);
	//return number;
}
*/