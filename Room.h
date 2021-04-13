#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "clues.h"
using namespace std;

class Room{

private:
    string description;
    map<string, Room*> exits;
    string exitString();
    vector <clues> cluesInRoom;


public:
    int numberOfClues();
    Room(string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    string longDescription();
    Room* nextRoom(string direction);
    void addClues(clues *inclues);
    string displayClue();
    int isClueInRoom(string inString);
    bool allCluesCollected();
    void removeClueFromRoom(int location);
};

#endif

