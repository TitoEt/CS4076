#include "rooms.h"
#include "command.h"
#include <algorithm>

rooms::rooms(string description)
{
    this->description = description;
}

void rooms::setExits(rooms *north, rooms *east, rooms *south, rooms *west)
{
    if (north != nullptr)
    {
        exits["north"] = north;
    }

    if (east != nullptr)
    {
        exits["east"] = east;
    }

    if (south != nullptr)
    {
        exits["south"] = south;
    }

    if (west != nullptr)
    {
        exits["west"] = west;
    }
}

string rooms::shortDescription()
{
    return description;
}

string rooms::longDescription()
{
    return "rooms = " + description + "." + exitString();
}

string rooms::exitString()
{
    string returnString = "\nexits = ";
    for (map<string, rooms*>::iterator i = exits.begin(); i != exits.end(); i++)
        // Loop through map
        returnString += "  " + i->first;
    return returnString;
}

rooms* rooms::nextrooms(string direction)
{
    map<string, rooms*>::iterator next = exits.find(direction);

    if (next == exits.end())
    {
        return nullptr;
    }

    return next->second;
}

void rooms::addclues(clues *inclues)
{
    cluessInrooms.push_back(*inclues);
}

string rooms::displaycluess()
{
    string tempString = "cluess in rooms: ";
    int cluesAmount = cluessInrooms.size();

    if (cluesAmount < 1)
    {
        tempString = "No cluess in rooms.";
    }
    else if (cluesAmount > 0)
    {
        int x = 0;

        for (int n = cluesAmount; n > 0; n--)
        {
            tempString += cluessInrooms[x].getShortDescription() + " ";
            x++;
        }
    }

    return tempString;
}

int rooms::numberOfcluess()
{
    return cluessInrooms.size();
}

void rooms::removeclues(clues clues)
{
    int pos = 0;

    for (unsigned int i = 0; i < (unsigned int)cluessInrooms.size(); i++)
    {
        if (cluessInrooms[i] == clues)
        {
            pos = (int)i;
            break;
        }
    }

    cluessInrooms.erase(cluessInrooms.begin() + pos);
}

clues rooms::findclues(clues clues)
{
    for (unsigned int i = 0; i < cluessInrooms.size(); i++)
    {
        if (cluessInrooms[i] == clues)
        {
            return cluessInrooms[i];
        }
    }
}

vector<clues> rooms::viewCluess()
{
    return cluessInrooms;
}

bool rooms::allcluessCollected()
{
    if (cluessInrooms.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool rooms::containsExit(string exit)
{
    return exits.find(exit) != exits.end();
}

