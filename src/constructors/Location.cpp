#include <iostream>

#include "constructors/Location.h"

using namespace std;

void Location::Display() {
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
}

void Location::Set(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
}