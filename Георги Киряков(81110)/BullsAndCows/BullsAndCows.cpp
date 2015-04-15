//
//  BullsAndCows.cpp
//  BullsAndCows
//
//  Created by Georgi Kiryakov on 4/6/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#include "BullsAndCows.h"


BullsAndCows::BullsAndCows(int size)
{
    SetContainerSize(size);
    SetRandomContainer();
    Init();
}

BullsAndCows::BullsAndCows(int numbers[], int size)
{
    SetContainerSize(size);
    SetContainer(numbers);
    Init();
}

BullsAndCows::~BullsAndCows() {
    delete[] numbersContainer;
    delete[] msg;
}

void BullsAndCows::Init()
{
    numberOfGuesses = 0;
    msg = new char[100];
    gameLoop = true;
}

void BullsAndCows::SetRandomContainer()
{
    int num;
    numbersContainer = new int[sizeOfContainer];
    
    srand(time(NULL));
    
    int zeroFix = rand()%10;
    for (int i=0; i < sizeOfContainer; i++)
        numbersContainer[i] = zeroFix;
    
    numbersContainer[0] = rand()%9 + 1;
    
    for (int i = 1; i<sizeOfContainer; i++) {
        do
            num = rand()%10;
        while (IsInsideContainer(num));
        numbersContainer[i] = num;
    }
}


/**
 * V else moje sizeOfContainer = DEF_SIZE
 */

void BullsAndCows::SetContainerSize(int size)
{
    if(size >= MIN_SIZE && size <= MAX_SIZE)
        sizeOfContainer = size;
    else
        throw std::invalid_argument("SetContainerSize: size error!");
}

/*
 * Kak da razberem kolko elementa ima int *container?
 */

void BullsAndCows::SetContainer(int *container)
{
    numbersContainer = new int[sizeOfContainer];
    
    if(container[0] == 0)
        throw std::invalid_argument("SetContainer: Number begins with ZERO!");
    
    for (int i=0; i<sizeOfContainer; i++)
        numbersContainer[i] = container[i];
}


bool BullsAndCows::IsInsideContainer(int number)
{
    for (int i = 0; i < sizeOfContainer; i++)
        if(numbersContainer[i] == number)
            return true;
    
    return false;
}

/**
 * Kakva e nujdata ot *arr 
 * kato mojem da izvikame numbersContainer[position]
 * i taka CowElement i BullElement
 * da priemat samo position i value
 */

bool BullsAndCows::CowElement(int *arr, int position, int value)
{
    return IsInsideContainer(value) && arr[position] != value;
}


bool BullsAndCows::BullElement(int *arr, int positon, int value)
{
    return arr[positon] == value;
}


char* BullsAndCows::TryToGuess(int guess)
{
    int bullCount = 0, cowCount = 0;
    
    numberOfGuesses++;
    
    int i = sizeOfContainer - 1;
    for (; i >= 0; i--) {
        if (BullElement(numbersContainer, i, guess%10))
            bullCount++;
        else if (CowElement(numbersContainer, i, guess%10))
            cowCount++;
        
        guess /= 10;
        if(guess == 0)
            break;
    }
    
    /**
     * if i > 0 guess has less digits
     * if i < 0 guess has more gigits
     */
    
    if(i != 0)
        sprintf(msg, "You must guess %d digit number ;)", sizeOfContainer);
    else if(bullCount != sizeOfContainer)
        sprintf(msg, "Cows: %d and Bulls: %d", cowCount, bullCount);
    else
    {
        sprintf(msg, "You made right guess!!!");
        gameLoop = false;
    }
        
    return msg;
}

void BullsAndCows::Start()
{
    int userGuess;
    //std::cout<<ToString()<<std::endl;
    std::cout<<"Try to guess my "<<sizeOfContainer<<" digit number!\n\n";
    
    while (gameLoop) {
        std::cout<<"Your guess: ";
        std::cin>>userGuess;
        
        std::cout<<TryToGuess(userGuess)<<std::endl;
        
        if(gameLoop == false)
            std::cout<<"It took you "<<numberOfGuesses<<" guesses to finish the game\n";
    }
}

std::string BullsAndCows::ToString()
{
    std::strstream str;
    for (int i = 0; i < sizeOfContainer; i++)
        str<<numbersContainer[i];
    
    str<<" | guesses made: "<<numberOfGuesses;
    
    return str.str();
}


