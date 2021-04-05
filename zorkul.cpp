#include <iostream>

using namespace std;
#include "ZorkUL.h";

ZorkUL::ZorkUL() {
    createRooms();
    createClues();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e;

    a = new Room("Living room", ":/maps/livingroom.png",true, false);
        a->addClue(new Clue("x", 1, 11));
        a->addClue(new Clue("y", 2, 22));
    b = new Room("b");
        b->addClue(new Clue("xx", 3, 33));
        b->addClue(new Clue("yy", 4, 44));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");

//             (N, E, S, W)
    a->setExits(e, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, c);
    e->setExits(NULL, NULL, NULL, d);
    currentRoom = a;
}

void ZorkUL::createClues(){
    Clues *v, *w, *x, *y, *z;
}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();

    else if (commandWord.compare("map") == 0)
        {
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        }

    else if (commandWord.compare("go") == 0)
        goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isClueInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "Clue is not in room" << endl;
        else
            cout << "Clue is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            CluesInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
    }
    return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
    }
}

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

/*

this could maybe be away of assigning certain parts of the script and clues to certain rooms? idk 
forced navigation ig, ill come back to this

Room *one, *two, *three,*four,*five,*six,*seven,*eight,*nine,*ten,*eleven,*twelve,*thirteen,*fourteen,*fifteen,*sixteen;
    one = new Room("one","You wake up, vision hazy and head dizzy. You find yourself in a dark, grim room. You hear scampering in the distance.\nThere seems to be only one exit, to the north.");
    two = new Room("two","You enter a very poorly lit sqaure chamber. All of the walls are grey stone and it is eerily cold. \nThere are hallways to the north, south, east and west.");
    three = new Room("three","Another chamber quite similar to the previous. There seems to only be exits to the east and the west. \nYou feel a chill and the sudden urge to leave.");
    four = new Room("four","A very cold chamber. You see water trickling down one of the walls. You're certain that this place is underground. \nThere are exits to the north and the east.");
    five = new Room("five","All of the chambers are merging into one. An almost identical room. You wonder how long it'll take for you to go insane. \nThere are hallways to the south and the west.");
    six = new Room("six","You swear you've been in this room before. Although, you could say that about all the rooms. \nThere are exits to the south and the east.");
    seven = new Room("seven","Yet another chamber. Your spirits are starting to waver. Suddenly, the walls tremble! Time to go. \nThere are hallways to the south and the west.");
    eight = new Room("eight","Your stomach rumbles. If you aren't killed by the monsters in here, you know you'll die eventually. \nThere are exits to the north and the south.");
    nine = new Room("nine","Guess what? Another. Chamber. This is a very poorly designed dungeon. No passion. Disappointing. \nThere are hallways to the north and the west.");
    ten = new Room("ten","You hear clacking and deep breathing. Rather unnerving. You swear you can hear chirping also. \nThere are exits to the north, east and west.");
    eleven = new Room("eleven","This chamber is different to the others. There are no obvious exits but there are two small spaces\nyou could possibly fit through.");
    twelve = new Room("twelve","The sound of chirping increases but you still hear that deep breathing. \nThere are exits to the south and the east.");
    thirteen = new Room("thirteen","Down another hallway, twisting almost further down. The breathing is very distinct now. \n There are hallways to the north and the west.");
    fourteen = new Room("fourteen","You turn the corner, into what must be one of the final chambers and are faced with an ugly troll. \nYour final test. Defeat it and south to your freedom!");
    fifteen = new Room("fifteen");
    sixteen = new Room("sixteen","Congratulations! You have found the hidden easter egg! Your reward? Being trapped for eternity! \nIf only I could restart this.... (Hit Exit and start over)");


    roomList.push_back(one);
    roomList.push_back(two);
    roomList.push_back(three);
    roomList.push_back(four);
    roomList.push_back(five);
    roomList.push_back(six);
    roomList.push_back(seven);
    roomList.push_back(eight);
    roomList.push_back(nine);
    roomList.push_back(ten);
    roomList.push_back(eleven);
    roomList.push_back(twelve);
    roomList.push_back(thirteen);
    roomList.push_back(fourteen);
    roomList.push_back(fifteen);
    roomList.push_back(sixteen);
    fifteen -> setLast();

    two->addItem(knife);
    three->addEnemy(new Enemy("Ghoul","If death had a baby, it would look like this creature. Small, ugly and ravenous.",10,2,.40));
    four->addEnemy(new Enemy("Goblin","Green abomination. Little to no threat.",5,2,.60));
    six->addItem(sword);
    eleven->addEnemy(new Enemy("Skeleton","What you would look like after rotting away for hundreds of years. Dangerous if not dealt with quickly.",5,3,.10));
    eleven->addItem(axe);
    //twelve->addItem(healthElixir);
    fourteen->addEnemy(new Enemy("Troll","Big. Angry. Big. Avoid unless absolutely necessary.",25,4,.50));

 

