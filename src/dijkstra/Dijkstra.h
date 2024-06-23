#pragma once

#include "tube-map/TubeMap.h"
#include "node/Node.h"
#include "station/Station.h"
#include "stack/Stack.h"
#include "linked-list/LinkedList.h"


class Dijkstra {
    private:
        TubeMap* tubeMap;
        LinkedList<Node>* open;
        Stack<Node>* path;
        Node* FindLowestNode(LinkedList<Node>* lst);
        Stack<Node>* ReconstructPath(Node* goal);
    public:
        Dijkstra(TubeMap* tubeMap);
        Stack<Node>* GetPath(int start, int goal);
};