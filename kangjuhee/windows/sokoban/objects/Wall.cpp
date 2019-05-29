#include "Wall.h"



Wall::Wall(int x,int y,WINDOW *parentWindow):Object(x,y,parentWindow)
{
}


Wall::~Wall()
{
}

void Wall::render() {
	wattron(this->parentWindow, COLOR_PAIR(this->COLOR));
	mvwprintw(this->parentWindow, this->y, this->x*2, (char *)this->CHARACTER);
	wattroff(this->parentWindow, COLOR_PAIR(this->COLOR));
}
void Wall::update(IN int key) {}