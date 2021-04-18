#include "zorkul.h"

ZorkUL::ZorkUL() {
    createRooms();
}

string ZorkUL::printWelcome() {
    return "Something something you're a detective, crime scene jazz.\n" + getRoom()->getName() + getRoom()->getDescription();

}

void ZorkUL::createRooms()  {

    Room *outside, *livingRoom, *kitchen, *bathroom, *garden, *flowerShop;

        outside = new Room("Outside" , "\nYou stand outside the crimescene. The current suspects are outside, maybe you could talk to them. You can also go east to enter the house.\n");
        livingRoom = new Room("Living Room" , "\nStanding inside the crimescene, you can see one body on the floor, covered up. You should probably start searching for clues.\n");
        kitchen = new Room("Kitchen" , "\nIt seems like there was a struggle. Search for clues to get a better idea of what happened here.\n");
        bathroom = new Room("Bathroom" , "\nThere may not be much here, but it's worth a look.\n");
        garden = new Room("Garden" , "\nThere's another body in the garden. Seems like they were attempting to run away, but collapsed.\n");
        flowerShop = new Room("Flower Shop" , "\nThe flower shop has been closed for awhile. You can search around for any possible clues.\n");

        roomList[0] = outside;
        roomList[1] = livingRoom;
        roomList[2] = kitchen;
        roomList[3] = bathroom;
        roomList[4] = garden;
        roomList[5] = flowerShop;

    clues *bloodstains, *pillbottle, *baseballbat, *fingerprint, *gelsium;

        bloodstains = new clues("Bloodstain","Its a bloodstain pog");
        pillbottle = new clues("A bottle of pills","Its a bottle");
        baseballbat = new clues("Baseball Bat", "It has some blood on it");
        fingerprint = new clues("Fingerprint", "!!!who could it be");
        gelsium = new clues("Gelsium", "flower");

        /*<just throwing this here for myself to make it all make sense lmao
            outside -> People to talk to -- witness statements or something like that. motives. blah blah.
            living room -> bloodstains, pillbottle.
            kitchen -> baseball bat
            bathroom -> pillbottle (seems to have gelsium, blah blah)
            garden -> gelsium
            flower shop -> gelsium, fingerprints
          */

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
