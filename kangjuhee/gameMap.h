
#ifndef PUSHBOX_GAMEMAP_H
#define PUSHBOX_GAMEMAP_H

 struct Position{
    int row=0;
    int column = 0;
};

class gameMap{
private:
    int goalNum;
    int **map;
    Position box;
    Position const goal;
    Position current;
public:
    gameMap(int goalNum);
    void setBlock();
    void setCurrent(int ,int);
    Position getCurrent();
    void setGoal(int []);
    void setBox(int []);
    Position getGoal();
    Position getBox();
    int up();
    int down();
    int left();
    int right();
};

#endif //PUSHBOX_GAMEMAP_H
