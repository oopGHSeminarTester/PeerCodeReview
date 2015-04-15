#include<iostream>
#include <iomanip>
using namespace std;
#include"bullsandcowss.h"

BullsAndCows::BullsAndCows(int size){
if (size==2 || size==3 || size==4) {  sizeOfContainer = size ;}
else {  sizeOfContainer = 4;}
for(int i=0;i<sizeOfContainer;i++){
   if(i==0) { numbersContainer[i]=rand()%9+1;}
   else {
      for(int j=0;j<i;j++){
        while(numbersContainer[i]==numbersContainer[j]){
           numbersContainer[i]=rand()%10;
        }
      }
   }
}
numberOfGuesses=MAX;
}

BullsAndCows::BullsAndCows(int* numbers,int size1){
    sizeOfContainer=size1;
    numbersContainer=numbers;
    numberOfGuesses=MAX;
}
void BullsAndCows::SetContainerSize(int _size){
if(_size>4 || _size<2) { cout<<"The size must be 2,3,4!!"<<endl;}
else { sizeOfContainer=_size; }
}
void BullsAndCows::SetContainer(int* container){
numbersContainer=new int[sizeOfContainer];
int p=0;
while(container!=NULL){
p++;
}
if(sizeOfContainer!=p || container[0]==0){ cout<<"Your number is wrong!"<<endl; }
else { numbersContainer = container;}
}
bool BullsAndCows::IsInsideContainer(int x){
  for(int i=0;i<sizeOfContainer;i++){
     if( numbersContainer[i]==x) { return true;}
  }

  return false;
}
bool BullsAndCows::CowElement(int *arr,int position,int value){
    if(IsInsideContainer(value) && arr[position]!=value){
       return true;
    }
 return false;
}
bool BullsAndCows::BullElement(int *arrr,int positionn,int valuee){
    if(IsInsideContainer(valuee) && arrr[positionn]==valuee){ return true ;}
    return false;
}
int BullsAndCows::BullsElement(int vall){
   int bull1=0;
   for(int k=sizeOfContainer-1;k>=0;k--){
       if(BullElement(numbersContainer,k,(vall%10))){
        bull1++;
     }
     vall=vall/10;
   }
   return bull1;
}
void BullsAndCows::TryToGuess(int myGuess){
int p=myGuess;
int myGuesscopy=myGuess;
int br=0;
while(p>0){
p=p/10;
br++;
}
if(br!=sizeOfContainer) { cout<<setw(20)<<"Error!!"<<endl;}
else {
  int cow=0;
  int bull=0;
  for(int p=sizeOfContainer-1;p>=0;p--){
     if(CowElement(numbersContainer,p,(myGuesscopy%10))){
         cow++;
     }
     if(BullElement(numbersContainer,p,(myGuesscopy%10))){
        bull++;
     }
     myGuesscopy=myGuesscopy/10;
  }
  if(bull!=4) {
  cout<<setw(20)<<"["<<myGuess<<"] => "<<"Cows:"<<cow<<"     Bulls:"<<bull<<endl;
}}
 }
 bool isDiffrent(int number1,BullsAndCows p){
  int broi=0;
    for(int i=0;i<p.getSize();i++){
        int number2=number1;
        for(int j=i;j<p.getSize();j++){
           if(number1%10==number2%10) { broi=broi+1 ;}
           number2=number2/10;
        }
        number1=number1/10;
    }
    if(broi>4){ return true;}
    else { return false;}
}
int howMany(int num){
  int p=0;
  while(num>0){
    p++;
    num=num/10;
  }
  return p;
}
void Start(){
 int p[4]={1,4,5,2};
 BullsAndCows first(p,4);
 int number;
 for (int y=0;y<first.getLimit();y++){
 cout<<"Your guess: ";
 cin>>number;
 cout<<endl;
 if(howMany(number)!=first.getSize()) { cout<<setw(20)<<"Your number must be "<<first.getSize()<<" digits!"<<endl;}
 else {
 if(isDiffrent(number,first)) { cout<<setw(20)<<"Your digits must be diffrent!"<<endl;}
 else{
 if (first.BullsElement(number)==4) { cout<<setw(20)<<"["<<number<<"] => "<<"Congratualtions! You made a right guess!"<<endl;
 cout<<endl;
 cout<<endl;
 cout<<setw(15)<<"It took "<<y+1<<" step to guess the number!"<<endl;
 break;
 }
 else {
 first.TryToGuess(number);
   }
   if(y==first.getLimit()-1) { cout<<endl;
      cout<<setw(15)<<"Sorry you lose!"<<endl;
    }
}
}}
}
int main(){
 Start();
 return 0;
}
