#pragma once

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(int id, int damage) : Vehicle(id, damage) {}

    void Display() override {
        cout << "Car Class"
             << " ID: " << id
             << " Damage: " << damage
             << endl;
    }
};
