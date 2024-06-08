#include <iostream>

#include "test-class/TestClass.h"
#include "another-class/AnotherClass.h"
#include "station/Station.h"

using namespace std;

int main() {
    cout << "hello, world!" << endl;

    // TestClass* tc = new TestClass("FOOBAR 123");
    // AnotherClass* ac = new AnotherClass();
    Station* st = new Station(0, "Picadillyjh");
    st->Display();
    return 0;
}