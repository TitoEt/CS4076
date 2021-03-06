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
    string name;
    map<string, Room*> exits;
    string exitString();
    vector <clues*> cluesInRoom;


public:
    int numberOfClues();
    Room(string name, string description);
    void setExits(Room *north, Room *east, Room *south, Room *west);
    string getDescription();
    string getName();
    Room* nextRoom(string direction);
    void addClues(clues *inclues);
    string displayClue();
    string allCluesCollected();
    void removeClues();
    vector<clues*> getClues();
    bool isClueInRoom();

};

#endif
