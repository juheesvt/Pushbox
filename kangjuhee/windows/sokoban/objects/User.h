//
// Created by jh_svt on 19. 5. 26.
//

#ifndef SOKOBAN_USER_H
#define SOKOBAN_USER_H
#include "../utils/define.h"
#include <curses.h>
#include "Object.h"
class User:public Object {
private:
	PRINT_CHAR CHARACTER[3] = "  ";
	PRINT_COLOR COLOR = RED_RED;
public:
	User(int x,int y,WINDOW *parentWindow);
	~User();
	virtual void render();
	virtual void update(IN int key);
};


#endif //SOKOBAN_USER_H
