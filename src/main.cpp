#include <iostream>

#include "station/Station.h"
#include "tube-map/TubeMap.h"
#include "stack/Stack.h"
#include "dijkstra/Dijkstra.h"

// Advanced Programming
#include "constructors/GameObject.h"
#include "constructors/Location.h"

using namespace std;

void runTubeMap() {
    cout << "London Underground: Route Planner" << endl;

    TubeMap* tm = new TubeMap(89); // Can this be dynamic? (vector??)

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
    // District Line
    tm->AddVertex(new Station(53, "Upminster", {"District"}));
    tm->AddVertex(new Station(54, "Upminster Bridge", {"District"}));
    tm->AddVertex(new Station(55, "Hornchurch", {"District"}));
    tm->AddVertex(new Station(56, "Elm Park", {"District"}));
    tm->AddVertex(new Station(57, "Dagenham East", {"District"}));
    tm->AddVertex(new Station(58, "Dagenham Heathway", {"District"}));
    tm->AddVertex(new Station(59, "Becontree", {"District"}));
    tm->AddVertex(new Station(60, "Upney", {"District"}));
    tm->AddVertex(new Station(61, "Barking", {"District", "Hammersmith & City"}));
    tm->AddVertex(new Station(62, "East Ham", {"District", "Hammersmith & City"}));
    tm->AddVertex(new Station(63, "Plaistow", {"District", "Hammersmith & City"}));
    tm->AddVertex(new Station(64, "West Ham", {"District", "Hammersmith & City", "Jubilee"}));
    tm->AddVertex(new Station(65, "Bromley-by-Bow", {"District", "Hammersmith & City"}));
    tm->AddVertex(new Station(66, "Bow Road", {"District", "Hammersmith & City"}));
    tm->AddVertex(new Station(67, "Mile End", {"District", "Central", "Hammersmith & City"}));
    tm->AddVertex(new Station(68, "Stepney Green", {"District", "Hammersmith & City"}));
    tm->AddVertex(new Station(69, "Whitechapel", {"District", "Hammersmith & City"}));
    tm->AddVertex(new Station(70, "Aldgate East", {"District", "Hammersmith & City"}));
    tm->AddVertex(new Station(71, "Tower Hill", {"District", "Circle"}));
    tm->AddVertex(new Station(72, "Monument", {"District", "Circle"}));
    tm->AddVertex(new Station(73, "Cannon Street", {"District", "Circle"}));
    tm->AddVertex(new Station(74, "Mansion House", {"District", "Circle"}));
    tm->AddVertex(new Station(75, "Blackfriars", {"District", "Circle"}));
    tm->AddVertex(new Station(76, "Temple", {"District", "Circle"}));
    tm->AddVertex(new Station(77, "Embankment", {"District", "Circle", "Bakerloo", "Northern"}));
    tm->AddVertex(new Station(78, "Westminster", {"District", "Circle", "Jubilee"}));
    tm->AddVertex(new Station(79, "St. James's Park", {"District", "Circle"}));
    tm->AddVertex(new Station(80, "Victoria", {"District", "Circle", "Victoria"}));
    tm->AddVertex(new Station(81, "Sloane Square", {"District", "Circle"}));
    tm->AddVertex(new Station(82, "South Kensington", {"District", "Circle", "Piccadilly"}));
    tm->AddVertex(new Station(83, "Gloucester Road", {"District", "Circle", "Piccadilly"}));
    tm->AddVertex(new Station(84, "High Street Kensington", {"District", "Circle"}));
    tm->AddVertex(new Station(85, "Notting Hill Gate", {"District", "Circle", "Central"}));
    tm->AddVertex(new Station(86, "Bayswater", {"District", "Circle"}));
    tm->AddVertex(new Station(87, "Paddington", {"District", "Circle", "Bakerloo", "Hammersmith & City"}));
    tm->AddVertex(new Station(88, "Edgware Road", {"District", "Circle", "Bakerloo", "Hammersmith & City"}));
    
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
    // District Line Edges
    tm->AddEdge(53, 54, 2); // Upminster - Upminster Bridge
    tm->AddEdge(54, 55, 2); // Upminster Bridge - Hornchurch
    tm->AddEdge(55, 56, 2); // Hornchurch - Elm Park
    tm->AddEdge(56, 57, 2); // Elm Park - Dagenham East
    tm->AddEdge(57, 58, 2); // Dagenham East - Dagenham Heathway
    tm->AddEdge(58, 59, 2); // Dagenham Heathway - Becontree
    tm->AddEdge(59, 60, 2); // Becontree - Upney
    tm->AddEdge(60, 61, 2); // Upney - Barking
    tm->AddEdge(61, 62, 2); // Barking - East Ham
    tm->AddEdge(62, 63, 2); // East Ham - Plaistow
    tm->AddEdge(63, 64, 2); // Plaistow - West Ham
    tm->AddEdge(64, 65, 2); // West Ham - Bromley-by-Bow
    tm->AddEdge(65, 66, 2); // Bromley-by-Bow - Bow Road
    tm->AddEdge(66, 67, 2); // Bow Road - Mile End
    tm->AddEdge(67, 68, 2); // Mile End - Stepney Green
    tm->AddEdge(68, 69, 2); // Stepney Green - Whitechapel
    tm->AddEdge(69, 70, 2); // Whitechapel - Aldgate East
    tm->AddEdge(70, 71, 2); // Aldgate East - Tower Hill
    tm->AddEdge(71, 72, 2); // Tower Hill - Monument
    tm->AddEdge(72, 73, 2); // Monument - Cannon Street
    tm->AddEdge(73, 74, 2); // Cannon Street - Mansion House
    tm->AddEdge(74, 75, 2); // Mansion House - Blackfriars
    tm->AddEdge(75, 76, 2); // Blackfriars - Temple
    tm->AddEdge(76, 77, 2); // Temple - Embankment
    tm->AddEdge(77, 78, 2); // Embankment - Westminster
    tm->AddEdge(78, 79, 2); // Westminster - St. James's Park
    tm->AddEdge(79, 80, 2); // St. James's Park - Victoria
    tm->AddEdge(80, 81, 2); // Victoria - Sloane Square
    tm->AddEdge(81, 82, 2); // Sloane Square - South Kensington
    tm->AddEdge(82, 83, 2); // South Kensington - Gloucester Road
    tm->AddEdge(83, 84, 2); // Gloucester Road - High Street Kensington
    tm->AddEdge(84, 85, 2); // High Street Kensington - Notting Hill Gate
    tm->AddEdge(85, 86, 2); // Notting Hill Gate - Bayswater
    tm->AddEdge(86, 87, 2); // Bayswater - Paddington
    tm->AddEdge(87, 88, 2); // Paddington - Edgware Road

    // Intersections
    tm->AddEdge(6, 29, 0);  // King's Cross St. Pancras (Victoria) to King's Cross St. Pancras (Circle)
    tm->AddEdge(29, 6, 0);  // King's Cross St. Pancras (Circle) to King's Cross St. Pancras (Victoria)
    tm->AddEdge(11, 44, 0); // Victoria (Victoria) to Victoria (Circle)
    tm->AddEdge(44, 11, 0); // Victoria (Circle) to Victoria (Victoria)

    tm->AddEdge(25, 88, 0); // Edgware Road (Circle) to Edgware Road (District)
    tm->AddEdge(88, 25, 0); // Edgware Road (District) to Edgware Road (Circle)
    tm->AddEdge(35, 71, 0); // Tower Hill (Circle) to Tower Hill (Distrcit)
    tm->AddEdge(71, 35, 0); // Tower Hill (District) to Tower Hill (Circle)
    tm->AddEdge(36, 72, 0); // Monument (Circle) to Monument (District)
    tm->AddEdge(72, 36, 0); // Monument (District) to Monument (Circle)
    tm->AddEdge(37, 73, 0); // Cannon Street (District) to Monument (Circle)
    tm->AddEdge(73, 37, 0); // Monument (District) to Cannon Street (Circle)
    tm->AddEdge(38, 74, 0); // Monument (District) to Cannon Street (Circle)
    tm->AddEdge(74, 38, 0); // Monument (District) to Cannon Street (Circle)

    tm->AddEdge(39, 75, 2);  // Blackfriars (Circle) - Blackfriars (District)
    tm->AddEdge(40, 76, 2);  // Temple (Circle) - Temple (District)
    tm->AddEdge(41, 77, 2);  // Embankment (Circle) - Embankment (District)
    tm->AddEdge(42, 78, 2);  // Westminster (Circle) - Westminster (District)
    tm->AddEdge(43, 79, 2);  // St. James's Park (Circle) - St. James's Park (District)
    tm->AddEdge(44, 80, 2);  // Victoria (Circle) - Victoria (District)
    tm->AddEdge(45, 81, 2);  // Sloane Square (Circle) - Sloane Square (District)
    tm->AddEdge(46, 82, 2);  // South Kensington (Circle) - South Kensington (District)
    tm->AddEdge(47, 83, 2);  // Gloucester Road (Circle) - Gloucester Road (District)
    tm->AddEdge(48, 84, 2);  // High Street Kensington (Circle) - High Street Kensington (District)
    tm->AddEdge(49, 85, 2);  // Notting Hill Gate (Circle) - Notting Hill Gate (District)
    tm->AddEdge(50, 86, 2);  // Bayswater (Circle) - Bayswater (District)
    tm->AddEdge(51, 87, 2);  // Paddington (Circle) - Paddington (District)
    tm->AddEdge(52, 88, 2);  // Edgware Road (Circle) - Edgware Road (District)

    tm->AddEdge(75, 39, 2);  // Blackfriars (District) - Blackfriars (Circle)
    tm->AddEdge(76, 40, 2);  // Temple (District) - Temple (Circle)
    tm->AddEdge(77, 41, 2);  // Embankment (District) - Embankment (Circle)
    tm->AddEdge(78, 42, 2);  // Westminster (District) - Westminster (Circle)
    tm->AddEdge(79, 43, 2);  // St. James's Park (District) - St. James's Park (Circle)
    tm->AddEdge(80, 44, 2);  // Victoria (District) - Victoria (Circle)
    tm->AddEdge(81, 45, 2);  // Sloane Square (District) - Sloane Square (Circle)
    tm->AddEdge(82, 46, 2);  // South Kensington (District) - South Kensington (Circle)
    tm->AddEdge(83, 47, 2);  // Gloucester Road (District) - Gloucester Road (Circle)
    tm->AddEdge(84, 48, 2);  // High Street Kensington (District) - High Street Kensington (Circle)
    tm->AddEdge(85, 49, 2);  // Notting Hill Gate (District) - Notting Hill Gate (Circle)
    tm->AddEdge(86, 50, 2);  // Bayswater (District) - Bayswater (Circle)
    tm->AddEdge(87, 51, 2);  // Paddington (District) - Paddington (Circle)
    tm->AddEdge(88, 52, 2);  // Edgware Road (District) - Edgware Road (Circle)

    tm->AddEdge(61, 71, 2); // Barking (District) - Tower Hill (Circle)
    tm->AddEdge(64, 67, 3); // West Ham (District, Jubilee) - Mile End (District, Central, Hammersmith & City)
    tm->AddEdge(70, 80, 2); // Aldgate East (District, Hammersmith & City) - Victoria (District, Circle, Victoria)
    tm->AddEdge(77, 80, 2); // Embankment (District, Circle, Bakerloo, Northern) - Victoria (District, Circle, Victoria)
    tm->AddEdge(71, 77, 2); // Tower Hill (District, Circle) - Embankment (District, Circle, Bakerloo, Northern)

    // tm->Display();
    tm->DisplayKeyList();

    string startStationKey, endStationKey;
    cout << "Enter start station key: ";
    getline(cin, startStationKey);
    cout << "Enter end station key: ";
    getline(cin, endStationKey);

    string journeyPath = "";
    int journeyTime = 0;

    Dijkstra* d = new Dijkstra(tm);
    Stack<Node> *path = d->GetPath(stoi(startStationKey), stoi(endStationKey));

    while(!path->IsEmpty()){
        journeyTime = path->Peek()->g;
        journeyPath += path->Peek()->station->name += " : (" + to_string(path->Peek()->station->key) + ")";

        if (path->Count() != 1) {
            journeyPath += " -> ";
        }
        
        path->Pop();
    }

    cout << "Journey Path: " << journeyPath << endl;
    cout << "Journey Time: " << journeyTime << endl;

    // Clean up
    delete path;
    delete d;
    delete tm;
}

// Week 4: Constructors
void runConstructors() {
    


    // ex 1
    // static identifier named obj1
    // static GameObject obj1;
    // display value of id on GameObject
    // cout << "GameObject 1: " << obj1.id << endl;
    // Output is zero as this is initialised within the default constructor

    // EX2
    // static identifier name obj2
    static GameObject obj2(45);
    // display output of id
    cout << "GameObject 2: " << obj2.id << endl;
    // output is 45 as this is passed in as an argument

    static GameObject obj3(5);
    static GameObject obj4(10);
    static GameObject obj5(20);

    cout << "Game Object instance count = " << GameObject::instanceCount << endl;
    cout << "obj5 Object instance count = " << obj5.instanceCount << endl;

    //EX 5
    static Location loc(1, 2, 3);
    loc.Display();
}

// initialise instanceCount with a value
int GameObject::instanceCount = 0;

int main() {
    runConstructors();

    return 0;
}