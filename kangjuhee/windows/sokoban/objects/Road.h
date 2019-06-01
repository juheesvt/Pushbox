#ifndef SOKOBAN_ROAD_H
#define SOKOBAN_ROAD_H
#include "../utils/define.h"
#include <curses.h>
#include "Object.h"
class Road :public Object
{
private:
	PRINT_CHAR CHARACTER[3] = "  ";
	PRINT_COLOR COLOR = WHITE_WHITE;
public:
	Road(int x, int y, WINDOW *parentWindow,int type);
	~Road();
	virtual void render();
	virtual void update(IN int key);
};
#endif

