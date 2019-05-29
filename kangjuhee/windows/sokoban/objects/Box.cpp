//
// Created by jh_svt on 19. 5. 26.
//

#include "Box.h"
Box::Box(int x, int y, WINDOW *parentWindow) :Object(x, y, parentWindow)
{
}


Box::~Box()
{
}

void Box::render() {
	wattron(this->parentWindow, COLOR_PAIR(this->COLOR));
	mvwprintw(this->parentWindow, this->y, this->x*2, (char *)this->CHARACTER);

	wattroff(this->parentWindow, COLOR_PAIR(this->COLOR));
}
void Box::update(IN int key) {}