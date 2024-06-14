#include <iostream>
#include <string>
#include <vector>

#include "Station.h"

using namespace std;

Station::Station(int key, string name, vector<string> lines) {
    this->key = key;
    this->name = name;
    this->lines = lines;
}

void Station::Display() {
    cout << this->name << endl;
}

void Station::DisplayLines() {
    for (string value : lines) {
        cout << "Lines L " << value << "\t";
    }

    cout << endl;
}

bool Station::operator!=(const Station& rhd) {
    if(this->key != rhd.key) {
        return true;
    } else {
        return false;
    }
}

bool Station::operator==(const Station& rhd) {
    if(this->key == rhd.key) {
        return true;
    } else {
        return false;
    }
}

bool Station::operator<(const Station& rhd) {
    if(this->key < rhd.key) {
        return true;
    } else {
        return false;
    }
}

bool Station::operator>(const Station& rhd) {
    if(this->key > rhd.key) {
        return true;
    } else {
        return false;
    }
}