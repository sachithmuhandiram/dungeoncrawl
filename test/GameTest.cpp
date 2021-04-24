#include <gtest/gtest.h>
#include "../game.hpp"

TEST(GameTests,checkPlayerSymbol){
    Player playerDetails = getPlayerLocation();
    ASSERT_EQ(playerDetails.playerSymbol,'G');
}

TEST(GameTest,playerOutsideTheGridInValid){
    Player playerLocation = getPlayerLocation();
    EXPECT_TRUE(((playerLocation.playerLocation.x >= 0) && (playerLocation.playerLocation.x <= 8)));
    EXPECT_TRUE(((playerLocation.playerLocation.y >= 0) && (playerLocation.playerLocation.y <= 12)));
}

// TEST(GameTest,playerOutsideTheGridisInvalid){
//     Player playerLocation = getPlayerLocation();
//     EXPECT_FALSE(((playerLocation.playerLocation.x < 0) && (playerLocation.playerLocation.x > 8)));
//     EXPECT_TRUE(((playerLocation.playerLocation.y < 0) && (playerLocation.playerLocation.y > 12)));
    
// }