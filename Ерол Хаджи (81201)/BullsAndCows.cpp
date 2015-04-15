/*
 * BullsAndCows.cpp
 *
 *  Created on: 9.04.2015 г.
 *      Author: Erol Hadzhi - 81201
 */

#include "BullsAndCows.h"
#include <iostream>
using namespace std;
#include <stdexcept>
#include <stdlib.h>
#include <ctime>


void BullsAndCows::setContainerSize(int size)
{
	if(size >=2 && size<=4)
		size_of_container=size;
	else
		throw invalid_argument("Size must be 2,3 or 4");
}
bool isContainerComptable(int* container,int size_of_container)  // checks if an array's first cell!=0 %% all cells are different
{
	bool flag=0;
	if( *(container)>=1 && *(container)<=9)
	{
		flag=1;
		for(int i=1;i<size_of_container;i++)
		{
			for(int j=(i-1);j>=0;j--)
			{
				if( *(container+i) == *(container+j) )
					flag=0;
			}
		}
	}
	return flag;
}
void BullsAndCows::setContainer(int* container)
{
	if( isContainerComptable(container,size_of_container) )
	{
		delete[] numbers_container;
		numbers_container = new int[size_of_container];
		for(int i=0;i<size_of_container;i++)
		{
			*(numbers_container+i)=*(container+i);
		}
	}
	else
		throw invalid_argument("Not a comptable container");
}
void populate_container(int* container,int size)  //TODO fix !!!! populates container with random compatable data
{
	while( !isContainerComptable(container,size) )
	{
		for(int i=0;i<size;i++)
		{
			*(container+i) = rand() %10;
		}
	}
}

BullsAndCows::BullsAndCows(int size)
: size_of_container(0),numbers_container(NULL),number_of_guesses(0)
{
	setContainerSize(size);
	int random_container[size];
	populate_container(random_container,size);
	setContainer(random_container);
}

BullsAndCows::BullsAndCows(int* container,int size=4)
: size_of_container(0),numbers_container(NULL),number_of_guesses(0)
{
	setContainerSize(size);
	setContainer(container);
}

BullsAndCows::BullsAndCows() : BullsAndCows(4)
{}

BullsAndCows::~BullsAndCows()
{
	delete[] numbers_container;
}

bool BullsAndCows::isInsideContainer(int digit)
{
	for(int i=0;i<size_of_container;i++)
	{
		if (digit==*(numbers_container+i) )
		{
			return 1;
		}
	}
	return 0;
}

bool BullsAndCows::CowDigit(int* arr,int position,int value)
{
	return (isInsideContainer(value) && (*(numbers_container+position) != value) );
}

bool BullsAndCows::BullDigit(int* arr,int position,int value)
{
	return (isInsideContainer(value) && (*(numbers_container+position) == value) );
}

bool BullsAndCows::TryToGuess(int myGuess)
{
	int myGuessContainer[size_of_container],cows=0,bulls=0;
	bool flag=0;

	int i;
	i = (size_of_container-1);
	while(myGuess!=0)
	{
		*(myGuessContainer+i)=(myGuess%10);
		i--;
		myGuess/=10;
	}

	if( isContainerComptable(myGuessContainer,size_of_container))
	{
		for(int i=0;i<size_of_container;i++)
		{
			if(BullDigit(myGuessContainer,i,*(myGuessContainer+i)) )
				bulls++;
			if(CowDigit(myGuessContainer,i,*(myGuessContainer+i)) )
				cows++;
		}
		if(bulls==4)
		{
			cout<<"Congratualtions! You made a right guess!"<<endl;
			flag=1;
		}
		else
		{
			cout<<"Cows:"<<cows<<"    Bulls:"<<bulls<<endl;
		}
	}
	return flag;
}


void BullsAndCows::Start()
{
	int myGuess;
	do
	{
		cout<<"Enter your guess : "; cin>>myGuess;
	}
	while( !TryToGuess(myGuess) );
}

