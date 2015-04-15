#ifndef _BULLS_AND_COWS_H_
#define _BULLS_AND_COWS_H_

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

class BullsAndCows
{
public:
    static const int MIN_SIZE = 2;
    static const int MAX_SIZE = 4;

    struct GuessResult
    {
        GuessResult ();

        int bulls;
        int cows;
    };

public:
    BullsAndCows (int size);
    BullsAndCows (int numbers[], int size);
    ~BullsAndCows ();

    bool IsInsideContainer (int number);
    bool CowElement (int*, int position, int value);
    bool BullElement (int*, int position, int value);

    char* TryToGuess (int myGuess);
    void Start ();

    void SetContainerSize (int size);   // why???
    void SetContainer (int* container); // why???

private:
    GuessResult checkGuess (int* guess);
    bool validate (int* guess);
    void writeMessage (GuessResult res);

    int sizeOfContainer;
    int* numbersContainer;
    int numberOfGuesses;

    char* lastMessage;
    static const int MSG_SIZE = 128;
};

#endif // _BULLS_AND_COWS_H_
