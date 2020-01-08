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

class king: public piece {
public:
    using piece::piece;
};

class queen: public piece {
public:
    using piece::piece;
};

class rook: public piece {
public:
    using piece::piece;
};

class bishop: public piece {
public:
    using piece::piece;
};

class knight: public piece {
public:
    using piece::piece;
};

class pawn: public piece {
public:
    using piece::piece;
};

piece::piece(cell givenCell) {
    isAlive = true;
    pos = givenCell;
}

cell piece::getPos() {
    return pos;
}

class player {
private:
    king playerKing;
    queen playerQueen;
    rook playerRooks[2];
    bishop playerBishops[2];
    knight playerKnights[2];
    pawn playerPawns[8];
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
        while (game.getTurn() == White) {
            delay(100);
        }
        while (game.getTurn() == Black) {
            delay(100);
        }
    }
    //getch();
}
