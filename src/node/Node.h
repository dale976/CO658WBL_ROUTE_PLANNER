#pragma once

#include "station/Station.h"

class Node {
    public: 
        float g;
        int connections;
        Station* station;
        Node* next;
        Node* parent;

        Node(Station* station);
        bool operator!=(const Node& rhd);
        bool operator==(const Node& rhd);
        bool operator>(const Node& rhd);
        bool operator<(const Node& rhd);
};