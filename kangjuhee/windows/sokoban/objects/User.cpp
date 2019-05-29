//
// Created by jh_svt on 19. 5. 26.
//

#include "User.h"
User::User(int x,int y,WINDOW *parentWindow) :Object(x,y,parentWindow) {}
User::~User() {}
void User::render() {
	wattron(this->parentWindow, COLOR_PAIR(this->COLOR));
	mvwprintw(this->parentWindow, this->y , this->x*2, (char *)this->CHARACTER);
	wattroff(this->parentWindow, COLOR_PAIR(this->COLOR));
}
void User::update(IN int key) {

}