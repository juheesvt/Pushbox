//
// Created by jh_svt on 19. 5. 23.
//

#ifndef SOKOBAN_PANE_H
#define SOKOBAN_PANE_H

#include <curses.h>
#include <iostream>
#include "../utils/define.h"
#include "../managers/SceneManager.h"
class SceneManager;

class Pane {
public:
    Pane(int x, int y, int width, int heigth, SceneManager *sceneManage=NULL);
    ~Pane();
    virtual void render();
    virtual void update(IN int key);
    WINDOW * getWindow();                       // Scene

protected:
    int width, height;
    int x,y;
    WINDOW * pWindow;
	SceneManager *sceneManager;
};


#endif SOKOBAN_PANE_H
