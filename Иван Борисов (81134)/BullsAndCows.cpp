/*
 * BullsAndCows.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: ivan
 */

//#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>


using namespace std;

#include "BullsAndCows.h"

int DEFAULT_SIZE = 4;
BullsAndCows::BullsAndCows(int size) {
	srand(time(NULL));
	this->setContainerSize(size);
	int* container = this->randomGameNumber();
	this->setContainer(container);
	this->numberOfGuesses = 0;
	this->endGame = false;

}
BullsAndCows::BullsAndCows(int numbers[],int size) {

	this->sizeOfContainer = size;
	int* nums = numbers;
	this->setContainer(nums);
	this->numberOfGuesses = 0;
	this->endGame = false;
}
void BullsAndCows::setContainerSize(int size){
	if(size <2 || size >4){
		cout<<"Invalid size.Size was set to "<<DEFAULT_SIZE;
		this->sizeOfContainer = DEFAULT_SIZE;
	}
	else
		this->sizeOfContainer = size;
}
void BullsAndCows::setContainer(int* container){

	numbersContainer = new int[sizeOfContainer];
	for (int i = 0; i <this->sizeOfContainer; i++){
		this->numbersContainer[i] = container[i];

	}
	delete[] container;

}

int BullsAndCows::randomNumberWithZero() {
	return  rand() % 10 ;
}
int BullsAndCows::randomNumberWithoutZero() {
	return  (rand() % 9) + 1;
}
int* BullsAndCows::randomGameNumber(){
	int* digits = new int[this->sizeOfContainer];
	int count_nums = 1;

	digits[0] = this->randomNumberWithoutZero();
	int curr_digit;
	bool checkDiffNum;

	while(count_nums < this->sizeOfContainer){
		do {
			checkDiffNum = true;
			curr_digit = this->randomNumberWithZero();

			for(int i= 0; i < count_nums; i++){
				if(digits[i] == curr_digit){
					checkDiffNum = false;
				}
			}
		}
		while(!checkDiffNum);
		digits[count_nums] = curr_digit;
		++count_nums;
	}

	return digits;
}

bool BullsAndCows::IsInsideContainer(int num){
	for (int i = 0; i < this->sizeOfContainer; i++) {
			if (this->numbersContainer[i] == num)
				return true;
	}
	return false;

}

//CowElement и BullElement съм ги направил без arr* ,понеже мисля че е излишно
//ние можем да достъпим this->numbersContainer директно
bool BullsAndCows::CowElement(int position, int value) {
	if(this->IsInsideContainer(value)){
		if(this->numbersContainer[position] == value)
			return false;
		else
			return true;
	}
	else return false;

}
bool BullsAndCows::BullElement(int position, int value) {
	if(this->IsInsideContainer(value)){
		if(this->numbersContainer[position] == value)
			return true;
		else
			return false;
	}
	else return false;

}

char* BullsAndCows::TryToGuess(int myGuess) {

	++this->numberOfGuesses;

	int pos_digit,cows = 0,bulls = 0;
	bool win = true;

	for(int i = this->sizeOfContainer-1; i>=0;i--){

		pos_digit = myGuess % 10;

		if(pos_digit != this->numbersContainer[i])
			win = false;
		if(this->BullElement(i,pos_digit))
			++bulls;
		if(this->CowElement(i,pos_digit))
			++cows;

		myGuess /= 10;
	}

	char* message = new char[50];
	if(win){
		this->endGame = true;

		sprintf (message,"Congratualtions! You made a right guess!");
		return message;

	}
	else {
		sprintf (message,"Cows: %d     Bulls: %d" , cows, bulls);
		return message;
	}


}
void BullsAndCows::Start() {

	int number;
	do {
		cout<<"Your guess:";
		cin>>number;

		cout<<"                        ["<<number<<"] => ";
		char* message;
		message = this->TryToGuess(number);
		cout<<message<<endl;
	}
	while(!this->endGame);
	cout<<"\n       It took you "<<this->numberOfGuesses<<"guesses to finish the game";

}
BullsAndCows::~BullsAndCows() {
	delete[] numbersContainer;
}

