#include "zorkul.h"

ZorkUL::ZorkUL() {
    createRooms();
}

string ZorkUL::printWelcome() {
    return "Something something you're a detective, crime scene jazz.\n" + getRoom()->getName() + getRoom()->getDescription();

}

void ZorkUL::createRooms()  {

    Room *outside, *livingRoom, *kitchen, *bathroom, *garden, *flowerShop;

        outside = new Room("Outside" , "\nYou stand outside the crimescene. Go east to enter the house.\n");
        livingRoom = new Room("Living Room" , "\nInside the living room, there are two bodies. I should look for clues.\n");
        kitchen = new Room("Kitchen" , "\nThere's blood on the floor.\n");
        bathroom = new Room("Bathroom" , "\nThere's someone in here. What are they doing?\n");
        garden = new Room("Garden" , "\nflowers again\n");
        flowerShop = new Room("Flower Shop" , "\nFlowers\n");

        roomList[0] = outside;
        roomList[1] = livingRoom;
        roomList[2] = kitchen;
        roomList[3] = bathroom;
        roomList[4] = garden;
        roomList[5] = flowerShop;

    clues *bloodstains, *pillbottle, *baseballbat, *fingerprint, *gelsium;

        bloodstains = new clues("Its a bloodstain pog");
        pillbottle = new clues("A bottle of pills");
        baseballbat = new clues("It has some blood on it");
        fingerprint = new clues("!!!who could it be");
        gelsium = new clues("flower");

        livingRoom->addClues(bloodstains);
        kitchen->addClues(pillbottle);
        bathroom->addClues(baseballbat);
        bathroom->addClues(fingerprint);
        garden->addClues(gelsium);
        flowerShop->addClues(gelsium);
        flowerShop->addClues(fingerprint);


//             (N, E, S, W)
    outside->setExits(flowerShop, livingRoom, NULL, NULL);
    livingRoom->setExits(kitchen, NULL, NULL, outside);
    kitchen->setExits(garden, bathroom, livingRoom, NULL);
    bathroom->setExits(NULL, NULL, NULL, kitchen);
    garden->setExits(NULL, NULL, kitchen, NULL);
    flowerShop->setExits(NULL, NULL, outside, NULL);
    currentRoom = outside;
}

Room* ZorkUL::getRoom() {
    return currentRoom;
}

bool ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return false;
    else
    {
        currentRoom = nextRoom;
        return true;
    }
}
