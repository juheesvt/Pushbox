//
// Created by jh_svt on 19. 5. 23.
//

#include "StartScene.h"
StartScene::StartScene(int x, int y, int width, int height):Pane(x,y,width,height) {
    this->startData=new FileManager("../datas/startscene.dat"); // 파 일경 로알아보
    this->menuPane = new MenuPane(4,7,10,7);
}
StartScene::~StartScene() {
    delete this->menuPane;
    delete this->startData;
    delwin(this->pWindow);
}
void StartScene::render() {
    attron(COLOR_PAIR(2));

    for(int row = 0; row < this->startData->getLineLength();++row){
        mvwprintw(this->getWindow(),row , 0, this->startData->getLine(row).c_str());      // c_str : string -> char *
    }
//    this->menuPane->render();
    attroff(COLOR_PAIR(2));

    wrefresh(this->getWindow());
}
void StartScene::update(IN char key){
    this->menuPane->update(key);
}