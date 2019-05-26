//
// Created by jh_svt on 19. 5. 23.
//

#include "MenuPane.h"
#include "ncurses.h"

MenuPane::MenuPane(int x, int y, int width, int height):Pane(x,y,width,height) {
    this->menuData=new FileManager("../datas/menu.dat"); // 파 일경 로알아보
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
        this->nowSelect = 0;
    }
}
int MenuPane::getNowSelect() {
    return this->nowSelect;
}
void MenuPane::update(IN char key){
    if(key == KEY_UP){
        this->prev();
    }
    else if(key == KEY_DOWN){
        this->next();
    }
}
void MenuPane::render() {
    for(int row = 0; row < this->menuData->getLineLength();++row){
        mvwprintw(this->getWindow(),row , 0, this->menuData->getLine(row).c_str());      // c_str : string -> char *
    }
    mvwprintw(this->getWindow(),this->nowSelect*2,0,this->SELECT_CHAR);
    wrefresh(this->getWindow());
}