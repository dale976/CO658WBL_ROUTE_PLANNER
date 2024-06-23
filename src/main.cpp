#include <iostream>

#include "station/Station.h"
#include "tube-map/TubeMap.h"
#include "stack/Stack.h"
#include "dijkstra/Dijkstra.h"

using namespace std;

int main() {
    cout << "hello, world!" << endl;
    cout << "London Underground: Route Planner" << endl;

    TubeMap* tm = new TubeMap(53); // Can this be dynamic? (vector??)

    // Victoria Line
    tm->AddVertex(new Station(0, "Walthamstow Central", {"Victoria"}));
    tm->AddVertex(new Station(1, "Blackhorse Road", {"Victoria"}));
    tm->AddVertex(new Station(2, "Tottenham Hale", {"Victoria"}));
    tm->AddVertex(new Station(3, "Seven Sisters", {"Victoria"}));
    tm->AddVertex(new Station(4, "Finsbury Park", {"Victoria"}));
    tm->AddVertex(new Station(5, "Highbury & Islington", {"Victoria"}));
    tm->AddVertex(new Station(6, "King's Cross St. Pancras", {"Victoria", "Circle"}));
    tm->AddVertex(new Station(7, "Euston", {"Victoria"}));
    tm->AddVertex(new Station(8, "Warren Street", {"Victoria"}));
    tm->AddVertex(new Station(9, "Oxford Circus", {"Victoria"}));
    tm->AddVertex(new Station(10, "Green Park", {"Victoria"}));
    tm->AddVertex(new Station(11, "Victoria", {"Victoria", "Circle"}));
    tm->AddVertex(new Station(12, "Pimlico", {"Victoria"}));
    tm->AddVertex(new Station(13, "Vauxhall", {"Victoria"}));
    tm->AddVertex(new Station(14, "Stockwell", {"Victoria"}));
    tm->AddVertex(new Station(15, "Brixton", {"Victoria"}));

    // Circle Line
    tm->AddVertex(new Station(16, "Hammersmith", {"Circle"}));
    tm->AddVertex(new Station(17, "Goldhawk Road", {"Circle"}));
    tm->AddVertex(new Station(18, "Shepherd's Bush Market", {"Circle"}));
    tm->AddVertex(new Station(19, "Wood Lane", {"Circle"}));
    tm->AddVertex(new Station(20, "Latimer Road", {"Circle"}));
    tm->AddVertex(new Station(21, "Ladbroke Grove", {"Circle"}));
    tm->AddVertex(new Station(22, "Westbourne Park", {"Circle"}));
    tm->AddVertex(new Station(23, "Royal Oak", {"Circle"}));
    tm->AddVertex(new Station(24, "Paddington", {"Circle"}));
    tm->AddVertex(new Station(25, "Edgware Road", {"Circle", "Bakerloo", "District", "Hammersmith & City"}));
    tm->AddVertex(new Station(26, "Baker Street", {"Circle", "Bakerloo", "Jubilee", "Metropolitan"}));
    tm->AddVertex(new Station(27, "Great Portland Street", {"Circle", "Hammersmith & City", "Metropolitan"}));
    tm->AddVertex(new Station(28, "Euston Square", {"Circle", "Hammersmith & City", "Metropolitan"}));
    tm->AddVertex(new Station(29, "King's Cross St. Pancras", {"Circle", "Victoria"}));
    tm->AddVertex(new Station(30, "Farringdon", {"Circle", "Hammersmith & City", "Metropolitan"}));
    tm->AddVertex(new Station(31, "Barbican", {"Circle", "Hammersmith & City", "Metropolitan"}));
    tm->AddVertex(new Station(32, "Moorgate", {"Circle", "Hammersmith & City", "Metropolitan", "Northern"}));
    tm->AddVertex(new Station(33, "Liverpool Street", {"Circle", "Central", "Hammersmith & City", "Metropolitan"}));
    tm->AddVertex(new Station(34, "Aldgate", {"Circle", "Metropolitan"}));
    tm->AddVertex(new Station(35, "Tower Hill", {"Circle", "District"}));
    tm->AddVertex(new Station(36, "Monument", {"Circle", "District"}));
    tm->AddVertex(new Station(37, "Cannon Street", {"Circle", "District"}));
    tm->AddVertex(new Station(38, "Mansion House", {"Circle", "District"}));
    tm->AddVertex(new Station(39, "Blackfriars", {"Circle", "District"}));
    tm->AddVertex(new Station(40, "Temple", {"Circle", "District"}));
    tm->AddVertex(new Station(41, "Embankment", {"Circle", "District", "Bakerloo", "Northern"}));
    tm->AddVertex(new Station(42, "Westminster", {"Circle", "District", "Jubilee"}));
    tm->AddVertex(new Station(43, "St. James's Park", {"Circle", "District"}));
    tm->AddVertex(new Station(44, "Victoria", {"Circle", "Victoria"}));
    tm->AddVertex(new Station(45, "Sloane Square", {"Circle", "District"}));
    tm->AddVertex(new Station(46, "South Kensington", {"Circle", "District", "Piccadilly"}));
    tm->AddVertex(new Station(47, "Gloucester Road", {"Circle", "District", "Piccadilly"}));
    tm->AddVertex(new Station(48, "High Street Kensington", {"Circle", "District"}));
    tm->AddVertex(new Station(49, "Notting Hill Gate", {"Circle", "District", "Central"}));
    tm->AddVertex(new Station(50, "Bayswater", {"Circle", "District"}));
    tm->AddVertex(new Station(51, "Paddington", {"Circle", "District", "Bakerloo", "Hammersmith & City"}));
    tm->AddVertex(new Station(52, "Edgware Road", {"Circle", "Bakerloo", "District", "Hammersmith & City"}));


    // Victoria Line
    tm->AddEdge(0, 1, 2);  // Walthamstow Central - Blackhorse Road
    tm->AddEdge(1, 2, 3);  // Blackhorse Road - Tottenham Hale
    tm->AddEdge(2, 3, 2);  // Tottenham Hale - Seven Sisters
    tm->AddEdge(3, 4, 3);  // Seven Sisters - Finsbury Park
    tm->AddEdge(4, 5, 2);  // Finsbury Park - Highbury & Islington
    tm->AddEdge(5, 6, 3);  // Highbury & Islington - King's Cross St. Pancras
    tm->AddEdge(6, 7, 1);  // King's Cross St. Pancras - Euston
    tm->AddEdge(7, 8, 1);  // Euston - Warren Street
    tm->AddEdge(8, 9, 2);  // Warren Street - Oxford Circus
    tm->AddEdge(9, 10, 2); // Oxford Circus - Green Park
    tm->AddEdge(10, 11, 1); // Green Park - Victoria
    tm->AddEdge(11, 12, 2); // Victoria - Pimlico
    tm->AddEdge(12, 13, 2); // Pimlico - Vauxhall
    tm->AddEdge(13, 14, 2); // Vauxhall - Stockwell
    tm->AddEdge(14, 15, 2); // Stockwell - Brixton

    // Reverse journeys for Victoria Line
    tm->AddEdge(1, 0, 2);  // Blackhorse Road - Walthamstow Central
    tm->AddEdge(2, 1, 3);  // Tottenham Hale - Blackhorse Road
    tm->AddEdge(3, 2, 2);  // Seven Sisters - Tottenham Hale
    tm->AddEdge(4, 3, 3);  // Finsbury Park - Seven Sisters
    tm->AddEdge(5, 4, 2);  // Highbury & Islington - Finsbury Park
    tm->AddEdge(6, 5, 3);  // King's Cross St. Pancras - Highbury & Islington
    tm->AddEdge(7, 6, 1);  // Euston - King's Cross St. Pancras
    tm->AddEdge(8, 7, 1);  // Warren Street - Euston
    tm->AddEdge(9, 8, 2);  // Oxford Circus - Warren Street
    tm->AddEdge(10, 9, 2); // Green Park - Oxford Circus
    tm->AddEdge(11, 10, 1); // Victoria - Green Park
    tm->AddEdge(12, 11, 2); // Pimlico - Victoria
    tm->AddEdge(13, 12, 2); // Vauxhall - Pimlico
    tm->AddEdge(14, 13, 2); // Stockwell - Vauxhall
    tm->AddEdge(15, 14, 2); // Brixton - Stockwell

    // Circle Line
    tm->AddEdge(16, 17, 1);  // Hammersmith - Goldhawk Road
    tm->AddEdge(17, 18, 1);  // Goldhawk Road - Shepherd's Bush Market
    tm->AddEdge(18, 19, 1);  // Shepherd's Bush Market - Wood Lane
    tm->AddEdge(19, 20, 1);  // Wood Lane - Latimer Road
    tm->AddEdge(20, 21, 1);  // Latimer Road - Ladbroke Grove
    tm->AddEdge(21, 22, 1);  // Ladbroke Grove - Westbourne Park
    tm->AddEdge(22, 23, 1);  // Westbourne Park - Royal Oak
    tm->AddEdge(23, 24, 1);  // Royal Oak - Paddington
    tm->AddEdge(24, 25, 1);  // Paddington - Edgware Road
    tm->AddEdge(25, 26, 1);  // Edgware Road - Baker Street
    tm->AddEdge(26, 27, 1);  // Baker Street - Great Portland Street
    tm->AddEdge(27, 28, 1);  // Great Portland Street - Euston Square
    tm->AddEdge(28, 29, 1);  // Euston Square - King's Cross St. Pancras
    tm->AddEdge(29, 30, 1);  // King's Cross St. Pancras - Farringdon
    tm->AddEdge(30, 31, 1);  // Farringdon - Barbican
    tm->AddEdge(31, 32, 1);  // Barbican - Moorgate
    tm->AddEdge(32, 33, 1);  // Moorgate - Liverpool Street
    tm->AddEdge(33, 34, 1);  // Liverpool Street - Aldgate
    tm->AddEdge(34, 35, 1);  // Aldgate - Tower Hill
    tm->AddEdge(35, 36, 1);  // Tower Hill - Monument
    tm->AddEdge(36, 37, 1);  // Monument - Cannon Street
    tm->AddEdge(37, 38, 1);  // Cannon Street - Mansion House
    tm->AddEdge(38, 39, 1);  // Mansion House - Blackfriars
    tm->AddEdge(39, 40, 1);  // Blackfriars - Temple
    tm->AddEdge(40, 41, 1);  // Temple - Embankment
    tm->AddEdge(41, 42, 1);  // Embankment - Westminster
    tm->AddEdge(42, 43, 1);  // Westminster - St. James's Park
    tm->AddEdge(43, 44, 1);  // St. James's Park - Victoria
    tm->AddEdge(44, 45, 1);  // Victoria - Sloane Square
    tm->AddEdge(45, 46, 1);  // Sloane Square - South Kensington
    tm->AddEdge(46, 47, 1);  // South Kensington - Gloucester Road
    tm->AddEdge(47, 48, 1);  // Gloucester Road - High Street Kensington
    tm->AddEdge(48, 49, 1);  // High Street Kensington - Notting Hill Gate
    tm->AddEdge(49, 50, 1);  // Notting Hill Gate - Bayswater
    tm->AddEdge(50, 51, 1);  // Bayswater - Paddington
    tm->AddEdge(51, 52, 1);  // Paddington - Edgware Road
    tm->AddEdge(25, 52, 1);  // Edgware Road - Paddington (loop continuation)

    // Reverse journeys for Circle Line
    tm->AddEdge(17, 16, 1);  // Goldhawk Road - Hammersmith
    tm->AddEdge(18, 17, 1);  // Shepherd's Bush Market - Goldhawk Road
    tm->AddEdge(19, 18, 1);  // Wood Lane - Shepherd's Bush Market
    tm->AddEdge(20, 19, 1);  // Latimer Road - Wood Lane
    tm->AddEdge(21, 20, 1);  // Ladbroke Grove - Latimer Road
    tm->AddEdge(22, 21, 1);  // Westbourne Park - Ladbroke Grove
    tm->AddEdge(23, 22, 1);  // Royal Oak - Westbourne Park
    tm->AddEdge(24, 23, 1);  // Paddington - Royal Oak
    tm->AddEdge(25, 24, 1);  // Edgware Road - Paddington
    tm->AddEdge(26, 25, 1);  // Baker Street - Edgware Road
    tm->AddEdge(27, 26, 1);  // Great Portland Street - Baker Street
    tm->AddEdge(28, 27, 1);  // Euston Square - Great Portland Street
    tm->AddEdge(29, 28, 1);  // King's Cross St. Pancras - Euston Square
    tm->AddEdge(30, 29, 1);  // Farringdon - King's Cross St. Pancras
    tm->AddEdge(31, 30, 1);  // Barbican - Farringdon
    tm->AddEdge(32, 31, 1);  // Moorgate - Barbican
    tm->AddEdge(33, 32, 1);  // Liverpool Street - Moorgate
    tm->AddEdge(34, 33, 1);  // Aldgate - Liverpool Street
    tm->AddEdge(35, 34, 1);  // Tower Hill - Aldgate
    tm->AddEdge(36, 35, 1);  // Monument - Tower Hill
    tm->AddEdge(37, 36, 1);  // Cannon Street - Monument
    tm->AddEdge(38, 37, 1);  // Mansion House - Cannon Street
    tm->AddEdge(39, 38, 1);  // Blackfriars - Mansion House
    tm->AddEdge(40, 39, 1);  // Temple - Blackfriars
    tm->AddEdge(41, 40, 1);  // Embankment - Temple
    tm->AddEdge(42, 41, 1);  // Westminster - Embankment
    tm->AddEdge(43, 42, 1);  // St. James's Park - Westminster
    tm->AddEdge(44, 43, 1);  // Victoria - St. James's Park
    tm->AddEdge(45, 44, 1);  // Sloane Square - Victoria
    tm->AddEdge(46, 45, 1);  // South Kensington - Sloane Square
    tm->AddEdge(47, 46, 1);  // Gloucester Road - South Kensington
    tm->AddEdge(48, 47, 1);  // High Street Kensington - Gloucester Road
    tm->AddEdge(49, 48, 1);  // Notting Hill Gate - High Street Kensington
    tm->AddEdge(50, 49, 1);  // Bayswater - Notting Hill Gate
    tm->AddEdge(51, 50, 1);  // Paddington - Bayswater
    tm->AddEdge(52, 51, 1);  // Edgware Road - Paddington
    tm->AddEdge(52, 25, 1);  // Paddington - Edgware Road (loop continuation)

    // Intersections
    tm->AddEdge(6, 29, 0);  // King's Cross St. Pancras (Victoria) to King's Cross St. Pancras (Circle)
    tm->AddEdge(29, 6, 0);  // King's Cross St. Pancras (Circle) to King's Cross St. Pancras (Victoria)
    tm->AddEdge(11, 44, 0); // Victoria (Victoria) to Victoria (Circle)
    tm->AddEdge(44, 11, 0); // Victoria (Circle) to Victoria (Victoria)

    // tm->Display();

    string journeyPath = "";
    int journeyTime = 0;
    int numberConnections = 0;

    Dijkstra* d = new Dijkstra(tm);
    Stack<Node> *path = d->GetPath(0, 52);

    while(!path->IsEmpty()){
        journeyTime = path->Peek()->g;
        journeyPath += path->Peek()->station->name += " : (" + std::to_string(path->Peek()->station->key) + ")";
        numberConnections += path->Peek()->numberOfConnections;

        if (path->Count() != 1) {
            journeyPath += " -> ";
        }
        
        path->Pop();
    }

    cout << "Journey Path: " << journeyPath << endl;
    cout << "Journey Time: " << journeyTime << endl;
    cout << "Connections : " << numberConnections << endl;

        // Clean up
    delete path;
    delete d;
    delete tm;

    return 0;
}