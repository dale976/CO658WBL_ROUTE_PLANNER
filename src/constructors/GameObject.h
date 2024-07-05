#pragma once

class GameObject {
public:
    // static property
    static int instanceCount;

    int id;
    // GameObject(): id(0) {}; //EX 1: default constructor initialising id with a value of 0
    GameObject(int id): id(id) {
        instanceCount++; // increment instanceCount each time a new instance is created
    }; //EX 2: Create a non default constructor that takes the id as an argument and assigns it to the corresponding data member.
};
