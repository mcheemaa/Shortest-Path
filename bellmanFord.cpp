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
    string * eLabels;
    
    int ** edgeList;
    double * wei;
    
    int numE;

    int sou;



    ifstream file (inFile);

    
    int vert = readGraph(file, edgeList, wei, numE, vLabels, eLabels);

    cout << "Num Vert " << vert << endl;

    for (int i = 0; i < vert; i++) {

        if ( source == vLabels[i]) {

            sou = i;

        }

    }

    cout << "Source " << sou << endl;

    double * dist;
    int * prev;

    std::chrono::time_point<std::chrono::system_clock> start, end; 
    
    start = std::chrono::system_clock::now();

    int cycle = bellmanFord(edgeList, wei, vert, numE, sou, dist, prev);

    end =  std::chrono::system_clock::now();

    std::chrono::duration<double> spent = end - start;


    if (cycle != -1) {

        cout << "Negative Cycle Detected! " << endl;
        cout << "Total Weght: " << wei [cycle] << endl;
        cout << "Runtime: "<< spent.count() << " Microseconds\n" <<endl;


        int * negi;    

        int negC = getCycle(cycle, prev, vert, negi);

        ofstream ofile;

        ofile.open(outFile);

        ofile << vert << " " << "4" << endl;

        for (int i = 0; i < vert; i++) {

            ofile << vLabels[i] << endl ;
        }

       
        for (int i = 1; i < negC; i++) {
     
           ofile << wei [negi[i]] << " " << negi[i - 1] << " -> " << negi [i] <<endl ;
         
        }

        
    }


    else {



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

    }


    cout << "\nTime Taken By Bellman Ford: " << spent.count() << "\n" <<endl;






}