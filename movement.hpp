#include <ncurses.h>
#include <stdio.h>
#include "game.hpp"
#include <cstdio> // for logging
#include <iostream>
#include <fstream>

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
    bool trapped = isUserFallToATrap(numberOfTraps);

    // std::cout << "Value returned : " << trapped << std::endl;
    // std::cout << "  " << std::endl;
    // std::fclose( stdout );

    if(trapped==1){
        mvwaddch(w,yLocation+1,xLocation,'D');
    }else{
        mvwaddch(w,yLocation+1,xLocation,'K');
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
    bool trapped = isUserFallToATrap(numberOfTraps);

    if(trapped==1){
        mvwaddch(w,yLocation+1,xLocation,'D');
    }else{
        mvwaddch(w,yLocation+1,xLocation,'K');
    }
}

void moveLeft(WINDOW *win){
    xLocation--;

    if (xLocation < 1)
    {
        xLocation = 1;
    }
        player->playerLocation.x--;
        mvwaddch(win,yLocation,xLocation+1,' ');
}

void moveRight(WINDOW *win){
    xLocation++;
    if (xLocation > xMax-2)
    {
        xLocation = xMax-2;
    }
    player->playerLocation.x++;
    mvwaddch(win,yLocation,xLocation-1,' ');
}

Player getPlayerLocation(){
    Player playerDetails;

    //playerDetails.playerSymbol = 'G';
    playerDetails.playerLocation.x = player->playerLocation.x;
    playerDetails.playerLocation.y = player->playerLocation.y;

    return playerDetails;

}

bool isUserFallToATrap(int numberOfEnemies){
    // get enemy locations
	//ifstream infile(fileName);
    Player p;
    p = getPlayerLocation();
    Trap *trap = getTraps();
    //std::freopen( "output.txt", "w", stdout );
    // std::freopen( "error.txt", "w", stderr );

    for (int i = 0; i < numberOfEnemies; i++){
        
            if(p.playerLocation.x == trap[i].trapLocation.x && p.playerLocation.y == trap[i].trapLocation.y){
                

                // std::cout << "Player Location  X : " << p.playerLocation.x << std::endl;
                // std::cout << " Player Y location : " << p.playerLocation.y << std::endl;
                // std::cerr << stderr << std::endl;              
                // std::fclose( stdout );
                // std::fclose(stderr);
                return true;
            }
           
            // std::cout << "Player Location  X : " << p.playerLocation.x << " Player Y location : " << p.playerLocation.y << std::endl;
            // std::cout <<   << std::endl;
            //std::cout << "Iteration : " << i << " : Trap Location x : " << trap[i].trapLocation.x << " Trap location Y : " << trap[i].trapLocation.y << std::endl;
            // std::cerr << stderr << std::endl;              
                
        }
       // std::fclose( stdout );
        //         std::fclose(stderr);
    return false;
}