#include <iostream>

#include "TubeMap.h"
#include "station/Station.h"
#include "priority-queue/PriorityQueue.h"

using namespace std;

TubeMap::TubeMap(int size) {
    this->size = size;
    numberVertices = 0;

    vertices = new Station* [size];
    adjMat = new int* [size];
    for (int i = 0; i < size; i++) {
        adjMat[i] = new int [size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adjMat[i][j] = INF;
        }
    }
}

void TubeMap::AddVertex(Station* vertex) {
    vertices[numberVertices] = vertex;
    numberVertices++;
}

void TubeMap::AddEdge(int start, int end, int weight) {
    adjMat[start][end] = weight;
}

void TubeMap::Display() {
    string matrixHeading = "\t";

    for (int k = 0; k < size; k++) {
        matrixHeading += vertices[k]->name;
        matrixHeading += "\t";
    }

    cout << matrixHeading << endl;

    for (int i = 0; i < size; i++) {
        cout << vertices[i]->key << "\t";
        for (int j = 0; j < size; j++) {
            cout << adjMat[i][j] << "\t";
        }
        cout << endl;
    }
}

PriorityQueue<Station>* TubeMap::GetAdjacentVertices(Station* vertex) {
    PriorityQueue<Station>* adjacent = new PriorityQueue<Station>(numberVertices);
    // iterate through adjMat array for the amount of vertices there are, if the key at position does not
    // equal INF, then insert into the new array. 
    // This means the vertex has another next to it
    for (int j = 0; j < numberVertices; j++) {
        if(adjMat[vertex->key][j] != INF) {
            adjacent->Insert(vertices[j]);
        }
    }
    return adjacent;
}

// LinkedList<Station>* TubeMap::GetAdjacentVerticesLL(Station* vertex) {
//     LinkedList<Station>* adjacent = new LinkedList<Station>();
//     for (int j = 0; j < numberVertices; j++) {
//         if (adjMat[vertex->key != INF]) {
//             adjacent->Insert(vertices[j]);
//         }
//     }
//     return adjacent;
// }

int TubeMap::DistanceBetweenVertices(Station* first, Station* second) {
    return adjMat[first->key][second->key];
}

// Station* TubeMap::GetLowestWeight(TPriorityQueue<Station>* adjacentVertices, Station* vertex) {
//     int lowest = adjacentVertices->first->key;
//     float lowestWeight = adjMat[vertex->key][lowest];
//     Station* current = adjacentVertices->first->next;

//     while(current != NULL) {
//         if (adjMat[vertex->key][current->key] < lowestWeight) {
//             lowest = current->key;
//             lowestWeight = adjMat[vertex->key][current->key];
//         }
//         current = current->next;
//     }

//     return vertices[lowest];
// }