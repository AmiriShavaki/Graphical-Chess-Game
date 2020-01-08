#include <iostream>
#include <graphics.h>

using namespace std;

class cell{
public:
    cell(int, int);
    int getX();
    int getY();
private:
    int x;
    int y;
};

cell::cell(int givenX, int givenY) {
    x = givenX;
    y = givenY;
}

int cell::getX() {
    return x;
}

int cell::getY() {
    return y;
}

/*
class piece {
public:
    piece();
private:
    cell pos;
};

class board {
public:
    board();
private:
    bool gameIsOver;
};

board::board() {
    gameIsOver = 0;
}
*/
int main() {
    initwindow(800,600);
    /* In case we want to test cell class
    cell tst(100, 200);
    cout << tst.getX() << tst.getY(); */
    getch();
}
