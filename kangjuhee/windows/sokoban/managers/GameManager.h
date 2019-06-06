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

struct Command {				// command pattern -> undo, redo
	int type = NULL;			
	bool hasBox = false;
};

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
	DEQUE<Command> commands;
	DEQUE<Command> undoCommands;

public:
	GameManager(WINDOW *parentWindow);
	~GameManager();
	void init();
	void update(IN int key);
	void render();
	void move(IN int key,bool undoClear);
	bool checkFinish();

	bool undo();
	bool redo();

	int getMoveCount();
	int getBoxCount();
	int getLevel();

	void nextLevel();

};
#endif

