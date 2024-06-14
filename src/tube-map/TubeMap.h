#pragma once

#include "linked-list/LinkedList.h"
#include "station/Station.h"
#include <unordered_map>
#include <iostream>

class TubeMap {
private:
    vector<vector<float>> adjMat; // adjacency matrix (2 dimensional array)
    int numberVertices;
    int size;
    static const int INF = 999999;
public:
    unordered_map<int, vector<pair<int, int>>> adjacencyList;
    Station** vertices; // 1 dimensioanl array

    TubeMap(int size);
    void Display();
    void AddEdge(int start, int end, float weight);
    void AddVertex(Station* vertex);
    // PriorityQueue<Station>* GetAdjacentVertices(Station* vertex);
    // LinkedList<Station>* GetAdjacentVerticesLL(Station* vertex);
    int DistanceBetweenVertices(Station* first, Station* second);
    Station* GetLowestWeight(LinkedList<Station>* adjacentVertices, Station* vertex);
    Station* GetStationById(int stationId);
    int GetNumberVertices();
    vector<pair<Station*, float>> GetAdjacentVertices(Station* station);
};