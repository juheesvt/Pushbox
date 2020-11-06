#ifndef SOKOBAN_OBJECTMANAGER_H
#define SOKOBAN_OBJECTMANAGER_H
#include <vector>
#include <utility>
#include <algorithm>
#include "../objects/Object.h"

#include "../objects/Wall.h"
#include "../objects/User.h"
#include "../objects/Box.h"
#include "../objects/Goal.h"
#include "../objects/Road.h"

#define VECTOR std::vector
#define PAIR std::pair
#define MAKE_PAIR std::make_pair
class ObjectManager {
public:
	ObjectManager();
	~ObjectManager();
	void render();
	Object* getObject(int x, int y);
	void insertObject(Object *object);
	void deleteObject(Object *object);
private:
	VECTOR<Object *> map;
};
#endif