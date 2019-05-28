#include "../panes/GamePane.h"

GamePane::GamePane(int x, int y, int width, int height, SceneManager *sceneManager) :Pane(x, y, width, height, sceneManager) {
	this->mapData = new FileManager("datas/map.dat"); // map 파일경로

	}
GamePane::~GamePane() {
	delete this->mapData;
	delwin(this->pWindow);
}
void GamePane::update(IN int key) {

}
void GamePane::render() {
	

	

}