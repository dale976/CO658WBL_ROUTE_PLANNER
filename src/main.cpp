#include <iostream>

#include "test-class/TestClass.h"
#include "another-class/AnotherClass.h"

using namespace std;

int main() {
    cout << "hello, world!" << endl;

    TestClass* tc = new TestClass("FOOBAR 123");
    AnotherClass* ac = new AnotherClass();
    return 0;
}