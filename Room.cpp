#include "Room.h"
#include "command.h"


Room::Room(string shortDescription, string longDescription) {
    this->shoDescription = shortDescription;
    this->loDescription = longDescription;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

string Room::shortDescription() {
    return shoDescription;
}

string Room::longDescription() {
    return "room = " + shoDescription + ".\n" + loDescription + ".\n" + displayClue() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		// Loop through map
		returnString += "  " + i->first;	// access the "first" element of the pair (direction as a string)
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
	if (next == exits.end())
		return NULL; // if exits.end() was returned, there's no room in that direction.
	return next->second; // If there is a room, remove the "second" (Room*)
				// part of the "pair" (<string, Room*>) and return it.
}

void Room::addClues(clues *inClue) {
    //cout <<endl;
    //cout << "Just added" + inClue->getLongDescription();
    cluesInRoom.push_back(*inClue);
}

string Room::displayClue() {
    string tempString = "clues in room = ";
    int sizeClues = (cluesInRoom.size());
    if (cluesInRoom.size() < 1) {
        tempString = "no clues in room";
        }
    else if (cluesInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeClues; n > 0; n--) {
            tempString = tempString + cluesInRoom[x].getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

int Room::numberOfClues() {
    return cluesInRoom.size();
}

int Room::isClueInRoom(string inString)
{
    int sizeClues = (cluesInRoom.size());
    if (cluesInRoom.size() < 1) {
        return false;
        }
    else if (cluesInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeClues; n > 0; n--) {
            // compare inString with short description
            int tempFlag = inString.compare( cluesInRoom[x].getShortDescription());
            if (tempFlag == 0) {
                cluesInRoom.erase(cluesInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}
