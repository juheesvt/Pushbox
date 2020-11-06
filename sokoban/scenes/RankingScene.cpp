#include "RankingScene.h"
#include <string>
#define TO_STRING std::to_string

RankingScene::RankingScene(int x, int y, int width, int height, SceneManager* sceneManager) :Pane(x, y, width, height, sceneManager) {
	this->rank = new Ranking();

	wattron(this->getWindow(), COLOR_PAIR(WHITE_GREEN));


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 70; j++) {
			mvwprintw(this->getWindow(), i, j, " ");
		}
	}

	wborder(this->pWindow, '|', '|', '-', '-', '*', '*', '*', '*');

	mvwprintw(this->getWindow(), 1, 7, "LEVEL");
	mvwprintw(this->getWindow(), 1, 21, "BOX COUNT");
	mvwprintw(this->getWindow(), 1, 42, "MOVE COUNT");

	mvwprintw(this->getWindow(), 4, 7, "1");
	mvwprintw(this->getWindow(), 7, 7, "2");
	mvwprintw(this->getWindow(), 10, 7, "3");
	mvwprintw(this->getWindow(), 13, 7, "4");
	mvwprintw(this->getWindow(), 16, 7, "5");

	int idx = 0;

	for (int i = 4; i < 18; i += 3) {
		mvwprintw(this->getWindow(), i, 21, TO_STRING((rank->GetRanking())[idx++].box_count).c_str());

	}

	idx = 0;

	for (int i = 4; i < 18; i += 3) {
		mvwprintw(this->getWindow(), i, 42, TO_STRING((rank->GetRanking())[idx++].move_count).c_str());
	}

	wattroff(this->getWindow(), COLOR_PAIR(WHITE_GREEN));
	wrefresh(this->getWindow());
}

void RankingScene::update(IN int key) {

}

void RankingScene::render() {

}

RankingScene::~RankingScene()
{
}