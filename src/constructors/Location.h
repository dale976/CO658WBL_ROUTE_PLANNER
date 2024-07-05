#pragma once

class Location {
public:
    int x;
    int y;
    int z;
    
    Location() {};
    Location(int x, int y, int z): x(x), y(y), z(z) {};
    void Display();
    void Set(int x, int y, int z);

};