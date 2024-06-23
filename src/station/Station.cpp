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

// Destructor implementation
Station::~Station() {
    // Normally, you don't need to explicitly define a destructor if there's nothing to clean up.
    // The compiler will generate a default destructor that does nothing for you in this case.
    // If you had dynamically allocated resources like memory or file handles, you would release them here.

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