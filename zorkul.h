#ifndef ZORKUL_H_
#define ZORKUL_H_
#define YELLOW 12

#include "character.h"
#include "Room.h"
#include "clues.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Room* currentRoom;
    void createRooms();
    void createClues();
    void displayClues();
    Room* roomList[6];

public:
    ZorkUL();
    string play();
    bool go(string direction);
    Room* getRoom();
    string printWelcome();
};

#endif /*ZORKUL_H_*/
