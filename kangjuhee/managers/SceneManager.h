//
// Created by jh_svt on 19. 5. 26.
//

#ifndef SOKOBAN_SCENEMANAGER_H
#define SOKOBAN_SCENEMANAGER_H


#include "../panes/Pane.h"

class SceneManager {
private:
    Pane *nowScene;
public:
    SceneManager();
    ~SceneManager();
    void render();
    void update(IN char key);
    void setNowScene(Pane * nowScene){
        if(this->nowScene !=NULL){
            delete this->nowScene;
        }
        this->nowScene = nowScene;
    }
};


#endif //SOKOBAN_SCENEMANAGER_H
