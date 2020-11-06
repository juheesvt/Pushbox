#ifndef SOKOBAN_GUIDEPANE_H
#define SOKOBAN_GUIDEPANE_H

#include "../utils/FileManager.h"
#include "Pane.h"


class GuidePane :public Pane {
public:
	GuidePane(int x, int y, int width, int height, SceneManager * sceneManager);
	~GuidePane();
	virtual void render();// ������ �׷��ִ� draw�Դ�
	virtual void update(IN int key);// ���⼱ �Ⱦ�

private:
	FileManager * guideData;
};
#endif
