#include <iostream>
#include <graphics.h>

using namespace std;

class cell{
public:
    cell(int = 0, int = 0);
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

class piece {
public:
    piece(cell);
    cell getPos();
private:
    cell pos;
    bool isAlive;
};

piece::piece(cell givenCell) {
    isAlive = true;
    pos = givenCell;
}

cell piece::getPos() {
    return pos;
}

class king: public piece {
};

class queen: public piece {
};

class rook: public piece {
};

class bishop: public piece {
};

class knight: public piece {
};

class pawn: public piece {
};

class player {
    king playerKing;
    queen playerQueen;
    rook playerRooks[2];
    bishop playerBishops[2];
    knight playerBishops[2];
    pawn playerPawns[8];
};

class board {
public:
    board();
    bool isRunning();
private:
    bool gameIsOver;
    int turn;
    player white, black;
};

board::board() {
    gameIsOver = false;
}

bool board::isRunning() {
    return !gameIsOver;
}

int main() {
    //initwindow(800,600);

    /* In case we want to test cell class
    cell tst(100, 200);
    cout << tst.getX() << ' ' << tst.getY() << '\n'; */

    /* In case we want to test piece class
    cell startingCell(100, 200);
    piece anHorse(startingCell);
    cout << anHorse.getPos().getX() << ' ' << anHorse.getPos().getY() << '\n';
    */

    board game; //object of running gameTable

    while (game.isRunning()) { //mainLoop
    }

    //getch();
}
