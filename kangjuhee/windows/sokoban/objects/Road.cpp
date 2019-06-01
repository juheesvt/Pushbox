#include "Road.h"
Road::Road(int x, int y, WINDOW *parentWindow,int type) :Object(x, y, parentWindow,type)
{
}


Road::~Road()
{
}

void Road::render() {
	wattron(this->parentWindow, COLOR_PAIR(this->COLOR));
	mvwprintw(this->parentWindow, this->y, this->x*2, (char *)this->CHARACTER);

	wattroff(this->parentWindow, COLOR_PAIR(this->COLOR));
}
void Road::update(IN int key) {}