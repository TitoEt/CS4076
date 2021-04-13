#include <iostream>

using namespace std;
#include "zorkul.h"
#include "clues.h"
#include "room.h"

ZorkUL::ZorkUL() {
    createRooms();
    createClues();
}

void ZorkUL::createRooms()  {

    Room *one, *two, *three, *four, *five, *six;

        one = new Room("Outside; You stand outside the crimescene. Go east to enter the house.");
        two = new Room("Living Room; Inside the living room, there are two bodies. I should look for clues.");
        three = new Room("Bathroom; There's someone in here. What are they doing?");
        four = new Room("Kitchen; There's blood on the floor.");
        five = new Room("Garden; flowers again");
        six = new Room("Flower Shop; Flowers");

        roomList.push_back(one);
        roomList.push_back(two);
        roomList.push_back(three);
        roomList.push_back(four);
        roomList.push_back(five);
        roomList.push_back(six);

    clues *bloodstains, *pillbottle, *baseballbat, *fingerprint, *gelsium;

        two->addClues(bloodstains);
        three->addClues(pillbottle);
        four->addClues(baseballbat);
        four->addClues(fingerprint);
        five->addClues(gelsium);
        six->addClues(gelsium);
        six->addClues(fingerprint);


//             (N, E, S, W)
    one->setExits(six, two, NULL, NULL);
    two->setExits(three, NULL, NULL, one);
    three->setExits(five, four, two, NULL);
    four->setExits(NULL, NULL, NULL, three);
    five->setExits(NULL, NULL, three, NULL);
    six->setExits(NULL, NULL, one, NULL);
    currentRoom = one;
}

Room* ZorkUL::getRoom() {
    return currentRoom;
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
