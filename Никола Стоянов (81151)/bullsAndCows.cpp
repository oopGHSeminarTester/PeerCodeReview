#include "bullsAndCows.h"

BullsAndCows::GuessResult::GuessResult () :
    bulls(0),
    cows(0)
{
}

BullsAndCows::BullsAndCows (int size) :
    sizeOfContainer(0),
    numbersContainer(0),
    numberOfGuesses(0),
    lastMessage(0)
{
    if (size < MIN_SIZE || size > MAX_SIZE)
    {
        printf("ERROR: Invalid size\n");
    }

    numbersContainer = new int[size];
    sizeOfContainer = size;

    int poolSize = 10;
    int digitPool[poolSize];
    for (int i = 0; i < poolSize; i++)
    {
        digitPool[i] = i;
    }

    // first digit
    int digitIndx = (rand() % (poolSize - 1)) + 1;
    numbersContainer[0] = digitPool[digitIndx];
    std::swap(digitPool[digitIndx], digitPool[poolSize-1]);
    poolSize--;

    // other digits
    for (int i = 1; i < sizeOfContainer; i++)
    {
        digitIndx = rand() % poolSize;
        numbersContainer[i] = digitPool[digitIndx];
        std::swap(digitPool[digitIndx], digitPool[poolSize-1]);
        poolSize--;
    }

    lastMessage = new char[MSG_SIZE];
}

BullsAndCows::BullsAndCows (int numbers[], int size) :
    sizeOfContainer(0),
    numbersContainer(0),
    numberOfGuesses(0),
    lastMessage(0)
{
    if (size < MIN_SIZE || size > MAX_SIZE)
    {
        printf("ERROR: Invalid size\n");
    }

    numbersContainer = new int[size];
    sizeOfContainer = size;
    memcpy(numbersContainer, numbers, sizeof(int) * sizeOfContainer);

    lastMessage = new char[MSG_SIZE];
}

BullsAndCows::~BullsAndCows ()
{
    delete[] numbersContainer;
    delete[] lastMessage;
}

bool BullsAndCows::IsInsideContainer (int number)
{
    for (int i = 0; i < sizeOfContainer; i++)
    {
        if (numbersContainer[i] == number)
        {
            return true;
        }
    }
    return false;
}

bool BullsAndCows::CowElement (int*, int position, int value)
{
    return numbersContainer[position] != value && IsInsideContainer(value);
}

bool BullsAndCows::BullElement (int*, int position, int value)
{
    return numbersContainer[position] == value;
}

char* BullsAndCows::TryToGuess (int myGuess)
{
    int guessDigits[MAX_SIZE];
    for (int i = 0; i < sizeOfContainer; i++)
    {
        guessDigits[i] = myGuess % 10;
        myGuess /= 10;
    }
    if (myGuess)
    {
        printf("ERROR: Invalid guess format\n");
        return 0;
    }

    if (!validate(guessDigits))
    {
        printf("ERROR: Invalid guess format\n");
        return 0;
    }

    GuessResult res = checkGuess(guessDigits);
    numberOfGuesses++;

    writeMessage(res);
    return lastMessage;
}

BullsAndCows::GuessResult BullsAndCows::checkGuess (int* guess)
{
    GuessResult res;

    for (int i = 0; i < sizeOfContainer; i++)
    {
        if (CowElement(0, i, guess[i]))
        {
            res.cows++;
        }

        if (BullElement(0, i, guess[i]))
        {
            res.bulls++;
        }
    }

    return res;
}

void BullsAndCows::Start ()
{
    bool haveGuessed = false;

    while (!haveGuessed)
    {
        char guessStr[MAX_SIZE + 1];

        printf("Your guess: ");
        scanf(" ");     //eat the whitespaces
        fgets(guessStr, sizeOfContainer + 1, stdin);

        int guessDigits[MAX_SIZE];
        for (int i = 0; i < sizeOfContainer; i++)
        {
            guessDigits[i] = guessStr[i] - '0';
        }

        if (!validate(guessDigits))
        {
            printf("ERROR: Invalid guess format\n");
            continue;
        }

        GuessResult res = checkGuess(guessDigits);
        numberOfGuesses++;
        haveGuessed = (res.bulls == 4);
        writeMessage(res);
        printf("Guess %2d:        [%s] => %s\n", numberOfGuesses, guessStr, lastMessage);
    }
}

bool BullsAndCows::validate (int* guess)
{
    if (guess[0] == 0)
        return false;

    bool used[10] = {};
    for (int i = 0; i < sizeOfContainer; i++)
    {
        if (guess[i] < 0 || guess[i] > 9 || used[guess[i]])
        {
            return false;
        }
        used[guess[i]] = true;
    }

    return true;
}

void BullsAndCows::writeMessage(GuessResult res)
{
    if (res.bulls == 4)
    {
        sprintf(lastMessage, "Congratualtions! You made a right guess!");
    }
    else
    {
        sprintf(lastMessage, "Cows:%d    Bulls:%d", res.cows, res.bulls);
    }
}

void BullsAndCows::SetContainerSize (int size)
{
    if (sizeOfContainer != size)
    {
        int* newContainer = new int[size];
        int smallerSize = std::min(sizeOfContainer, size);

        memcpy(newContainer, numbersContainer, sizeof(int) * smallerSize);

        delete[] numbersContainer;
        numbersContainer = newContainer;
        sizeOfContainer = size;
    }
}

void BullsAndCows::SetContainer (int* container)
{
    memcpy(container, numbersContainer, sizeof(int) * sizeOfContainer);
}
