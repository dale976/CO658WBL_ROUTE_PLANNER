#include <iostream>
#include "Node.h"
#include "station/Station.h"


using namespace std;

Node::Node(Station* station) {
    this->station = station;
    
    g = 0;
    parent = 0;
}

bool Node::operator!=(const Node& rhd) {
    return (this->station->key != rhd.station->key);
}

bool Node::operator==(const Node& rhd) {
    return (this->station->key == rhd.station->key);
}

bool Node::operator<(const Node& rhd) {
    return (this->station->key < rhd.station->key);
}

bool Node::operator>(const Node& rhd) {
    return (this->station->key > rhd.station->key);
}