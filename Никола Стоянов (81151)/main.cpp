/**
  * Nikola Stoyanov, KN, 6th group, fn 81151
  * 08.04.2015
  */

#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "bullsAndCows.h"

int main ()
{
    srand(time(0));

    BullsAndCows game(4);
    game.Start();

    return 0;
}
