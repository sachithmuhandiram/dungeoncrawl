#ifndef GAME_HPP
#define GAME_HPP

void grid();

struct Location
{
    int x;
    int y;
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

Player getPlayerLocation();

#endif