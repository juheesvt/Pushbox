//
// Created by jh_svt on 19. 5. 26.
//

#include "Goal.h"
Goal::Goal(int x, int y, WINDOW *parentWindow,int type) :Object(x, y, parentWindow,type)
{
}


Goal::~Goal()
{
}

void Goal::render() {
	wattron(this->parentWindow, COLOR_PAIR(this->COLOR));
	mvwprintw(this->parentWindow, this->y, this->x*2, (char *)this->CHARACTER);

	wattroff(this->parentWindow, COLOR_PAIR(this->COLOR));
}
void Goal::update(IN int key) {}