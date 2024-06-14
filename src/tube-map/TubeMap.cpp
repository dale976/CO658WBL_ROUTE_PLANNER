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
    adjMat.resize(size, std::vector<float>(size, INF));
    for (int i = 0; i < size; ++i) {
        adjMat[i][i] = 999999; // Distance to itself is 0
    }
}

void TubeMap::AddVertex(Station* vertex) {
    vertices[numberVertices] = vertex;
    numberVertices++;
}

void TubeMap::AddEdge(int start, int end, float weight) {
    adjMat[start][end] = weight;
    adjMat[end][start] = weight;
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

vector<pair<Station*, float>> TubeMap::GetAdjacentVertices(Station* station) {
    vector<pair<Station*, float>> adjacent;
    int index = station->key;

    for (int i = 0; i < size; ++i) {
        if (adjMat[index][i] < INF && i != index) {
            adjacent.emplace_back(vertices[i], adjMat[index][i]);
        }
    }

    return adjacent;
}

int TubeMap::DistanceBetweenVertices(Station* first, Station* second) {
    return adjMat[first->key][second->key];
}

Station* TubeMap::GetLowestWeight(LinkedList<Station>* adjacentVertices, Station* vertex) {
    int lowest = adjacentVertices->first->key;
    float lowestWeight = adjMat[vertex->key][lowest];
    Station* current = adjacentVertices->first->next;

    while(current != NULL) {
        if (adjMat[vertex->key][current->key] < lowestWeight) {
            lowest = current->key;
            lowestWeight = adjMat[vertex->key][current->key];
        }
        current = current->next;
    }

    return vertices[lowest];
}

int TubeMap::GetNumberVertices() {
    return numberVertices;
}

Station* TubeMap::GetStationById(int stationId) {
    return vertices[stationId];
}