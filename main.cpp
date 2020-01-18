#include <iostream>
#include <vector>
#include <SDL.h>
#include <string>

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

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

king::king(cell givenCell) {
    isAlive = true;
    pos = givenCell;
    SDL_Surface* kingSurface = NULL;
    if (pos.getY() == 0) {
        kingSurface = SDL_LoadBMP("pieces\\whiteGreenBackground\\king.bmp");
    } else {
        kingSurface = SDL_LoadBMP("pieces\\blackWhiteBackground\\king.bmp");
    }
    kingSurface = SDL_ConvertSurface(kingSurface, screenSurface -> format, 0);
    SDL_Rect position;
    position.x = pos.getX() * 50;
    position.y = pos.getY() * 50;
    position.w = 50;
    position.h = 50;
    SDL_BlitScaled(kingSurface, NULL, screenSurface, &position);
    SDL_UpdateWindowSurface(window);
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

enum playerColor {White, Black};

class player {
public:
    player(playerColor = White);
private:
    vector <king> playerKing;
    vector <queen> playerQueen;
    vector <rook> playerRooks;
    vector <bishop> playerBishops;
    vector <knight> playerKnights;
    vector <pawn> playerPawns;
};

player::player(playerColor color) {
    if (color == White) {
        cell position(4, 0);
        king tempKing(position);
        playerKing.push_back(tempKing);
    } else {
        cout << "lanat";
        cell position(4, 7);
        king tempKing(position);
        playerKing.push_back(tempKing);
    }
}

class board {
public:
    board();
    void updateBoard();
    bool isRunning();
    playerColor getTurn();
    bool isChecked(player attacker, player deffender);
    bool isCheckmated(player attacker, player deffender);
    bool isStalemated(player attacker, player deffender);
private:
    bool gameIsOver;
    playerColor turn;
    SDL_Surface* background = NULL;
};

board::board() {
    window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);
    background = SDL_LoadBMP("background.bmp");
    updateBoard();
    gameIsOver = false;
    turn = White;
    player white(White), black(Black);
    SDL_UpdateWindowSurface(window);
}

void board::updateBoard() {
    SDL_BlitSurface(background, NULL, screenSurface, NULL);
}

bool board::isRunning() {
    return !gameIsOver;
}

playerColor board::getTurn() {
    return turn;
}

int main(int argc, char* args[]) {
    board game; //object of running gameTable

    while (game.isRunning()) { //mainLoop
        while (game.getTurn() == White) {
            /*while (!kbhit()) {
                int firstClickX, secondClickX, firstClickY, secondClickY;
                delay(100);
            }*/
            game.updateBoard();
            SDL_Delay(1000);
        }
        while (game.getTurn() == Black) {
            /*while (!kbhit()) {
                int firstClickX, secondClickX, firstClickY, secondClickY;
                delay(100);
            }*/
            game.updateBoard();
            SDL_Delay(1000);
        }
    }
}
