//
// Created by jh_svt on 19. 5. 23.
//

#include "MenuPane.h"
#include "../scenes/GameScene.h"
#include "../scenes/RankingScene.h"

MenuPane::MenuPane(int x, int y, int width, int height,SceneManager *sceneManager):Pane(x,y,width,height,sceneManager) {
    this->menuData=new FileManager("datas/menu.dat"); // 파 일경 로알아보
    this->nowSelect=0;
}
MenuPane::~MenuPane() {
	delete this->menuData;
	delwin(this->pWindow);
}
void MenuPane::next(){
    this->nowSelect = (this->nowSelect + 1) % this->MENU_NUM;
}
void MenuPane::prev(){
    this->nowSelect--;
    if(this->nowSelect < 0){
        this->nowSelect = this->MENU_NUM-1;
    }
}
int MenuPane::getNowSelect() {
    return this->nowSelect;
}
void MenuPane::update(IN int key){
    if(key == KEY_UP){
        this->prev();
    }
    else if(key == KEY_DOWN){
        this->next();
    }
	else if (key == KEY_ENTER) {
		switch(this->nowSelect){
		case MENU_NEW_GAME:
			this->sceneManager->setNowScene(new GameScene(0, 0, 70, 20, this->sceneManager));
			break;
		case MENU_RANKING:
			this->sceneManager->setNowScene(new RankingScene(0, 0, 70, 20, this->sceneManager));
			break;
		case MENU_QUIT:
			this->sceneManager->setNowScene(NULL);
			exit(0);
		}
		
	}
}
void MenuPane::render() {
	
	wattron(this->getWindow(), COLOR_PAIR(BLACK_GREEN));
    for(int row = 0; row < this->menuData->getLineLength();++row){
        mvwprintw(this->getWindow(),row , 0, this->menuData->getLine(row).c_str());      // c_str : string -> char *
    }
    mvwprintw(this->getWindow(),this->nowSelect*2,0,this->SELECT_CHAR);
	wattroff(this->getWindow(), COLOR_PAIR(BLACK_GREEN));
    wrefresh(this->getWindow());
}