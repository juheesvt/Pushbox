#include "InfoPane.h"

#define TO_STRING std::to_string
InfoPane::InfoPane(int x, int y, int width, int height, SceneManager * sceneManager):Pane(x,y,width,height,sceneManager) 
{
	this->infoData = new FileManager("datas/info.dat");

}
InfoPane::~InfoPane() {}
void InfoPane::render() {

	wattron(this->getWindow(), COLOR_PAIR(WHITE_BLACK));
	for (int row = 0; row < this->infoData->getLineLength(); ++row) {
		mvwprintw(this->getWindow(), row, 0, this->infoData->getLine(row).c_str());      // c_str : string -> char *
	}
	mvwprintw(this->getWindow(), 1, 7, TO_STRING(this->level).c_str());
	mvwprintw(this->getWindow(), 1, 15, TO_STRING(this->moveCount).c_str());
	mvwprintw(this->getWindow(), 1, 24, TO_STRING(this->boxMoveCount).c_str());
	wattroff(this->getWindow(), COLOR_PAIR(WHITE_BLACK));
	wrefresh(this->getWindow());

}
void InfoPane::update(IN int key) {}
void InfoPane::setLevel(int level) {
	this->level = level;
}
void InfoPane::setBoxMoveCount(int boxMoveCount) {
	this->boxMoveCount = boxMoveCount;
}
void InfoPane::setMoveCount(int moveCount) {
	this->moveCount = moveCount;
}