#pragma once

#include <iostream>

using namespace std;

class Station {
public:
    int key;
    string name;
    Station* next;
    bool visited;

    Station(int key, string name);
    ~Station();
    void Display();
    bool operator!=(const Station& rhd);
    bool operator==(const Station& rhd);
    bool operator<(const Station& rhd);
    bool operator>(const Station& rhd);
};