//
// Created by Jiho Park on 2019-06-05.
//

#include "Ranking.h"
#include <fstream>
#include <iostream>

using namespace std;

Ranking::Ranking() {
	ranklist = new Rank[5];
	ifstream rankfile("./datas/rank.txt");
	if (rankfile.fail()) {
		// generate default rank
		Save();
	}
	for (int i = 0; i < 5; i++) {
		rankfile >> ranklist[i].move_count;
		rankfile >> ranklist[i].box_count;
	}
	rankfile.close();
}
Ranking::~Ranking() {
	delete[] ranklist;
}
Rank* Ranking::GetRanking() {
	return this->ranklist;
}
void Ranking::SetRanking(int level, int move, int box) {
	ranklist[level - 1].move_count = move;
	ranklist[level - 1].box_count = box;
	Save();
}

void Ranking::Save() {
	ofstream out("rank.txt");
	for (int i = 0; i < 10; i++) {
		out << ranklist[i].move_count << " " << ranklist[i].box_count << endl;
	}
	out.close();
}