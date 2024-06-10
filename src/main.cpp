#include <iostream>

#include "station/Station.h"
#include "tube-map/TubeMap.h"
#include "stack/Stack.h"
#include "dijkstra/Dijkstra.h"

using namespace std;

int main() {
    cout << "hello, world!" << endl;
    cout << "London Underground: Route Planner" << endl;


    TubeMap* tm = new TubeMap(6); // Can this be dynamic? (vector??)

    // Victoria Line Stations
    // tm->AddVertex(new Station(0, "Walthamstow Central"));
    // tm->AddVertex(new Station(1, "Blackhorse Road"));
    // tm->AddVertex(new Station(2, "Tottenham Hale"));
    // tm->AddVertex(new Station(3, "Seven Sisters"));
    // tm->AddVertex(new Station(4, "Finsbury_Park"));
    // tm->AddVertex(new Station(5, "Highbury_&_Islington"));
    // tm->AddVertex(new Station(6, "King's_Cross"));
    // tm->AddVertex(new Station(7, "Euston"));
    // tm->AddVertex(new Station(8, "Warren Street"));
    // tm->AddVertex(new Station(9, "Oxford Circus"));
    // tm->AddVertex(new Station(10, "Green Park"));
    // tm->AddVertex(new Station(11, "Victoria"));
    // tm->AddVertex(new Station(12, "Pimlico"));
    // tm->AddVertex(new Station(13, "Vauxhall"));
    // tm->AddVertex(new Station(14, "Stockwell"));
    // tm->AddVertex(new Station(15, "Brixton"));

    // Add weighting (time in mins approx)
    // tm->AddEdge(0, 1, 2); // Walthamstow Central to Blackhorse Road: 2 minutes
    // tm->AddEdge(1, 2, 2); // Blackhorse Road to Tottenham Hale: 2 minutes
    // tm->AddEdge(2, 3, 2); // Tottenham Hale to Seven Sisters: 2 minutes
    // tm->AddEdge(3, 4, 4); // Seven Sisters to Finsbury Park: 4 minutes
    // tm->AddEdge(4, 5, 2); // Finsbury Park to Highbury & Islington: 2 minutes
    // tm->AddEdge(5, 6, 4); // Highbury & Islington to King's Cross St Pancras: 4 minutes
    // tm->AddEdge(6, 7, 2); // King's Cross St Pancras to Euston: 2 minutes
    // tm->AddEdge(7, 8, 1); // Euston to Warren Street: 1 minute
    // tm->AddEdge(8, 9, 2); // Warren Street to Oxford Circus: 2 minutes
    // tm->AddEdge(9, 10, 2); // Oxford Circus to Green Park: 2 minutes
    // tm->AddEdge(10, 11, 2); // Green Park to Victoria: 2 minutes
    // tm->AddEdge(11, 12, 2); // Victoria to Pimlico: 2 minutes
    // tm->AddEdge(12, 13, 2); // Pimlico to Vauxhall: 2 minutes
    // tm->AddEdge(13, 14, 3); // Vauxhall to Stockwell: 3 minutes
    // tm->AddEdge(14, 15, 2); // Stockwell to Brixton: 2 minutes

    Station *start = new Station(0, "A", {"red", "blue"});
    Station *end = new Station(5, "F", {"green"});

    tm->AddVertex(start);
    tm->AddVertex(new Station(1, "B", {"red"}));
    tm->AddVertex(new Station(2, "C", {"blue", "red"}));
    tm->AddVertex(new Station(3, "D", {"green", "red"}));
    tm->AddVertex(new Station(4, "E", {"red"}));
    tm->AddVertex(end);

    tm->AddEdge(0, 1, 2); // a - b : 1
    tm->AddEdge(0, 3, 1); // a - d : 1
    tm->AddEdge(1, 2, 1); // b - c : 1
    tm->AddEdge(1, 4, 2); // b - e : 1
    tm->AddEdge(3, 4, 2); // d - e : 1
    tm->AddEdge(3, 5, 1); // d - e : 1

    tm->Display();

    Dijkstra* d = new Dijkstra(tm);
    Stack<Node> *path = d->GetPath(start, end);
    while(path->IsEmpty() == false){
        cout << path->Pop()->station->name <<endl;
    }

    return 0;
}