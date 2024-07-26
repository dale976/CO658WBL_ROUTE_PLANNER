#pragma once

#include <iostream>

using namespace std;

class Vehicle {
public:
    int damage;
    int id;

    Vehicle(int id, int damage) : id(id), damage(damage) {}

    virtual void Display() {
        cout << "Vehicle Class"
             << " ID: " << id
             << " Damage: " << damage
             << endl;
    }
};
