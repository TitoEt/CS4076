#include <iostream>
#include <cstdlib>

using namespace std;
#include "crimescene.h"

crimescene::crimescene()
{
    createRooms();

}

void crimescene::createRooms(){
    Room *toilet *flowershop * kitchen *livingroom *garden *f *g;

    toilet = new Room("toilet");
            toilet->addclues(new clues("x", 1, 11));

    flowershop = new Room("flowershop");
            flowershop->addclues(new clues("xx", 3, 33));

    kitchen = new Room("kitchen");

    livingroom = new Room("livingroom");

    garden = new Room("garden");

     currentRoom = livingroom;
}

string crimescene::printWelcome() {
    return "start \ninfo for help\n" + currentRoom->longDescription();
}
string crimescene::printEnd() {
    return "end";
}

string crimescene::map() {
    string output;
    output += "\n          [h] --- [livingroom] --- [g]";
    output += "\n                      |         ";
    output += "\n                      |         ";
    output += "\n[j] --- [kitchen] --- [toilet] --- [flowershop]";
    output += "\n                      |         ";
    output += "\n                      |         ";
    output += "\n            [i] --- [garden] --- [e]";
    return output;
}

string crimescene::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL) {
        return "You can't go that way.";
    } else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

string crimescenes::viewClues() {
    return currentRoom->displayClues();
}

Room crimescenes::getCurrentRoom() {
    return *currentRoom;
}
