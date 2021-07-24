#ifndef GAME_HPP
#define GAME_HPP

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ARROW_CHAR1 224

#include <vector>
#include <ncurses.h>
#include <random>
#include <iostream>

int globalTrapLocations {5};
int * enemyLocations;
int numberOfTraps =5;

void captureUserMovement();
void setEnemies(WINDOW *win,int);
int * generateRandomNumber(int );


struct Location
{
    int x=1;
    int y=1;
};

struct Player
{
    Location playerLocation;
    char playerSymbol = 'G';
};

struct Trap
{
    int trapNumber;
    Location trapLocation;
    char trapSymbol = 'T';
};

struct Destination
{
    Location destinationLocation;
    char destinationSymbol = 'W';
};

// Global variables

Trap *traps = new Trap[numberOfTraps]; // = {5};
Player *player = new Player[1];


Player getPlayerLocation();
Player getPlayerStartingLocation();

void setPlayerLocation(Player);
void setTrapLocations(Trap);
void logUserAndTraps(std::string);
//void setEnemies(WINDOW *win,int numberOfEnemies){
void setPlayer(){

    player->playerSymbol = 'P';
    player->playerLocation.x = 1;
    player->playerLocation.y = 1;

}

Player * getPlayer(){

    return player;
}


void setTraps(int numberOfEnemies){
    enemyLocations = generateRandomNumber(numberOfEnemies*2);
    //Trap *traps = new Trap();

    for (int i = 0; i < numberOfEnemies; i++){
            traps[i].trapNumber =i;
            traps[i].trapLocation.x = enemyLocations[((i+1)*2-2)];
            traps[i].trapLocation.y = enemyLocations[((i+1)*2-1)];
            traps[i].trapSymbol = 'T';

            //mvwaddch(win,traps[i].trapLocation.x,traps[i].trapLocation.y,traps[i].trapSymbol);
        }

}

Trap* getTraps(){

    return traps;
}

void showTraps (WINDOW *win,Trap *t,int totalTraps){

    for (int i = 0; i < totalTraps; i++)
    {
       mvwaddch(win,t[i].trapLocation.x,t[i].trapLocation.y,t[i].trapSymbol);
    }
    
}
int * generateRandomNumber(int requiredRandomNumbers){

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(2, 12); // define the range

    static int randomNumberArray[10];   // This has to be there to get numbers to random order

    int randomNumber =0;
    for(int n=0; n<requiredRandomNumbers; ++n){

        randomNumber = distr(gen);
        randomNumberArray[n]=randomNumber;
    }
    
    return randomNumberArray;
}


bool isUserFallToATrap(int numberOfEnemies,Player p);

#endif