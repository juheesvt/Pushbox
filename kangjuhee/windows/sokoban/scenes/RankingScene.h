
#ifndef SOKOBAN_RANKINGSCENE_H
#define SOKOBAN_RANKINGSCENE_H

#include <curses.h>

#include "../utils/Ranking.h"
#include "../panes/Pane.h"
#include "../utils/define.h"



class RankingScene :public Pane {
public:
	RankingScene(int x, int y, int width, int height, SceneManager *SceneManager);
	~RankingScene();
	virtual void    render();
	virtual void    update(IN int key);
private:
	Ranking			*rank;
	int             x, y;
	int             width, height;
};


#endif
