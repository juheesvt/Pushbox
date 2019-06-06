//
// Created by jh_svt on 19. 5. 26.
//

#ifndef SOKOBAN_BOX_H
#define SOKOBAN_BOX_H
#include "../utils/define.h"
#include "Object.h"
class Box:public Object {
private:
	PRINT_CHAR CHARACTER[4] = "[ ]";
	PRINT_COLOR COLOR = WHITE_CYAN;
public:
	Box(int x, int y, WINDOW *parentWindow,int type);
	~Box();
	virtual void render();
	virtual void update(IN int key);
};


#endif //SOKOBAN_BOX_H
