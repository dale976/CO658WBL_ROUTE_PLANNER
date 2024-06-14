#include <iostream>
#include <unordered_set>
#include "dijkstra/Dijkstra.h"
#include "station/Station.h"
#include "node/Node.h"
#include "tube-map/TubeMap.h"
#include "priority-queue/PriorityQueue.h"
#include "linked-list/LinkedList.h"
#include <memory>

using namespace std;

Dijkstra::Dijkstra(TubeMap* tubeMap)
{
    // this->open = new LinkedList<Node>();
    this->openQ = std::make_unique<PriorityQueue<Node>>(tubeMap->GetNumberVertices());
    this->tubeMap = tubeMap;
    
    // Initialize distances to infinity
    for (int i = 0; i < tubeMap->GetNumberVertices(); i++) {
        dist[tubeMap->vertices[i]->key] = 999999;
        allNodes[tubeMap->vertices[i]->key] = std::make_unique<Node>(tubeMap->vertices[i]);
    }
}

Stack<Node>* Dijkstra::ReconstructPath(Node *goal)
{   
    cout << "Entering ReconstructPath" << endl;
    if (goal == nullptr) {
        cout << "Goal is nullptr" << endl;
        return nullptr;
    }

    Stack<Node> path(tubeMap->GetNumberVertices());
    Node *current = goal;
    cout << "Building path:" << endl;
    while (current != nullptr) {
        cout << "Visiting node: " << current->station->key << " (parent: " << (current->parent ? to_string(current->parent->station->key) : "none") << ")" << endl;
        path.Push(current);
        current = current->parent;
    }

    Stack<Node> reversedPath(tubeMap->GetNumberVertices());
    while (!path.IsEmpty()) {
        reversedPath.Push(path.Pop());
    }

    Stack<Node>* resultPath = new Stack<Node>(tubeMap->GetNumberVertices());
    while (!reversedPath.IsEmpty()) {
        resultPath->Push(reversedPath.Pop());
    }

    cout << "Exiting ReconstructPath" << endl;
    return resultPath;  
}

// Node* Dijkstra::FindLowestNode(LinkedList<Node> *lst)
// {
//     int lowest = 100000;
//     Node *lowestNode = 0;
//     Node *current = lst->first;
//     while (current != 0)
//     {
//         if (current->g < lowest)
//         {
//             lowest = current->g;
//             lowestNode = current;
//         }
//         current = current->next;
//     }
//     return lowestNode;
// }

Stack<Node>* Dijkstra::GetPath(int start, int goal) {
    // wrap start and goal in Nodes
    auto startNode = std::make_unique<Node>(this->tubeMap->GetStationById(start));
    auto goalNode = std::make_unique<Node>(this->tubeMap->GetStationById(goal));

    dist[startNode->station->key] = 999999;

    // insert the start node into the queue
    this->openQ->Insert(startNode.get());
    allNodes[startNode->station->key] = std::move(startNode);

    try {
        while(openQ->IsEmpty() == false) {
            cout << "in here?" << endl;
            // grab the top item in the queue
            Node* current = openQ->PeakMin();
            // remove the top item from the queue
            openQ->Remove();
            // if goal reached, recreate the path
            if (current->station->key == goalNode->station->key) {
                cout << "reconstruct" << endl;
                path = ReconstructPath(current);
                return path;
            }
            // get the adjacent vertices
            auto adjacent = tubeMap->GetAdjacentVertices(current->station);

            for (const auto& pair : adjacent) {
                cout << "in for loop----- " << endl;
                Station* adjStation = pair.first;
                float weight = pair.second;

                // Ensure adjNode is initialized
                Node* adjNode;
                if (allNodes.find(adjStation->key) != allNodes.end()) {
                    adjNode = allNodes[adjStation->key].get();
                } else {
                    auto newAdjNode = std::make_unique<Node>(adjStation);
                    adjNode = newAdjNode.get();
                    adjNode->g = 999999;
                    allNodes[adjStation->key] = std::move(newAdjNode);
                }

                float distance = current->g + weight;

                // std::unordered_set<std::string> currentLines(current->station->lines.begin(), current->station->lines.end());
                // std::unordered_set<std::string> adjLines(adjStation->lines.begin(), adjStation->lines.end());
                // bool lineChange = false;

                // for (const auto& line : currentLines) {
                //     if (adjLines.find(line) == adjLines.end()) {
                //         lineChange = true;
                //         break;
                //     }
                // }

                // if (lineChange) {
                //     distance += 5.0; // Add penalty for line change
                //     adjNode->connections = current->connections + 1;
                // } else {
                //     adjNode->connections = current->connections;
                // }
                cout << "Updating node " << adjNode->station->key << " with new distance " << distance << " from node " << current->station->key << endl;
                if (distance < adjNode->g) { // Update only if the new distance is shorter
                    cout << "Updating node " << adjNode->station->key << " with new distance " << distance << " from node " << current->station->key << endl;
                    adjNode->g = distance;
                    adjNode->parent = current;
                    openQ->Insert(adjNode);
                }

            }
            
            return nullptr;
        }


    } catch (const std::exception& e) {
        cout << "EXCEPTION: " << e.what() << endl;
        throw;

    }
}
