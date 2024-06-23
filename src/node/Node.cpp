#include <iostream>
#include "Node.h"
#include "station/Station.h"


using namespace std;

Node::Node(Station* station) {
    this->station = station;
    this->g = 0;
    parent = 0;
    numberOfConnections = 0;
    
}

bool Node::operator!=(const Node& rhd) {
    return (this->g != rhd.g);
}

bool Node::operator==(const Node& rhd) {
    return (this->g == rhd.g);
}

bool Node::operator<(const Node& rhd) {
    return (this->g < rhd.g);
}

bool Node::operator>(const Node& rhd) {
    return (this->g > rhd.g);
}