#include <gtest/gtest.h>
#include "../game.hpp"
#include "../movement.hpp"
#include "../game.cpp"
//#include <ncurses.h>
#include <stdio.h>
#include <iostream>

TEST(GameTests,checkPlayerSymbol){
    Player playerDetails = getPlayerLocation();
    ASSERT_EQ(playerDetails.playerSymbol,'G');
}

TEST(GameTest,playerInsideTheGridIsValid){
    Player playerLocation = getPlayerLocation();
    EXPECT_TRUE(((playerLocation.playerLocation.x >= 0) && (playerLocation.playerLocation.x <= 12)));
    EXPECT_TRUE(((playerLocation.playerLocation.y >= 0) && (playerLocation.playerLocation.y <= 12)));
}

TEST(GameTest,playerStartingLocation){
    Player playerStartingLocation = getPlayerStartingLocation();
    ASSERT_EQ(playerStartingLocation.playerLocation.x,1);
    ASSERT_EQ(playerStartingLocation.playerLocation.y,11);
}

TEST(GameTest,playerOutsideTheGridIsInvalid){
    Player playerLocation = getPlayerLocation();
    EXPECT_FALSE(((playerLocation.playerLocation.x < 0) && (playerLocation.playerLocation.x > 12)));
    EXPECT_FALSE(((playerLocation.playerLocation.y < 0) && (playerLocation.playerLocation.y > 12)));
    
}

TEST(GameTest,totalNumberOfEnemiesAreFive){
    //Trap trapLocation = getPlayerLocation();
    int numberOfTraps = globalTrapLocations;
    ASSERT_EQ(numberOfTraps,5);
    
}