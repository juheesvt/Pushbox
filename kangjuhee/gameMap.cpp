#include <iostream>
#include "gameMap.h"

using namespace std;

gameMap::gameMap(int goalNum) : this->goalNum(goalNum), box = new Position[this->goalNum]{

    map = new int*[10];
    for( int i =0 ; i < 10; i ++){
        map[i] = new int[10];

    }

    int goalList = {1,4,1,5,1,6};
    int boxlList = {3,4,4,5,2,6};
    setBlock();
    setGaol(goalList);
    setBox(boxList);


}

void gameMap::setBlock() {

    // 바 깥 테두 리 블록
    for(int i =0; i<10; i++) {
        map[0][i] = 1;
        map[i][0] = 1;
        map[9][i] = 1;
        map[i][9] = 1;
    }
    //  이밑에  블록추가
}

void gameMap::setGaol(int goalList[]){
    for(int i =0; i< sizeof(goalList)/ sizeof(int); i+=2){
        goal.row = goalList[i];
        goal.column = goalList[i+1];
    }
}

void gameMap::setBox(int boxList[]) {
    for(int i =0; i< sizeof(boxList)/ sizeof(int); i+=2){
        box.row = boxList[i];
        box.column = boxList[i+1];
    }
}

void gameMap::setCurrent(int x, int y) {
    this->current.row = x;
    this->current.column = y;
}


int gameMap::up(){
    if(map[getCurrent().row-1][getCurrent().column] != 1)
        return 1;
    return 0;
}
int gameMap::down(){
    if(map[getCurrent().row+1][getCurrent().column] != 1)
        return 1;
    return 0;
}
int gameMap::left(){
    if(map[getCurrent().row][getCurrent().column-1] != 1)
        return 1;
    return 0;
}
int gameMap::right(){
    if(map[getCurrent().row][getCurrent().column+1] != 1)
        return 1;
    return 0;
}