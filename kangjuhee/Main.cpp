//
// Created by jh_svt on 19. 5. 26.
//

#include "managers/SceneManager.h"
#include "scenes/StartScene.h"

int main(){
    SceneManager * sceneManager = new SceneManager();
    StartScene * startScene = new StartScene(0,0,50,50);

    initscr();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_RED, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_CYAN);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);

    bkgd(COLOR_PAIR(1));

    // 현재 윈도우를 startScene으로 설정하고 render()함수를 통해 보여주
    sceneManager->setNowScene(startScene);
    sceneManager->render();


    while(true){
        int key;
        keypad(stdscr, true);
        key = getch();
        sceneManager->update(key);
        sceneManager->render();
    }
    return 0;
}