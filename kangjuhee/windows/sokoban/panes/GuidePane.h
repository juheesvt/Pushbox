#ifndef SOKOBAN_GUIDEPANE_H
#define SOKOBAN_GUIDEPANE_H

#include "../utils/FileManager.h"
#include "Pane.h"


class GuidePane :public Pane {
public:
	GuidePane(int x, int y, int width, int height, SceneManager * sceneManager);
	~GuidePane();
	virtual void render();// 영역을 그려주는 draw함는
	virtual void update(IN int key);// 여기선 안씀

private:
	FileManager * guideData;
};
#endif
