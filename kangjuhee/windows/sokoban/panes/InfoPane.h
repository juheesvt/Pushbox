#ifndef SOKOBAN_INFOPANE_H
#define SOKOBAN_INFOPANE_H
#include "Pane.h"
#include "../utils/FileManager.h"
#include <string>

#define STRING std::string

class InfoPane :public Pane {
public:
	InfoPane(int x, int y, int width, int height, SceneManager * sceneManager);
	~InfoPane();
	virtual void render();// 영역을 그려주는 draw함는
	virtual void update(IN int key);// 영역을 그려주는 draw함는
	void setLevel(int level);
	void setMoveCount(int moveCount);
	void setBoxMoveCount(int boxMoveCount);
	void setMessage(STRING message);
private:
	FileManager * infoData;
	int level;
	int moveCount;
	int boxMoveCount;
	STRING message;
};
#endif