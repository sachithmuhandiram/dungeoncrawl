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
    //setEnemies(5);
    // for (int i = 0; i < 5; i++)
    // {
    //     std::cout << "Iteration : " << i << std::endl;
    //     std::cout << "Enemy symbol :" << traps[i].trapSymbol << std::endl;

    //     std::cout << "location :" << traps[i].trapNumber << std::endl;
    //     std::cout << "trap x :" << traps[i].trapLocation.x << std::endl;
    //     std::cout << "trap y :" << traps[i].trapLocation.y << std::endl;
    //     std::cout << " " << std::endl;
    // }
    
    // Player p = getPlayerLocation();

    // bool trapped = isUserFallToATrap(numberOfEnemies,p);

    // if(trapped==true){
    //     cout << "Trapped " << endl;
    // }else{
    //    cout << "Not trapped " << endl;
    // }
    
    return 0;
}

bool isUserFallToATrap(int numberOfEnemies, Player player){
    // get enemy locations
  
    for (int i = 0; i < numberOfEnemies; i++){

        
            if(player.playerLocation.x == traps[i].trapLocation.x && player.playerLocation.y == traps[i].trapLocation.y){
                return true;
            }

        }
    return false;
}