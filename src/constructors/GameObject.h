#pragma once

#include "Location.h"

class GameObject {
public:
    // static property
    static int instanceCount;
    
    int id;
    Location* location;
    // GameObject(): id(0) {}; //EX 1: default constructor initialising id with a value of 0
    GameObject(int id): id(id) {
        instanceCount++; // increment instanceCount each time a new instance is created
    }; //EX 2: Create a non default constructor that takes the id as an argument and assigns it to the corresponding data member.
    ~GameObject(){
        delete location;
    };
    GameObject(int id, Location* location): id(id), location(location){};
    // Copy Constructor
    // The object to be copied is passed as a constant to ensure that the members can’t be changed.
    GameObject(const GameObject& g) {
        instanceCount++;
        this->id = g.id;
        this->location = new Location(g.location->x, g.location->y, g.location->z);
    }
};
