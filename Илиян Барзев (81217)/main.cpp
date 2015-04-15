#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class BullsAndCows
{
private:
    int sizeOfContainer;
    int* numbersContainer;
    int numberOfGuesses;

public:

    BullsAndCows(int size)
    {
        SetContainerSize(size);

        int number[size];
        srand(time(0));
        for (int i = 0; i < size; i++)
        {
            number[i] = rand() % 10;
            if (i == 0) number[i] = rand() % 9 + 1;
            for(int j = 0; j < i; j++) if (number[j] == number[i]) i--;
        }
    }

    BullsAndCows(int numbers[] , int size)
    {
        SetContainerSize(size);
        SetContainer(numbers);
    }

    void SetContainerSize(int size)
    {
        if (size > 1 && size < 5) sizeOfContainer = size;
        else cerr << "Size must be 2, 3, or 4.";
    }

    void SetContainer(int* container)
    {
        numbersContainer = container;
        if (container[0] == 0) cerr << "Number must not begin with 0";
            else for (int i = 0; i < sizeOfContainer; i++) numbersContainer[i] = container[i];
    }
    bool IsInsideContainer(int number)
    {
        bool inside = false;
        for (int i = 0; i < sizeOfContainer; i++)
        {
            if (numbersContainer[i] == number) inside = true;
        }
        return inside;
    }
    bool CowElement(int* arr, int position, int value)
    {

    }
    bool BullElement(int* arr, int position, int value)
    {

    }

    char* TryToGuess2(int myGuess)
    {


    }

    char* TryToGuess3(int myGuess)
    {

    }

    char* TryToGuess4(int myGuess)
    {

    }

    char* TryToGuess(int myGuess)
    {
        if (myGuess > 9 && myGuess < 100) TryToGuess2();
            else if (myGuess > 99 && myGuess < 1000) TryToGuess3();
                else if (myGuess > 999 && myGuess < 10000) TryToGuess4();
                    else cerr << "You have entered a wrong number";
    }
};


void Start()
{

}

int main()
{
    Start();
    return 0;
}
