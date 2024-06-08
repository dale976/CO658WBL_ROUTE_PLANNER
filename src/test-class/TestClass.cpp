#include <iostream>
#include "TestClass.h"

TestClass::TestClass(string name) {
    this->name = name;
    cout << this->name << endl;
}