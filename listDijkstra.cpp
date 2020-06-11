#include "readGraph.hpp"
#include "shortestPath.hpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <chrono>


using namespace std;


int main(int argc, char** argv) 
{

	if (argc != 4) {
		
		cout << "Try Again With Proper Information " << endl;

		return 1;
	}

	string inFile = argv[1];
	string outFile = argv[2];
	string source = argv[3];
	
    string * vLabels;
    string ** eLabels;
    double ** weights;
    int * lengths;
    int ** adj;

    int sou;
    double * dist;
    int * prev;


    ifstream file (inFile);

    
    int vert = readGraph(file, adj, weights, lengths, vLabels, eLabels);

	cout << "Num Vert " << vert << endl;

    for (int i = 0; i < vert; i++) {

    	if ( source == vLabels[i]) {

    		sou = i;

    	}

 	}

	cout << "Source " << sou << endl;

    std::chrono::time_point<std::chrono::system_clock> start, end; 
    
    start = std::chrono::system_clock::now();

    dijkstra(adj, weights, lengths, vert, sou, dist, prev);

    end =  std::chrono::system_clock::now();

	
	ofstream ofile;

	ofile.open(outFile);

	ofile << vert << " " << "6" << endl;

	for (int i = 0; i < vert; i++) {

        ofile << vLabels[i] << endl ;
    }

    for (int i = 0; i < vert; i++) {

        if (i != sou ) {

            ofile << sou << " " << i << " " << dist [i] <<  endl ;

        }
        
    }


    std::chrono::duration<double> spent = end - start;

    cout << "\nTime Taken By Dijkstra (Heap): " << spent.count() << "\n" <<endl;



}