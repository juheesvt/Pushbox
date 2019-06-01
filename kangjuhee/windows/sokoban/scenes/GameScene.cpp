//
// Created by jh_svt on 19. 5. 26.
//

#include "GameScene.h"
GameScene::GameScene(int x, int y, int width, int height, SceneManager *sceneManager) :Pane(x, y, width, height, sceneManager) {
	erase();
	refresh();
	wbkgd(this->pWindow, COLOR_PAIR(WHITE_GREEN));
	wborder(this->pWindow, '|', '|', '-', '-', '*', '*', '*', '*');
	wrefresh(this->pWindow);

	this->gamePane = new GamePane(4, 7, 24, 11, this->sceneManager);
	this->infoPane = new InfoPane(4, 2, 28, 3, this->sceneManager);

}
GameScene::~GameScene() {
	delete this->gamePane;
	delwin(this->pWindow);
}
void GameScene::render() {
	
	this->gamePane->render();
	this->infoPane->render();
}
void GameScene::update(IN int key) {
	this->gamePane->update(key);
	this->infoPane->setLevel(this->gamePane->getGameManager()->getLevel());
	this->infoPane->setMoveCount(this->gamePane->getGameManager()->getMoveCount());
	this->infoPane->setBoxMoveCount(this->gamePane->getGameManager()->getBoxCount());
}