#include <iostream>

#include "TubeMap.h"
#include "station/Station.h"
#include "priority-queue/PriorityQueue.h"
#include "linked-list/LinkedList.h"

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
        cout << vertices[i]->name << "\t";
        for (int j = 0; j < size; j++) {
            cout << adjMat[i][j] << "\t";
        }
        cout << endl;
    }
}

LinkedList<Station>* TubeMap::GetAdjacentVerticesLL(Station* vertex) {
    LinkedList<Station>* adjacent = new LinkedList<Station>();
    for (int j = 0; j < numberVertices; j++) {
        if (adjMat[vertex->key][j] != INF) {
            adjacent->Insert(vertices[j]);
        }
    }
    return adjacent;
}

int TubeMap::DistanceBetweenVertices(Station* first, Station* second) {
    return adjMat[first->key][second->key];
}

StationInfo TubeMap::GetLowestWeight(LinkedList<Station>* adjacentVertices, Station* vertex) {
    int lowest = adjacentVertices->first->key;
    float lowestWeight = adjMat[vertex->key][lowest];
    Station* current = adjacentVertices->first->next;
    int lowestConnections = 0;

    // Check to see if the vertex is on a different line
    auto it = find_first_of(vertex->lines.begin(), vertex->lines.end(), vertices[lowest]->lines.begin(), vertices[lowest]->lines.end());
    bool lineChange = it == vertex->lines.end();

    if (lineChange) {
        lowestWeight += 5;
        lowestConnections = 1;
    }

    while (current != nullptr) {
        float currentWeight = adjMat[vertex->key][current->key];
        int currentConnections = 0;

        // Check to see if a line change occurs
        it = find_first_of(vertex->lines.begin(), vertex->lines.end(), current->lines.begin(), current->lines.end());
        lineChange = it == vertex->lines.end();
        // Add penalty for changing lines
        if (lineChange) {
            currentWeight += 5;  // Use currentWeight instead of lowestWeight
            currentConnections = 1;
        }

        if (currentWeight < lowestWeight) {
            lowest = current->key;
            lowestWeight = currentWeight;
            lowestConnections = currentConnections;
        }

        current = current->next;
    }

    return {vertices[lowest], lowestConnections};
}

int TubeMap::GetNumberVertices() {
    return numberVertices;
}

Station* TubeMap::GetStationById(int id) {
    return vertices[id];
}