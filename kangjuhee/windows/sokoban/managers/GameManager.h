#ifndef SOKOBAN_GAMEMANAGER_H
#define SOKOBAN_GAMEMANAGER_H

#include "../utils/FileManager.h"
#include "ObjectManager.h"
#include "../objects/User.h"

#include <string>
#include <curses.h>
#include <vector>
#include <deque>

#define VECTOR std::vector
#define DEQUE std::deque
#define STRING std::string

class GameManager
{
private:
	FileManager * gameMapData;
	ObjectManager *objectManager;
	WINDOW *parentWindow;
	User *user;
	int moveCount;
	int boxMoveCount;
	int level;
	DEQUE<int> command;
	DEQUE<int> undoCommand;

public:
	GameManager(WINDOW *parentWindow);
	~GameManager();
	void update(IN int key);
	void render();
	void undo();
	void redo();
	int getMoveCount();
	int getBoxCount();
	int getLevel();
	void init();
};
#endif

