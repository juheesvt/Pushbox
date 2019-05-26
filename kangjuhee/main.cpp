//
//  main.cpp
//  Pushbox
//
//  Created by Jiho Park on 14/05/2019.
//  Copyright © 2019 Jiho Park. All rights reserved.
//

//  g++ -o test ./main.cpp ./FileManager.cpp ./FileManager.h ./Map.cpp ./Map.hpp -lncurses -std=c++14

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "ncurses.h"
#include "utils/FileManager.h"
#include "Map.hpp"
using namespace std;

bool IsTerminalAvailable = false; // Check this global variable before ncurses calls
void startPage();
void Print(Map *);



int main(int argc, const char *argv[])
{
    // start page에서 옵션 위치
    int position[3][2]={{7,4},{8,4},{9,4}};
    int nowPosition=0;
    Map *m = new Map();
    startPage();

    while(true) {

        keypad(stdscr, true);
        int ch;
        ch = getch();
        attron(COLOR_PAIR(2));
        if(ch == KEY_RIGHT) {
            // TODO start page option
            //  - nowPosition = 0 , start game
            //  - nowPosition = 1 , view ranking
            //  - nowPosition = 0 , quit (ctrl+C)
            break;
        }
        else if(ch == KEY_LEFT) {
        }
        else if(ch == KEY_UP){
            mvprintw(position[nowPosition][0],position[nowPosition][1]," ");

            nowPosition--;
            if(nowPosition < 0){
                nowPosition=2;
            }

        }
        else if(ch == KEY_DOWN){
            mvprintw(position[nowPosition][0],position[nowPosition][1]," ");
            nowPosition=(nowPosition+1)%3;
        }
        else if(ch == KEY_END) {
            return 0;
        }
        else if(ch == KEY_BREAK){
        }
        mvprintw(position[nowPosition][0],position[nowPosition][1],">");
        attroff(COLOR_PAIR(2));
        refresh();
    }
    clear();

    // game start
    int x = 0, y = 0;
    curs_set(0);
    while(true) {
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

void startPage() { // init page

    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    bkgd(COLOR_PAIR(1));
    attron(COLOR_PAIR(1));



    refresh();
    attroff(COLOR_PAIR(1));

    refresh();
}

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