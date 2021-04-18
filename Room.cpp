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
    cluesInRoom.push_back(inClue);
}

void Room::removeClues() {
    cluesInRoom.clear();
}

int Room::numberOfClues() {
    return cluesInRoom.size();
}

bool Room::isClueInRoom() {
    return numberOfClues() > 0;
}

vector<clues*> Room::getClues()
{
    return cluesInRoom;
}

string Room::allCluesCollected(){
    if(cluesInRoom.empty()){
        return "There are no clues left in this room";
    }
    else
    {
        return "Keep searching!";
    }
}
