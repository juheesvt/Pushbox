#include "ObjectManager.h"
#define ITERATOR VECTOR<Object *>::iterator
#define FIND_IF std::find_if
#define FIND std::find

ObjectManager::ObjectManager() {}
ObjectManager::~ObjectManager() {
//여기다가 세이브 소스를 넣어볼까요?

//////////////////
	for (ITERATOR iter = this->map.begin(); iter != this->map.end(); ++iter)
		delete *iter;
}
void ObjectManager::deleteObject(Object *object) {
	ITERATOR iter = FIND(this->map.begin(), this->map.end(), object);
	this->map.erase(iter);
}
void ObjectManager::insertObject(Object *object) {
	this->map.push_back(object);
}
Object* ObjectManager::getObject(int x, int y) {
	struct Equal {
		Equal(int x,int y) : x(x),y(y) {}

		bool operator()(Object * obj) {
			return obj->getX() == x && obj->getY() == y;
		}

		int x,y;
	};
	ITERATOR iter = FIND_IF(this->map.begin(), this->map.end(), Equal(x, y));
	if (iter != this->map.end())
		return *iter;
	else
		return NULL;
}
void ObjectManager::render() {
	for (ITERATOR iter = this->map.begin(); iter != this->map.end(); ++iter) {
		(*iter)->render();
	}
}
