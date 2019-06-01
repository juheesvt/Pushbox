#ifndef SOKOBAN_OBJECT_H
#define SOKOBAN_OBJECT_H
#include "../utils/define.h"
#include <curses.h>
class Object
{
protected:
	int x, y;
	WINDOW *parentWindow;
	int type;
public:
	Object(int x, int y, WINDOW *parentWindow,int type);
	~Object();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int getType();
	void setType(int type);
	virtual void render();
	virtual void update(IN int key);
};

#endif