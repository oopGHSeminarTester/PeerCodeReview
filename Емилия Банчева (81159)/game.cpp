#include <iostream>
#include <ctime>
#include <iomanip>
#include "BullsAndCows.h"
using namespace std;

BullsAndCows:: BullsAndCows(int size){
    numbersContainer = new int[size];
    SetContainerSize(size);
    for (int i = 0; i < sizeOfContainer; i++)
            numbersContainer[i] = -1;
    numberOfGuesses=0;
    srand(time(0));
    for(int i=0;i<size;i++){
        if(i==0)
        {
            numbersContainer[i]=1 + rand()%9;
        }
    else
        {
            numbersContainer[i]=rand()%10;
            for(int p=i-1; p>=0; p--)
            {
                if(numbersContainer[p]==numbersContainer[i])
                {
                    numbersContainer[i]=rand()%10;
                }
            }
        }
    }
}
BullsAndCows:: BullsAndCows(int* numbers , int size){
    SetContainerSize(size);
    SetContainer(numbers);
    numbers[size];
    numberOfGuesses=0;
}
void BullsAndCows:: SetContainerSize(int _size){
    if(_size<=4 && _size>=2)
        sizeOfContainer=_size;
}
void BullsAndCows:: SetContainer(int* container){
    numbersContainer=new int[sizeOfContainer];
    int p=0;
    while(p<sizeOfContainer){p++;}
    if(sizeOfContainer==p)
    {
        if(container[0]=0)
            cout<<"ERROR"<<endl;
        numbersContainer=container;
    }
    else
        cout<<"ERROR"<<endl;
}
bool BullsAndCows:: IsInsideContainer(int number){
    for(int i=0; i<sizeOfContainer; i++)
    {
        if(numbersContainer[i]==number)
            return true;
    }
}
bool BullsAndCows:: CowElement(int* arr, int position, int value){
    for(int i=0; i<sizeOfContainer; i++)
    {
        if(i!=position && arr[position]==value)
        {
                return true;
        }
    }
}
bool BullsAndCows:: BullElement(int* arr, int position, int value){
    return arr[position] == value;
}
void BullsAndCows:: TryToGuess(int myGuess){
    int _myGuess;
    int br=0;
    int cows=0;
    int bulls=0;
    while(myGuess/10!=0)
    {
        _myGuess=myGuess%10;
        myGuess/=10;
        int guesses[sizeOfContainer];
        for(int i=sizeOfContainer-1; i>=0; i--)
                {
                    guesses[i]=_myGuess;
                    if(CowElement(guesses,i,_myGuess))
                        cows++;
                        br++;
                    if(BullElement(guesses,i,_myGuess))
                        bulls++;
                        br++;
                }
    }
    if(bulls==4)
        cout<<"Congratulations, you guessed it!!"<<endl;
    else
        cout<<'\t'<<'\t'<<"["<<myGuess<<"] => Cows:"<<cows<<'\t'<<"Bulls:"<<bulls<<endl;
        cout<<endl;
        cout<<setw(15)<<"It took "<<br<<" step to guess the number!"<<endl;

}
void BullsAndCows::Start(){
    int myGuess;
    cout<<"Your guess: ";cin>>myGuess;
    cout<<endl;
    TryToGuess(myGuess);
}
BullsAndCows:: ~BullsAndCows()
{
    delete[] numbersContainer;
}

