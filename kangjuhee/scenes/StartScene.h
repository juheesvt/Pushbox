//
// Created by jh_svt on 19. 5. 23.
//

#ifndef SOKOBAN_STARTSCENE_H
#define SOKOBAN_STARTSCENE_H

#include <ncurses.h>

#include "../utils/FileManager.h"
#include "../panes/MenuPane.h"

class StartScene :public Pane{
public:
    StartScene(int x, int y, int width, int height);
    ~StartScene();
    virtual void    render();
    virtual void    update(IN char key);
private:
    MenuPane        *menuPane;
    FileManager     *startData;
    int             x,y;
    int             width,height;
};


#endif SOKOBAN_STARTSCENE_H
