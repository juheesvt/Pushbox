//
// Created by jh_svt on 19. 5. 26.
//

#ifndef SOKOBAN_USER_H
#define SOKOBAN_USER_H
#include "../utils/define.h"

#define DEFAULT 0
#define T_T 1
#define SUCCESS 2

#include <curses.h>
#include "Object.h"
class User:public Object {
private:
	int status;
	PRINT_CHAR CHARACTER[3][4] = { "+_+" ,"T_T",">_<" };
	PRINT_COLOR COLOR = WHITE_RED;
public:
	User(int x,int y,WINDOW *parentWindow,int type);
	~User();
	virtual void render();
	virtual void update(IN int key);
	void setStatus(int status) {	this->status = status;		}
};


#endif
