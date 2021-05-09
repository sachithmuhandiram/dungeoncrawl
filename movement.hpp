#include <ncurses.h>
#include <stdio.h>

void moveUp();
void moveDown();
void moveLeft();
void moveRight(); 
void display();

int yMax =15;
int xMax =15;
int yLocation,xLocation;

void display(){

    initscr(); // this must be top
    int height,width,start_x,start_y;
    
    height=15;
    width=15;
    start_x=start_y=1;
    xLocation=0;
    yLocation=1;

    WINDOW *win = newwin(height,width,start_y,start_x); 
    
    box(win,0,0);

    refresh();
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
            moveUp();
            break;
        case KEY_DOWN:
            moveDown();
            break;
        case KEY_LEFT:
            moveLeft();
            break;

        case KEY_RIGHT:
            moveRight();
            break;
        default:
            break;
        }
        wrefresh(win);
        mvwaddch(win,yLocation,xLocation,'f');
        
    }
    endwin();
}

void moveUp(){
    yLocation--;

    if (yLocation <1)
    {
        //std::cout << "up" << std::endl;
        yLocation =1;
    }
}

void moveDown(){
    yLocation++;

    if (yLocation > yMax-2)
    {
        yLocation = yMax-2; 
    }
}

void moveLeft(){
    xLocation--;

    if (xLocation < 1)
    {
        xLocation = 1;
    }
}

void moveRight(){
    xLocation++;
    if (xLocation > xMax-2)
    {
        xLocation = xMax-2;
    }
}
