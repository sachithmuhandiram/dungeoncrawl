#include "game.hpp"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <curses.h>

std::vector<Player> globalPlayerLocation(1);
std::vector<Trap> globalTrapLocations(5);

Player getPlayerLocation(){
    Player playerDetails;

    //playerDetails.playerSymbol = 'G';
    playerDetails.playerLocation.x = 5;
    playerDetails.playerLocation.y = 11;

    return playerDetails;

}

Player getPlayerStartingLocation(){

    Player playerStartingLocation {};

    playerStartingLocation.playerLocation.x = 1;
    playerStartingLocation.playerLocation.y = 11;

    return playerStartingLocation;
}

// std::vector<Trap> getTrapLocations(){

// }

void setPlayerLocation(Player player){

    globalPlayerLocation[0].playerSymbol = 'G';

    // These two should be with movements of the user
    globalPlayerLocation[0].playerLocation.x = 5;
    globalPlayerLocation[0].playerLocation.y = 10;

}

void setTrapLocations(Trap trap){

    for (int i = 0; i < sizeof(globalTrapLocations); i++)
    {
        globalTrapLocations[0].trapSymbol = 'T';
        // These two should be random
        globalTrapLocations[0].trapLocation.x = 4;
        globalTrapLocations[0].trapLocation.y = 4;
    }

}

void captureUserMovement(){

    std::vector<Player> userOldLocation = globalPlayerLocation;

    int c = 0;
        unsigned char ch1 = getchar();

        std::cout <<" User pressed : " << ch1 << std::endl;
        if (ch1 == KEY_ARROW_CHAR1)
        {
            unsigned char ch2 = getchar();
            switch(ch2) {
            case KEY_UP:
                std::cout << std::endl << "Up" << std::endl;//key up
                // y value increamentd
                break;
            case KEY_DOWN:
                std::cout << std::endl << "Down" << std::endl;   // key down
                // y val decremented
                break;
            case KEY_LEFT:
                std::cout << std::endl << "Left" << std::endl;  // key left
                // x val decremented
                break;
            case KEY_RIGHT:
                std::cout << std::endl << "Right" << std::endl;  // key right
                // x val incremented
                break;
            default:
                std::cout << std::endl << "null" << std::endl;  // not arrow
                break;
            }
        }
    
}