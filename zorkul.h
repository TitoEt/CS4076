#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "command.h"
#include "Parser.h"
#include "Room.h"
#include "clues.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
private:
    Parser parser;
    Room *currentRoom;
    void createRooms();
    void createClues();
    void printWelcome();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void displayClues();

public:
    ZorkUL();
    void play();
    string go(string direction);
};

#endif /*ZORKUL_H_*/
