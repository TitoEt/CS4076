#include <iostream>

using namespace std;
#include "zorkul.h"
#include "clues.h"

ZorkUL::ZorkUL() {
    createRooms();
    createClues();
}

void ZorkUL::createRooms()  {

    Room *one, *two, *three,*four,*five,*six;
        one = new Room("Outside","You stand outside the crimescene. Go west to enter the house.");
        two = new Room("Living Room","Inside the living room, there are two bodies. Start investigating.");
        three = new Room("Bathroom","Another chamber quite similar to the previous. There seems to only be exits to the east and the west. \nYou feel a chill and the sudden urge to leave.");
        four = new Room("Kitchen","A very cold chamber. You see water trickling down one of the walls. You're certain that this place is underground. \nThere are exits to the north and the east.");
        five = new Room("Garden","flowers again");
        six = new Room("Flower Shop", "Flowers");
        roomList.push_back(one);
        roomList.push_back(two);
        roomList.push_back(three);
        roomList.push_back(four);
        roomList.push_back(five);
        roomList.push_back(six);


//             (N, E, S, W)
    one->setExits(NULL, two, NULL, NULL);
    two->setExits(three, one, NULL, NULL);
    three->setExits(four, NULL, two, NULL);
    four->setExits(five, NULL, three, NULL);
    five->setExits(NULL, NULL, four, NULL);
    currentRoom = one;
}

Room* ZorkUL::getRoom() {
    return currentRoom;
}

void ZorkUL::createClues(){
    clues *pillbottle = new clue("Pill Bottle", true);
    clues *bloodstain = new Clue("Blood Stains", true);
    clues *gelsiumflower = new Clue("Gelsium", true);
    clues *fingerprint = new Clue("Culprit finger print", true);
    clues *bat = new clues("Baseball bat", true);
    clues *autopsy = new Clue("Autopsy Results", true);
}

string ZorkUL::play() {
    return currentRoom->longDescription();
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}
