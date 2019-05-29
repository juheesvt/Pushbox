#include "Object.h"



Object::Object(int x,int y,WINDOW *parentWindow):x(x),y(y),parentWindow(parentWindow)
{
}


Object::~Object()
{
}

int Object::getX() {
	return x;
}
int Object::getY() {
	return y;
}
void Object::setX(int x) {
	this->x = x;
}
void Object::setY(int y) {
	this->y = y;
}
int Object::getType() {
	return type;
}
void Object::setType(int type) {
	this->type = type;
}
void Object::render() {
}
void Object::update(IN int key) {}