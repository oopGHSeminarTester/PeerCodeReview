
/*

#include <iostream>
#include "BullsAndCows.h"

int main() {
	std::cout << "Please select game mode:";
	std::cout << "\n\t2 \n\t3 \n\t4\n>>";

	int n;
	std::cin >> n;

	BullsAndCows game(n);

	game.Start();

	return 0;
}*/


#include <iostream>
#include "BullsAndCows.h"

int main() {
	std::cout << "Please select game mode:";
	std::cout << "\n\t2 \n\t3 \n\t4\n>>";

	int n;
	std::cin >> n;

	BullsAndCows game(n);

	game.Start();

	return 0;
}