//
//  Map.hpp
//  Pushbox
//
//  Created by Jiho Park on 19/05/2019.
//  Copyright © 2019 Jiho Park. All rights reserved.
//

#include <vector>

#ifndef PUSHBOX_MAP_H
#define PUSHBOX_MAP_H

using namespace std;

// 움직일 수 있는 길
const unsigned char ROAD = 1;
// 상자를 넣을 목적지
const unsigned char DEST = 2;
// 벽
const unsigned char WALL = 3;
// 정사각형을 만들고 남은 빈 공간
const unsigned char SPACE = 4;

// 캐릭터의 위치
struct Position {
    unsigned char row = 0;
    unsigned char col = 0;
};

struct Log {
    unsigned char moveType = 0;
    bool hasBox = false;
};

struct Box {
    Position pos;
};

struct Block {
    unsigned char type = 3;
    Box *box;
};
class Map {
private:
    
public:
    Box *box;
    Position myPos;
    Block **map;
    Map();
    ~Map();
    // 방향 움직임 함수
    char moveUp();
    char moveDown();
    char moveLeft();
    char moveRight();
    
    bool undo();
    
    // 게임 클리어 판단 함수
    bool checkFinish();
    
    // 맵 로드 함수
    void loadMap(string path);
    
    // 게임 실패 판단 함수(Solver 시에 구현 예정)
//    bool checkFail();
private:
    vector<Log> history;
};


#endif //PUSHBOX_MAP_H
