//
// Created by jh_svt on 19. 5. 23.
//

#include "Pane.h"

Pane::Pane(int x, int y, int width, int height) : x(x), y(y),width(width), height(height) {
    pWindow = newwin(height,width,y,x);
    wrefresh(pWindow);
}
Pane::~Pane() {
    delwin(pWindow);
}

void Pane::render() {
    wrefresh(pWindow);      // 현재 윈도우에 refresh
}
WINDOW * Pane::getWindow() {
    return pWindow;
}
void Pane::update(IN char key) {}