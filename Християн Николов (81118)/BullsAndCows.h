/*
 * BullsAndCows.h
 *
 *  Created on: Apr 6, 2015
 *      Author: Hristiyan Nikolov
 */

#ifndef BULLSANDCOWS_H_
#define BULLSANDCOWS_H_

class BullsAndCows {
private:
	int sizeOfContainer;
	int* numbersContainer;
	int numberOfGuesses;

	bool validateNumber(int number, int size);
	bool validateNumber(int digits[], int size);
	// Връща указател към масив в който се намира произволно число с различни цифри в интервала [from, to]
	int* randomNumber(int from, int to);

public:

	BullsAndCows(int size);
	BullsAndCows(int numbers[], int size);

	void SetContainerSize(int size);
	void SetContainer(int* container);
	bool IsInsideContainer(int number);
	bool CowElement(int* arr, int position, int value); // Проверява дали
	bool BullElement(int* arr, int position, int value);
	char* TryToGuess(int myGuess);
	void Start();

	~BullsAndCows();

};

#endif /* BULLSANDCOWS_H_ */
