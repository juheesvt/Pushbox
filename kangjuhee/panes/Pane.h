//
// Created by jh_svt on 19. 5. 23.
//

#ifndef SOKOBAN_PANE_H
#define SOKOBAN_PANE_H

#include <curses.h>
#include "../utils/define.h"


class Pane {
public:
    Pane(int x, int y, int width, int heigth);
    virtual ~Pane();
    virtual void render();
    virtual void update(IN char key);
    WINDOW * getWindow();                       // Scene

protected:
    int width, height;
    int x,y;
    WINDOW * pWindow;
};


#endif SOKOBAN_PANE_H
