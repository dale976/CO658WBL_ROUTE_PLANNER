#pragma once

#include "linked-list/LinkedList.h"
#include "station/Station.h"

class TubeMap {
private:
    int** adjMat;
    int numberVertices;
    int size;
    static const int INF = 999999;
public:
    Station** vertices;

    TubeMap(int size);
    void Display();
    void DisplayKeyList();
    void AddEdge(int start, int end, int weight);
    void AddVertex(Station* vertex);
    LinkedList<Station>* GetAdjacentVerticesLL(Station* vertex);
    int DistanceBetweenVertices(Station* first, Station* second);
    Station* GetLowestWeight(LinkedList<Station>* adjacentVertices, Station* vertex);
    int GetNumberVertices();
    Station* GetStationById(int id);
};