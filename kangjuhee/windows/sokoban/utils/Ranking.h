//
// Created by Jiho Park on 2019-06-05.
//

#ifndef SOKOBAN_RANKING_H
#define SOKOBAN_RANKING_H

struct Rank {
	int move_count = 0;
	int box_count = 0;
};

class Ranking {
private:
	Rank *ranklist;
	void Save();
public:
	Ranking();
	~Ranking();
	Rank* GetRanking();
	void SetRanking(int level, int move, int box);
};
#endif;