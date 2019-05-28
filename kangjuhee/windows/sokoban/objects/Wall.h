#ifndef SOKOBAN_WALL_H
#define SOKOBAN_WALL_H
#include "../utils/define.h"
class Wall
{
public:
	Wall();
	~Wall();
private:
	PRINT_CHAR CHARACTER[3] = "  ";
	PRINT_COLOR COLOR = CYAN_CYAN;
	int x, y;
};
#endif

