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
    void setX(int);
    void setY(int);
private:
    int x;
    int y;
};

cell::cell(int givenX, int givenY) {
    x = givenX;
    y = givenY;
}

void cell::setX(int givenX) {
    x = givenX;
}

int cell::getX() {
    return x;
}

void cell::setY(int givenY) {
    y = givenY;
}

int cell::getY() {
    return y;
}

enum pieceType {King = 0, Queen = 1, Rook = 2, Bishop = 3, Knight = 4, Pawn = 5, None = 6};
enum playerColor {White, Black, none};

class piece {
public:
    cell getPos();
    void setPos(cell toSet);
    vector <cell> getAttacking();
protected:
    cell pos;
    bool isAlive;
    pieceType type;
    vector <cell> attacking;
};

cell piece::getPos() {
    return pos;
}

void piece::setPos(cell toSet) {
    pos.setX(toSet.getX());
    pos.setY(toSet.getY());
    //cout << pos.getY() << "here we goh\n";
}

vector <cell> piece::getAttacking() {
    return attacking;
}

class king: public piece {
public:
    king(cell);
    vector <cell> canGo(playerColor, playerColor colorTable[8][8]);
};

class queen: public piece {
public:
    queen(cell);
    vector <cell> canGo(playerColor, playerColor colorTable[8][8]);
};

class rook: public piece {
public:
    rook(cell);
    vector <cell> canGo(playerColor, playerColor colorTable[8][8]);
};

class bishop: public piece {
public:
    bishop(cell);
    vector <cell> canGo(playerColor, playerColor colorTable[8][8]);
};

class knight: public piece {
public:
    knight(cell);
    vector <cell> canGo(playerColor, playerColor colorTable[8][8]);
};

class pawn: public piece {
public:
    pawn(cell);
    vector <cell> canGo(playerColor, playerColor colorTable[8][8]);
};

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
bool dangerousForWhite[8][8], dangerousForBlack[8][8];

king::king(cell givenCell) {
    isAlive = true;
    type = King;
    pos = givenCell;

}

vector <cell> king::canGo(playerColor color, playerColor colorTable[8][8]) {
    attacking.clear();
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    if(xPosition + 1 <= 7) {
        cell tmp(xPosition + 1 , yPosition);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition - 1 >= 0) {
        cell tmp(xPosition - 1 , yPosition);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(yPosition + 1 <= 7) {
        cell tmp(xPosition , yPosition + 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(yPosition - 1 >= 0) {
        cell tmp(xPosition , yPosition - 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition + 1 <= 7 && yPosition + 1 <= 7) {
        cell tmp(xPosition + 1 , yPosition + 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition - 1 >= 0 && yPosition - 1 >= 0) {
        cell tmp(xPosition - 1 , yPosition - 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition + 1 <= 7 && yPosition - 1 >= 0) {
        cell tmp(xPosition + 1 , yPosition - 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition - 1 >= 0 && yPosition + 1 <= 7) {
        cell tmp(xPosition - 1 , yPosition + 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    return attacking;
}

queen::queen(cell givenCell) {
    isAlive = true;
    type = Queen;
    pos = givenCell;
}

vector <cell> queen::canGo(playerColor color, playerColor colorTable[8][8]) {
    attacking.clear();
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    int counter;
    for(counter = 1 ; xPosition + counter <= 7 && yPosition + counter <= 7 ; counter++) {
        cell tmp(xPosition + counter , yPosition + counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; xPosition - counter >= 0 && yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition - counter , yPosition - counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; xPosition - counter >= 0 && yPosition + counter <= 7 ; counter++) {
        cell tmp(xPosition - counter , yPosition + counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; xPosition + counter <= 7 && yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition + counter , yPosition - counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; counter + xPosition <= 7 ; counter++) {
        cell tmp(counter + xPosition , yPosition);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; xPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition - counter , yPosition);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; counter + yPosition <= 7 ; counter++) {
        cell tmp(xPosition , yPosition + counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition , yPosition - counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    return attacking;
}

rook::rook(cell givenCell) {
    isAlive = true;
    type = Rook;
    pos = givenCell;
}

vector <cell> rook::canGo(playerColor color, playerColor colorTable[8][8]) {
    attacking.clear();
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    int counter;
    for(counter = 1 ; counter + xPosition <= 7 ; counter++) {
        cell tmp(counter + xPosition , yPosition);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; xPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition - counter , yPosition);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; counter + yPosition <= 7 ; counter++) {
        cell tmp(xPosition , yPosition + counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition , yPosition - counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    return attacking;
}

bishop::bishop(cell givenCell) {
    isAlive = true;
    type = Bishop;
    pos = givenCell;

}

vector <cell> bishop::canGo(playerColor color, playerColor colorTable[8][8]) {
    attacking.clear();
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    int counter;
    for(counter = 1 ; xPosition + counter <= 7 && yPosition + counter <= 7 ; counter++) {
        cell tmp(xPosition + counter , yPosition + counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; xPosition - counter >= 0 && yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition - counter , yPosition - counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; xPosition - counter >= 0 && yPosition + counter <= 7 ; counter++) {
        cell tmp(xPosition - counter , yPosition + counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    for(counter = 1 ; xPosition + counter <= 7 && yPosition - counter >= 0 ; counter++) {
        cell tmp(xPosition + counter , yPosition - counter);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] == none) {
            attacking.push_back(tmp);
        } else if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
            break;
        } else if (colorTable[tmp.getY()][tmp.getX()] == color) {
            break;
        }
    }
    return attacking;
}

knight::knight(cell givenCell) {
    isAlive = true;
    type = Knight;
    pos = givenCell;
}

vector <cell> knight::canGo(playerColor color, playerColor colorTable[8][8]) {
    attacking.clear();
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    if(xPosition + 1 <= 7 && yPosition + 2 <= 7) {
        cell tmp(xPosition + 1 , yPosition + 2);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition + 1 <= 7 && yPosition - 2 >= 0) {
        cell tmp(xPosition + 1 , yPosition - 2);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition + 2 <= 7 && yPosition - 1 >= 0) {
        cell tmp(xPosition + 2 , yPosition - 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition + 2 <= 7 && yPosition + 1 <= 7) {
        cell tmp(xPosition + 2 , yPosition + 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition - 1 >= 0 && yPosition - 2 >= 0) {
        cell tmp(xPosition - 1 , yPosition - 2);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition - 1 >= 0 && yPosition + 2 <= 7) {
        cell tmp(xPosition - 1 , yPosition + 2);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition - 2 >= 0 && yPosition - 1 >= 0) {
        cell tmp(xPosition - 2 , yPosition - 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    if(xPosition - 2 >= 0 && yPosition + 1 <= 7) {
        cell tmp(xPosition - 2 , yPosition + 1);
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[tmp.getY()][tmp.getX()] != color) {
            attacking.push_back(tmp);
        }
    }
    return attacking;
}

pawn::pawn(cell givenCell) {
    isAlive = true;
    type = Pawn;
    pos = givenCell;
}

map <playerColor, playerColor> rivalMap;

vector <cell> pawn::canGo(playerColor color, playerColor colorTable[8][8]) {
    attacking.clear();
    cell position = getPos();
    int xPosition = position.getX();
    int yPosition = position.getY();
    //cout << type << ' ' << xPosition << ' ' << yPosition  << ' ' << endl;
    bool firstTurn = false;
    if(color == White && yPosition == 1) {
        firstTurn = true;
    }
    if(color == Black && yPosition == 6) {
        firstTurn = true;
    }
    if(firstTurn) {
        if (colorTable[yPosition + (color == White ? 1 : -1)][xPosition] == none) {
            cell tmp1(xPosition , yPosition + (color == White ? 1 : -1));
            attacking.push_back(tmp1);
            if (colorTable[yPosition + (color == White ? 2 : -2)][xPosition] == none) {
                cell tmp2(xPosition , yPosition + (color == White ? 2 : -2));
                attacking.push_back(tmp2);
                firstTurn = false;
            }
        }
    } else {
        if(yPosition + (color == White ? 1 : -1) <= 7 && yPosition + (color == White ? 1 : -1) >= 0 &&
          colorTable[yPosition + (color == White ? 1 : -1)][xPosition] == none) {
            cell tmp(xPosition , yPosition + (color == White ? 1 : -1));
            attacking.push_back(tmp);
        }
    }
    if (yPosition + (color == White ? 1 : -1) <= 7 && yPosition + (color == White ? 1 : -1) >= 0 && xPosition + 1 <= 7) {
        cell tmp(xPosition + 1, yPosition + (color == White ? 1 : -1));
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[yPosition + (color == White ? 1 : -1)][xPosition + 1] == rivalMap[color]) {
            attacking.push_back(tmp);
        }
    }
    if (yPosition + (color == White ? 1 : -1) <= 7 && yPosition + (color == White ? 1 : -1) >= 0 && xPosition - 1 >= 0) {
        cell tmp(xPosition - 1, yPosition + (color == White ? 1 : -1));
        if (color == White) {
            dangerousForBlack[tmp.getY()][tmp.getX()] = true;
        } else {
            dangerousForWhite[tmp.getY()][tmp.getX()] = true;
        }
        if (colorTable[yPosition + (color == White ? 1 : -1)][xPosition - 1] == rivalMap[color]) {
            attacking.push_back(tmp);
        }
    }
    return attacking;
}

class player {
public:
    player(playerColor = White);
    vector <king*> getKing();
    vector <queen*> getQueen();
    vector <rook*> getRooks();
    vector <bishop*> getBishops();
    vector <knight*> getKnights();
    vector <pawn*> getPawns();
    playerColor getColor();
private:
    vector <king> playerKing;
    vector <queen> playerQueen;
    vector <rook> playerRooks;
    vector <bishop> playerBishops;
    vector <knight> playerKnights;
    vector <pawn> playerPawns;
    playerColor Color;
};

vector <king*> player::getKing() {
    vector <king*> res;
    for (int i = 0; i < playerKing.size(); i++) {
        res.push_back(&playerKing[i]);
    }
    return res;
}
vector <queen*> player::getQueen() {
    vector <queen*> res;
    for (int i = 0; i < playerQueen.size(); i++) {
        res.push_back(&playerQueen[i]);
    }
    return res;
}
vector <rook*> player::getRooks() {
    vector <rook*> res;
    for (int i = 0; i < playerRooks.size(); i++) {
        res.push_back(&playerRooks[i]);
    }
    return res;
}
vector <bishop*> player::getBishops() {
    vector <bishop*> res;
    for (int i = 0; i < playerBishops.size(); i++) {
        res.push_back(&playerBishops[i]);
    }
    return res;
}
vector <knight*> player::getKnights() {
    vector <knight*> res;
    for (int i = 0; i < playerKnights.size(); i++) {
        res.push_back(&playerKnights[i]);
    }
    return res;
}
vector <pawn*> player::getPawns() {
    vector <pawn*> res;
    for (int i = 0; i < playerPawns.size(); i++) {
        res.push_back(&playerPawns[i]);
    }
    return res;
}

player::player(playerColor color) {
    Color = color;
    int counter;
    if (color == White) {
        //cout << "sefiiiidIneeee" << Color << endl;
        cell positionRook1(0, 0);
        rook tempRook1(positionRook1);
        playerRooks.push_back(tempRook1);
        cell positionRook2(7, 0);
        rook tempRook2(positionRook2);
        playerRooks.push_back(tempRook2);
        cell positionBishop1(2, 0);
        bishop tempBishop1(positionBishop1);
        playerBishops.push_back(tempBishop1);
        cell positionBishop2(5, 0);
        bishop tempBishop2(positionBishop2);
        playerBishops.push_back(tempBishop2);
        cell positionKnight1(1, 0);
        knight tempKnight1(positionKnight1);
        playerKnights.push_back(tempKnight1);
        cell positionKnight2(6, 0);
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
        //cout << "siiiiahhhIneeee" << Color << endl;
        cell positionRook1(0, 7);
        rook tempRook1(positionRook1);
        playerRooks.push_back(tempRook1);
        cell positionRook2(7, 7);
        rook tempRook2(positionRook2);
        playerRooks.push_back(tempRook2);
        cell positionBishop1(2, 7);
        bishop tempBishop1(positionBishop1);
        playerBishops.push_back(tempBishop1);
        cell positionBishop2(5, 7);
        bishop tempBishop2(positionBishop2);
        playerBishops.push_back(tempBishop2);
        cell positionknight1(1, 7);
        knight tempKnight1(positionknight1);
        playerKnights.push_back(tempKnight1);
        cell positionknight2(6, 7);
        knight tempKnight2(positionknight2);
        playerKnights.push_back(tempKnight2);
        cell positionQueen(3, 7);
        queen tempQueen(positionQueen);
        playerQueen.push_back(tempQueen);
        for(counter = 0 ; counter < 8 ; counter++) {
            //cout << "hooou\n";
            cell positionPawn(counter, 6);
            pawn tempPawn(positionPawn);
            playerPawns.push_back(tempPawn);
            //cout << "size: " << playerPawns.size() << endl;
        }
        cell position(4, 7);
        king tempKing(position);
        playerKing.push_back(tempKing);
    }
}

playerColor player::getColor() {
    return Color;
}

class board {
public:
    board();
    void updateBoard(bool, int, int, bool, bool, bool, bool);
    bool isRunning();
    playerColor getTurn();
    bool isChecked(king* defenderKing, playerColor color);
    bool isCheckmated(king* defenderKing, playerColor color);
    bool isStalemated(king* defenderKing, playerColor color);
    void endGame();
    pieceType pieceOf(cell);
    void setTable(cell, pieceType);
    pieceType getTable(cell);
    playerColor getColorTable(cell);
    int getIndexTable(cell);
    void initializeTable();
    void initializePieceMap();
    bool movePiece(cell starting, cell ending);
    void updateAttackingCellGraphics(playerColor attacker, pieceType type, int index);
    void printBoard();
    player* getPlayer(playerColor);
    void nextTurn();
private:
    bool gameIsOver;
    playerColor turn;
    SDL_Surface* background = NULL;
    pieceType table[8][8];
    playerColor colorTable[8][8];
    int indexTable[8][8];
    player white, black;
    bool dangerForWhite[8][8] = {}, dangerForBlack[8][8] = {};
};

board::board() : white(White), black(Black) {
    window = SDL_CreateWindow("Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 500, SDL_WINDOW_SHOWN);
    screenSurface = SDL_GetWindowSurface(window);
    background = SDL_LoadBMP("pictures\\backgrounds\\turnWhite.bmp");
    initializePieceMap();
    initializeTable();
    gameIsOver = false;
    turn = White;
}

map <pieceType, string> pieceMap;

void board::updateAttackingCellGraphics(playerColor attacker, pieceType type, int index){
    rivalMap[White] = Black;
    rivalMap[Black] = White;
    if (type == Pawn) {
        //cout << "vaaaaaay" << getPlayer(attacker) -> getPawns()[index]->getPos().getY() << endl;
        for (int i = 0; i < getPlayer(attacker) -> getPawns()[index] -> canGo(attacker, colorTable).size(); i++) {
            cell toRed = getPlayer(attacker) -> getPawns()[index] -> canGo(attacker, colorTable)[i];
            SDL_Surface* pieceSurface = NULL;
            string address = "pictures\\pieces\\";
            if (colorTable[toRed.getY()][toRed.getX()] == White) {
                address += "whiteAttacked\\";
            } else {
                address += "blackAttacked\\";
            }
            address += pieceMap[table[toRed.getY()][toRed.getX()]] + ".bmp";
            pieceSurface = SDL_LoadBMP(address.data());
            pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
            SDL_Rect position;
            position.x = toRed.getX() * 50;
            position.y = toRed.getY() * 50;
            position.h = 50;
            position.w = 50;
            SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
            if (attacker == White) {
                dangerForBlack[toRed.getY()][toRed.getX()] = true;
            }
            if (attacker == Black) {
                dangerForWhite[toRed.getY()][toRed.getX()] = true;
                //cout << "Hey O\n";
            }
        }
    }
    if (type == King) {
        //cout << "kiiiing" << getPlayer(attacker) -> getKing()[index]->getPos().getY() << endl;
        for (int i = 0; i < getPlayer(attacker) -> getKing()[index] -> canGo(attacker, colorTable).size(); i++) {
            cell toRed = getPlayer(attacker) -> getKing()[index] -> canGo(attacker, colorTable)[i];
            SDL_Surface* pieceSurface = NULL;
            string address = "pictures\\pieces\\";
            if (colorTable[toRed.getY()][toRed.getX()] == White) {
                address += "whiteAttacked\\";
            } else {
                address += "blackAttacked\\";
            }
            address += pieceMap[table[toRed.getY()][toRed.getX()]] + ".bmp";
            pieceSurface = SDL_LoadBMP(address.data());
            pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
            SDL_Rect position;
            position.x = toRed.getX() * 50;
            position.y = toRed.getY() * 50;
            position.h = 50;
            position.w = 50;
            SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
            if (attacker == White) {
                dangerForBlack[toRed.getY()][toRed.getX()] = true;
            }
            if (attacker == Black) {
                dangerForWhite[toRed.getY()][toRed.getX()] = true;
            }
        }
    }
    if (type == Rook) {
        //cout << "kiiiing" << getPlayer(attacker) -> getRooks()[index]->getPos().getY() << endl;
        for (int i = 0; i < getPlayer(attacker) -> getRooks()[index] -> canGo(attacker, colorTable).size(); i++) {
            cell toRed = getPlayer(attacker) -> getRooks()[index] -> canGo(attacker, colorTable)[i];
            SDL_Surface* pieceSurface = NULL;
            string address = "pictures\\pieces\\";
            if (colorTable[toRed.getY()][toRed.getX()] == White) {
                address += "whiteAttacked\\";
            } else {
                address += "blackAttacked\\";
            }
            address += pieceMap[table[toRed.getY()][toRed.getX()]] + ".bmp";
            pieceSurface = SDL_LoadBMP(address.data());
            pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
            SDL_Rect position;
            position.x = toRed.getX() * 50;
            position.y = toRed.getY() * 50;
            position.h = 50;
            position.w = 50;
            SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
            if (attacker == White) {
                dangerForBlack[toRed.getY()][toRed.getX()] = true;
            }
            if (attacker == Black) {
                dangerForWhite[toRed.getY()][toRed.getX()] = true;
            }
        }
    }
    if (type == Bishop) {
        //cout << "kiiiing" << getPlayer(attacker) -> getBishops()[index]->getPos().getY() << endl;
        for (int i = 0; i < getPlayer(attacker) -> getBishops()[index] -> canGo(attacker, colorTable).size(); i++) {
            cell toRed = getPlayer(attacker) -> getBishops()[index] -> canGo(attacker, colorTable)[i];
            SDL_Surface* pieceSurface = NULL;
            string address = "pictures\\pieces\\";
            if (colorTable[toRed.getY()][toRed.getX()] == White) {
                address += "whiteAttacked\\";
            } else {
                address += "blackAttacked\\";
            }
            address += pieceMap[table[toRed.getY()][toRed.getX()]] + ".bmp";
            pieceSurface = SDL_LoadBMP(address.data());
            pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
            SDL_Rect position;
            position.x = toRed.getX() * 50;
            position.y = toRed.getY() * 50;
            position.h = 50;
            position.w = 50;
            SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
            if (attacker == White) {
                dangerForBlack[toRed.getY()][toRed.getX()] = true;
            }
            if (attacker == Black) {
                dangerForWhite[toRed.getY()][toRed.getX()] = true;
            }
        }
    }
    if (type == Knight) {
        //cout << "kiiiing" << getPlayer(attacker) -> getKnights()[index]->getPos().getY() << endl;
        for (int i = 0; i < getPlayer(attacker) -> getKnights()[index] -> canGo(attacker, colorTable).size(); i++) {
            cell toRed = getPlayer(attacker) -> getKnights()[index] -> canGo(attacker, colorTable)[i];
            SDL_Surface* pieceSurface = NULL;
            string address = "pictures\\pieces\\";
            if (colorTable[toRed.getY()][toRed.getX()] == White) {
                address += "whiteAttacked\\";
            } else {
                address += "blackAttacked\\";
            }
            address += pieceMap[table[toRed.getY()][toRed.getX()]] + ".bmp";
            pieceSurface = SDL_LoadBMP(address.data());
            pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
            SDL_Rect position;
            position.x = toRed.getX() * 50;
            position.y = toRed.getY() * 50;
            position.h = 50;
            position.w = 50;
            SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
            if (attacker == White) {
                dangerForBlack[toRed.getY()][toRed.getX()] = true;
            }
            if (attacker == Black) {
                dangerForWhite[toRed.getY()][toRed.getX()] = true;
            }
        }
    }
    if (type == Queen) {
        //cout << "kiiiing" << getPlayer(attacker) -> getQueen()[index]->getPos().getY() << endl;
        for (int i = 0; i < getPlayer(attacker) -> getQueen()[index] -> canGo(attacker, colorTable).size(); i++) {
            cell toRed = getPlayer(attacker) -> getQueen()[index] -> canGo(attacker, colorTable)[i];
            SDL_Surface* pieceSurface = NULL;
            string address = "pictures\\pieces\\";
            if (colorTable[toRed.getY()][toRed.getX()] == White) {
                address += "whiteAttacked\\";
            } else {
                address += "blackAttacked\\";
            }
            address += pieceMap[table[toRed.getY()][toRed.getX()]] + ".bmp";
            pieceSurface = SDL_LoadBMP(address.data());
            pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
            SDL_Rect position;
            position.x = toRed.getX() * 50;
            position.y = toRed.getY() * 50;
            position.h = 50;
            position.w = 50;
            SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
            if (attacker == White) {
                dangerForBlack[toRed.getY()][toRed.getX()] = true;
            }
            if (attacker == Black) {
                dangerForWhite[toRed.getY()][toRed.getX()] = true;
            }
        }
    }
}

map <playerColor, player> playerMap;

void board::updateBoard(bool firstClick, int firstClickX, int firstClickY, bool checkWhite, bool checkBlack,
                        bool checkmateWhite, bool checkmateBlack) {
    for (int i = 0; i < 8; i++) {
        fill(dangerForBlack[i], dangerForBlack[i] + 8, false);
        fill(dangerForWhite[i], dangerForWhite[i] + 8, false);
    }
    if (checkmateWhite) {
        background = SDL_LoadBMP("pictures\\backgrounds\\WinnerIsBlack.bmp");
    }
    if (checkmateBlack) {
        background = SDL_LoadBMP("pictures\\backgrounds\\WinnerIsWhite.bmp");
    }
    if (checkmateBlack || checkmateWhite) {
        gameIsOver = true;
    }
    SDL_BlitSurface(background, NULL, screenSurface, NULL);
    if (checkWhite) {
        SDL_Surface* pieceSurface = NULL;
        pieceSurface = SDL_LoadBMP("pictures\\checkMessages\\whiteCheck.bmp");
        pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
        SDL_Rect position;
        position.x = 0;
        position.y = 450;
        position.h = 50;
        position.w = 400;
        SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
    }
    if (checkBlack) {
        SDL_Surface* pieceSurface = NULL;
        pieceSurface = SDL_LoadBMP("pictures\\checkMessages\\blackCheck.bmp");
        pieceSurface = SDL_ConvertSurface(pieceSurface , screenSurface -> format , 0);
        SDL_Rect position;
        position.x = 0;
        position.y = 450;
        position.h = 50;
        position.w = 400;
        SDL_BlitScaled(pieceSurface, NULL, screenSurface, &position);
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (table[i][j] != None) {
                string address = "pictures\\pieces\\";
                if (colorTable[i][j] == White) {
                    if (dangerForWhite[i][j]) {
                        continue;
                    }
                    address += "white";
                } else {
                    if (dangerForBlack[i][j]) {
                        continue;
                    }
                    address += "black";
                }
                if (!firstClick && firstClickX == j && firstClickY == i) {
                    address += "Selected\\";
                    cell cur(j, i);
                    //cout << "color:" << getColorTable(cur) << endl;
                    updateAttackingCellGraphics(getColorTable(cur), getTable(cur), getIndexTable(cur));
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
    for (int i = 0; i < 8; i++) {
        fill(dangerousForBlack[i], dangerousForBlack[i] + 8, false);
        fill(dangerousForWhite[i], dangerousForWhite[i] + 8, false);
    }
    playerColor color = White;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 8; i++) {
            getPlayer(color) -> getPawns()[i] -> canGo(getPlayer(color) -> getColor(), colorTable);
        }
        for (int i = 0; i < 1; i++) {
            getPlayer(color) -> getKing()[i] -> canGo(getPlayer(color) -> getColor(), colorTable);
        }
        for (int i = 0; i < 1; i++) {
            getPlayer(color) -> getQueen()[i] -> canGo(getPlayer(color) -> getColor(), colorTable);
        }
        for (int i = 0; i < 2; i++) {
            getPlayer(color) -> getKnights()[i] -> canGo(getPlayer(color) -> getColor(), colorTable);
        }
        for (int i = 0; i < 2; i++) {
            getPlayer(color) -> getBishops()[i] -> canGo(getPlayer(color) -> getColor(), colorTable);
        }
        for (int i = 0; i < 2; i++) {
            getPlayer(color) -> getRooks()[i] -> canGo(getPlayer(color) -> getColor(), colorTable);
        }
        color = Black;
    }
    printBoard();
    cout << endl;
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

int board::getIndexTable(cell position) {
    return indexTable[position.getY()][position.getX()];
}

playerColor board::getColorTable(cell position) {
    return colorTable[position.getY()][position.getX()];
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
    pieceMap[None] = "none";
}

bool board::movePiece(cell starting, cell ending) {
    int x = starting.getX(), y = starting.getY(), x2 = ending.getX(), y2 = ending.getY();
    bool isValidMove = false;
    vector <cell> validMoves;
    playerColor color = colorTable[y][x];
    int index = indexTable[y][x];
    if (table[y][x] == Pawn) {
        validMoves = getPlayer(color) -> getPawns()[index] -> canGo(getPlayer(color) -> getColor(), colorTable);
    }
    if (table[y][x] == King) {
        validMoves = getPlayer(color) -> getKing()[index] -> canGo(getPlayer(color) -> getColor(), colorTable);
    }
    if (table[y][x] == Rook) {
        validMoves = getPlayer(color) -> getRooks()[index] -> canGo(getPlayer(color) -> getColor(), colorTable);
    }
    if (table[y][x] == Bishop) {
        validMoves = getPlayer(color) -> getBishops()[index] -> canGo(getPlayer(color) -> getColor(), colorTable);
    }
    if (table[y][x] == Knight) {
        validMoves = getPlayer(color) -> getKnights()[index] -> canGo(getPlayer(color) -> getColor(), colorTable);
    }
    if (table[y][x] == Queen) {
        validMoves = getPlayer(color) -> getQueen()[index] -> canGo(getPlayer(color) -> getColor(), colorTable);
    }
    for (int i = 0; i < validMoves.size(); i++) {
        cell cur = validMoves[i];
        if (cur.getX() == x2 && cur.getY() == y2) {
            isValidMove = true;
        }
    }
    if (!isValidMove || table[y2][x2] == King) {
        return false;
    }
    swap(table[y][x], table[y2][x2]);
    swap(colorTable[y][x], colorTable[y2][x2]);
    swap(indexTable[y][x], indexTable[y2][x2]);
    if (table[y][x] != None) {
        table[y][x] = None;
        colorTable[y][x] = none;
    }
    if (table[y2][x2] == Pawn) {
        cell toSet(x2, y2);
        getPlayer(colorTable[y2][x2]) -> getPawns()[indexTable[y2][x2]] -> setPos(toSet);
        //cout << getPlayer(colorTable[y2][x2]) -> getPawns()[indexTable[y2][x2]] -> getPos().getY() << endl;
    }
    if (table[y2][x2] == King) {
        cell toSet(x2, y2);
        getPlayer(colorTable[y2][x2]) -> getKing()[indexTable[y2][x2]] -> setPos(toSet);
        //cout << getPlayer(colorTable[y2][x2]) -> getKing()[indexTable[y2][x2]] -> getPos().getY() << endl;
    }
    if (table[y2][x2] == Rook) {
        cell toSet(x2, y2);
        getPlayer(colorTable[y2][x2]) -> getRooks()[indexTable[y2][x2]] -> setPos(toSet);
        //cout << getPlayer(colorTable[y2][x2]) -> getRooks()[indexTable[y2][x2]] -> getPos().getY() << endl;
    }
    if (table[y2][x2] == Bishop) {
        cell toSet(x2, y2);
        getPlayer(colorTable[y2][x2]) -> getBishops()[indexTable[y2][x2]] -> setPos(toSet);
        //cout << getPlayer(colorTable[y2][x2]) -> getBishops()[indexTable[y2][x2]] -> getPos().getY() << endl;
    }
    if (table[y2][x2] == Knight) {
        cell toSet(x2, y2);
        getPlayer(colorTable[y2][x2]) -> getKnights()[indexTable[y2][x2]] -> setPos(toSet);
        //cout << getPlayer(colorTable[y2][x2]) -> getKnights()[indexTable[y2][x2]] -> getPos().getY() << endl;
    }
    if (table[y2][x2] == Queen) {
        cell toSet(x2, y2);
        getPlayer(colorTable[y2][x2]) -> getQueen()[indexTable[y2][x2]] -> setPos(toSet);
        //cout << getPlayer(colorTable[y2][x2]) -> getQueen()[indexTable[y2][x2]] -> getPos().getY() << endl;
    }
    return true;
}

void board::printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cell cur(j, i);
            //cout << getTable(cur);
            cout << dangerousForWhite[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

player* board::getPlayer(playerColor color) {
    if (color == White) {
        //cout << "sefiiiiid\n";
        return &white;
    }
    //cout << "siaaaaah\n";
    //cout << white.getColor() << '\n';
    //cout << black.getColor() << '\n';
    return &black;
}

void board::nextTurn() {
    turn = rivalMap[turn];
    if (turn == White) {
        background = SDL_LoadBMP("pictures\\backgrounds\\turnWhite.bmp");
    } else {
        background = SDL_LoadBMP("pictures\\backgrounds\\turnBlack.bmp");
    }
}

bool board::isChecked(king* defenderKing, playerColor color) {
    if (color == White) {
        return dangerousForWhite[defenderKing -> getPos().getY()][defenderKing -> getPos().getX()];
    }
    if (color == Black) {
        return dangerousForBlack[defenderKing -> getPos().getY()][defenderKing -> getPos().getX()];
    }
    //return defenderKing -> canGo(getColorTable(defenderKing -> getPos()), colorTable).size() == 0;
}

bool board::isCheckmated(king* defenderKing, playerColor color) {
    if (!isChecked(defenderKing, color)) {
        return false;
    }
    for (int i = 0; i < defenderKing -> canGo(getColorTable(defenderKing -> getPos()), colorTable).size(); i++) {
        cell curMove = defenderKing -> canGo(getColorTable(defenderKing -> getPos()), colorTable)[i];
        if (color == White && !dangerousForWhite[curMove.getY()][curMove.getX()]) {
            return false;
        }
        if (color == Black && !dangerousForBlack[curMove.getY()][curMove.getX()]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* args[]) {
    board game; //object of running gameTable
    //game.printBoard();
    //cout << endl;
    SDL_Event event;
    int x , y;
    bool firstClick = true;
    int firstClickX = -1, firstClickY = -1;
    while (game.isRunning()) { //mainLoop
        bool checkWhite = false, checkBlack = false, checkmateWhite = false, checkmateBlack = false;
        while (game.getTurn() == White && game.isRunning()) {
           while(SDL_PollEvent(&event) && game.getTurn() == White && game.isRunning()) {
                if (game.isChecked(game.getPlayer(White) -> getKing()[0], White)) {
                    cout << "CheckkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkWhiteeeeeeeeee\n";
                    checkWhite = true;
                }
                if (game.isCheckmated(game.getPlayer(White) -> getKing()[0], White)) {
                    cout << "CheckkkkkkkkkkkmatttttttttttttttteWhiteeeeeeeeee\n";
                    checkmateWhite = true;
                }
                switch(event.type) {
                    case SDL_QUIT:
                        game.endGame();
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        cell current(event.motion.x / 50, event.motion.y / 50);
                        if (firstClick && game.getTurn() == game.getColorTable(current)) {
                            firstClickX = event.motion.x / 50;
                            firstClickY = event.motion.y / 50;
                            firstClick = false;
                        } else if (!firstClick && game.getTurn() != game.getColorTable(current)) {
                            //should be no check or checkmate created against current player
                            firstClick = true;
                            cell starting(firstClickX, firstClickY), ending(event.motion.x / 50, event.motion.y / 50);
                            if (game.movePiece(starting, ending)) {
                                    //cout << "biaaaaaaaaaaaaaaaaaaa" << game.getTurn() << endl;
                                game.nextTurn();
                                //cout << "biaaaaaaaaaaaaaaaaaaa" << game.getTurn() << endl;
                            }
                            //game.printBoard();
                            //cout << endl;
                        }
                        //cout << "biaaaaaaaaaaaaaaaaaaa" << game.getTurn() << endl;
                }
                game.updateBoard(firstClick, firstClickX, firstClickY, checkWhite, checkBlack, checkmateWhite, checkmateBlack);
                SDL_Delay(100);
            }
        }
        //cout << "siaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaah\n";
         while (game.getTurn() == Black && game.isRunning()) {
           while(SDL_PollEvent(&event) && game.getTurn() == Black && game.isRunning()) {
                if (game.isChecked(game.getPlayer(Black) -> getKing()[0], Black)) {
                    cout << "CheckkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkBlackkkkkkkkkk\n";
                    checkBlack = true;
                }
                if (game.isCheckmated(game.getPlayer(Black) -> getKing()[0], Black)) {
                    cout << "CheckkkkkkkkkkkmatttttttttttttttteBlackkkkkkkkkkk\n";
                    checkmateBlack = true;
                }
                switch(event.type) {
                    case SDL_QUIT:
                        game.endGame();
                        break;
                    case SDL_MOUSEBUTTONDOWN:

                        cell current(event.motion.x / 50, event.motion.y / 50);
                        if (firstClick && game.getTurn() == game.getColorTable(current)) {
                            firstClickX = event.motion.x / 50;
                            firstClickY = event.motion.y / 50;
                            firstClick = false;
                        } else if (!firstClick && game.getTurn() != game.getColorTable(current)) {
                            /*should be checked if piece is able to do such a move
                            and then no check or checkmate created against current player*/
                            firstClick = true;
                            cell starting(firstClickX, firstClickY), ending(event.motion.x / 50, event.motion.y / 50);
                            if (game.movePiece(starting, ending)) {
                                game.nextTurn();
                            }
                            //game.printBoard();
                            //cout << endl;
                        }
                        //cout << "biaa" << game.getTurn() << ' ' << game.getColorTable(current) << endl;
                }
                game.updateBoard(firstClick, firstClickX, firstClickY, checkWhite, checkBlack, checkmateWhite, checkmateBlack);
                SDL_Delay(100);
            }
        }
    }
    SDL_Delay(1000);
    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
    window = NULL;
    screenSurface = NULL;
    SDL_Quit();
}
