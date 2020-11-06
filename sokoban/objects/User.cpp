//
// Created by jh_svt on 19. 5. 26.
//

#include "User.h"
User::User(int x,int y,WINDOW *parentWindow,int type) :Object(x,y,parentWindow,type) {
	this->status = DEFAULT;
}
User::~User() {}
void User::render() {
	wattron(this->parentWindow, COLOR_PAIR(this->COLOR));
	mvwprintw(this->parentWindow, this->y, this->x*PIXEL_SIZE, (char *)this->CHARACTER[this->status]);
	wattroff(this->parentWindow, COLOR_PAIR(this->COLOR));
}
void User::update(IN int key) {}