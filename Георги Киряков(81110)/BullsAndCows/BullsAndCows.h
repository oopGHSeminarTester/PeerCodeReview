//
//  BullsAndCows.h
//  BullsAndCows
//
//  Created by Georgi Kiryakov on 4/6/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#ifndef __BullsAndCows__BullsAndCows__
#define __BullsAndCows__BullsAndCows__

#include <iostream>
#include <string>
#include <strstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#define DEF_SIZE 4
#define MIN_SIZE 2
#define MAX_SIZE 4


class BullsAndCows {
    
    int sizeOfContainer;
    int *numbersContainer;
    int numberOfGuesses;
    
    char* msg;
    bool gameLoop;
    
    void SetRandomContainer();
    
    void Init();
    
public:
    
    BullsAndCows(int size = DEF_SIZE);
    BullsAndCows(int numbers[], int size = DEF_SIZE);
    ~BullsAndCows();
    
    void SetContainerSize(int size = DEF_SIZE);
    void SetContainer(int* container);
    
    bool IsInsideContainer(int number);
    bool CowElement(int *arr, int position, int value);
    bool BullElement(int *arr, int position, int value);
    
    char* TryToGuess(int guess);
    
    void Start();
    std::string ToString();
};

#endif /* defined(__BullsAndCows__BullsAndCows__) */
