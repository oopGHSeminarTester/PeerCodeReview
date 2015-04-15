/*
 * main.cpp
 *
 *  Created on: 9.04.2015 г.
 *      Author: Erol Hadzhi 81201
 */

#include <iostream>
#include "BullsAndCows.h"
using namespace std;

int main()
{
	int number[4] ={8,2,3,9};
	BullsAndCows first(number,4);
	first.Start();
	return 0;
}
