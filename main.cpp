#include <iostream>
#include <vector>
#include <SDL.h>
#include <string>
#include <map>

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

enum pieceType {King, Queen, Rook, Bishop, Knight, Pawn, None};
enum playerColor {White, Black, none};

class piece {
public:
    cell getPos();
protected:
    cell pos;
    bool isAlive;
    pieceType type;
    vector <cell> attacking;
};

cell piece::getPos() {
    return pos;
}

class king: public piece {
public:
    king(cell);
    cell canGo();
};

class queen: public piece {
public:
    queen(cell);
    void canGo();
};

class rook: public piece {
public:
    rook(cell);
    void canGo();
};

class bishop: public piece {
public:
    bishop(cell);
    void canGo();
};

class knight: public piece {
public:
    knight(cell);
    void canGo();
};

class pawn: public piece {
public:
    pawn(cell);
    void canGo(playerColor);
};

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

king::king(cell givenCell) {
    isAlive = true;
    type = King;
    pos = givenCell;

}

cell king::canGo() {
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    if(xPosition + 1 <= 7) {
        cell tmp(xPosition + 1 , yPosition);
        attacking.push_back(tmp);
    }
    if(xPosition - 1 >= 0) {
        cell tmp(xPosition - 1 , yPosition);
        attacking.push_back(tmp);
    }
    if(yPosition + 1 <= 7) {
        cell tmp(xPosition , yPosition + 1);
        attacking.push_back(tmp);
    }
    if(yPosition - 1 >= 0) {
        cell tmp(xPosition , yPosition - 1);
        attacking.push_back(tmp);
    }
    if(xPosition + 1 <= 7 && yPosition + 1 <= 7) {
        cell tmp(xPosition + 1 , yPosition + 1);
        attacking.push_back(tmp);
    }
    if(xPosition - 1 >= 0 && yPosition - 1 >= 0) {
        cell tmp(xPosition - 1 , yPosition - 1);
        attacking.push_back(tmp);
    }
    if(xPosition + 1 <= 7 && yPosition - 1 >= 0) {
        cell tmp(xPosition + 1 , yPosition - 1);
        attacking.push_back(tmp);
    }
    if(xPosition - 1 >= 0 && yPosition + 1 <= 7) {
        cell tmp(xPosition - 1 , yPosition + 1);
        attacking.push_back(tmp);
    }
}

queen::queen(cell givenCell) {
    isAlive = true;
    type = Queen;
    pos = givenCell;
}

void queen::canGo() {
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    int counter;
    for(counter = 0 ; xPosition + counter <= 7 && yPosition + counter <= 7 ; counter++) {
        cell tmp(xPosition + counter , yPosition + counter);
        attacking.push_back(tmp);
    }
    for(counter = 0 ; xPosition - counter >= 0 && yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition - counter , yPosition - counter);
        attacking.push_back(tmp);
    }
    for(counter = 0 ; xPosition - counter >= 0 && yPosition + counter <= 7 ; counter++) {
        cell tmp(xPosition - counter , yPosition + counter);
        attacking.push_back(tmp);
    }
    for(counter = 0 ; xPosition + counter <= 7 && yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition + counter , yPosition - counter);
        attacking.push_back(tmp);
    }
    for(counter = 1 ; counter + xPosition <= 7 ; counter++) {
        cell tmp(counter + xPosition , yPosition);
        attacking.push_back(tmp);
    }
    for(counter = 1 ; xPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition - counter , yPosition);
        attacking.push_back(tmp);
    }
    for(counter = 1 ; counter + yPosition <= 7 ; counter++) {
        cell tmp(xPosition , yPosition + counter);
        attacking.push_back(tmp);
    }
    for(counter = 1 ; yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition , yPosition - counter);
        attacking.push_back(tmp);
    }
}

rook::rook(cell givenCell) {
    isAlive = true;
    type = Rook;
    pos = givenCell;
}

void rook::canGo() {
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    int counter;
    for(counter = 1 ; counter + xPosition <= 7 ; counter++) {
        cell tmp(counter + xPosition , yPosition);
        attacking.push_back(tmp);
    }
    for(counter = 1 ; xPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition - counter , yPosition);
        attacking.push_back(tmp);
    }
    for(counter = 1 ; counter + yPosition <= 7 ; counter++) {
        cell tmp(xPosition , yPosition + counter);
        attacking.push_back(tmp);
    }
    for(counter = 1 ; yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition , yPosition - counter);
        attacking.push_back(tmp);
    }
}

bishop::bishop(cell givenCell) {
    isAlive = true;
    type = Bishop;
    pos = givenCell;

}

void bishop::canGo() {
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    int counter;
    for(counter = 0 ; xPosition + counter <= 7 && yPosition + counter <= 7 ; counter++) {
        cell tmp(xPosition + counter , yPosition + counter);
        attacking.push_back(tmp);
    }
    for(counter = 0 ; xPosition - counter >= 0 && yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition - counter , yPosition - counter);
        attacking.push_back(tmp);
    }
    for(counter = 0 ; xPosition - counter >= 0 && yPosition + counter <= 7 ; counter++) {
        cell tmp(xPosition - counter , yPosition + counter);
        attacking.push_back(tmp);
    }
    for(counter = 0 ; xPosition + counter <= 7 && yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition + counter , yPosition - counter);
        attacking.push_back(tmp);
    }
}

knight::knight(cell givenCell) {
    isAlive = true;
    type = Knight;
    pos = givenCell;
}

void knight::canGo() {
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    if(xPosition + 1 <= 7 && yPosition + 2 <= 7) {
        cell tmp(xPosition + 1 , yPosition + 2);
        attacking.push_back(tmp);
    }
    if(xPosition + 1 <= 7 && yPosition - 2 >= 0) {
        cell tmp(xPosition + 1 , yPosition - 2);
        attacking.push_back(tmp);
    }
    if(xPosition + 2 <= 7 && yPosition - 1 >= 0) {
        cell tmp(xPosition + 2 , yPosition - 1);
        attacking.push_back(tmp);
    }
    if(xPosition + 2 <= 7 && yPosition + 1 <= 7) {
        cell tmp(xPosition + 2 , yPosition + 1);
        attacking.push_back(tmp);
    }
    if(xPosition - 1 >= 0 && yPosition - 2 >= 0) {
        cell tmp(xPosition - 1 , yPosition - 2);
        attacking.push_back(tmp);
    }
    if(xPosition - 1 >= 0 && yPosition + 2 <= 7) {
        cell tmp(xPosition - 1 , yPosition + 2);
        attacking.push_back(tmp);
    }
    if(xPosition - 2 >= 0 && yPosition - 1 >= 0) {
        cell tmp(xPosition - 2 , yPosition - 1);
        attacking.push_back(tmp);
    }
    if(xPosition - 2 >= 0 && yPosition + 1 <= 7) {
        cell tmp(xPosition - 2 , yPosition + 1);
        attacking.push_back(tmp);
    }
}

pawn::pawn(cell givenCell) {
    isAlive = true;
    type = Pawn;
    pos = givenCell;
}

void pawn::canGo(playerColor color) {
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    bool firstTurn = false;
    if(color == White && yPosition == 1) {
        firstTurn = true;
    }
    if(color == Black && yPosition == 6) {
        firstTurn = true;
    }
    if(firstTurn) {
       cell tmp1(xPosition , yPosition + 1);
       attacking.push_back(tmp1);
       cell tmp2(xPosition , yPosition + 2);
       attacking.push_back(tmp2);
       firstTurn = false;
    } else {
       if(yPosition + 1 <= 7) {
        cell tmp(xPosition , yPosition + 1);
        attacking.push_back(tmp);
       }
    }
}

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
    void updateBoard(bool, int, int);
    bool isRunning();
    playerColor getTurn();
    bool isChecked(player attacker, player deffender);
    bool isCheckmated(player attacker, player deffender);
    bool isStalemated(player attacker, player deffender);
    void endGame();
    pieceType pieceOf(cell);
    void setTable(cell, pieceType);
    pieceType getTable(cell);
    void initializeTable();
    void initializePieceMap();
    void movePiece(cell starting, cell ending);
    void selectedPieces(int selectedX , int selectedY);
private:
    bool gameIsOver;
    playerColor turn;
    SDL_Surface* background = NULL;
    pieceType table[8][8];
    playerColor colorTable[8][8];
    int indexTable[8][8];
};

board::board() {
    window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);
    background = SDL_LoadBMP("background.bmp");
    initializePieceMap();
    initializeTable();
    player white(White), black(Black);
    gameIsOver = false;
    turn = White;
}

map <pieceType, string> pieceMap;

void board::updateBoard(bool firstClick, int firstClickX, int firstClickY) {
    SDL_BlitSurface(background, NULL, screenSurface, NULL);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (table[i][j] != None) {
                string address = "pieces\\";
                if (colorTable[i][j] == White) {
                    address += "white";
                } else {
                    address += "black";
                }
                if (!firstClick && firstClickX == j && firstClickY == i) {
                    address += "Selected\\";
                }
                else {
                    if ((i + j) % 2) {
                        address += "WhiteBackground\\";
                    } else {
                        address += "GreenBackground\\";
                    }
                }
                address += pieceMap[table[i][j]] + ".bmp";
                SDL_Surface* pieceSurface = NULL;
                pieceSurface = SDL_LoadBMP(address.data());
                pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
                SDL_Rect position;
                position.x = j * 50;
                position.y = i * 50;
                position.h = 50;
                position.w = 50;
                SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
            }
        }
    }
    SDL_UpdateWindowSurface(window);
}

bool board::isRunning() {
    return !gameIsOver;
}

playerColor board::getTurn() {
    return turn;
}

void board::endGame() {
    gameIsOver = true;
}

pieceType board::pieceOf(cell position) {
    return table[position.getY()][position.getX()];
}

void board::setTable(cell position, pieceType toAdd) {
    table[position.getY()][position.getX()] = toAdd;
}

pieceType board::getTable(cell position) {
    return table[position.getY()][position.getX()];
}

void board::initializeTable() {
    pieceType tmp[8] = {Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook};
    int tmp2[8] = {0, 0, 0, 0, 0, 1, 1, 1};
    copy(tmp, tmp + 8, &table[0][0]);
    copy(tmp, tmp + 8, &table[7][0]);
    copy(tmp2, tmp2 + 8, &indexTable[0][0]);
    copy(tmp2, tmp2 + 8, &indexTable[7][0]);
    for (int i = 0; i < 8; i++) {
        table[1][i] = Pawn;
        table[6][i] = Pawn;
        colorTable[0][i] = White;
        colorTable[1][i] = White;
        colorTable[6][i] = Black;
        colorTable[7][i] = Black;
        indexTable[1][i] = i;
        indexTable[6][i] = i;
    }
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            table[i][j] = None;
            colorTable[i][j] = none;
            indexTable[i][j] = -1;
        }
    }
}

void board::initializePieceMap() {
    pieceMap[King] = "king";
    pieceMap[Queen] = "queen";
    pieceMap[Rook] = "rook";
    pieceMap[Bishop] = "bishop";
    pieceMap[Knight] = "knight";
    pieceMap[Pawn] = "pawn";
}

void board::movePiece(cell starting, cell ending) {
    int x = starting.getX(), y = starting.getY(), x2 = ending.getX(), y2 = ending.getY();
    swap(table[y][x], table[y2][x2]);
    swap(colorTable[y][x], colorTable[y2][x2]);
    swap(indexTable[y][x], indexTable[y2][x2]);
    if (table[y][x] != None) {
        table[y][x] = None;
        colorTable[y][x] = none;
    }
}

int main(int argc, char* args[]) {
    board game; //object of running gameTable
    SDL_Event event;
    int x , y;
    bool firstClick = true;
    int firstClickX, firstClickY;
    while (game.isRunning()) { //mainLoop
        while (game.getTurn() == White && game.isRunning()) {
           while(SDL_PollEvent(&event) && game.getTurn() == White && game.isRunning()) {
                switch(event.type) {
                    case SDL_QUIT:
                        game.endGame();
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        cell current(event.motion.x / 50, event.motion.y / 50);
                        if (firstClick && game.getTable(current) != None) {
                            firstClickX = event.motion.x / 50;
                            firstClickY = event.motion.y / 50;
                            firstClick = false;
                        } else {
                            /*should be checked if piece is able to do such a move
                            and then no check or checkmate created against current player*/
                            firstClick = true;
                            cell starting(firstClickX, firstClickY), ending(event.motion.x / 50, event.motion.y / 50);
                            game.movePiece(starting, ending);
                        }
                }
                game.updateBoard(firstClick, firstClickX, firstClickY);
                SDL_Delay(100);
            }
        }
        while (game.getTurn() == Black && game.isRunning()) {
           while(SDL_PollEvent(&event) && game.getTurn() == Black && game.isRunning()) {
                switch(event.type) {
                    case SDL_QUIT:
                        game.endGame();
                        break;
                    case SDL_MOUSEBUTTONDOWN: // if the event is mouse click
                        cout << "Hey\n";
                }
            }
        }
    }
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
    window = NULL;
    screenSurface = NULL;
    SDL_Quit();
}
