//
//  Map.cpp
//  Pushbox
//
//  Created by Jiho Park on 19/05/2019.
//  Copyright © 2019 Jiho Park. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Map.hpp"

using namespace std;

char Map::moveUp() {
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
                Log l = {1, true};
                history.push_back(l);
                return 2;
            }
        }
    }
    // 박스가 없을 경우
    else {
        // 이 공간이 ROAD 또는 DEST일 경우에만 움직일 수 있다.
        if(next->type < 3) {
            myPos.row --;
            Log l = {1, false};
            history.push_back(l);
            return 1;
        }
    }
    return 0;
}

char Map::moveDown() {
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
                Log l = {2, true};
                history.push_back(l);
                return 2;
            }
        }
    }
    // 박스가 없을 경우
    else {
        // 이 공간이 ROAD 또는 DEST일 경우에만 움직일 수 있다.
        if(next->type < 3) {
            myPos.row ++;
            Log l = {2, false};
            history.push_back(l);
            return 1;
        }
    }
    return 0;
}

char Map::moveLeft() {
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
                Log l = {3, true};
                history.push_back(l);
                return 2;
            }
        }
    }
    // 박스가 없을 경우
    else {
        // 이 공간이 ROAD 또는 DEST일 경우에만 움직일 수 있다.
        if(next->type < 3) {
            myPos.col --;
            Log l = {3, false};
            history.push_back(l);
            return 1;
        }
    }
    return 0;
}

char Map::moveRight() {
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
                Log l = {4, true};
                history.push_back(l);
                return 2;
            }
        }
    }
    // 박스가 없을 경우
    else {
        // 이 공간이 ROAD 또는 DEST일 경우에만 움직일 수 있다.
        if(next->type < 3) {
            myPos.col ++;
            Log l = {4, false};
            history.push_back(l);
            return 1;
        }
    }
    return 0;
}
Map::Map() {

}

Map::~Map() {
    // 맵 지움
    for (int i = 0; i < 10 + 2; i++)
        delete[] map[i];
    delete[] map;
    // 박스 지움
    delete[] box;
    history.clear();
}

void Map::loadMap(string path) {
    ifstream mapfile;
    mapfile.open(path);
    
    int x, y;
    mapfile >> x;
    mapfile >> y;
    
    myPos = {(unsigned char)x, (unsigned char)y};
    
    int boxSize;
    mapfile >> boxSize;
    
    box = new Box[boxSize];
    map = new Block *[10 + 2];
    for (int i = 0; i < 10 + 2; i++)
        map[i] = new Block[10 + 2];
    
    for(int i = 0; i < boxSize; i++) {
        int row, col;
        mapfile >> row;
        mapfile >> col;
        box[i].pos.row = (unsigned char)row;
        box[i].pos.col = (unsigned char)col;
    }
    
    for(int r = 1; r < 11; r++) {
        for(int c = 1; c < 11; c++) {
            int data;
            mapfile >> data;
            switch (data) {
                case 6:
                case ROAD:
                    map[r][c].type = ROAD;
                    break;
                case DEST:
                    map[r][c].type = DEST;
                    break;
                case WALL:
                    map[r][c].type = WALL;
                    break;
                case 5:
                    map[r][c].type = ROAD;
                    for(int i = 0; i < boxSize; i++)
                        if(box[i].pos.row == r && box[i].pos.col == c)
                            map[r][c].box = &box[i];
                    break;
                case SPACE:
                    map[r][c].type = SPACE;
                    break;
            }
        }
    }
}

bool Map::checkFinish() {
    for(int r = 1; r < 11; r++) {
        for(int c  = 1; c < 11; c++) {
            if(map[r][c].type == DEST && map[r][c].box == nullptr)
                return false;
        }
    }
    return true;
}

bool Map::undo() {
    if(history.size() == 0)
        return false;
    Log l = history.back();
    switch (l.moveType) {
        case 1:
            // up
            if(l.hasBox) {
                Box *b = map[myPos.row-1][myPos.col].box;
                b->pos.row --;
                map[myPos.row-1][myPos.col].box = nullptr;
                map[myPos.row][myPos.col].box = b;
            }
            myPos.row ++;
            break;
        case 2:
            // down
            if(l.hasBox) {
                Box *b = map[myPos.row+1][myPos.col].box;
                b->pos.row ++;
                map[myPos.row+1][myPos.col].box = nullptr;
                map[myPos.row][myPos.col].box = b;
            }
            myPos.row --;
            break;
        case 3:
            // left
            if(l.hasBox) {
                Box *b = map[myPos.row][myPos.col-1].box;
                b->pos.col ++;
                map[myPos.row][myPos.col-1].box = nullptr;
                map[myPos.row][myPos.col].box = b;
            }
            myPos.col ++;
            break;
        case 4:
            // right
            if(l.hasBox) {
                Box *b = map[myPos.row][myPos.col+1].box;
                b->pos.col --;
                map[myPos.row][myPos.col+1].box = nullptr;
                map[myPos.row][myPos.col].box = b;
            }
            myPos.col --;
            break;
        default:
            break;
    }
    history.pop_back();
    return true;
}

/*
4 9 // Character Position ROW COL
4 4 5 5 6 4 7 5 8 // Box Size Box1 ROW COL
4 3 3 3 3 3 3 3 4 4 // Map
3 3 1 2 2 2 2 3 4 4 // 1 = ROAD
3 1 1 1 3 3 3 3 3 3 // 2 = DESTINATION
3 1 1 1 5 1 5 1 6 3 // 3 = WALL
3 3 3 1 1 5 1 5 1 3 // 4 = SPACE
4 4 3 3 3 1 1 1 1 3 // 5 = BOX
4 4 4 4 3 3 3 3 3 3 // 6 = CHARACTER
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
4 4 4 4 4 4 4 4 4 4
*/
