#include <iostream>
#include <unordered_set>

#include "dijkstra/Dijkstra.h"
#include "station/Station.h"
#include "node/Node.h"
#include "tube-map/TubeMap.h"
#include "linked-list/LinkedList.h"

using namespace std;

Dijkstra::Dijkstra(TubeMap* tubeMap)
{
    this->open = new LinkedList<Node>();
    this->tubeMap = tubeMap;
}

Stack<Node> *Dijkstra::ReconstructPath(Node *goal)
{
    Stack<Node> *path = new Stack<Node>(tubeMap->GetNumberVertices());
    Node *current = goal;
    while (current->parent != 0)
    {
        path->Push(current);
        current = current->parent;
    }

    return path;
}

Node* Dijkstra::FindLowestNode(LinkedList<Node> *lst)
{
    int lowest = 100000;
    Node *lowestNode = 0;
    Node *current = lst->first;
    while (current != 0)
    {
        if (current->g < lowest)
        {
            lowest = current->g;
            lowestNode = current;
        }
        current = current->next;
    }
    return lowestNode;
}

Stack<Node>* Dijkstra::GetPath(int start, int goal) {
    // wrap start and goal in Nodes
    Node* startNode = new Node(this->tubeMap->GetStationById(start));
    Node* goalNode = new Node(this->tubeMap->GetStationById(goal));
    // insert start node into open list
    this->open->Insert(startNode);
    // Set to keep track of visited nodes
    unordered_set<int> visited;
    // loop while open not empty
    while(open->IsEmpty() == false) {
        // set current to lowest node in open
        Node* current = FindLowestNode(open);
        // remove current from open
        this->open->Delete(current);
        visited.insert(current->station->key);
        // store currents adjacent vertices in a LL
        LinkedList<Station>* adjacent = this->tubeMap->GetAdjacentVerticesLL(current->station);
        // loop while adjacent not empty
        while(adjacent->IsEmpty() == false) {
            // set adj to lowest weighted in adjacent list
            Station* adj = this->tubeMap->GetLowestWeight(adjacent, current->station);
            // If the adjacent node is already visited, skip it
            if (visited.find(adj->key) != visited.end()) {
                adjacent->Delete(adj);
                continue;
            }
            // wrap adj in node
            Node* adjNode = new Node(adj);
            // set distance to current.g value + distanceBetween current and adj
            float distance = current->g + this->tubeMap->DistanceBetweenVertices(current->station, adj);
            //if adj node’s g is zero  or distance < adj node’s g
            if (adjNode->g == 0 || distance < adjNode->g) {
                // set adj node’s g to distance 
                adjNode->g = distance;
                // set adj node’s parent to current
                adjNode->parent = current;
            }
            if (adj == goalNode->station) {
                return ReconstructPath(adjNode);
            }
            open->Insert(adjNode);
            adjacent->Delete(adj);
        }
    }
    return 0;
}
