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

}

queen::queen(cell givenCell) {
    isAlive = true;
    pos = givenCell;
    SDL_Surface* queenSurface = NULL;
    if (pos.getY() == 0 && pos.getX() == 3) {
        queenSurface = SDL_LoadBMP("pieces\\whiteWhiteBackground\\queen.bmp");
    } else if (pos.getY() == 7 && pos.getX() == 3) {
        queenSurface = SDL_LoadBMP("pieces\\blackGreenBackground\\queen.bmp");
    }
    queenSurface = SDL_ConvertSurface(queenSurface , screenSurface -> format , 0);
    SDL_Rect position;
    position.x = pos.getX() * 50;
    position.y = pos.getY() * 50;
    position.w = 50;
    position.h = 50;
    SDL_BlitScaled(queenSurface, NULL, screenSurface, &position);
}

rook::rook(cell givenCell) {
    isAlive = true;
    pos = givenCell;
    SDL_Surface* rookSurface = NULL;
    if (pos.getY() == 0 && pos.getX() == 7) {
        rookSurface = SDL_LoadBMP("pieces\\whiteWhiteBackground\\rook.bmp");
    } else if (pos.getY() == 0 && pos.getX() == 0) {
        rookSurface = SDL_LoadBMP("pieces\\whiteGreenBackground\\rook.bmp");
    } else if (pos.getX() == 0 && pos.getY() == 7) {
        rookSurface = SDL_LoadBMP("pieces\\blackWhiteBackground\\rook.bmp");
    }  else if (pos.getX() == 7 && pos.getY() == 7) {
        rookSurface = SDL_LoadBMP("pieces\\blackGreenBackground\\rook.bmp");
    }
    rookSurface = SDL_ConvertSurface(rookSurface , screenSurface -> format , 0);
    SDL_Rect position;
    position.x = pos.getX() * 50;
    position.y = pos.getY() * 50;
    position.w = 50;
    position.h = 50;
    SDL_BlitScaled(rookSurface, NULL, screenSurface, &position);
}

bishop::bishop(cell givenCell) {
    isAlive = true;
    pos = givenCell;
    SDL_Surface* bishopSurface = NULL;
    if(pos.getX() == 1 && pos.getY() == 0) {
        bishopSurface = SDL_LoadBMP("pieces\\whiteWhiteBackground\\bishop.bmp");
    } else if(pos.getX() == 6 && pos.getY() == 0) {
        bishopSurface = SDL_LoadBMP("pieces\\whiteGreenBackground\\bishop.bmp");
    } else if(pos.getX() == 1 && pos.getY() == 7) {
        bishopSurface = SDL_LoadBMP("pieces\\blackGreenBackground\\bishop.bmp");
    } if(pos.getX() == 6 && pos.getY() == 7) {
        bishopSurface = SDL_LoadBMP("pieces\\blackWhiteBackground\\bishop.bmp");
    }
    bishopSurface = SDL_ConvertSurface(bishopSurface , screenSurface -> format , 0);
    SDL_Rect position;
    position.x = pos.getX() * 50;
    position.y = pos.getY() * 50;
    position.w = 50;
    position.h = 50;
    SDL_BlitScaled(bishopSurface, NULL, screenSurface, &position);
}

knight::knight(cell givenCell) {
    isAlive = true;
    pos = givenCell;
    SDL_Surface* knightSurface = NULL;
    if(pos.getX() == 5 && pos.getY() == 0) {
        knightSurface = SDL_LoadBMP("pieces\\whiteWhiteBackground\\knight.bmp");
    } else if(pos.getX() == 2 && pos.getY() == 0) {
        knightSurface = SDL_LoadBMP("pieces\\whiteGreenBackground\\knight.bmp");
    } else if(pos.getX() == 5 && pos.getY() == 7) {
        knightSurface = SDL_LoadBMP("pieces\\blackGreenBackground\\knight.bmp");
    } if(pos.getX() == 2 && pos.getY() == 7) {
        knightSurface = SDL_LoadBMP("pieces\\blackWhiteBackground\\knight.bmp");
    }
    knightSurface = SDL_ConvertSurface(knightSurface , screenSurface -> format , 0);
    SDL_Rect position;
    position.x = pos.getX() * 50;
    position.y = pos.getY() * 50;
    position.w = 50;
    position.h = 50;
    SDL_BlitScaled(knightSurface, NULL, screenSurface, &position);
}

pawn::pawn(cell givenCell) {
    isAlive = true;
    pos = givenCell;
    SDL_Surface* pawnSurface = NULL;
    if(pos.getY() == 1 && pos.getX() % 2 == 0) {
        pawnSurface = SDL_LoadBMP("pieces\\whiteWhiteBackground\\pawn.bmp");
    } else if (pos.getY() == 1 && pos.getX() % 2 != 0) {
        pawnSurface = SDL_LoadBMP("pieces\\whiteGreenBackground\\pawn.bmp");
    } else if (pos.getY() == 6 && pos.getX() % 2 == 0) {
        pawnSurface = SDL_LoadBMP("pieces\\blackGreenBackground\\pawn.bmp");
    } else if (pos.getY() == 6 && pos.getX() % 2 != 0) {
        pawnSurface = SDL_LoadBMP("pieces\\blackWhiteBackground\\pawn.bmp");
    }
    pawnSurface = SDL_ConvertSurface(pawnSurface , screenSurface -> format , 0);
    SDL_Rect position;
    position.x = pos.getX() * 50;
    position.y = pos.getY() * 50;
    position.h = 50;
    position.w = 50;
    SDL_BlitScaled(pawnSurface, NULL, screenSurface, &position);
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
    int counter;
    if (color == White) {
        cell positionRook1(0, 0);
        rook tempRook1(positionRook1);
        playerRooks.push_back(tempRook1);
        cell positionRook2(7, 0);
        rook tempRook2(positionRook2);
        playerRooks.push_back(tempRook2);
        cell positionBishop1(1, 0);
        bishop tempBishop1(positionBishop1);
        playerBishops.push_back(tempBishop1);
        cell positionBishop2(6, 0);
        bishop tempBishop2(positionBishop2);
        playerBishops.push_back(tempBishop2);
        cell positionKnight1(2, 0);
        knight tempKnight1(positionKnight1);
        playerKnights.push_back(tempKnight1);
        cell positionKnight2(5, 0);
        knight tempKnight2(positionKnight2);
        playerKnights.push_back(tempKnight2);
        cell positionQueen(3, 0);
        queen tempQueen(positionQueen);
        playerQueen.push_back(tempQueen);
        for(counter = 0 ; counter < 8 ; counter++) {
            cell positionPawn(counter, 1);
            pawn tempPawn(positionPawn);
            playerPawns.push_back(tempPawn);
        }
        cell positionKing(4, 0);
        king tempKing(positionKing);
        playerKing.push_back(tempKing);
    } else {
        cell positionRook1(0, 7);
        rook tempRook1(positionRook1);
        playerRooks.push_back(tempRook1);
        cell positionRook2(7, 7);
        rook tempRook2(positionRook2);
        playerRooks.push_back(tempRook2);
        cell positionBishop1(1, 7);
        bishop tempBishop1(positionBishop1);
        playerBishops.push_back(tempBishop1);
        cell positionBishop2(6, 7);
        bishop tempBishop2(positionBishop2);
        playerBishops.push_back(tempBishop2);
        cell positionknight1(2, 7);
        knight tempKnight1(positionknight1);
        playerKnights.push_back(tempKnight1);
        cell positionknight2(5, 7);
        knight tempKnight2(positionknight2);
        playerKnights.push_back(tempKnight2);
        cell positionQueen(3, 7);
        queen tempQueen(positionQueen);
        playerQueen.push_back(tempQueen);
        for(counter = 0 ; counter < 8 ; counter++) {
            cell positionPawn(counter, 6);
            pawn tempPawn(positionPawn);
            playerPawns.push_back(tempPawn);
        }
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
