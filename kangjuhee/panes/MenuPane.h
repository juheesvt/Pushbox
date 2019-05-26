//
// Created by jh_svt on 19. 5. 23.
//

#ifndef SOKOBAN_MENUPANE_H
#define SOKOBAN_MENUPANE_H

#include <ncurses.h>

#include "Pane.h"
#include "../utils/FileManager.h"

class MenuPane:public Pane {
public:
    MenuPane(int x, int y, int width, int height);
    ~MenuPane();
    void next();
    void prev();
    int getNowSelect();
    virtual void render();// 영역을 그려주는 draw함는
    virtual void update(IN char key);// 영역을 그려주는 draw함는

private:
    FileManager *menuData;
    const char *SELECT_CHAR = ">";
    const int MENU_NUM = 3;
    int nowSelect;
};


#endif
