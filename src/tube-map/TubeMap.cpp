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

Station* TubeMap::GetLowestWeight(LinkedList<Station>* adjacentVertices, Station* vertex) {
    int lowestKey = adjacentVertices->first->key;
    float lowestWeight = adjMat[vertex->key][lowestKey];
    Station* current = adjacentVertices->first->next;

    while (current != nullptr) {

        float currentWeight = adjMat[vertex->key][current->key];

        // Update lowest weight and connections count if currentWeight is lower
        if (currentWeight < lowestWeight) {
            lowestKey = current->key;
            lowestWeight = currentWeight;
        }

        current = current->next;
    }

    return vertices[lowestKey];
}

int TubeMap::GetNumberVertices() {
    return numberVertices;
}

Station* TubeMap::GetStationById(int id) {
    return vertices[id];
}