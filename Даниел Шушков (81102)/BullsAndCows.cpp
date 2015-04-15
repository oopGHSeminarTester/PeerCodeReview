#include < iostream>
using namespace std;
#include "BullsAndCows.h"

void BullsAndCows::Start() {
	int input_guess;
	char *guess;

	while (is_it_right){
		cout << "Your guess: ";
		cin >> input_guess;

		guess = TryToGuess(input_guess);

		std::cout << guess << std::endl;
		delete[] guess;

		if (is_it_right == false)
			std::cout << "It took you " << numberOfGuesses << " guesses to finish the game\n";
	}

}
void BullsAndCows:: SetContainerSize(int size){

	if (size == 2)
		sizeOfContainer = 2;
	else if (size == 3)
		sizeOfContainer = 3;
	else sizeOfContainer = 4;
}

	BullsAndCows::	BullsAndCows(int size) {
		SetContainerSize(size);
		SetRandomContainer();
		numberOfGuesses = 0;
		is_it_right = true;



	}


	BullsAndCows::BullsAndCows(int numbers[], int size) {
		for (int i = 0; i < size; i++)
			numbersContainer[i] = numbers[i];
		SetContainer(numbers);
		numberOfGuesses = 0;
		is_it_right = true;
	}

	void BullsAndCows:: SetContainer(int* container){
		numbersContainer = new int[sizeOfContainer];

		for (int i = 0; i<sizeOfContainer; i++)
			numbersContainer[i] = container[i];

	}

	void BullsAndCows::SetRandomContainer()
	{
		int num;
		numbersContainer = new int[sizeOfContainer];

		srand(time(NULL));

		for (int i = 0; i < sizeOfContainer; i++)
			numbersContainer[i] = rand() % 10;

		numbersContainer[0] = rand() % 9 + 1;

		for (int i = 1; i<sizeOfContainer; i++) {
			do
				num = rand() % 10;
			while (IsInsideContainer(num));
			numbersContainer[i] = num;
		}


	}


	bool BullsAndCows::IsInsideContainer(int number){
		for (int i = 0; i < sizeOfContainer; i++)
			if (numbersContainer[i] == number)
				return true;
		return false;
	}


	bool BullsAndCows::CowElement(int* arr, int position, int value){
		if (arr[position] != value && IsInsideContainer(value))
			return 1;
		else
			return 0;

	}



	bool BullsAndCows:: BullElement(int* arr, int position, int value){
		if (arr[position] == value)
			return 1;
		else
			return 0;


	}




	char*  BullsAndCows::TryToGuess(int myGuess){
		int myGuess_copy = myGuess;
		/*for (int i = 0; i < sizeOfContainer; i++)
			cout << numbersContainer[i];*/
		bool flag = true;
		int cow_counter = 0;
		int bull_counter = 0;
		char* pointer =new  char[100];

		numberOfGuesses++;

		for (int i = sizeOfContainer - 1; i >=0; i--){
			if (CowElement(numbersContainer, i, myGuess % 10))
				cow_counter++;

			if (BullElement(numbersContainer, i, myGuess % 10))
				bull_counter++;
			myGuess /= 10;
		}

	//		cout << sizeof(&p);

		if (bull_counter == sizeOfContainer) {
			sprintf_s(pointer, 100, "[ %d ] => Congartulations! You made right guess!",myGuess_copy);
			is_it_right = false;
		}
		else
			sprintf_s(pointer,100,"[ %d ] => Cows:%d    Bulls:%d",myGuess_copy, cow_counter, bull_counter);

		return p;


	}