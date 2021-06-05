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

int globalTrapLocations {5};

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
    Location trapLocation;
    char trapSymbol = 'T';
};

struct Destination
{
    Location destinationLocation;
    char destinationSymbol = 'W';
};

// Global variables


Player getPlayerLocation();
Player getPlayerStartingLocation();

void setPlayerLocation(Player);
void setTrapLocations(Trap);

void setEnemies(WINDOW *win,int numberOfEnemies){

    int justCheck = numberOfEnemies;
    int * randomLocationArray = generateRandomNumber(numberOfEnemies*2);

    for (int i = 0; i < numberOfEnemies; i++)

        for (int i = 0; i < numberOfEnemies*2; i++)
        {
            for (int j = i; j < i+2; j++)
            {
                mvwaddch(win,randomLocationArray[j],randomLocationArray[j+1],'T');
            }
            
            
        }

}

int * generateRandomNumber(int requiredRandomNumbers){

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(25, 63); // define the range

    int randomNumberArray [requiredRandomNumbers];
    int randomNumber =0;
    for(int n=0; n<requiredRandomNumbers; ++n){

        randomNumber = distr(gen);
        randomNumberArray[n]=randomNumber;
    }

    return randomNumberArray;
}

#endif