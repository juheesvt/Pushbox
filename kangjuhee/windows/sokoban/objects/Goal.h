//
// Created by jh_svt on 19. 5. 26.
//

#ifndef SOKOBAN_GOAL_H
#define SOKOBAN_GOAL_H
#include "../utils/define.h"
#include "Object.h"
class Goal:public Object {
private:
	PRINT_CHAR CHARACTER[3] = "  ";
	PRINT_COLOR COLOR = BLUE_BLUE;
public:
	Goal(int x, int y, WINDOW *parentWindow);
	~Goal();
	virtual void render();
	virtual void update(IN int key);
};


#endif //SOKOBAN_GOAL_H
