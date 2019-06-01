#include "managers/SceneManager.h"
#include "scenes/StartScene.h"
void init();
int main() {
	init();
	SceneManager * sceneManager = new SceneManager();
	StartScene * startScene = new StartScene(0,0,70,20,sceneManager);

	// 현재 윈도우를 startScene으로 설정하고 render()함수를 통해 보여주
	sceneManager->setNowScene(startScene);
	sceneManager->render();
		
	while (true) {
		int key = 0;
		keypad(stdscr, true);

		key = getch();

		sceneManager->update(key);
		sceneManager->render();
	}
	
	endwin();
	return 0;
}
void init() {
	initscr();

	start_color();

	init_pair(BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(WHITE_GREEN, COLOR_WHITE, COLOR_GREEN);
	init_pair(RED_GREEN, COLOR_RED, COLOR_GREEN);
	init_pair(BLACK_BLACK, COLOR_BLACK, COLOR_BLACK);
	init_pair(CYAN_CYAN, COLOR_CYAN, COLOR_CYAN);
	init_pair(BLUE_BLUE, COLOR_BLUE, COLOR_BLUE);
	init_pair(RED_RED, COLOR_RED, COLOR_RED);
	init_pair(BRIGHT_BLUE_BRIGHT_BLUE, COLOR_BRIGHT_BLUE, COLOR_BRIGHT_BLUE);
	init_pair(YELLO_YELLO, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(WHITE_WHITE, COLOR_WHITE, COLOR_WHITE);
	init_pair(WHITE_YELLO, COLOR_WHITE, COLOR_YELLOW);
	init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);

	curs_set(0);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	scrollok(stdscr, TRUE);

	refresh();
}