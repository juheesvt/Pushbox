//
//  Map.hpp
//  Pushbox
//
//  Created by Jiho Park on 19/05/2019.
//  Copyright © 2019 Jiho Park. All rights reserved.
//

#ifndef PUSHBOX_MAP_H
#define PUSHBOX_MAP_H


// 움직일 수 있는 길
const short ROAD = 1;
// 상자를 넣을 목적지
const short DEST = 2;
// 벽
const short WALL = 3;
// 정사각형을 만들고 남은 빈 공간
const short SPACE = 4;

// 캐릭터의 위치
struct Position {
    int row = 0;
    int col = 0;
};

struct Box {
    Position pos;
};

struct Block {
    int type = 0;
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
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();
};


#endif //PUSHBOX_MAP_H
