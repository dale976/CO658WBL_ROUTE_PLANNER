#pragma once

#include "tube-map/TubeMap.h"
#include "node/Node.h"
#include "station/Station.h"
#include "stack/Stack.h"
#include "linked-list/LinkedList.h"
#include "priority-queue/PriorityQueue.h"



class Dijkstra {
    private:
        TubeMap* tubeMap;
        // LinkedList<Node>* open;
        std::unique_ptr<PriorityQueue<Node>> openQ;
        // PriorityQueue<Node>* openQ;
        Stack<Node>* path;
        // Node* FindLowestNode(LinkedList<Node>* lst);
        Stack<Node>* ReconstructPath(Node* goal);
        std::unordered_map<int, std::unique_ptr<Node>> allNodes;
        unordered_map<int, float> dist;
    public:
        Dijkstra(TubeMap* tubeMap);
        Stack<Node>* GetPath(int start, int goal);
        
};