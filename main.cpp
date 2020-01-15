#include <iostream>
#include <graphics.h>
#include <vector>

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
    cell getPos();
protected:
    cell pos;
    bool isAlive;
};

class king: public piece {
public:
    king(cell);
};

class queen: public piece {
public:
    queen(cell);
};

class rook: public piece {
public:
    rook(cell);
};

class bishop: public piece {
public:
    bishop(cell);
};

class knight: public piece {
public:
    knight(cell);
};

class pawn: public piece {
public:
    pawn(cell);
};

king::king(cell givenCell) {
    isAlive = true;
    pos = givenCell;
}

queen::queen(cell givenCell) {
    isAlive = true;
    pos = givenCell;
}

rook::rook(cell givenCell) {
    isAlive = true;
    pos = givenCell;
}

bishop::bishop(cell givenCell) {
    isAlive = true;
    pos = givenCell;
}

knight::knight(cell givenCell) {
    isAlive = true;
    pos = givenCell;
}

pawn::pawn(cell givenCell) {
    isAlive = true;
    pos = givenCell;
}

cell piece::getPos() {
    return pos;
}

class player {
public:
private:
    vector <king> playerKing;
    vector <queen> playerQueen;
    vector <rook> playerRooks;
    vector <bishop> playerBishops;
    vector <knight> playerKnights;
    vector <pawn> playerPawns;
};

enum playerColor {White, Black};

class board {
public:
    board();
    bool isRunning();
    playerColor getTurn();
    bool isChecked(player attacker, player deffender);
    bool isCheckmated(player attacker, player deffender);
    bool isStalemated(player attacker, player deffender);
private:
    bool gameIsOver;
    playerColor turn;
    player white, black;
};

board::board() {
    gameIsOver = false;
    turn = White;
}

bool board::isRunning() {
    return !gameIsOver;
}

playerColor board::getTurn() {
    return turn;
}

int main() {
    initwindow(400,400);
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
        while (game.getTurn() == White) {
            while (!kbhit()) {
                int firstClickX, secondClickX, firstClickY, secondClickY;
                delay(100);
            }
        }
        while (game.getTurn() == Black) {
            while (!kbhit()) {
                int firstClickX, secondClickX, firstClickY, secondClickY;
                delay(100);
            }
        }
    }
    //getch();
}
