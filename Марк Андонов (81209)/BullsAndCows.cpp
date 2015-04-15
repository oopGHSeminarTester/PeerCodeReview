/*
 * BullsAndCows.h
 *
 *  Created on: 08.04.2015 г.
 *      Author: Mark
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
using namespace std;

#include "BullsAndCows.h"

int *RandomNumber(int size) {
    bool flag=false;
    int number,a1,a2,a3,a4;
    int *numberarray=new int[100];
    srand (time(NULL));
    while(flag==false){
    switch(size){
    case 4:number=rand()%9000+1000;
            a1=number%10;   a2=number/10%10;    a3=number/100%10;   a4=number/1000;
                if((a1!=a2)&&(a1!=a3)&&(a1!=a4) && (a2!=a3)&&(a2!=a4) && (a3!=a4)) flag=true;
                break;
    case 3:number=rand()%900+100;
        a1=number%10;   a2=number/10%10;    a3=number/100;
            if((a1!=a2)&&(a1!=a3) && (a2!=a3)) flag=true;
            break;
    case 2:number=rand()%90+10;
            a1=number%10;   a2=number/10;
            if(a1!=a2) flag=true;
            break;

    }
    }
    for(int i=size-1;i>=0;i--)
    {
        numberarray[i]=number%10;
        number=number/10;
    }
    return numberarray;

}

BullsAndCows::BullsAndCows() {
    size=4;
    numbers=RandomNumber(size);
    numberOfGuesses=0;
}
BullsAndCows::BullsAndCows(int n) {
    if(n!=2 && n!=3) n=4;
    size=n;
    numbers=RandomNumber(size);
    numberOfGuesses=0;
}
BullsAndCows::BullsAndCows(int a[],int n) {
    if(n!=2 && n!=3) n=4;
    size=n;
    for(int i=size-1;i>=0;i--)
    {
        numbers[i]=a[i];
    }
    numberOfGuesses=0;
}

//селектори
int BullsAndCows::SizeOfContainer()  {
return size;
}
int* BullsAndCows::NumbersContainer()  {
return numbers;
}
int BullsAndCows::NumberOfGuesses()  {
return numberOfGuesses;
}

//мутатори
void BullsAndCows::SetContainerSize(int size_) {
 size=size_;
}
void BullsAndCows::SetContainer(int *container) {
numbers=container;
}
void BullsAndCows::SetNumberOfGuesses() {
numberOfGuesses++;
}

bool BullsAndCows::IsInsideContainer(int x) {
bool flag=false;
for(int i=0;i<size;i++)
    if(numbers[i]==x) flag=true;
return flag;
}

bool BullsAndCows::CowElement(int *arr,int position,int value) {
    bool flag=false;
    for(int i=0;i<size;i++)
    if(arr[i]==value && i!=position) flag=true;
return flag;
}

bool BullsAndCows::BullElement(int *arr,int position,int value) {
    return arr[position]==value;
}

char* BullsAndCows::TryToGuess(int myGuess) {
    //char c[1000]="";
    char *c=new char[100];
    int cows=0,bulls=0;
    for(int i=this->SizeOfContainer()-1;i>=0;i--) {
        if(BullElement(this->NumbersContainer(),i,myGuess%10)) bulls++;
        if(CowElement(this->NumbersContainer(),i,myGuess%10)) cows++;
         myGuess=myGuess/10;
    }
    if(bulls==this->SizeOfContainer()) strcpy(c,"Congratulations! You made a right guess!");
   else { strcpy(c,"Cows:     Bulls: "); c[5]=cows+'0';c[16]=bulls+'0';}
    this->SetNumberOfGuesses();
   return c;
}
void start() {
BullsAndCows  p=BullsAndCows();
int myGuess;
do  {
    cout<<"Your guess is:"; cin>>myGuess;
    cout<<"              ";
    cout<<p.TryToGuess(myGuess);
    cout<<endl;
}
while(strcmp(p.TryToGuess(myGuess),"Congratulations! You made a right guess!")!=0);
cout<<endl;
cout<<"        It took you "<<p.NumberOfGuesses()/2<<" guesses to finish the game";
}
