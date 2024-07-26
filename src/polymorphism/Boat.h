#pragma once

#include "polymorphism/Vehicle.h"

class Boat : public Vehicle {
public:
    Boat(int id, int damage) : Vehicle(id, damage) {}

    void Display() override {
        cout << "Boat Class"
             << " ID: " << id
             << " Damage: " << damage
             << endl;
    }
};
