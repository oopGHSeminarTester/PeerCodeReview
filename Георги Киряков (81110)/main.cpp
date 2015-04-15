//
//  main.cpp
//  BullsAndCows
//
//  Created by Georgi Kiryakov on 4/6/15.
//  Copyright (c) 2015 Georgi Kiryakov. All rights reserved.
//

#include <iostream>
#include "BullsAndCows.h"

int main() {
    std::cout << "Please select game mode:";
    std::cout<<"\n\t2 \n\t3 \n\t4\n>>";
    
    int n;
    std::cin>>n;
    
    try {
        BullsAndCows game(n);
        game.Start();
    } catch (const std::exception& e) {
        std::cout<<e.what()<<std::endl;
    }
    
    return 0;
}
