#include "../panes/GamePane.h"

GamePane::GamePane(int x, int y, int width, int height, SceneManager *sceneManager) :Pane(x, y, width, height, sceneManager) {
	wbkgd(this->pWindow, COLOR_PAIR(WHITE_YELLO));
	wborder(this->pWindow, '|', '|', '-', '-', '*', '*', '*', '*');
	wrefresh(this->pWindow);
	this->gameManager = new GameManager(this->pWindow);
	
}
GamePane::~GamePane() {
	delete this->gameManager;
	delwin(this->pWindow);
}
void GamePane::update(IN int key) {
	this->gameManager->update(key);
}
void GamePane::render() {
	this->gameManager->render();
	wrefresh(this->pWindow);

}
GameManager * GamePane::getGameManager() {
	return this->gameManager;
}