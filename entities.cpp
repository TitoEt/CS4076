#include "entities.h"

//<Rach> Inheritance here! Character is deriving from this class, it's using the methods from this.
entities::entities(string name, string description)
{
    this->name = name;
    this->description = description;
}

string entities::getName() {
    return name;
}

string entities::getDescription() {
    return description;
}

