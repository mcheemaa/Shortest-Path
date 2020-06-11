#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>

#include <chrono>



using namespace std;


TEST_CASE("TESTING shortestPath Class")
{

  
  SECTION("Test shortestPath")
  {

  	ifstream inFile ("graph.txt");
    

    double ** matrix;
    string * vLabels;
    string ** eLabels;
    double ** weights;
    int * lengths;
    int ** adj;
    int ** edgeList;
    int ** numEdges;
    double * wei;
    
    int ** edge;
    int numE;

    string * eL;

    int vert = readGraph(inFile, matrix, vLabels, eLabels);

    int source = 0;

    double * dist;
    int * prev;

    

    dijkstra(matrix, vert, source, dist, prev);



    for (int i = 0; i < vert; i++) {

    	cout << "Source " << source << " Vertex " << i << endl;

    	cout << "Distance " << dist[i] << " Previous " << prev [i] << endl;

    }

    SECTION("Test Path Length")
  {

  	ifstream inFile ("graph.txt");
    

    double ** matrix;
    string * vLabels;
    string ** eLabels;
    double ** weights;
    int * lengths;
    int ** adj;
    int ** edgeList;
    int ** numEdges;
    double * wei;
    
    int ** edge;
    int numE;

    int * path;

    string * eL;

    int vert = readGraph(inFile, matrix, vLabels, eLabels);

    int source = 1;

    double * dist;
    int * prev;


    dijkstra(matrix, vert, source, dist, prev);


    int dest = 3;

    int finals = getPath(source, dest, prev, path);

    REQUIRE (finals == 3);

    cout << "\nSource: " << source <<endl;
    cout << "Destination: " << dest << endl;
    

    cout << "\nFollows This Path " << endl;

    for (int i = 0; i < finals; i++) {
    	
    	cout << path[i] << "  "; 


    }

    cout << "\n" <<endl;




	} 



 }


 SECTION("Test shortestPath")
  {

    ifstream inFile ("graph.txt");


    double ** matrix;
    string * vLabels;
    string ** eLabels;
    double ** weights;
    int * lengths;
    int ** adj;
    int ** edgeList;
    int ** numEdges;
    double * wei;
    
    int ** edge;
    int numE;

    string * eL;

    int vert = readGraph(inFile, adj, weights, lengths, vLabels, eLabels);

    int source = 1;


    double * dist;
    int * prev;

    dijkstra(adj, weights, lengths, vert, source, dist, prev);

    cout << "Using Heap Implementation" << endl; 

    cout << "Source " << source << endl;


    for (int i = 0; i < vert; i++) {
        
        cout << "Distance To " << i << " " << dist [i] << endl;

    }

}

    SECTION("Test Belman Ford")
  {

    ifstream inFile ("graph.txt");

    string * vLabels;
    string * eLabels;
    
    int ** edgeList;
    int ** numEdges;
    double * wei;
    
    int ** edge;
    int numE;

    int vert = readGraph(inFile, edgeList, wei, numE, vLabels, eLabels);

   

    int source = 0;

    double * dist;
    int * prev;

    int cycle = bellmanFord(edgeList, wei, vert, numE, source, dist, prev);


    cout << "\nCycle " << cycle << endl;

    cout << "Source " << source << endl;


    for (int i = 0; i < vert; i++) {
        
        cout << "Distance To " << i << " " << dist [i] << endl;

    }

    cout << endl;

   

}

   SECTION("Test Belman Ford - Negative Cycle")
  {

    ifstream inFile ("graph2.txt");

    string * vLabels;
    string * eLabels;
    
    int ** edgeList;
    int ** numEdges;
    double * wei;
    
    int ** edge;
    int numE;

    int vert = readGraph(inFile, edgeList, wei, numE, vLabels, eLabels);

   

    int source = 0;

    double * dist;
    int * prev;

    int cycle = bellmanFord(edgeList, wei, vert, numE, source, dist, prev);


    cout << "\nCycle " << cycle << endl;

    cout << "Source " << source << endl;


    for (int i = 0; i < vert; i++) {
        
        cout << "Distance To " << i << " " << dist [i] << endl;

    }

    cout << endl;

    int * negi;    

    int negC = getCycle(cycle, prev, vert, negi);

    cout << "Negative Cycle Is" << endl;

    for (int i = 0; i < negC; i++) {

        if (i < negC - 1 ) {

            cout << negi[i] << " -> " ;
        }

        else if (i == negC - 1) {

            cout << negi[i] << endl;

        }
    }

}


}


