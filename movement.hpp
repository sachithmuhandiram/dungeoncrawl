#include <ncurses.h>
#include <stdio.h>
#include "game.hpp"
#include <cstdio> // for logging
#include <iostream>
#include <fstream>
#include<string>

void moveUp(WINDOW *);
void moveDown(WINDOW *);
void moveLeft(WINDOW *);
void moveRight(WINDOW *); 
void display();

int yMax =15;
int xMax =15;
int yLocation,xLocation;
    
int height=15;
int width=15;
int start_x=1;
int start_y=1;

Trap *trap;
//Player *player = new Player[1];

void display(){

    initscr(); // this must be top
    xLocation=1;
    yLocation=1;
    
    WINDOW *win = newwin(height,width,start_y,start_x); 
    box(win,0,0);

    refresh();
    setPlayer();
    player = getPlayer();

    mvwaddch(win,player->playerLocation.x,player->playerLocation.y,player->playerSymbol);
    
    setTraps(numberOfTraps);

    trap = getTraps();

    showTraps(win,trap,numberOfTraps);
    wrefresh(win);
    keypad(win,true);
    // above two should be in line
    
   // int c = wgetch(win);
    while (1)
    {
       // display();
        int choices = wgetch(win);
        
        switch (choices)
        {
        case KEY_UP:
            
            moveUp(win);
            break;
        case KEY_DOWN:
            
            moveDown(win);
            break;
        case KEY_LEFT:
            
            moveLeft(win);
            break;

        case KEY_RIGHT:
            
            moveRight(win);
            break;
        default:
            break;
        }
        mvwaddch(win,yLocation,xLocation,'P');
        wrefresh(win);
        
    }
    endwin();

}

void moveUp(WINDOW *w){
    yLocation--;

    if (yLocation <1)
    {
        yLocation =1;
    }
    player->playerLocation.y--;
    
    //check whether user jumped to a trap 
    bool trapped = isUserFallToATrap(numberOfTraps,*player);

    if(trapped){

        mvwaddch(w,yLocation+1,xLocation,'D');
    }else{

        mvwaddch(w,yLocation+1,xLocation,' ');
    }
    //std::fclose( stdout );

}

void moveDown(WINDOW *w){
    yLocation++;

    if (yLocation > yMax-2)
    {
        yLocation = yMax-2; 
    }
    player->playerLocation.y++;
    bool trapped = isUserFallToATrap(numberOfTraps,*player);

    if(trapped){
        mvwaddch(w,yLocation+1,xLocation,'D');
    }else{
        mvwaddch(w,yLocation+1,xLocation,' ');
   }
}

void moveLeft(WINDOW *win){
    xLocation--;

    if (xLocation < 1)
    {
        xLocation = 1;
    }
        player->playerLocation.x--;
        bool trapped = isUserFallToATrap(numberOfTraps,*player);
        if(trapped){
        mvwaddch(win,yLocation+1,xLocation,'D');
        }else{
            mvwaddch(win,yLocation+1,xLocation,' ');
        }
}

void moveRight(WINDOW *win){
    xLocation++;
    if (xLocation > xMax-2)
    {
        xLocation = xMax-2;
    }
    player->playerLocation.x++;
    bool trapped = isUserFallToATrap(numberOfTraps,*player);
        if(trapped){
            mvwaddch(win,yLocation+1,xLocation,'D');
        }else{
            mvwaddch(win,yLocation+1,xLocation,' ');
        }
}

Player getPlayerLocation(){
    Player playerDetails;

    //playerDetails.playerSymbol = 'G';
    playerDetails.playerLocation.x = player->playerLocation.x;
    playerDetails.playerLocation.y = player->playerLocation.y;

    return playerDetails;

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

void logUserAndTraps(std::string data){


    std::freopen( "output.txt", "w", stdout );
    std::cout << "Player is : " << data  << std::endl;
    std::cout << "" << std::endl;

     std::fclose( stdout );
}