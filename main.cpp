#include <iostream>
#include "game.hpp"
#include "movement.hpp"

using namespace std;
bool isUserFallToATrap(int numberOfEnemies,Player );

// Player getPlayerLocation(){
//     Player playerDetails;

//     playerDetails.playerSymbol = 'G';
//     playerDetails.playerLocation.x = 5;
//     playerDetails.playerLocation.y = 5;

//     return playerDetails;

// }


int main(){

   display();
    // setPlayer();

    // setTraps(5);

    // Trap *trap = getTraps();

    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << "Trap " << i << " x : " << traps[i].trapLocation.x << " y : " << traps[i].trapLocation.y << std::endl;
    // }
    
    // Player *p = getPlayer();

    // p->playerLocation.x =10;
    // p->playerLocation.y =5;

    // bool trapped = isUserFallToATrap(5,*p);
    // if(trapped){
    //     std::cout << "User is :  " << trapped << std::endl;
    // }
    
    return 0;
}

// bool isUserFallToATrap(int numberOfEnemies, Player player){
//     // get enemy locations
  
//     for (int i = 0; i < numberOfEnemies; i++){

        
//             if(player.playerLocation.x == traps[i].trapLocation.x && player.playerLocation.y == traps[i].trapLocation.y){
//                 return true;
//             }

//         }
//     return false;
// }