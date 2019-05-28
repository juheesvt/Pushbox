//
// Created by jh_svt on 19. 5. 26.
//

#include "SceneManager.h"
SceneManager::SceneManager() {
    this->nowScene=NULL;
}
void SceneManager::render() {
    this->nowScene->render();           // 현재 윈도우에 Scene refresh
}
void SceneManager::update(IN int key) {
    this->nowScene->update(key);
}