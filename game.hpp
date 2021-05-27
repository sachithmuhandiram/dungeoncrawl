#ifndef GAME_HPP
#define GAME_HPP

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ARROW_CHAR1 224

#include <vector>

void captureUserMovement();

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

#endif