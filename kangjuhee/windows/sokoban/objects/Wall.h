#ifndef SOKOBAN_WALL_H
#define SOKOBAN_WALL_H
#include "../utils/define.h"
#include <curses.h>
#include "Object.h"
class Wall:public Object
{
private:
	PRINT_CHAR CHARACTER[3] = "  ";
	PRINT_COLOR COLOR = BLACK_BLACK;
public:
	Wall(int x, int y, WINDOW *parentWindow);
	~Wall();
	virtual void render();
	virtual void update(IN int key);
};
#endif

