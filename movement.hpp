#include <ncurses.h>
#include <stdio.h>

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

void display(){

    initscr(); // this must be top
    xLocation=1;
    yLocation=1;
    
    WINDOW *win = newwin(height,width,start_y,start_x); 
    box(win,0,0);

    refresh();
    mvwaddch(win,1,1,'f');
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
        mvwaddch(win,yLocation,xLocation,'f');
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
    mvwaddch(w,yLocation+1,xLocation,' ');
}

void moveDown(WINDOW *win){
    yLocation++;

    if (yLocation > yMax-2)
    {
        yLocation = yMax-2; 
    }
    mvwaddch(win,yLocation-1,xLocation,' ');
}

void moveLeft(WINDOW *win){
    xLocation--;

    if (xLocation < 1)
    {
        xLocation = 1;
    }
        mvwaddch(win,yLocation,xLocation+1,' ');
}

void moveRight(WINDOW *win){
    xLocation++;
    if (xLocation > xMax-2)
    {
        xLocation = xMax-2;
    }
    mvwaddch(win,yLocation,xLocation-1,' ');
}
