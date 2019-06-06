//
// Created by jh_svt on 19. 5. 26.
//

#include "Box.h"
Box::Box(int x, int y, WINDOW *parentWindow,int type) :Object(x, y, parentWindow,type)
{
}


Box::~Box()
{
}

void Box::render() {
	wattron(this->parentWindow, COLOR_PAIR(this->COLOR));
	mvwprintw(this->parentWindow, this->y, this->x*PIXEL_SIZE, (char *)this->CHARACTER);

	wattroff(this->parentWindow, COLOR_PAIR(this->COLOR));
}
void Box::update(IN int key) {}