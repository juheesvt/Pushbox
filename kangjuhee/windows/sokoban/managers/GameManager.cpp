#include "GameManager.h"

#define TO_STRING std::to_string

GameManager::GameManager(WINDOW *parentWindow) :parentWindow(parentWindow)
{
	this->level = 1;
	this->objectManager = NULL;
	init();
}
void GameManager::init() {

	wclear(this->parentWindow);
	wbkgd(this->parentWindow, COLOR_PAIR(WHITE_YELLO));
	wborder(this->parentWindow, '|', '|', '-', '-', '*', '*', '*', '*');
	this->moveCount = 0;
	this->boxMoveCount = 0;

	this->commands.clear();
	this->undoCommands.clear();

	if (this->objectManager != NULL)
		delete this->objectManager;

	this->objectManager = new ObjectManager();
	this->gameMapData = new FileManager("datas/map" + TO_STRING(this->level) + ".dat");

	for (int mi = 0; mi < this->gameMapData->getLineLength(); ++mi) {
		STRING row = this->gameMapData->getLine(mi);
		for (int ri = 0; ri < row.length(); ++ri) {
			switch (row[ri] - '0') {
			case WALL:
				objectManager->insertObject(new Wall(ri / 2 + 1, mi + 1, this->parentWindow, WALL));
				break;
			case ROAD:
				objectManager->insertObject(new Road(ri / 2 + 1, mi + 1, this->parentWindow, ROAD));
				break;
			case USER:
				this->user = new User(ri / 2 + 1, mi + 1, this->parentWindow, USER);
				//objectManager->insertObject(new Road(ri / 2 + 1, mi + 1, this->parentWindow, ROAD));
				break;
			case BOX:
				objectManager->insertObject(new Box(ri / 2 + 1, mi + 1, this->parentWindow, BOX));
				break;
			case DEST:
				objectManager->insertObject(new Goal(ri / 2 + 1, mi + 1, this->parentWindow, DEST));
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

void GameManager::move(IN int key, bool undoClear = true) {
	this->user->setStatus(T_T);

	int xDelta = 0;
	int yDelta = 0;

	switch (key) {
	case KEY_UP:
		yDelta = -1;
		break;
	case KEY_DOWN:
		yDelta = 1;
		break;
	case KEY_LEFT:
		xDelta = -1;
		break;
	case KEY_RIGHT:
		xDelta = 1;
		break;
	}

	Object *nextObj = this->objectManager->getObject(this->user->getX() + xDelta, this->user->getY() + yDelta);
	if (nextObj != NULL && (nextObj->getType() == BOX || nextObj->getType() == BOX_ON_DEST)) {
		if (this->user->getY() - 2 > MAP_MIN_SIZE
			&& this->user->getY() + 2 < MAP_MAX_SIZE
			&& this->user->getX() - 2 > MAP_MIN_SIZE
			&& this->user->getX() + 2 < MAP_MAX_SIZE
			) {
			Object *doubleNextObj = this->objectManager->getObject(this->user->getX() + xDelta * 2, this->user->getY() + yDelta * 2);
			if (doubleNextObj != NULL && (doubleNextObj->getType() == ROAD || doubleNextObj->getType() == DEST)) {
				this->user->setStatus(DEFAULT);

				nextObj->setY(doubleNextObj->getY());
				nextObj->setX(doubleNextObj->getX());

				int userType = this->user->getType();
				if (nextObj->getType() == BOX_ON_DEST) {
					this->user->setType(USER_ON_DEST);
				}
				else {
					this->user->setType(USER);
				}
				if (doubleNextObj->getType() == DEST) {
					nextObj->setType(BOX_ON_DEST);
					this->user->setStatus(SUCCESS);
				}
				else {
					nextObj->setType(BOX);
				}
				if (doubleNextObj->getType() == DEST && userType == USER) {
					this->objectManager->deleteObject(doubleNextObj);
					this->objectManager->insertObject(new Road(this->user->getX(), this->user->getY(), this->parentWindow, ROAD));
				}
				else if (doubleNextObj->getType() == ROAD && userType == USER_ON_DEST) {
					this->objectManager->deleteObject(doubleNextObj);
					this->objectManager->insertObject(new Goal(this->user->getX(), this->user->getY(), this->parentWindow, DEST));
				}
				else {
					doubleNextObj->setY(this->user->getY());
					doubleNextObj->setX(this->user->getX());
				}
				this->user->setX(this->user->getX() + xDelta);
				this->user->setY(this->user->getY() + yDelta);
				this->moveCount++;
				this->boxMoveCount++;

				Command command = { key, true };
				this->commands.push_back(command);
				if (undoClear)
					this->undoCommands.clear();
			}

		}

	}
	else if (nextObj != NULL && (nextObj->getType() == ROAD || nextObj->getType() == DEST)) {
		this->user->setStatus(DEFAULT);

		int userType = this->user->getType();
		if (nextObj->getType() == DEST) {
			this->user->setType(USER_ON_DEST);
		}
		else {
			this->user->setType(USER);
		}

		if (userType == USER_ON_DEST && nextObj->getType() == ROAD) {
			this->objectManager->deleteObject(nextObj);
			this->objectManager->insertObject(new Goal(this->user->getX(), this->user->getY(), this->parentWindow, DEST));
		}
		else if (userType == USER && nextObj->getType() == DEST) {
			this->objectManager->deleteObject(nextObj);
			this->objectManager->insertObject(new Road(this->user->getX(), this->user->getY(), this->parentWindow, ROAD));
		}
		else {
			nextObj->setX(this->user->getX());
			nextObj->setY(this->user->getY());
		}
		this->user->setX(this->user->getX() + xDelta);
		this->user->setY(this->user->getY() + yDelta);

		this->moveCount++;

		Command command = { key, false };
		this->commands.push_back(command);
		if (undoClear)
			this->undoCommands.clear();

	}

}
bool GameManager::checkFinish() {

	for (int row = 1; row < MAP_MAX_SIZE; ++row) {
		for (int col = 1; col < MAP_MAX_SIZE; ++col) {
			Object *object = this->objectManager->getObject(col, row);
			if (object != NULL && object->getType() == BOX) {
				return false;
			}
		}
	}

	Rank temp = rank.GetRanking()[this->level - 1];

	if (temp.move_count > 0 && temp.move_count + temp.box_count > this->moveCount + this->boxMoveCount)
		rank.SetRanking(this->level, this->moveCount, this->boxMoveCount);

	else if (temp.move_count == 0)
		rank.SetRanking(this->level, this->moveCount, this->boxMoveCount);

	return true;
}
void GameManager::nextLevel() {
	this->level = (this->level + 1) % 6;
	if (this->level == 0) {
		this->level = 1;
	}
	this->init();
}

void GameManager::update(IN int key) {

	if (key == KEY_LEFT) {
		this->move(key);
	}
	else if (key == KEY_RIGHT) {
		this->move(key);
	}
	else if (key == KEY_UP) {
		this->move(key);
	}
	else if (key == KEY_DOWN) {
		this->move(key);
	}
	else if (key == 'U' || key == 'u') {
		this->undo();
	}
	else if (key == 'R' || key == 'r') {
		this->redo();
	}
	if (this->checkFinish()) {
		if (key == 'S' || key == 's')
			this->nextLevel();
	}
}
void GameManager::render() {
	this->objectManager->render();
	this->user->render();
}
bool GameManager::redo() {
	if (this->undoCommands.size() == 0)
		return false;
	Command command = this->undoCommands.back();
	move(command.type, false);
	this->undoCommands.pop_back();
	return true;
}
bool GameManager::undo() {
	if (this->commands.size() == 0)
		return false;
	Command command = this->commands.back();
	int xDelta = 0;
	int yDelta = 0;

	switch (command.type) {
	case KEY_UP:
		yDelta = -1;
		break;
	case KEY_DOWN:
		yDelta = 1;
		break;
	case KEY_LEFT:
		xDelta = -1;
		break;
	case KEY_RIGHT:
		xDelta = 1;
		break;
	}
	Object *object = this->objectManager->getObject(this->user->getX() - xDelta, this->user->getY() - yDelta);


	if (command.hasBox) {
		Box *box = (Box *)this->objectManager->getObject(this->user->getX() + xDelta, this->user->getY() + yDelta);
		Object  *beforeObj = this->objectManager->getObject(this->user->getX() - xDelta, this->user->getY() - yDelta);
			
		int userType = this->user->getType();
		if (beforeObj->getType() == DEST && box->getType() == BOX) {
			this->user->setType(USER_ON_DEST);
			this->objectManager->deleteObject(beforeObj);
			this->objectManager->insertObject(new Road(box->getX(), box->getY(), this->parentWindow, ROAD));
		}
		else if (beforeObj->getType() == ROAD && box->getType() == BOX_ON_DEST) {
			this->user->setType(USER);
			this->objectManager->deleteObject(beforeObj);
			this->objectManager->insertObject(new Goal(box->getX(), box->getY(), this->parentWindow, DEST));
		}
		else {
			// user 이전 위치가 load인지 goal인지 확인하는 작업
			if (beforeObj->getType() == ROAD) {
				user->setType(USER);
			}
			else if (beforeObj->getType() == DEST) {
				user->setType(USER_ON_DEST);
			}

			beforeObj->setY(box->getY());
			beforeObj->setX(box->getX());
		}

		box->setX(box->getX() - xDelta);
		box->setY(box->getY() - yDelta);

		if (userType == USER_ON_DEST) {
			box->setType(BOX_ON_DEST);
		}
		else {
			box->setType(BOX);
		}
		this->boxMoveCount -= 1;

	}
	else {
		if (object->getType() == DEST && this->user->getType() == USER) {
			this->user->setType(USER_ON_DEST);
			this->objectManager->deleteObject(object);
			this->objectManager->insertObject(new Road(this->user->getX(), this->user->getY(), this->parentWindow, ROAD));
		}
		else if (object->getType() == ROAD && this->user->getType() == USER_ON_DEST) {
			this->user->setType(USER);
			this->objectManager->deleteObject(object);
			this->objectManager->insertObject(new Goal(this->user->getX(), this->user->getY(), this->parentWindow, DEST));
		}
		else {
			object->setY(this->user->getY());
			object->setX(this->user->getX());
		}
	}
	this->user->setY(this->user->getY() - yDelta);
	this->user->setX(this->user->getX() - xDelta);
	this->moveCount -= 1;
	this->commands.pop_back();
	this->undoCommands.push_back(command);
	return true;
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