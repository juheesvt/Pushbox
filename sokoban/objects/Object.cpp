#include "Object.h"



Object::Object(int x,int y,WINDOW *parentWindow,int type):x(x),y(y),parentWindow(parentWindow),type(type)
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