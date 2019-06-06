//
// Created by jh_svt on 19. 5. 26.
//

#ifndef SOKOBAN_GAMESCENE_H
#define SOKOBAN_GAMESCENE_H

#include <curses.h>

#include "../utils/FileManager.h"
#include "../panes/GamePane.h"
#include "../panes/InfoPane.h"
#include "../panes/GuidePane.h"

class GameScene :public Pane {
public:
	GameScene(int x, int y, int width, int height, SceneManager *SceneManager);
	~GameScene();
	virtual void    render();
	virtual void    update(IN int key);
private:
	int             x, y;
	int             width, height;
	GamePane		*gamePane;
	InfoPane		*infoPane;
	GuidePane		*guidePane;

};



#endif //SOKOBAN_GAMESCENE_H
