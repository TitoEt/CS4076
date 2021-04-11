#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "clues.h"
using namespace std;
using std::vector;//sequence container -- think pass the parcel but with pointers to an array element

class Room {

private:
    string shoDescription;
    string loDescription;
	map<string, Room*> exits;
	string exitString();
    vector <clues> cluesInRoom;


public:
    int numberOfItems();
    Room(string shortDescription, string longDescription);
	void setExits(Room *north, Room *east, Room *south, Room *west);
	string shortDescription();
	string longDescription();
	Room* nextRoom(string direction);
    void addClues(clues *inClue);
    string displayClue();
    int isClueInRoom(string inString);
    void removeClueFromRoom(int location);
    int numberOfClues();
};

#endif
