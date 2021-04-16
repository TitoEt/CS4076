#ifndef ZORKUL_H_
#define ZORKUL_H_

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
    vector <Room*> roomList;

public:
    ZorkUL();
    string play();
    string go(string direction);
    Room* getRoom();
};

#endif /*ZORKUL_H_*/
