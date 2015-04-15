/*
 * BullsAndCows.h
 *
 *  Created on: 9.04.2015 г.
 *      Author: Erol Hadzhi 81201
 */

#ifndef BULLSANDCOWS_H_
#define BULLSANDCOWS_H_

class BullsAndCows
{
private:
	int size_of_container;  // 2,3,or 4
	int* numbers_container; // array pointer
	int number_of_guesses;
public:
	BullsAndCows();
	BullsAndCows(int size);
	BullsAndCows(int* arr,int size);
	//BullsAndCows(int number,int size); - TODO //number is converted to array

	void setContainerSize(int size);
	void setContainer(int* container);

	bool isInsideContainer(int digit);
	bool CowDigit(int* arr,int position,int value);
	bool BullDigit(int* arr,int position,int value);
	bool TryToGuess(int myGuess);
	void Start();

	~BullsAndCows();
};

#endif /* BULLSANDCOWS_H_ */
