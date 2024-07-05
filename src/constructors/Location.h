#pragma once

#include <iostream>

using namespace std;

class Location {
public:
    int x;
    int y;
    int z;
    
    Location() {};
    Location(int x, int y, int z): x(x), y(y), z(z) {};
    void Display() {
        cout << x << 
        y << 
        z << endl;
    };
    void Set(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };
};