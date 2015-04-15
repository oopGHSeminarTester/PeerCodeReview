/*
 * BullsAndCows.h
 *
 *  Created on: 08.04.2015 ã.
 *      Author: Mark
 */

#ifndef BullsAndCows_H_
#define BullsAndCows_H_

class BullsAndCows {
private:
	int size;
	int *numbers;
	int numberOfGuesses;
public:
    BullsAndCows();
	BullsAndCows(int);
	BullsAndCows(int *,int);
	int SizeOfContainer();
	int* NumbersContainer();
	int NumberOfGuesses();//int

	void SetContainerSize(int);
	void SetContainer(int*);
	void SetNumberOfGuesses();
	bool IsInsideContainer(int);
	bool CowElement(int* , int , int );
	bool BullElement(int*, int , int );
    char* TryToGuess(int);



};
  void Start();


#endif /* BullsAndCows_H_ */

