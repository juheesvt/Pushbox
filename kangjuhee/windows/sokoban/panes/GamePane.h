#ifndef SOKOBAN_GAMEPANE_H
#define SOKOBAN_GAMEPANE_H

#include <string>
#include <curses.h>
#include "../panes/Pane.h"
#include "../utils/FileManager.h"

#define STRING std::string

class GamePane:public Pane
{
public:
	GamePane(int x, int y, int width, int height, SceneManager * sceneManager);
	~GamePane();
	virtual void render();// 영역을 그려주는 draw함는
	virtual void update(IN int key);// 영역을 그려주는 draw함는

private:
	FileManager * mapData;
};

#endif