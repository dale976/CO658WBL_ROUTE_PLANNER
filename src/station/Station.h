#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Station {
public:
    int key;
    string name;
    Station* next;
    vector<string> lines;
    bool visited;

    Station(int key, string name, vector<string> lines);
    ~Station();
    void Display();
    bool operator!=(const Station& rhd);
    bool operator==(const Station& rhd);
    bool operator<(const Station& rhd);
    bool operator>(const Station& rhd);
};