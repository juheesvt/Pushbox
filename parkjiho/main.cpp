//
//  main.cpp
//  Pushbox
//
//  Created by Jiho Park on 14/05/2019.
//  Copyright © 2019 Jiho Park. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "ncurses.h"
#include "Map.hpp"
using namespace std;

bool IsTerminalAvailable = false; // Check this global variable before ncurses calls

void Print(Map *m) {
    initscr();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_YELLOW);
    init_pair(2, COLOR_RED, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_CYAN);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    border(' ',' ',' ',' ',' ',' ',' ',' ');
    attroff(COLOR_PAIR(2));
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            if(m->map[i][j].box != nullptr ){
                attron(COLOR_PAIR(2));
                mvprintw(1 + i, 1 + j*2, "[]");
                attroff(COLOR_PAIR(2));
            }
            else if(m->map[i][j].type == WALL) {
                attron(COLOR_PAIR(4));
                mvprintw(1 + i, 1 + j*2, "  ");
                attroff(COLOR_PAIR(4));
            }
            else if(m->map[i][j].type == DEST) {
                attron(COLOR_PAIR(5));
                mvprintw(1 + i, 1 + j*2, "  ");
                attroff(COLOR_PAIR(5));
            }
        }
    }
    
    attron(COLOR_PAIR(3));
    mvprintw(1 + m->myPos.row, 1 + m->myPos.col*2, "  ");
    attroff(COLOR_PAIR(3));
    refresh();
}
int main(int argc, const char *argv[])
{
    for (int argi = 1; argi < argc; argi++)
    {
        if (strcmp(argv[argi], "--debug-in-terminal") == 0)
        {
            printf("Debugging in terminal enabled\n");
            getchar(); // Without this call debugging will be skipped
            break;
        }
    }
    
    char *term = getenv("TERM");
    
    IsTerminalAvailable = (term != NULL);
    
    if (IsTerminalAvailable)
        IsTerminalAvailable = (initscr() != NULL);
    
    int x = 0, y = 0;
    Map *m = new Map();
    curs_set(0);
    while(true) {
        keypad(stdscr, true);
        Print(m);
        int ch;
        ch = getch();
        if(ch == KEY_RIGHT) {
            m->moveRight();
        }
        else if(ch == KEY_LEFT) {
            m->moveLeft();
        }
        else if(ch == KEY_UP){
            m->moveUp();
        }
        else if(ch == KEY_DOWN){
            m->moveDown();
        }
        else if(ch == KEY_END) {
            break;
        }
        clear();
    }
    
    endwin();
    
    if (IsTerminalAvailable)
    {
//        printw("Press any key to exit...");
        refresh();
        
        getch();
        
        endwin();
    }
    
    return 0;
}
