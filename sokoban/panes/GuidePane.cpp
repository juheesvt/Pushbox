#include "GuidePane.h"

GuidePane::GuidePane(int x, int y, int width, int height, SceneManager * sceneManager) : Pane(x, y, width, height, sceneManager) {
	this->guideData = new FileManager("datas/guide.dat");
}


GuidePane::~GuidePane() {
	delete this->guideData;
	delwin(this->pWindow);
}

void GuidePane::render() {
	wattron(this->getWindow(), COLOR_PAIR(BLACK_GREEN));
	for (int row = 0; row < this->guideData->getLineLength(); ++row) {
		mvwprintw(this->getWindow(), row, 0, this->guideData->getLine(row).c_str());      // c_str : string -> char *
	}
	wattroff(this->getWindow(), COLOR_PAIR(BLACK_GREEN));
	wrefresh(this->getWindow());
}

void GuidePane::update(int key) {

}
