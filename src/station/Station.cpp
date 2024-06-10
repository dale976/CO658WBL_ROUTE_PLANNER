#include <iostream>
#include <string>

#include "Station.h"

using namespace std;

Station::Station(int key, string name) {
    this->key = key;
    this->name = name;
}

void Station::Display() {
    cout << this->name << endl;
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
    if(this->key == rhd.key) {
        return true;
    } else {
        return false;
    }
}

bool Station::operator>(const Station& rhd) {
    if(this->key == rhd.key) {
        return true;
    } else {
        return false;
    }
}