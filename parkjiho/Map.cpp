//
//  Map.cpp
//  Pushbox
//
//  Created by Jiho Park on 19/05/2019.
//  Copyright © 2019 Jiho Park. All rights reserved.
//

#include <iostream>
#include "Map.hpp"

using namespace std;

bool Map::moveUp() {
    // next에 박스가 놓였는지 체크를 한다.
    Block *next = &map[myPos.row - 1][myPos.col];
    // 박스가 있을 경우
    if (next->box != nullptr) {
        // 다음 공간이 ROAD 또는 DEST일 경우에만 박스를 밀 수 있다.
        // Index Out Of Range 방지용
        if (myPos.row - 2 > 0) {
            Block *next2 = &map[myPos.row - 2][myPos.col];
            // 박스가 없고 움직일 수 있는 거리라면
            if(next2->box == nullptr && next2->type < 3) {
                // 박스를 이동시키고
                next2->box = next->box;
                next->box = nullptr;
                // 캐릭터를 이동시킨다.
                myPos.row--;
                return true;
            }
        }
    }
    // 박스가 없을 경우
    else {
        // 이 공간이 ROAD 또는 DEST일 경우에만 움직일 수 있다.
        if(next->type < 3) {
            myPos.row --;
            return true;
        }
    }
    return false;
}

bool Map::moveDown() {
    // next에 박스가 놓였는지 체크를 한다.
    Block *next = &map[myPos.row + 1][myPos.col];
    // 박스가 있을 경우
    if (next->box != nullptr) {
        // 다음 공간이 ROAD 또는 DEST일 경우에만 박스를 밀 수 있다.
        // Index Out Of Range 방지용
        if (myPos.row + 2 < 11) {
            Block *next2 = &map[myPos.row + 2][myPos.col];
            // 박스가 없고 움직일 수 있는 거리라면
            if(next2->box == nullptr && next2->type < 3) {
                // 박스를 이동시키고
                next2->box = next->box;
                next->box = nullptr;
                // 캐릭터를 이동시킨다.
                myPos.row++;
                return true;
            }
        }
    }
    // 박스가 없을 경우
    else {
        // 이 공간이 ROAD 또는 DEST일 경우에만 움직일 수 있다.
        if(next->type < 3) {
            myPos.row ++;
            return true;
        }
    }
    return false;
}

bool Map::moveLeft() {
    // next에 박스가 놓였는지 체크를 한다.
    Block *next = &map[myPos.row][myPos.col- 1];
    // 박스가 있을 경우
    if (next->box != nullptr) {
        // 다음 공간이 ROAD 또는 DEST일 경우에만 박스를 밀 수 있다.
        // Index Out Of Range 방지용
        if (myPos.col - 2 > 0) {
            Block *next2 = &map[myPos.row][myPos.col - 2];
            // 박스가 없고 움직일 수 있는 거리라면
            if(next2->box == nullptr && next2->type < 3) {
                // 박스를 이동시키고
                next2->box = next->box;
                next->box = nullptr;
                // 캐릭터를 이동시킨다.
                myPos.col--;
                return true;
            }
        }
    }
    // 박스가 없을 경우
    else {
        // 이 공간이 ROAD 또는 DEST일 경우에만 움직일 수 있다.
        if(next->type < 3) {
            myPos.col --;
            return true;
        }
    }
    return false;
}

bool Map::moveRight() {
    // next에 박스가 놓였는지 체크를 한다.
    Block *next = &map[myPos.row][myPos.col + 1];
    // 박스가 있을 경우
    if (next->box != nullptr) {
        // 다음 공간이 ROAD 또는 DEST일 경우에만 박스를 밀 수 있다.
        // Index Out Of Range 방지용
        if (myPos.row + 2 < 11) {
            Block *next2 = &map[myPos.row][myPos.col + 2];
            // 박스가 없고 움직일 수 있는 거리라면
            if(next2->box == nullptr && next2->type < 3) {
                // 박스를 이동시키고
                next2->box = next->box;
                next->box = nullptr;
                // 캐릭터를 이동시킨다.
                myPos.col++;
                return true;
            }
        }
    }
    // 박스가 없을 경우
    else {
        // 이 공간이 ROAD 또는 DEST일 경우에만 움직일 수 있다.
        if(next->type < 3) {
            myPos.col ++;
            return true;
        }
    }
    return false;
}
Map::Map() {
    box = new Box[4];
    for(int i = 0; i < 3; i ++)
        box[i] = Box();
    map = new Block *[10 + 2];
    for (int i = 0; i < 10 + 2; i++)
        map[i] = new Block[10 + 2];
    
    map[4][5].box = &box[0];
    map[5][6].box = &box[1];
    map[4][7].box = &box[2];
    map[5][8].box = &box[3];
    myPos = {4,9};
    map[2][4].type = DEST;
    map[2][5].type = DEST;
    map[2][6].type = DEST;
    map[2][7].type = DEST;

    map[1][2].type = WALL;
    map[1][3].type = WALL;
    map[1][4].type = WALL;
    map[1][5].type = WALL;
    map[1][6].type = WALL;
    map[1][7].type = WALL;
    map[1][8].type = WALL;
    map[2][1].type = WALL;
    map[2][2].type = WALL;
    map[2][8].type = WALL;
    map[3][1].type = WALL;
    map[3][5].type = WALL;
    map[3][6].type = WALL;
    map[3][7].type = WALL;
    map[3][8].type = WALL;
    map[3][9].type = WALL;
    map[3][10].type = WALL;
    map[4][1].type = WALL;
    map[4][10].type = WALL;
    map[5][1].type = WALL;
    map[5][2].type = WALL;
    map[5][3].type = WALL;
    map[5][10].type = WALL;
    map[6][3].type = WALL;
    map[6][4].type = WALL;
    map[6][5].type = WALL;
    map[6][10].type = WALL;
    map[7][5].type = WALL;
    map[7][6].type = WALL;
    map[7][7].type = WALL;
    map[7][8].type = WALL;
    map[7][9].type = WALL;
    map[7][10].type = WALL;
    
    for(int i = 0 ; i < 12; i ++) {
        for(int j = 0; j < 12; j++) {
            if(i == 0 || i == 11 || j == 0 || j == 11)
                map[i][j].type = 4;
        }
    }
    //
}

Map::~Map() {
    // 맵 지움
    for (int i = 0; i < 10 + 2; i++)
        delete[] map[i];
    delete[] map;
    // 박스 지움
    delete[] box;
}

