/*
 * BullsAndCows.h
 *
 *  Created on: Apr 7, 2015
 *      Author: ivan
 */

#ifndef BULLSANDCOWS_H_
#define BULLSANDCOWS_H_

class BullsAndCows {

private:
	int sizeOfContainer;
	int* numbersContainer;
	int numberOfGuesses;
	bool endGame;

	void setContainer(int* container);
	void setContainerSize(int size);

	int* randomGameNumber();
	int randomNumberWithZero();
	int randomNumberWithoutZero();
	bool IsInsideContainer(int num);
	bool CowElement(int position, int value);
	bool BullElement(int position, int value);
	char* TryToGuess(int myGuess);



public:

	BullsAndCows(int size);
	BullsAndCows(int numbers[],int size);
	virtual ~BullsAndCows();

	void Start();
};

#endif /* BULLSANDCOWS_H_ */
