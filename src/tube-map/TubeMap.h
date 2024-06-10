#pragma once

#include "station/Station.h"
#include "priority-queue/PriorityQueue.h"

class TubeMap {
private:
    int** adjMat; // adjacency matrix (2 dimensional array)
    int numberVertices;
    int size;
    static const int INF = 999999;
public:
    Station** vertices; // 1 dimensioanl array

    TubeMap(int size);
    void Display();
    void AddEdge(int start, int end, int weight);
    void AddVertex(Station* vertex);
    PriorityQueue<Station>* GetAdjacentVertices(Station* vertex);
    // LinkedList<Location>* GetAdjacentVerticesLL(Location* vertex);
    int DistanceBetweenVertices(Station* first, Station* second);
    Station* GetLowestWeight(PriorityQueue<Station>* adjacentVertices, Station* vertex);
    int GetNumberVertices();

};