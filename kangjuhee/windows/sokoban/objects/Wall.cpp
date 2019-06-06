#include "Wall.h"



Wall::Wall(int x,int y,WINDOW *parentWindow,int type):Object(x,y,parentWindow,type)
{
}


Wall::~Wall()
{
}

void Wall::render() {
	wattron(this->parentWindow, COLOR_PAIR(this->COLOR));
	mvwprintw(this->parentWindow, this->y, this->x*PIXEL_SIZE, (char *)this->CHARACTER);
	wattroff(this->parentWindow, COLOR_PAIR(this->COLOR));
}
void Wall::update(IN int key) {}