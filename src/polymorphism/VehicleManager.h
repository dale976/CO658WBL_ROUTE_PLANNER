#pragma once
#include "Vehicle.h"
#include <iostream>

using namespace std;

class VehicleManager
{
private:
    int maxVehicles;
    int count;
    Vehicle **vehicles;

public:
    VehicleManager(int size) : maxVehicles(size)
    {
        count = 0;
        vehicles = new Vehicle *[maxVehicles];
    }
    ~VehicleManager(void){};
    bool Add(Vehicle *v)
    {
        if (count < maxVehicles)
        {
            vehicles[count] = v;
            count++;
            return true;
        }
        else
        {
            return false;
        }
    };
    void Display()
    {
        for (int n = 0; n < count; n++)
            vehicles[n]->Display();
    };
    int GetCount(){
        return count;
    };
    Vehicle **GetList()
    {
        return vehicles;
    };
    // Exercise 8
    void DamagedVehicles()
    {
        cout << "Damaged Vehicles " << endl;
        for (int n = 0; n < count; n++)
        {
            if (vehicles[n]->damage >= 35)
            {
                vehicles[n]->Display();
            }
        }
    };
};
