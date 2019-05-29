#include "GameManager.h"

#define TO_STRING std::to_string

GameManager::GameManager(WINDOW *parentWindow):parentWindow(parentWindow)
{
	this->level = 1;
	init();
}
void GameManager::init() {
	this->moveCount = 0;
	this->boxMoveCount = 0;
	this->command.clear();
	this->undoCommand.clear();

	this->objectManager = new ObjectManager();
	this->gameMapData = new FileManager("datas/map"+TO_STRING(this->level)+".dat");
	for (int mi = 0; mi < this->gameMapData->getLineLength(); ++mi) {
		STRING row = this->gameMapData->getLine(mi);
		for (int ri = 0; ri < row.length(); ++ri) {
			switch (row[ri] - '0') {
			case WALL:
				objectManager->insertObject(new Wall(ri / 2 + 1, mi + 1, this->parentWindow));
				break;
			case ROAD:
				objectManager->insertObject(new Road(ri / 2 + 1, mi + 1, this->parentWindow));
				break;
			case USER:
				this->user = new User(ri / 2+1, mi+1, this->parentWindow);
				objectManager->insertObject(new Road(ri / 2 + 1, mi + 1, this->parentWindow));
				break;
			case BOX:
				objectManager->insertObject(new Box(ri / 2 + 1, mi + 1, this->parentWindow));
				break;
			case DEST:
				objectManager->insertObject(new Goal(ri / 2 + 1, mi + 1, this->parentWindow));
				break;
			}
		}
	}
}

GameManager::~GameManager()
{
	delete this->gameMapData;
	delete this->objectManager;
}

void GameManager::update(IN int key) {
	this->user->update(key);
	if (key == 'S' || key == 's') {
		this->level = (this->level + 1) % 11;
		if (this->level == 0) {
			this->level = 1;
		}
		this->init();
	}
	else if (key == KEY_LEFT) {
		this->user->setX(this->user->getX() - 1);
		this->moveCount++;
	}
	else if (key == KEY_RIGHT) {
		this->user->setX(this->user->getX() + 1);
		this->moveCount++;
	}
	else if (key == KEY_UP) {
		this->user->setY(this->user->getY() - 1);
		this->moveCount++;
	}
	else if (key == KEY_DOWN) {
		this->user->setY(this->user->getY() + 1);
		this->moveCount++;
	}

}
void GameManager::render() {
	this->objectManager->render();
	this->user->render();
}
int GameManager::getBoxCount() {
	return this->boxMoveCount;
}
int GameManager::getMoveCount() {
	return this->moveCount;
}
int GameManager::getLevel() {
	return this->level;
}