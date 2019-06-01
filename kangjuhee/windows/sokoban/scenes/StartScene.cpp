//
// Created by jh_svt on 19. 5. 23.
//

#include "StartScene.h"
StartScene::StartScene(int x, int y, int width, int height,SceneManager *sceneManager):Pane(x,y,width,height,sceneManager) {
    this->startData=new FileManager("datas/startscene.dat"); // 파 일경 로알아보
    this->menuPane = new MenuPane(4,7,17,7,this->sceneManager);
}
StartScene::~StartScene() {
    delete this->menuPane;
    delete this->startData;
    delwin(this->pWindow);
}
void StartScene::render() {
	wattron(this->getWindow(),COLOR_PAIR(WHITE_GREEN));
	for (int row = 0; row < this->startData->getLineLength(); ++row) {
		mvwprintw(this->getWindow(), row, 0, this->startData->getLine(row).c_str());      // c_str : string -> char *
	}
	wattroff(this->getWindow(), COLOR_PAIR(WHITE_GREEN));

	wrefresh(this->getWindow());

    this->menuPane->render();


}
void StartScene::update(IN int key){
    this->menuPane->update(key);
}