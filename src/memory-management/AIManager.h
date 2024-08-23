#include "memory-management/NPC.h"
#include <iostream>
#include <assert.h>

using namespace std;

class AIManager
{
private:
    NPC **npcs;
    int count;
    int size;

public:
    AIManager(int size) : size(size) {
        // exercise 2: constructor is passed a size > 0
        assert(size > 0);
        npcs = new NPC *[size];
        count = 0;
    }
    // destructor
    // delete each pointer in the array of npcs first
    // delete the array after
    ~AIManager(){
        cout << "AI Manager destructor invoked" << endl;
        for(int i = 0; i < size; i++) {
            delete npcs[i];
        }
        delete[] npcs;
    }
    int Add(int id) {
        // exercise 2: ID can't be 0
        assert(id != 0);
        // exercise 2: count can't be less than size
        assert(count < size);
        NPC *temp = new NPC(id);
        for (int n = 0; n < count; n++)
            if (npcs[n]->id == id)
                return 0;
        npcs[count++] = temp;
        return id;
    }
    void Display() {
        for (int n = 0; n < count; n++)
            cout << "NPC ID: " << npcs[n]->id << endl;
    }
};