 #ifndef CRIMESCENE_H
#define CRIMESCENE_H

#include "rooms.h"
#include "clues.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class crimescene
{
private:
    Room *currentRoom;
    vector<Room> rooms;
    void createRooms();
    void createClues();
    void displayClues();

public:
    crimescene();
    void play();
    string printWelcome();
    string printHelp();
    string printEnd();
    string map();
    string viewClues();
    Room getCurrentRoom();
};

#endif // CRIMESCENE_H
