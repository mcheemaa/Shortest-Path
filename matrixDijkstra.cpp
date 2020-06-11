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

	if (argc != 5) {
		
		cout << "Try Again With Proper Information " << endl;

		return 1;
	}

	string inFile = argv[1];
	string outFile = argv[2];
	string source = argv[3];
	string dest = argv[4];

	double ** matrix;
	string * vLabels;
    string ** eLabels;
    
    int sou;
    double * dist;
    int * prev;

    int desti;

    ifstream file (inFile);

    
	int vert = readGraph(file, matrix, vLabels, eLabels);

	cout << "Num Vert " << vert << endl;

    for (int i = 0; i < vert; i++) {

    	if ( source == vLabels[i]) {

    		sou = i;

    	}

    	if ( dest == vLabels[i]) {

    		desti = i;
    	}
	}

	cout << "Source " << sou << endl;

    std::chrono::time_point<std::chrono::system_clock> start, end; 
    
    start = std::chrono::system_clock::now();

	dijkstra(matrix, vert, sou, dist, prev);

    end =  std::chrono::system_clock::now();

	int * path;

	int finals = getPath(sou, desti, prev, path);

	//cout << "Path Size " << finals << endl;

	ofstream ofile;

	ofile.open(outFile);

	ofile << vert << " " << finals - 1 << endl;

	for (int i = 0; i < vert; i++) {

        ofile << vLabels[i] << endl ;
    }

    int previous = path[0];
    int temp;


    for (int i = 1; i < finals; i++) {

    	temp = path [i];
    	ofile << previous << " " << temp << " " << matrix[previous][temp] << " " << eLabels[previous][temp] << " " << endl ;
   
    	previous = temp;
    	//cout << path[i] << "  " << endl;; 
    }

    double shortest = 0;

    previous = path[0];
    int tempo;

    for (int i = 1; i < finals; i++) {

        tempo = path [i];
        
        shortest = shortest + matrix[previous][tempo];

        previous = tempo;
        //cout << path[i] << "  " << endl;; 
    }

    cout << "\nShortest Path From " << sou << " To " << desti << " Is : " << shortest << endl;


    std::chrono::duration<double> spent = end - start;

    cout << "\nTime Take By Dijkstra: " << spent.count() << "\n" <<endl;


  

    


}