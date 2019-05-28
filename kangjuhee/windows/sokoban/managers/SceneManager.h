//
// Created by jh_svt on 19. 5. 26.
//

#ifndef SOKOBAN_SCENEMANAGER_H
#define SOKOBAN_SCENEMANAGER_H


#include "../panes/Pane.h"

class Pane;
class SceneManager {
private:
    Pane *nowScene;
public:
    SceneManager();
    ~SceneManager();
    void render();
    void update(IN int key);
    void setNowScene(Pane * nowScene){
        if(this->nowScene !=NULL){
			erase(); 
			refresh();
            delete this->nowScene;
        }
        this->nowScene = nowScene;
    }
};


#endif //SOKOBAN_SCENEMANAGER_H
