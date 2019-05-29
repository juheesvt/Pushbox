#include "ObjectManager.h"
#define ITERATOR MAP<PAIR<int,int>,Object *>::iterator
ObjectManager::ObjectManager() {}
ObjectManager::~ObjectManager() {
//����ٰ� ���̺� �ҽ��� �־���?

//////////////////
	for (ITERATOR iter = this->map.begin(); iter != this->map.end(); ++iter)
		delete iter->second;
}
void ObjectManager::insertObject(Object *object) {
	this->map[MAKE_PAIR(object->getX(), object->getY())] = object;
}
Object* ObjectManager::getObject(int x, int y) {
	if (this->map.find(MAKE_PAIR(x, y)) != this->map.end())
		return this->map[MAKE_PAIR(x, y)];
	else
		return NULL;
}
void ObjectManager::render() {
	for (ITERATOR iter = this->map.begin(); iter != this->map.end(); ++iter) {
		iter->second->render();
	}
}
