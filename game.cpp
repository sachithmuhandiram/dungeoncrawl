#include "game.hpp"
#include <vector>

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

std::vector<Trap> getTrapLocations(){

}

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
        // These tow should be random
        globalTrapLocations[0].trapLocation.x = 4;
        globalTrapLocations[0].trapLocation.y = 4;
    }

}