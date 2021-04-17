#include "Room.h"

Room::Room(string name, string description) {
    this->name = name;
    this->description = description;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
    if (north != NULL)
        exits["North"] = north;
    if (east != NULL)
        exits["East"] = east;
    if (south != NULL)
        exits["South"] = south;
    if (west != NULL)
        exits["West"] = west;
}

string Room::getName() {
    return name;
}

string Room::getDescription() {
    return description;
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
    cout << "Just added" + inClue->getLongDescription() <<endl;
    cluesInRoom.push_back(*inClue);
}

string Room::displayClue() {
    string tempString = "Clues in room = ";
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

bool Room::allCluesCollected(){
    if(cluesInRoom.empty()){
        return true;
    }
    else
    {
        return false;
    }
}
