#ifndef BULLSANDCOWSS_H_INCLUDED
#define BULLSANDCOWSS_H_INCLUDED
int const MAX=10;
class BullsAndCows {
private:
int sizeOfContainer;
int* numbersContainer;
int numberOfGuesses;
public:
BullsAndCows(int);
BullsAndCows(int*,int) ;
int getSize ()const { return sizeOfContainer; }
int getLimit() const { return numberOfGuesses; }
int BullsElement(int);
void SetContainerSize(int);
void SetContainer(int*);
bool IsInsideContainer(int);
bool CowElement(int*,int, int);
bool BullElement(int*,int, int);
void TryToGuess(int);
};
void Start();
bool isDiffrent(int,BullsAndCows);
int howMany(int);

#endif // BULLSANDCOWSS_H_INCLUDED
