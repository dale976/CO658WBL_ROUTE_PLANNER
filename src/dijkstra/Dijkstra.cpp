#include <iostream>
#include "dijkstra/Dijkstra.h"
#include "station/Station.h"
#include "node/Node.h"
#include "tube-map/TubeMap.h"
#include "priority-queue/PriorityQueue.h"
#include "linked-list/LinkedList.h"
#include <unordered_set>

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
    path->Push(current);
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

/*
    Dijkstra Pseudo.
    For each vertex v:
        Dist[v] = infinite
        Prev[v] = none
    Dist source = 0
    Set all vertices to unexplored
    While destination not explored:
    V = least valued unexplored vortex
    Set v to explored
    For each edge (v, w):
        If dist[v] + len(v, w) < dist[w]:
        Dist[w] = dist[v] + len[v, w]
Prev[w] = v
*/


Stack<Node>* Dijkstra::GetPath(int start, int goal) {
    // wrap start and goal in Nodes
    Node* startNode = new Node(this->tubeMap->GetStationById(start));
    Node* goalNode = new Node(this->tubeMap->GetStationById(goal));
    // insert start node into open list
    this->open->Insert(startNode);
    // loop while open not empty
    while(open->IsEmpty() == false) {
        // set current to lowest node in open
        Node* current = FindLowestNode(open);
        // remove current from open
        this->open->Delete(current);
        // store currents adjacent vertices in a LL
        LinkedList<Station>* adjacent = this->tubeMap->GetAdjacentVerticesLL(current->station);
        // loop while adjacent not empty
        while(adjacent->IsEmpty() == false) {
            // set adj to lowest weighted in adjacent list
            StationInfo lowestInfo = this->tubeMap->GetLowestWeight(adjacent, current->station);
            Station* adj = lowestInfo.station;
            // wrap adj in node
            Node* adjNode = new Node(adj);
            // update the number of connections on the wrapper node
            adjNode->numberOfConnections = lowestInfo.numberOfConnections;

            // check to see if the adjacent station is on the same line, if it is not, incur a penalty
            // and track number of changes
            vector<string> lineChanges;
            auto it = std::find_first_of(current->station->lines.begin(), current->station->lines.end(), adj->lines.begin(), adj->lines.end());
            bool lineChange = it != current->station->lines.end();
            cout << "LINE CHANGE : " << lineChange << endl;

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
